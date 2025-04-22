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
cin >> n >> k;
    
int** sum_map = (int**)calloc(sizeof(int*), n + 1);
for (int i = 0; i <= n; i++)
	sum_map[i] = (int*)calloc(sizeof(int), n + 1);

for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		int num;
		cin >> num;

		sum_map[i][j] = num + sum_map[i][j - 1] + sum_map[i - 1][j] - sum_map[i - 1][j - 1];
	}

for (int i = 0; i < k; i++)
{
	int s_x, s_y, e_x, e_y;
	cin >> s_y >> s_x >> e_y >> e_x;

	int answer = 0;
	answer = sum_map[e_y][e_x] - sum_map[e_y][s_x - 1] - sum_map[s_y - 1][e_x] + sum_map[s_y-1][s_x-1];
	cout << answer << '\n';
}
}
