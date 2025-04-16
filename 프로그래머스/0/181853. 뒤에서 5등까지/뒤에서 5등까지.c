#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void BubbleSort(int* num_list, int size_num_list)
{
	for (int i = 0; i < size_num_list - 1; i++)
	{
		for (int j = i + 1; j < size_num_list; j++)
		{
			if (num_list[i] > num_list[j])
			{
				int temp = num_list[i];
				num_list[i] = num_list[j];
				num_list[j] = temp;
			}
		}
	}
}
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    BubbleSort(num_list, num_list_len);

    int* answer_list = (int*)malloc(sizeof(int) * 5);

    for (int i = 0; i < 5; i++)
        answer_list[i] = num_list[i];
    
    return answer_list;
}