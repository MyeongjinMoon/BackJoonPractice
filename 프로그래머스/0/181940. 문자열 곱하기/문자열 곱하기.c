#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int GetLength(const char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int k) {
    int string_Length = GetLength(my_string);
    char* result = (char*)malloc(sizeof(char) * string_Length * k + 1);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < string_Length; j++)
        {
            result[(i * string_Length) + j] = my_string[j];
        }
    }
    result[string_Length * k] = '\0';

    return result;
}