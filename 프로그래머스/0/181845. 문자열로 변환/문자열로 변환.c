#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int NumberOfDigits(int n)
{
	int digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return digits;
}
char* MakeStringNumber(int digit, int n)
{
	char* stringNumber = (char*)malloc(sizeof(char) * (digit + 1));

	for (int i = 0; i < digit; i++)
	{
		int newDigit = pow(10, digit - i - 1);
		stringNumber[i] = n / newDigit + '0';
		n %= newDigit;
	}
	stringNumber[digit] = '\0';
	return stringNumber;
}
char* solution(int n) {
    int digit = NumberOfDigits(n);
    char* stringNumber = MakeStringNumber(digit, n);
    return stringNumber;
}