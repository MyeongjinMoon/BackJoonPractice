#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* target) {
    int lengthA, lengthB;

    lengthA = GetLength(my_string);
    lengthB = GetLength(target);

    for (int i = 0; i < lengthA; i++)
    {
        int j = 0;
        for (; j < lengthB; j++)
        {
            if (my_string[i + j] != target[j])
                break;
        }
        if (j == lengthB)
            return 1;
    }
    return 0;
}
int GetLength(const char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}