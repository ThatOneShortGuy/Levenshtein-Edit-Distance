#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min_three(a, b, c) ((b) < (a) ? (b) : (a)) < (c) ? ((b) < (a) ? (b) : (a)) : (c)

#define LIST_OF_DIST_TYPES \
    X(char, strlen) \
    X(wchar_t, wcslen)

        // int *dists = malloc(sizeof(int) * (word1_len + 1));
#define X(type, len_func) \
    int compute_dist_##type(type word1[], type word2[]) { \
        int word1_len, word2_len, extra_left, extra; \
 \
        word1_len = (int) len_func(word1); \
        word2_len = (int) len_func(word2); \
        int dists[100]; \
 \
        if (word1_len > 100) { \
            *dists = malloc(sizeof(int) * (word1_len + 1)); \
        } \
 \
        for (int i = 0; i <= word1_len; i++) { \
            dists[i] = i; \
        } \
 \
        for (int row = 1; row <= word2_len; row++) { \
            extra_left = row; \
            for (int col = 1; col <= word1_len; col++) { \
                if (word1[col-1] == word2[row-1]) { \
                    extra = dists[col-1]; \
                } else { \
                    extra = min_three(extra_left, dists[col], dists[col-1]) + 1; \
                } \
                dists[col-1] = extra_left; \
                extra_left = extra; \
            } \
        } \
 \
        if (word1_len > 100) { \
            free(dists); \
        } \
        return extra; \
    }
LIST_OF_DIST_TYPES
#undef X