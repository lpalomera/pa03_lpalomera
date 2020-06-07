BINARIES=prog1.out

all: prog1.out

prog1.out: twoFive.cpp avl.cpp prog1.cpp
	clang++ twoFive.cpp avl.cpp prog1.cpp -o prog1.out

clean:
	/bin/rm -f ${BINARIES} *.o
