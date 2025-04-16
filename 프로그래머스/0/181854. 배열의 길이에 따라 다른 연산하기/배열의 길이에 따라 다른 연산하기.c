#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int n) {
    int* answer = (int*)malloc(sizeof(int) * arr_len);
    if (arr_len % 2 == 0)
        for (int i = 0; i < arr_len; i++)
        {
            answer[i] = arr[i];
            if (i % 2 != 0)
                answer[i] += n;
        }
    else
        for (int i = 0; i < arr_len; i++)
        {
            answer[i] = arr[i];
            if (i % 2 == 0)
                answer[i] += n;
        }
    return answer;
}