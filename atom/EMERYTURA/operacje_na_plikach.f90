program tes

implicit none

integer:: year,i, zmienna !, dimension(1)::see
real:: percent !,rnd_num
read "podaj integer: ", zmienna
open(unit=15,file='data.dat')
open(unit=16,file='data2.dat')
do i=1,8
        read(15,*)  year, percent
        !print*, year, " ", percent
        !call random_number(rnd_num)
        !write(16,*) year, rnd_num
        write(16,*) year, rand(0)*10+1
end do
close(15)

end program
