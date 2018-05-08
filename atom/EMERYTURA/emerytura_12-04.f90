program emerytura
implicit none

character :: tab
real :: summ, interest, rawsum, percent, spercent
integer :: years, monthSave, months, limit, i, j, curr_year, rok

tab = char(5)

summ = 0
print *, "Podaj ilosc lat:  "
read *, years
monthSave = 600
interest = 0.018
months = 12
rawsum = summ
spercent = 0.0
curr_year = 2018
limit = months*years


open(unit=12, file='dane_do_emerytury.dat')
open(unit=13, file='emer-test.dat')


do i=1,years
    write(12,'(f0.4,a,f0.4)') curr_year,' ', rand(0)*10
    curr_year = curr_year+1
end do



do i=1,years
    read(12,*) rok, percent
    do j=1,months
        summ = summ + monthSave
        rawsum = rawsum + monthsave
        spercent = summ*(percent/months)
        summ = summ + spercent 
    end do
end do

close(12)

print*," lat oszczedzania:", tab, years
print*,"miesiecznie odkladane:", tab, monthSave
print*,"oprocentowanie:", interest*100, "%"
print*,"Uzbierana suma:", summ
print*,"Z oprocentowaniem 0:", rawsum
print*,"Zysk:", summ-rawsum
print*,"+1000zl do pensji przez:", (summ/1000)/months, " lat"

end program
