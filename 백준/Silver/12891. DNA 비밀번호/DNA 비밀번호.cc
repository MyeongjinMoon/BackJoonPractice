#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void DNA_Password();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	DNA_Password();
}

bool IsInDNA(char password, int& index);
bool IsDNAPassword(int*, int*);
void DNA_Password()
{
	string dna_Str;
	int* dna = (int*)calloc(sizeof(int), 4);
	int* _dna = (int*)calloc(sizeof(int), 4);
	int s, p, result = 0;
	cin >> s >> p >> dna_Str;

	for (int i = 0; i < 4; i++)
		cin >> dna[i];

	for (int i = 0; i < p; i++)
	{
		int index = 0;
		if (IsInDNA(dna_Str[i], index))
			_dna[index]++;
	}
	if (IsDNAPassword(_dna, dna))
		result++;

	int start = 0, end = p;
	for (int i = 0; i < s - p; i++)
	{
		int index = 0;
		if (IsInDNA(dna_Str[start], index))
			_dna[index]--;
		if (IsInDNA(dna_Str[end], index))
			_dna[index]++;

		if (IsDNAPassword(_dna, dna))
			result++;

		start++; end++;
	}

	cout << result;
}
bool IsInDNA(char password, int& index)
{
	switch (password)
	{
	case 'A':
		index = 0;
		return true;
	case 'C':
		index = 1;
		return true;
	case 'G':
		index = 2;
		return true;
	case 'T':
		index = 3;
		return true;
	default:
		return false;
	}
}
bool IsDNAPassword(int* _dnaPassword, int* dnaPassword)
{
	for (int i = 0; i < 4; i++)
		if (_dnaPassword[i] < dnaPassword[i])
			return false;
	return true;
}