#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_three(int a, int b, int c) {
    int min = b < a ? b : a;
    min = c < min ? c : min;
    return min;
}

int compute_dist_char(char word1[], char word2[]) {
    int word1_len, word2_len, extra_left, extra;

    word1_len = (int) strlen(word1);
    word2_len = (int) strlen(word2);
    int *dists = malloc(sizeof(int) * (word1_len + 1));

    for (int i = 0; i <= word1_len; i++) {
        dists[i] = i;
    }

    for (int row = 1; row <= word2_len; row++) {
        extra_left = row;
        for (int col = 1; col <= word1_len; col++) {
            if (word1[col-1] == word2[row-1]) {
                extra = dists[col-1];
            } else {
                extra = min_three(extra_left, dists[col], dists[col-1]) + 1;
            }
            // extra = word1[col] == word2[row] ? dists[col-1] : min_three(extra_left, dists[col], dists[col-1]) + 1;
            dists[col-1] = extra_left;
            extra_left = extra;
        }
    }

    free(dists);
    return extra;

}


int compute_dist_wchar(wchar_t word1[], wchar_t word2[]) {
    int word1_len, word2_len, extra_left, extra;

    word1_len = (int) wcslen(word1);
    word2_len = (int) wcslen(word2);
    int *dists = malloc(sizeof(int) * (word1_len + 1));

    for (int i = 0; i <= word1_len; i++) {
        dists[i] = i;
    }

    for (int row = 1; row <= word2_len; row++) {
        extra_left = row;
        for (int col = 1; col <= word1_len; col++) {
            if (word1[col-1] == word2[row-1]) {
                extra = dists[col-1];
            } else {
                extra = min_three(extra_left, dists[col], dists[col-1]) + 1;
            }
            // extra = word1[col] == word2[row] ? dists[col-1] : min_three(extra_left, dists[col], dists[col-1]) + 1;
            dists[col-1] = extra_left;
            extra_left = extra;
        }
    }

    free(dists);
    return extra;

}

// int main(int argc, char *argv[])
// {
//     argc = 3;
//     argv[1] = "cabbages";
//     argv[2] = "rabbit";
//     if (argc != 3) {
//         printf("Usage: %s <word1> <word2>", argv[0]);
//         return 1;
//     }
    
//     printf("Word1: %s\n", argv[1]);
//     printf("Word2: %s\n", argv[2]);

//     int dist = compute_dist(argv[1], argv[2]);

//     printf("Distance: %d\n", dist);

//     return 0;
// }