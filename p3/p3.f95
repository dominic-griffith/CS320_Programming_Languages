program TravelingSalesman
    ! Given:  distance look up table
    !         list of cities
    !         path between cities
        implicit none
            
        integer :: numCities, currDistance, bestDistance, i, j, getOut
        integer, dimension(:,:), allocatable :: distanceFromCities      
        integer, dimension(:), allocatable :: tempPath              
        integer, dimension(:), allocatable :: bestPath
        character(25) :: fileName
        character(30), dimension(:), allocatable :: cityNames
        
        bestDistance = 999999999     
            
        print *, 'Enter File Name: '
        read *, fileName
        open(1, file = fileName, status = 'old', iostat = getOut)  
        if(getOut /= 0) then
            print *, 'File did not open correctly!'
            stop
        endif
        read (1, fmt=100) numCities
            
        allocate(distanceFromCities(1:numCities, 1:numCities))
        allocate(tempPath(1:numCities))
        allocate(bestPath(1:numCities))
        allocate(cityNames(1:numCities))
        
        !integer, dimension(1:numCities,1:numCities) :: distanceFromCities  
        !integer, dimension(1:numCities) :: path    
        !integer, dimension(1:numCities) :: best_path    
        !character(30), dimension(1:numCities) :: cityNames    
            
        do i = 1, numCities
            tempPath(i) = i
            bestPath(i) = i
            read(1, fmt=200) cityNames(i)    
            do j = 1, numCities
                read(1, fmt=100) distanceFromCities(i,j)  
            enddo
        enddo
        
        close(1)
        
        ! Permute all but home city
        call permute(2,numCities)
        
        
        ! Report best path and distances   
       
        do i = 1, numCities
            if (i /= numCities) then
                print *, cityNames(bestPath(i)),' to ', cityNames(bestPath(i+1)), &
                ' --  ', distanceFromCities(bestPath(i),bestPath(i+1)), '  miles'
            else
                print *, cityNames(bestPath(i)),' to ', cityNames(bestPath(1)), &
                ' --  ', distanceFromCities(bestPath(i),bestPath(1)), '  miles'
            endif
        enddo
        print *, 'Best distance is:  ', bestDistance, ' miles'
            
        100 format (I6)
        200 format (A)
    
        contains
        ! Inner subroutine
        recursive subroutine permute(first,last)
            implicit none
                integer :: first, last, temp, i
                ! Base case
                if (first == last) then
                    currDistance = distanceFromCities(1,tempPath(2))
                    do i = 2, (last - 1)
                        currDistance = currDistance + distanceFromCities(tempPath(i),tempPath(i+1))
                    enddo     
                    ! Get distance from last city back home
                    currDistance = currDistance + distanceFromCities(tempPath(last),tempPath(1))    
                    if (currDistance < bestDistance) then
                        bestDistance = currDistance
                        do i = 2, numCities
                            bestPath(i) = tempPath(i)
                        enddo
                    endif
                else
                    ! Mix it up
                    do i = first, last
                        temp = tempPath(first)
                        tempPath(first) = tempPath(i)
                        tempPath(i) = temp
                        ! Recursion reduction step
                        call permute(first+1,last)
    
                        temp = tempPath(first)
                        tempPath(first) = tempPath(i)
                        tempPath(i) = temp
                    enddo
                endif
            return
            
        end subroutine permute           
        end program