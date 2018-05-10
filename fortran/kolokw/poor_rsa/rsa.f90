program rsa
implicit none
integer :: a,b,c,d,e,f
integer, dimension(2) :: pubkey, privkey
integer :: prime_generator, modinv
call generate_keys(a,b,c)
pubkey(1) = a
pubkey(2) = c
privkey(1) = b
privkey(2) = c
call encrypt(12, pubkey, f)
call encrypt(f, privkey, e)
print*, "e", pubkey(2)
print*, "pub", pubkey(1)
print*,"priv", privkey(1)
print*,"crypto", f
print*,"msg", e
end program

function prime_generator(min)
integer :: i, min, nm,  tmp=3 
integer :: prime_generator
nm = min
do while (tmp>2)
        tmp = 0
        do i=1,nm,1
                if ( modulo(nm, i) == 0 ) then
                        tmp = tmp + 1
                end if
        end do
        nm = nm + 1
end do
prime_generator = min + 1
end function

function modinv(a, b)
integer :: modinv
integer :: a, b
integer :: x, y, rr, xx
integer :: r=1,s=0
x = a
y = b
do while (y/=0)
        rr = r
        r = s
        s = rr - x/y * s
        xx = x
        x = y
        y = modulo(xx,y)
end do
modinv = r
end function

subroutine generate_keys(pub, priv, rprime)
integer, intent(out) :: pub, priv, rprime
integer :: prime_generator, modinv
integer :: p, q, n, phi, e, d

p = prime_generator(123456)
q = prime_generator(4567)
n = p*q
phi = n-p-q+1
e = 65537
d = modulo(modinv(e,phi), phi)
!print*, e
pub = e
priv = d
rprime = n
end subroutine

subroutine encrypt(msg, key, crypto)
integer, intent(in) :: msg
integer, dimension(2), intent(in) :: key
integer, intent(out) :: crypto
print*,"Encrypting..."
crypto = modulo(msg**key(1),key(2))
end subroutine

subroutine decrypt(msg, key, crypto)
integer, intent(out) :: msg
integer, dimension(2), intent(in) :: key
integer, intent(in) :: crypto
print*,"Decrypting..."
msg = modulo(crypto**key(1),key(2))
end subroutine
