// Author: Aslam Khan
// Email : aslamkhanofficial@yahoo.com
// Institute : Air University Islamabad

#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
public:
	Node* root;
	Tree();
	void Insert_node(Node*);
	int get_height(Node*);
	bool Balanced(int,int);
	Node* Rotate_left(Node*);
	Node* Rotate_right(Node*);
	void Inorder(Node*);
	void Pre_order(Node*);
	void Post_order(Node*);
};


int main()
{
	cout << endl << endl << "\t\t\tCode is Written By Aslam Khan" << endl << endl;
	system("pause");
	system("cls");
	Tree T;
	int data, ch;
	while (true)
	{
		cout << "1 = Insert Node" << endl;
		cout << "2 = Height	" << endl;
		cout << "3 = Pre Order" << endl;
		cout << "4 = Post Order" << endl;
		cout << "5 = In Order" << endl;
		cout << "Enter Choice = ";
		Node* n = new Node();
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data =	";
			cin >> data;
			n->data = data;
			T.Insert_node(n);
			if (T.Balanced(T.get_height(T.root->left), T.get_height(T.root->right)) == false)
			{
				if (T.get_height(T.root->left) > T.get_height(T.root->right))
				{
					T.root = T.Rotate_right(T.root);
				}
				else
				{
					T.root = T.Rotate_left(T.root);
				}
			}
			
			break;
		case 2:
			cout << "Total Height = " << T.get_height(T.root) << endl;
			cout << "Left Tree Height = " << T.get_height(T.root->left) << endl;
			cout << "Right Tree Height = " << T.get_height(T.root->right) << endl;
			break;
		

		case 3:
			T.Pre_order(T.root);
			cout << endl;
			break;
		case 4:
			T.Post_order(T.root);
			cout << endl;
			break;
		case 5:
			T.Inorder(T.root);
			cout << endl;
			break;

		default:
			cout << "Please Enter Correct Option..." << endl;
			break;
		}
		system("pause");
		system("cls");
	}



}



Tree::Tree()
{
	root = NULL;

}


void Tree::Inorder(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	Inorder(r->left);
	cout << r->data << ", ";
	Inorder(r->right);
}

void Tree::Pre_order(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	cout << r->data << ", ";
	Pre_order(r->left);
	Pre_order(r->right);
}

void Tree::Post_order(Node* r)
{
	if (r == NULL)
	{
		return;
	}
	Post_order(r->left);
	Post_order(r->right);
	cout << r->data << ", ";
}

void Tree::Insert_node(Node* n)
{
	if (root == NULL)
	{
		root = n;
		cout << "Node Inserted at Root..." << endl;
	}
	else
	{
		Node* temp = root;
		while (temp != NULL)
		{
			if (n->data > temp->data && temp->right == NULL)
			{
				temp->right = n;
				cout << "Node Sucessfully Inserted..." << endl;
				break;
			}
			else if (n->data > temp->data)
			{
				temp = temp->right;
			}
			else if (n->data < temp->data && temp->left == NULL)
			{
				temp->left = n;
				cout << "Node Sucessfully Inserted.." << endl;
				break;
			}
			else if (n->data < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				cout << "No Duplicate Data Can be Inserted..." << endl;
			}

		}
	}
}


int Tree::get_height(Node* n)
{
	int lheight, rheight;
	if (n == NULL)
	{
		return -1;
	}
	else
	{
		lheight = get_height(n->left);
		rheight = get_height(n->right);
		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return (rheight + 1);
		}
	}
}


bool Tree::Balanced(int left, int right)
{
	int bf = left - right;
	if (bf == 1 || bf == -1 || bf == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Node* Tree::Rotate_left(Node* n)
{
	Node* ptr = n->right;
	Node* temp = ptr->left;

	ptr->left = n;
	n->right = temp;

	return ptr;


}

Node* Tree::Rotate_right(Node* n)
{
	Node* ptr = n->left;
	Node* temp = ptr->right;

	ptr->right = n;
	n->left = temp;
	return ptr;
}



