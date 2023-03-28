#include <stdlib.h>
#include <string.h>

int compute_dist_char(char word1[], char word2[]);
int compute_dist_wchar(wchar_t word1[], wchar_t word2[]);

#define compute_dist(word1, word2) _Generic((word1), wchar_t*: compute_dist_wchar, char*: compute_dist_char)(word1, word2)