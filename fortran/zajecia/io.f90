program io
implicit none
real :: x, y, z
integer :: i

open(15,file="test.data", status="OLD")

do i=1,5,1
read(15,*), x
print *, x
end do

close(15)

end program
