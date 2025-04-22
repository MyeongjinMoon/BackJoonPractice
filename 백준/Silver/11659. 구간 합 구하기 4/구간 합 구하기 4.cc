#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int n, k;

vector<int> array;
vector<int> sum_array;

cin >> n >> k;

for (int i = 0; i < n; i++)
{
	int number;
	cin >> number;
	array.push_back(number);
	if (i > 0)
		sum_array.push_back(sum_array[i - 1] + array[i]);
	else
		sum_array.push_back(array[i]);
}

for (int i = 0; i < k; i++)
{
	int a, b, answer = 0;
	cin >> a >> b;

	if (a != 1)
		answer = sum_array[b - 1] - sum_array[a - 2];
	else
		answer = sum_array[b - 1];
	cout << answer << '\n';
}
}