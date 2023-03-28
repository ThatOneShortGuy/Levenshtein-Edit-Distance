#include <stdio.h>
#include <stdlib.h>
#include "EditDist.h"


int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>", argv[0]);
        return 1;
    }
    
    printf("Word1: %s\n", argv[1]);
    printf("Word2: %s\n", argv[2]);

    int dist = compute_dist(argv[1], argv[2]);

    printf("Distance: %d\n", dist);

    return 0;
}