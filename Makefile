exec: EditDist.o main.o
	gcc -o editdist -O3 EditDist.o main.o

EditDist.o: EditDist.c EditDist.h
	gcc -c EditDist.c -O3 -o EditDist.o

main.o: main.c EditDist.h
	gcc -c main.c -O3 -o main.o

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