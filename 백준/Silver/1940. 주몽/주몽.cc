#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void OrderOfJumong();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//SumOfNumbers();
	//CalculateAverage();
	//SumOfSection();
	//SumOfSection2();
	//SumConsecutiveNumber();
	OrderOfJumong();
}

void OrderOfJumong()
{
	int n, k, answer = 0;
	cin >> n >> k;

	vector<int> materials(n);
	for (int i = 0; i < n; i++)
		cin >> materials[i];
	
	sort(materials.begin(), materials.end());

	int start = 0, end = n - 1;

	while (start < end)
	{
		int result = materials[start] + materials[end];
		if (result > k)
			end--;
		else if (result < k)
			start++;
		else
		{
			answer++;
			end--;
			start++;
		}
	}

	cout << answer;
}