#include <iostream>
#define el "\n"
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node()// constructor to initialize the node everytime we create new one
	{
		data = 0;
		next = NULL;
	}
};

class Queue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL;
	}

	bool Isempty()
	{
		if (front == NULL && rear == NULL)
			return true;
		else
			return false;
	}

	void Enqueue(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;
		if (Isempty())
			front = rear = newnode;

		else
		{
			rear->next = newnode;//the node that was last one make it points to the new last one
			rear = newnode; //make rear points to the new last node
		}
	}

	void Display()
	{
		if (Isempty())
			cout << "queue is empty" << el;
		else
		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << el;	
		}
	}

	int Count()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	int find(int item)
	{
		bool found = false;
		Node* temp = front;
		while (temp != NULL)
		{
			if (temp->data == item)
				found = true;
			temp = temp->next;
		}
		return found;
	}

	void Dequeue()
	{
		if (Isempty())
			cout << "the queue is already empty" << el;
		else if (front == rear)// if there is 1 item in the queue
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* delptr = front;
			front = front->next;
			delete delptr;
		}
	}

	int Getfront()
	{
		return front->data;
	}

	int Getrear()
	{
		return rear->data;
	}

	void Clear()
	{
		while (!Isempty())
		{
			Dequeue();
		}
	}

	~Queue()//destructor
	{
		Clear();
	}
};

int main()
{
	Queue q;
	cout << "how many items u wanna add to the queue?" << el;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter item " << el;
		int x; cin >> x;
		q.Enqueue(x);
	}
	q.Display();

	/*cout << "how many items u wanna dequeue?" << el;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		q.Dequeue();
		q.Display();
	}*/
}