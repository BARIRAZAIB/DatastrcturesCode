//#include<iostream>
//using namespace std;
//class Node {
//public:
//	int key;
//	Node* left;
//	Node* right;
//	int height;
//};
//class AVLTree {
//public:
//	Node* root;
//	AVLTree() {
//		root = NULL;
//	}
//	int height(Node* N) {
//		if (N == NULL)
//			return 0;
//		return N->height;
//	}
//	int max(int a, int b)
//	{
//		return (a > b) ? a : b;
//	}
//	Node* newNode(int key) 
//{
//		Node* node = new Node();
//		node->key = key;
//		node->left = NULL;
//		node->right = NULL;
//		node->height = 1;
//		return(node);
//	}
//	Node* rightRotate(Node* y)
//	{
//		Node* x = y->left;
//		Node* T2 = x->right;
//		x->right = y;
//		y->left = T2;
//		y->height = max(height(y->left), height(y->right)) + 1;
//		x->height = max(height(x->left), height(x->right)) + 1;
//		return x;
//	}
//	Node* leftRotate(Node* x)
//	{
//		Node* y = x->right;
//		Node* T2 = y->left;
//		y->left = x;
//		x->right = T2;
//		x->height = max(height(x->left), height(x->right)) + 1;
//		y->height = max(height(y->left), height(y->right)) + 1;
//		return y;
//	}
//	int getBalance(Node* N)
//	{
//		if (N == NULL)
//		{
//			return 0;
//		}
//		return height(N->left) - height(N->right);
//	}
//	void insert(int key)
//	{
//		root = insert(root, key);
//	}
//	Node* insert(Node*& node, int key)
//	{
//		if (node == NULL)
//		{
//			return(newNode(key));
//		}
//		if (key < node->key)
//		{
//			node->left = insert(node->left, key);
//		}
//		else if (key > node->key)
//		{
//			node->right = insert(node->right, key);
//		}
//		else
//		{
//			return node;
//		}
//		node->height = 1 + max(height(node->left), height(node->right));
//		int balance = getBalance(node);
//		if (balance > 1 && key < node->left->key)
//		{
//			return rightRotate(node);
//		}
//		if (balance < -1 && key > node->right->key)
//		{
//			return leftRotate(node);
//		}
//		if (balance > 1 && key > node->left->key) 
//		{
//			node->left = leftRotate(node->left);
//			return rightRotate(node);
//		}
//		if (balance < -1 && key < node->right->key) 
//		{
//			node->right = rightRotate(node->right);
//			return leftRotate(node);
//		}
//		return node;
//	}
//	bool searchElement(Node*& node, int X) 
//	{
//		if (node == nullptr)
//			return false;
//		if (node->key == X)
//			return true;
//		if (X < node->key)
//			return searchElement(node->left, X);
//		else
//			return searchElement(node->right, X);
//	}
//	bool isAvlSubTree(Node* node, int start, int end)
//	{
//		int balance;
//		if (node == NULL)
//			return true;
//		if (node->key >= start && node->key <= end) 
//		{
//			balance = getBalance(node);
//			if (balance >= -1 && balance <= 1 && isAvlSubTree(node->left, start,
//				end) && isAvlSubTree(node->right, start, end))
//			{
//				return true;
//			}
//			return false;
//		}
//		else if (node->key < start)
//		{
//			return isAvlSubTree(node->right, start, end);
//		}
//		else
//		{
//			return isAvlSubTree(node->left, start, end);
//		}
//	}
//	void display(Node*& newroot)
//	{
//		if (newroot)
//		{
//			display(newroot->left);
//			cout << newroot->key << " ";
//			display(newroot->right);
//		}
//	}
//	void display() 
//	{
//		display(root);
//		cout << endl;
//	}
//};
//int main() 
//{
//	AVLTree tree;
//	tree.insert(12);
//	tree.insert(13);
//	tree.insert(15);
//	tree.insert(20);
//	tree.insert(21);
//	tree.insert(21);
//	string choice;
//	do
//	{
//		cout << "I S A V L T R E E"<<endl;
//		cout << "1.To insert element in node." << endl;
//		cout << "2.To check ISAVL." << endl;
//		cout << "3.To display Node." << endl;
//		cout << "4.To exit Program." << endl;
//		cout << "enter the choice: ";
//		cin >> choice;
//		if (choice == "1")
//		{
//			int num;
//			cout << "Enter the num: "; cin >> num;
//			tree.insert(num);
//		}
//		else if (choice == "2")
//		{
//			int min, max;
//			cout << "Enter min: "; cin >> min; cout << "Enter max: "; cin >> max;
//			if (tree.isAvlSubTree(tree.root, min, max))
//				cout << "The subtree is an AVL tree." << endl;
//			else
//				cout << "The subtree is not an AVL tree." << endl;
//		}
//		if (choice == "3")
//		{
//			tree.display();
//		}
//		else if (choice == "4")
//		{
//			return 0;
//		}
//		cout << "\n\n-------------------------------------------------------\n\n";
//	} while (1);
//	return 0;//}