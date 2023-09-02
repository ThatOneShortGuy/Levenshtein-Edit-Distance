GCC_ARGS = -Wall -Wextra -std=c99 -O3

exec: EditDist.o main.o
	gcc -o editdist $(GCC_ARGS) EditDist.o main.o

EditDist.o: EditDist.c EditDist.h
	gcc -c EditDist.c $(GCC_ARGS) -o EditDist.o

main.o: main.c EditDist.h EditDist.o
	gcc -c main.c $(GCC_ARGS) -o main.o

python: EditDist.obj
	-rmdir /s /q build
	python setup.py build_ext --inplace

EditDist.obj: EditDist.c EditDist.h
	-"C:\Program Files\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c /O2 EditDist.c
	-"C:\Program Files\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c /O2 EditDist.c
	-"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c /O2 EditDist.c

clean:
	-del /f /q *.obj *.o editdist
	-rmdir /s /q build