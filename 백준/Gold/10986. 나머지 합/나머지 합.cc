#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void RestOfSum();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	RestOfSum();
}

// ----- RestOfSum -----
void RestOfSum()
{
	int n, k;
	cin >> n >> k;

	long long* sum_array = (long long*)calloc(sizeof(long long), n + 1);
	long long* rest_array = (long long*)calloc(sizeof(long long), k);

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		sum_array[i] = sum_array[i - 1] + num;

		rest_array[sum_array[i] % k]++;
	}

	long long answer = rest_array[0];
	for (int i = 0; i < k; i++)
	{
		answer += (rest_array[i] * (rest_array[i] - 1)) / 2;
	}

	cout << answer;
}