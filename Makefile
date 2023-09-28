GCC_ARGS = -O3 -fopenmp
VC_ARGS = /O2 /openmp:experimental
SRC_PATH = src

exec: EditDist.o main.o
	gcc -o editdist $(GCC_ARGS) $(SRC_PATH)/EditDist.o $(SRC_PATH)/main.o

EditDist.o: $(SRC_PATH)/EditDist.c $(SRC_PATH)/EditDist.h
	gcc -c $(SRC_PATH)/EditDist.c $(GCC_ARGS) -o $(SRC_PATH)/EditDist.o

main.o: $(SRC_PATH)/main.c $(SRC_PATH)/EditDist.h $(SRC_PATH)/EditDist.o
	gcc -c $(SRC_PATH)/main.c $(GCC_ARGS) -o $(SRC_PATH)/main.o

python: $(SRC_PATH)/EditDist.obj
	python setup.py build_ext --inplace --force

$(SRC_PATH)/EditDist.obj: $(SRC_PATH)/EditDist.c $(SRC_PATH)/EditDist.h
	-"C:\Program Files\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c $(VC_ARGS) $(SRC_PATH)/EditDist.c -Fo$(SRC_PATH)/EditDist.obj
	-"C:\Program Files\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c $(VC_ARGS) $(SRC_PATH)/EditDist.c -Fo$(SRC_PATH)/EditDist.obj
	-"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" && cl /c $(VC_ARGS) $(SRC_PATH)/EditDist.c -Fo$(SRC_PATH)/EditDist.obj

clean:
	@ECHO OFF & \
	del /f /q *.obj *.o editdist 2> nul & \
	rmdir /s /q build 2> nul & \
	cd $(SRC_PATH) && del /f /q *.obj *.o 2> nul & \
	echo Cleaned up.