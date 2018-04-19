program emerytura

implicit none

character :: tab
real :: summ, interest, rawsum, percent
integer :: years, monthSave, months, limit, i,k 

open(11,file="em.data",status="OLD")

tab = char(5)

summ = 10000
years = 45
monthSave = 600
read(11,*), interest
months = 12
rawsum = summ
percent = 0.0

limit = months*years

do i=1,limit,1

    if (k > 11) then
        read(11,*), interest
        k = 0
        !print *,"in",interest
    end if

summ = summ + monthSave
rawsum = rawsum + monthsave
percent = summ*(interest/months)
summ = summ + percent 
k = k + 1
end do

print*," lat oszczedzania:", tab, years
print*,"miesiecznie odkladane:", tab, monthSave
print*,"oprocentowanie:", interest*100, "%"
print*,"Uzbierana suma:", summ
print*,"Z oprocentowaniem 0:", rawsum
print*,"Zysk:", summ-rawsum
print*,"+1000zl do pensji przez:", (summ/1000)/months, " lat"

close(11)

end program
