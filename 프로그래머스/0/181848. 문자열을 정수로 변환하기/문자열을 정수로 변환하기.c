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
int solution(const char* n_str) {
    int digit = GetLength(n_str);
    int n = 0;
    
    for (int i = 0; i < digit; i++)
    {
        n += (n_str[i] - '0') * pow(10, digit - i - 1);
    }

    return n;
}