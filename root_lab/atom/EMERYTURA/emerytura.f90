program emerytura
implicit none

character :: tab
real :: summ, interest, rawsum, percent
integer :: years, monthSave, months, limit, i

tab = char(5)

summ = 10000
years = 45
monthSave = 600
interest = 0.018
months = 12
rawsum = summ
percent = 0.0

limit = months*years

do i=1,limit,1
summ = summ + monthSave
rawsum = rawsum + monthsave
percent = summ*(interest/months)
summ = summ + percent 
end do

print*," lat oszczedzania:", tab, years
print*,"miesiecznie odkladane:", tab, monthSave
print*,"oprocentowanie:", interest*100, "%"
print*,"Uzbierana suma:", summ
print*,"Z oprocentowaniem 0:", rawsum
print*,"Zysk:", summ-rawsum
print*,"+1000zl do pensji przez:", (summ/1000)/months, " lat"

end program
