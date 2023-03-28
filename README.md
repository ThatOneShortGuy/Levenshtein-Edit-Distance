This project is a fast implementation of the Levenshtein Edit Distance algorithm in C with a Python wrapper.
It uses an optimized version of the Wagner-Fischer algorithm to compute the edit distance between two strings.
It uses only on row of memory to compute the edit distance, so it can make better use of the cache and use less memory overall.
The idea came from a wonderful video by Creel on YouTube. You can see the video [here](https://www.youtube.com/watch?v=Cu7Tl7FGigQ).

# Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
    - [Install with Make](#install-with-make)
    - [Install without Make](#install-without-make)

# Introduction
The Levenshtein Edit Distance is a metric that measures the distance between two strings. It is defined as the minimum number of operations needed to transform one string into the other, where an operation is defined as an insertion, deletion, or substitution of a single character. This metric is used most commonly in spell checking because it can take the misspelled word and find the closest word in the dictionary.

# Usage
Use editdist.exe just to compute and print the edit distance for two strings using:
```bash
editdist.exe <string1> <string2>
```

Us the Python wrapper to compute the edit distance for two strings using:
```python
from EditDist import compute_dist

distance = compute_dist("string1", "string2")
print(distance) # Prints a distance of 1
```
## Install with Make
If you want to just use the C implementation to create an executable, you can run the following commands:
```bash
make
```
This will create an executable called `editdist.exe` that you can run with the following command:
```bash
./editdist.exe <string1> <string2>
```

If you want to use the Python wrapper, you can run the following commands:
```bash
make python
```
This will create a shared library for python (in Windows) using the CL compiler (probably won't work with linux). You will need the Microsoft Visuall C++ Build Tools installed to do this. You can install them [here](https://visualstudio.microsoft.com/visual-cpp-build-tools/). I have left the shared library in the repo called `EditDist.cp39-win_amd64.pyd` so you can use it without having to install the build tools if you are using Python 3.9. If you want to use the Python wrapper, you can run the following commands:
```python
from EditDist import compute_dist

distance = compute_dist("string1", "string2")
```

## Install without Make
If you want to just use the C implementation to create an executable, you can run the following commands:
```bash
gcc -o editdist main.c editdist.c -O3
```

If you want to use the Python wrapper, you can run the following commands:
```bash
python setup.py build_ext --inplace
```