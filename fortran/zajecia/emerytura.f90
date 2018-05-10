program emerytura

implicit none


character :: tab
real :: summ, interest, rawsum, percent
integer :: years, monthSave, months, limit, i, k, j 
tab = char(5)

summ = 500
years = 10
monthSave = 500
months = 12
rawsum = summ
percent = 0.0
k = 0
limit = months*years

call random(years)

open(11,file="new.dat",status="OLD")
read(11,*), interest
do i=1,limit,1
    if (k > 11) then
        read(11,*), interest
        k = 0
        !print *,"in",interest
    end if
    !print *, "in= ", interest
    summ = summ + monthSave
    rawsum = rawsum + monthsave
    percent = summ*(interest/months)
    summ = summ + percent 
    k = k + 1
end do
close(11)

call spam(tab, years, monthSave, interest, summ, rawsum, months)
 
end program



subroutine spam(tab, years, monthSave, interest, summ, rawsum, months)

    character, intent(out) :: tab
    real, intent(out) :: summ, interest, rawsum
    integer, intent(out) :: years, monthSave, months

    print*," lat oszczedzania:", tab, years
    print*,"miesiecznie odkladane:", tab, monthSave
    print*,"oprocentowanie:", interest*100, "%"
    print*,"Uzbierana suma:", summ
    print*,"Z oprocentowaniem 0:", rawsum
    print*,"Zysk:", summ-rawsum
    print*,"+1000zl do pensji przez:", (summ/1000)/months, " lat"

end subroutine

subroutine random(years)
    integer :: n, j, clock
    integer :: years
    integer, dimension(:), allocatable :: seed
    real :: tmp,tmp2
    call random_seed(size=n)
    allocate(seed(n))
    call system_clock(COUNT=clock)
    open(10, file="new.dat", status="REPLACE")
    tmp = 0.01
    seed = clock + (/ (i - 1, i = 1, n) /)
    call random_seed(PUT=seed)
    do j=1, years+1, 1

        call random_number(tmp2)
        tmp2 = tmp2/10
        write(10,*), tmp2
        tmp = tmp + 0.01
    end do
    close(10)

end subroutine 
