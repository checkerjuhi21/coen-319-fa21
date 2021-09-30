CC = g++

default: pi1 pi2 pi3

pi1: pi1.cpp
	${CC} -O3 -Wall -Wextra -fopenmp -o $@ pi1.cpp

pi2: pi2.cpp
	${CC} -O3 -Wall -Wextra -fopenmp -o $@ pi2.cpp

pi3: pi3.cpp
	${CC} -O3 -Wall -Wextra -fopenmp -o $@ pi3.cpp

clean:
	-rm -f pi1 pi2 pi3
