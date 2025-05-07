#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void FindMinNum1();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	FindMinNum1();
}

// FindMinNum1
/*
12 3
1 5 2 3 6 2 3 7 3 5 2 6
*/
struct Deque {
	int index;
	int value;
	Deque* front;
	Deque* back;
};
void AddDeque(Deque**, Deque**, Deque*);
void SubDeque(Deque**, int);
void FindMin(Deque**);

void PushHead(Deque**, Deque*);
void PushTail(Deque**, Deque*);
void PopHead(Deque**);
void PopTail(Deque**);

void FindMinNum1()
{
	int n, l;
	cin >> n >> l;

	int* num = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	Deque* head = nullptr;
	Deque* tail = nullptr;
	int minValue;

	for (int i = 0; i < n; i++)
	{
		Deque* newDeque = new Deque;
		newDeque->index = i;
		newDeque->value = num[i];
		newDeque->front = nullptr;
		newDeque->back = nullptr;

		AddDeque(&head, &tail, newDeque);
		SubDeque(&head, i - l);
		cout << head->value << ' ';
	}
}
void AddDeque(Deque** head, Deque** tail, Deque* newDeque)
{
	while (true)
	{
		if (*tail == nullptr || (*tail)->value <= newDeque->value)
			break;
		PopTail(tail);
	}
	if (*tail == nullptr)
	{
		*tail = newDeque;
		*head = newDeque;
		return;
	}
	PushTail(tail, newDeque);
}
void SubDeque(Deque** head, int index)
{
	if (index >= (*head)->index)
		PopHead(head);
}
void PushHead(Deque** head, Deque* newDeque)
{
	(*head)->front = newDeque;
	newDeque->back = *head;
	*head = newDeque;
}
void PushTail(Deque** tail, Deque* newDeque)
{
	(*tail)->back = newDeque;
	newDeque->front = *tail;
	*tail = newDeque;
}
void PopHead(Deque** head)
{
	Deque* temp = *head;
	*head = (*head)->back;
	(*head)->front = nullptr;
	delete temp;
}
void PopTail(Deque** tail)
{
	Deque* temp = *tail;
	*tail = (*tail)->front;
	if (*tail != nullptr)
		(*tail)->back = nullptr;
	delete temp;
}