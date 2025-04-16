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
int solution(int a, int b) {
    int digitB = NumberOfDigits(b);
    int caseA, caseB;
    caseA = a * pow(10, digitB) + b;
    caseB = 2 * a * b;

    if(caseA >= caseB)
        return caseA;
    else
        return caseB;
}