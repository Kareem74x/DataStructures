#include <iostream>
#define el "\n"
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};
 
class BST
{
public:
	Node* root;//points to the first node in the tree

	BST()//constructor
	{
		root = NULL;
	}

	Node* Insert(Node* x,int item)//using recursion   (x is the root pointer)
	{
		if (x == NULL)//tree or substree is empty
		{
			Node* newnode = new Node(item);
			x = newnode;
		}

		else if (item < x->data)//item is smaller = put it on the left
			x->left = Insert(x->left, item);

		else// item is bigger or equal = put it on the right
			x->right = Insert(x->right, item);

		return x;
	}
	
	void Insert(int item)// method overloading (simplified version of insert that asks only for item)
	{
		root = Insert(root, item);
	}

	void Preorder(Node* x)//root-left-right
	{
		if (x == NULL)
			return;
		
		cout << x->data << "\t";
		Preorder(x->left);
		Preorder(x->right);
	}

	void Inorder(Node* x)//left-root-right
	{
		if (x == NULL)
			return;

		Inorder(x->left);
		cout << x->data << "\t";
		Inorder(x->right);
	}

	void Postorder(Node* x)//left-right-root
	{
		if (x == NULL)
			return;

		Postorder(x->left);
		Postorder(x->right);
		cout << x->data << "\t";
	}

	Node* Search(Node* x, int key)
	{
		if (x == NULL)
			return NULL;
		else if (x->data == key)
			return x;
		else if (key < x->data)//smaller
			return Search(x->left, key);
		else
			return Search(x->right, key);
	}

	bool Search(int key)//method overloading
	{
		Node* result = Search(root, key);
		if (result == NULL)
			return false;
		else
			return true;
	}

	Node* Findmin(Node* x)
	{
		if (x == NULL)//tree is empty
			return NULL;
		else if (x->left == NULL)//there is no left subtree == root is the smallest element 
			return x;
		else
			return Findmin(x->left);
	}

	Node* Findmax(Node* x)
	{
		if (x == NULL)//tree is empty
			return NULL;
		else if (x->right == NULL)//there is no right subtree == root is the biggest element 
			return x;
		else
			return Findmax(x->right);
	}

	Node* Delete(Node* x, int key)
	{
		if (x == NULL)
			return NULL;

		if (key < x->data)//we go to the left (seraching for smaller value)
			x->left = Delete(x->left, key);

		else if (key > x->data)//we go to the left (seraching for smaller value)
			x->right = Delete(x->right, key);

		else//we found the key
		{
			if (x->left == NULL && x->right == NULL) //leaf node
				x = NULL;

			else if (x->left != NULL && x->right==NULL)//node with one child on the left
			{
				x->data = x->left->data;
				delete x->left;
				x->left = NULL;
			}

			else if (x->left == NULL && x->right != NULL)//node with one child on the right
			{
				x->data = x->right->data;
				delete x->right;
				x->right = NULL;
			}

			else//node with 2 childs
			{
				//we either swap with biggest value on the left or smallest value on the right
				Node* max = Findmax(x->left);
				x->data = max->data;
				x->left = Delete(x->left, max->data);
			}
			return x;
		}
		return x;
	}

	~BST()//destructor
	{
		// Call a helper function to delete all nodes
		destroyTree(root);
	}

private:

	void destroyTree(Node* x) 
	{
		if (x != NULL) 
		{
			destroyTree(x->left);
			destroyTree(x->right);
			delete x;
		}
	}
};

int main()
{
	BST t;

	int arr[9] = { 45, 15, 79, 90, 10, 55, 12, 20, 50 };
	for (int i = 0; i < 9; i++)
		t.Insert(arr[i]);

	t.Preorder(t.root);
	cout << el;
	/*t.Inorder(t.root);
	cout << el;
	t.Postorder(t.root);
	cout << el;*/



	/*cout << "enter item to search for" << el;
	int item; cin >> item;
	if (t.Search(item))
		cout << "Found" << el;
	else
		cout << "Not Found" << el;*/



	/*Node* min = t.Findmin(t.root);
	if (min == NULL)
		cout << "No items exist";
	else
		cout << min->data << el;

	Node* max = t.Findmax(t.root);
	if (max == NULL)
		cout << "No items exist";
	else
		cout << max->data << el;*/



	/*cout << "preorder after deletion (12)" << el;
	Node* result = t.Delete(t.root, 12);
	t.Preorder(t.root);
	cout << el;

	cout << "preorder after deletion (15)" << el;
	result = t.Delete(t.root, 15);
	t.Preorder(t.root);*/

}