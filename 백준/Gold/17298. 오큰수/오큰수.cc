#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Oakensu();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//RestOfSum();
	//GoodNumber();
	Oakensu();
}

struct Stack
{
	int* stack;
	int topIndex = -1;
};
static int CheckTop(Stack*);
static void Push_Stack(Stack*, int);
static int Pop_Stack(Stack*);

void Oakensu()
{
	int n;
	cin >> n;

	int* sequence = (int*)calloc(sizeof(int), n);
	int* oakensu = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	Stack myStack;
	myStack.stack = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
	{
		while (CheckTop(&myStack) != -1 && sequence[CheckTop(&myStack)] < sequence[i])
		{
			oakensu[Pop_Stack(&myStack)] = sequence[i];
		}
		Push_Stack(&myStack, i);
	}

	for (int i = 0; i < n; i++)
	{
		if (oakensu[i] == 0)
			cout << "-1 ";
		else
			cout << oakensu[i] << ' ';
	}
}
static int CheckTop(Stack* myStack)
{
	if (myStack->topIndex < 0)
		return -1;
	return myStack->stack[myStack->topIndex];
}
static void Push_Stack(Stack* myStack, int value)
{
	myStack->stack[++myStack->topIndex] = value;
}
static int Pop_Stack(Stack* myStack)
{
	if (myStack->topIndex < 0)
		return -1;
	return myStack->stack[myStack->topIndex--];
}