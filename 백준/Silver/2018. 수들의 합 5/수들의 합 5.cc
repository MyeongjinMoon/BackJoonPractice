#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void SumConsecutiveNumber();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	SumConsecutiveNumber();
}

void SumConsecutiveNumber()
{
	int n, answer = 0;
	cin >> n;

	int min = 0, max = 0;

	int result = 0;
	while (max <= n)
	{
		if (result < n)
		{
			max++;
			result += max;
		}
		else if (result > n)
		{
			min++;
			result -= min;
		}
		else
		{
			answer++;

			max++;
			result += max;
		}
	}
	cout << answer;
}