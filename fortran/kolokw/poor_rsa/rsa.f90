program rsa
        implicit none
        integer :: prime_generator
        integer, dimension(2) :: pub, priv
        integer :: msg, crypto, decr, x,y
        call generate_keys(pub, priv)
        
        read(*,*) msg

        call encrypt(msg, pub, crypto)
        
        call decrypt(crypto, priv, decr)
        print *, "msg: ", msg
        print *, "encrypted using pub.key: ", crypto
        print *, "decrypted using priv.key ", decr
end program


function prime_generator(num)
        integer :: prime_generator
        integer :: num
        integer :: i, tmp=3,num2,c
        num2 =num
        do while (tmp>2)
                num2 = num2+1
                tmp = 0
                do i=1, num2, 1
                        if (modulo(num2, i) == 0) then
                                tmp = tmp + 1
                        end if
                end do
        end do
        prime_generator = num2 
end function

function modinv(e,phi)
        integer :: modinv
        integer :: e, phi
        integer :: r=1, s=0
        integer :: x,y,tr,tx
        x = e
        y = phi
        do while ( y/=0 )
                tr = r
                r = s
                s = tr - x/y*s
                tx = x
                x = y
                y = modulo(tx, y)
        end do
        modinv = r
end function

subroutine generate_keys(pub, priv)
        integer :: prime_generator
        integer, dimension(2) :: pub, priv
        integer :: p, q, n, e, phi, d
        p = 61
        q = 53
        n = p*q
        phi = n - p - q +1
        e = 17
        d = modulo(modinv(e,phi), phi)

        pub(1) = e
        pub(2) = n

        priv(1) = d
        priv(2) = n
end subroutine

subroutine encrypt(msg, pub, crypto)
        integer, dimension(2) :: pub
        integer :: msg
        integer :: crypto
        open(1, file="key.pub", status="replace")
        write(1,*) msg, pub(1), pub(2)
        close(1)
        call execute_command_line("python3 mm.py key.pub")
        open(2, file="msg.txt", status="old" )
        read(2,*) crypto
        close(2)
end subroutine

subroutine decrypt(crypto, priv, decr)
        integer, dimension(2) :: priv
        integer :: crypto
        integer :: decr

        print *, "XXX: ", modulo(crypto**priv(1),priv(2))
        open(1, file="key.priv", status="replace")
        write(1,*) crypto, priv(1), priv(2)
        close(1)
        call execute_command_line("python3 mm.py key.priv") 
        !(msg^e % n) w pythonie poniewaz fortran zwracał inf dla msg^e mimo kind=16
        open(2, file="msg.txt", status="old" )
        read(2,*) decr
        close(2)
end subroutine
