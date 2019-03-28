#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    int adone = 0;
    int bdone = 0;

    while (1) {

        if (a[i] == '\0')
            adone = 1;
        if (b[i] == '\0')
            bdone = 1;
            
        if (adone && bdone)
            break;

        if (adone)
            return -1;
        if (bdone)
            return 1;
        
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
        i++;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    int adone = 0;
    int bdone = 0;

    while (1) {

        if (a[i] == '\0')
            adone = 1;
        if (b[i] == '\0')
            bdone = 1;
            
        if (adone && bdone)
            break;

        if (adone)
            return 1;
        if (bdone)
            return -1;
        
        if (a[i] < b[i])
            return 1;
        if (a[i] > b[i])
            return -1;
        i++;
    }
    return 0;
}

int find(const char* ptr, char c) {
    int i = 0;
    while (ptr[i] != '\0') {
        if (ptr[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i = 0;

    int ac = 0;
    int bc = 0;
    char alist[50] = "";
    char blist[50] = ""; 
    int adone = 0;
    int bdone = 0;

    while (1) {

        if (a[i] == '\0')
            adone = 1;
        if (b[i] == '\0')
            bdone = 1;

        if (adone && bdone)
            break;
        
        if (!adone && !find(alist, a[i])) {
            alist[ac++] = a[i];
        }
        if (!bdone && !find(blist, b[i])) {
            blist[bc++] = b[i];
        }

        i++;
    }

    //printf("A: %s - %d \n", a, ac);
    //printf("B: %s - %d \n", b, bc);

    if (ac < bc)
        return -1;
    if (ac > bc)
        return 1;

    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int i = 0;
    while (1) {
        if (a[i] == '\0' && b[i] == '\0')
            return lexicographic_sort(a, b);
        if (a[i] == '\0')
            return -1;
        if (b[i] == '\0')
            return 1;
        i++;
    }
    return 0;
}

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b; 
    *b = temp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i, j;
    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (cmp_func(arr[j], arr[j+1]) == 1)
                swap(&arr[j], &arr[j+1]);
        }
    }
}


