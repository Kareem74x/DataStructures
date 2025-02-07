#include <iostream>
#define el "\n"
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Linkedlist
{
public:
	Node* head;

	Linkedlist()
	{
		head = NULL; //means that linkedlist is empty 
	}

	bool Isempty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	void Insertfirst(int newvalue)
	{
		Node* newnode = new Node();
		newnode->data = newvalue;

		if (Isempty() == true)
		{
			newnode->next = NULL; //because there is only one value in the llist;
			head = newnode;
		}
		else
		{
			newnode->next = head; //points to the value that 'was' the first in llist
			head = newnode; //points to the new first value;
		}
	}

	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << el;
	}

	int Count()
	{
		int counter = 0;
		Node* temp = head;
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
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == item)
				found = true;

			temp = temp->next;
		}
		return found;
	}

	void Insertbefore(int item, int newvalue)//the item i want to insert a value before it
	{
		if (Find(item))
		{
			Node* newnode = new Node();
			newnode->data = newvalue;

			Node* temp = head;
			//the loop will stop once it finds pointer of item and it will be stored in temp
			//in other words this loop will stop when it finds the node before item node 
			// this pointer will be in the node before item node
			while (temp != NULL && temp->next->data != item)
			{
				temp = temp->next;
			}
			//we make newnode points to item node so it becomes before it
			newnode->next = temp->next;

			//we make this node points to newvalue so now new value is between temp and item
			temp->next = newnode;
		}
		else
			cout << "sorry item not found" << el;
	}

	void Append(int newvalue)
	{
		if (Isempty())
			Insertfirst(newvalue);
		else
		{
			Node* temp = head;
			//this loop will stop when it finds last node in the list
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			Node* newnode = new Node();
			newnode->data = newvalue;

			//make the last node points to the new last node
			temp->next = newnode;

			//make the new last node points to null
			newnode->next = NULL;
		}
	}

	void Delete_item(int item)
	{
		if (head->data == item)// it means that item is in the first node
		{
			Node* delptr = head; //delptr now points to the node we wanna delete
			head = head->next; //head now points to the next node
			delete delptr;	// now we delete delptr so now we deleted first item from memory 
		}

		else // it means that item is any item except the first
		{
			Node* prev = NULL;
			Node* delptr = head;
			//loop will stop when it finds node that contains the item we wanna delete  
			while (delptr->data != item)
			{
				prev = delptr;
				delptr = delptr->next;
			}
			//make prev node points to the node after item node
			prev->next = delptr->next;

			//delete item node from memory
			delete delptr;
		}
	}

	~Linkedlist()//destructor
	{
		Node* current = head;
		Node* next;
		while (current != NULL) {
			next = current->next;
			delete current;
			current = next;
		}
		head = NULL; // Set head to NULL to indicate that the list is now empty
	}
};

int main()
{
	Linkedlist lst;


	cout << "how many items do u want to insert? " << el;
	int cnt; cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cout << "enter ur item : " << el;
		int x; cin >> x;
		lst.Append(x);
	}


	cout << "ur list elements : ";
	lst.Display();
	cout << "the list contains : " << lst.Count() << " element" << el;


	/*cout << "enter element u wanns search for: ";
	int x; cin >> x;
	if (lst.Find(x))
		cout << "element found" << el;
	else
		cout << "element not found" << el;*/


		/*cout << "enter item that u wanna insert value before" << el;
		int i; cin >> i;
		cout << "enter value that u wanna insert" << el;
		int v; cin >> v;
		lst.Insertbefore(i, v);
		lst.Display();*/

		/*cout << "enter item to delete : " << el;
		int x; cin >> x;
		lst.Delete_item(x);
		lst.Display();*/
}