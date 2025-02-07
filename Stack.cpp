#include <iostream>
#define el "\n"
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Stack
{
	Node* top;

public:
	Stack()
	{
		top = NULL;
	}

	bool Isempty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void Push(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;
		if (Isempty())
		{
			newnode->next = NULL;
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
	}

	int Pop()
	{
		int value = top->data;
		Node* delptr = top;
		top = top->next;
		delete delptr;
		return value;
	}

	void Display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << el;
	}

	int Peek()
	{
		return top->data;
	}

	int Count()
	{
		int counter = 0;
		Node* temp = top;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	bool Find(int item)
	{
		bool found = false;
		Node* temp = top;
		while (temp != NULL)
		{
			if (temp->data == item)
				found = true;

			temp = temp->next;
		}
	}

	~Stack()//destructor
	{
		while (!Isempty())
		{
			Pop();
		}
	}
};

int main()
{
	Stack st;
	cout << "how many items u wanna push to the stack?" << el;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter item " << el;
		int x; cin >> x;
		st.Push(x);
	}
	st.Display();

	/*cout << st.Pop() << " was deleted from the stack" << el;
	st.Display();*/
}