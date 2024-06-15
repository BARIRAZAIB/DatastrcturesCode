//#include <iostream>
//#include <string>
//using namespace std;
//struct AVLNode
//{
//	AVLNode* Left;
//	AVLNode* Right;
//	AVLNode* next;
//	int songFrequency;
//	int Height, balancefactor1;
//	string songName;
//	AVLNode()
//	{
//		Height = songFrequency = 0, balancefactor1 = 0;
//		Left = Right = next = nullptr;
//	}
//};
//class AVLTree
//{
//	AVLNode* root;
//public:
//	AVLNode* Insertion(AVLNode*& node, int X, string songname)
//	{
//		if (node == NULL)
//		{
//			node = new AVLNode;
//			node->songFrequency = X;
//			node->songName = songname;
//			node->Height = 0;
//			node->Left = node->Right = node->next = NULL;
//			return node;
//		}
//		else if (X < node->songFrequency)
//		{
//			node->Left = Insertion(node->Left, X, songname);
//		}
//		else if (X > node->songFrequency)
//		{
//			node->Right = Insertion(node->Right, X, songname);
//		}
//		else
//		{
//			AVLNode* temp = new AVLNode;
//			temp->songFrequency = X;
//			temp->songName = songname;
//			if (X == node->songFrequency)
//			{
//				temp->next = node->next;
//				node->next = temp;
//			}
//			return temp;
//		}
//		node->balancefactor1 = GetHeight(node->Left) - GetHeight(node->Right);
//		if (node->balancefactor1 > 1)
//		{
//			if (X < node->Left->songFrequency)
//				node = SingleRotateRight(node);
//			else
//				node = DoubleRotateRight(node);
//		}
//		else if (node->balancefactor1 < -1)
//		{
//			if (X > node->Right->songFrequency)
//				node = SingleRotateLeft(node);
//			else
//				node = DoubleRotateLeft(node);
//		}
//		node->Height = Max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
//		return node;
//	}
//	AVLNode* searchElement(AVLNode*& node, int X)
//	{
//		if (node == nullptr || node->songFrequency == X)
//			return node;
//		if (X < node->songFrequency)
//			return searchElement(node->Left, X);
//		else
//			return searchElement(node->Right, X);
//	}
//	void playFunct(AVLNode* node, int songfrequency)
//	{
//		bool isFound = true;
//		AVLNode* deletedNode = deleteNode(node, songfrequency, isFound);
//		int id;
//		string songname, name;
//		if (!isFound)
//		{
//			cout << "Song to be played not found!!" << endl;
//			return;
//		}
//		else
//			cout << "Song is playing now Enjoy Music ";
//		
//		string deletedSongName = deletedNode->songName;
//		int deletedSongFrequency = deletedNode->songFrequency;
//	
//			Insertion(node, deletedSongFrequency + 1, deletedSongName);
//	}
//	void display(AVLNode* newroot)
//	{
//		if (newroot)
//		{
//			display(newroot->Left);
//			cout << "--------------------------------------------------";
//			cout << "\nNode song Name: " << newroot->songName << ": Song Frequency:" << newroot->songFrequency << endl;
//				 Display linked list for songs with the same frequency
//				AVLNode * temp = newroot->next;
//			while (temp != nullptr)
//			{
//				cout << "Linked Song Name: " << temp->songName << ": Song Frequency:" << temp->songFrequency << endl;
//					temp = temp->next;
//			}
//			display(newroot->Right);
//		}
//	}
//	void displayFunc()
//	{
//		cout << "Displaying the Playlist;\n";
//		display(root);
//		cout << "\n";
//	}
//	void insertElement(int data, string songName)
//	{
//		Insertion(root, data, songName);
//	}
//	AVLNode* FindMin(AVLNode* T)
//	{
//		if (T == nullptr)
//			return nullptr;
//		else if (T->Left == nullptr)
//			return T;
//		else
//			return FindMin(T->Left);
//	}
//	AVLNode* deleteNode(AVLNode*& T, int X, bool& isFound)
//	{
//		if (T == nullptr)
//		{
//			cout << "Node not found!!" << endl;
//			isFound = false;
//			return T;
//		}
//		if (X < T->songFrequency)
//			T->Left = deleteNode(T->Left, X, isFound);
//		else if (X > T->songFrequency)
//			T->Right = deleteNode(T->Right, X, isFound);
//		else
//		{
//			isFound = true;
//			if (T->Left == nullptr)
//			{
//				AVLNode* temp = T->Right;
//				delete T;
//				return temp;
//			}
//			else if (T->Right == nullptr)
//			{
//				AVLNode* temp = T->Left;
//				delete T;
//				return temp;
//			}
//			
//			AVLNode* temp = FindMin(T->Right);
//			
//			T->songFrequency = temp->songFrequency;
//			T->songName = temp->songName;
//			T->Right = deleteNode(T->Right, temp->songFrequency, isFound); 
//		}
//		T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
//		int balance = GetHeight(T->Left) - GetHeight(T->Right);
//		
//		if (balance > 1)
//		{
//			
//			if (GetHeight(T->Left->Left) >= GetHeight(T->Left->Right))
//				return SingleRotateRight(T);
//			
//			else
//			{
//				T->Left = SingleRotateLeft(T->Left);
//				return SingleRotateRight(T);
//			}
//		}
//	
//		else if (balance < -1)
//		{
//			
//			if (GetHeight(T->Right->Right) >= GetHeight(T->Right->Left))
//				return SingleRotateLeft(T);
//			
//			else
//			{
//				T->Right = SingleRotateRight(T->Right);
//				return SingleRotateLeft(T);
//			}
//		}
//		return T;
//	}
//	AVLNode* SingleRotateRight(AVLNode* K2)
//	{
//		AVLNode* K1;
//		K1 = K2->Left;
//		K2->Left = K1->Right;
//		K1->Right = K2;
//		K2->Height = Max(GetHeight(K2->Left), GetHeight(K2->Right)) + 1;
//		K1->Height = Max(GetHeight(K1->Left), K2->Height) + 1;
//		return K1;
//	}
//	AVLNode* SingleRotateLeft(AVLNode* K1)
//	{
//		AVLNode* K2;
//		K2 = K1->Right;
//		K1->Right = K2->Left;
//		K2->Left = K1;
//		K1->Height = Max(GetHeight(K1->Left), GetHeight(K1->Right)) + 1;
//		K2->Height = Max(GetHeight(K2->Right), K1->Height) + 1;
//		return K2;
//	}
//	AVLNode* DoubleRotateRight(AVLNode* K3)
//	{
//		K3->Left = SingleRotateLeft(K3->Left);
//		return SingleRotateRight(K3);
//	}
//	AVLNode* DoubleRotateLeft(AVLNode* K1)
//	{
//		K1->Right = SingleRotateRight(K1->Right);
//		return SingleRotateLeft(K1);
//	}
//	int GetHeight(AVLNode* p)
//	{
//		if (p == NULL)
//		{
//			return 0;
//		}
//		else
//			return 1 + max(GetHeight(p->Left), GetHeight(p->Right));
//	}
//	int Max(int x, int y)
//	{
//		if (x >= y)
//			return x;
//		else
//			return y;
//	}
//public:
//	AVLTree() : root(nullptr) {}
//	void playSong(int songfrequency)
//	{
//		playFunct(root, songfrequency);
//	}
//};
//int main()
//{
//	AVLTree tree1;
//	string choice;
//	do
//	{
//		cout << "S P O T I F Y L I M I T E D \n";
//		cout << "1.To insert songs.\n";
//		cout << "2.To Play Song.\n";
//		cout << "3.To display Songs.\n";
//		cout << "4.To exit Program.\n";
//		cout << "Enter the choice: ";
//		cin >> choice;
//		if (choice == "1")
//		{
//			int num;
//			string name;
//			tree1.insertElement(1, "Song_A");
//			tree1.insertElement(5, "Song_B");
//			tree1.insertElement(9, "Song_C");
//			tree1.insertElement(2, "Song_D");
//			tree1.insertElement(4, "Song_E");
//			tree1.insertElement(6, "Song_F");
//			tree1.insertElement(8, "Song_G");
//			tree1.insertElement(3, "Song_H");
//			tree1.insertElement(7, "Song_I");
//			tree1.insertElement(9, "Song_J");
//			tree1.insertElement(5, "Song_K");
//		}
//		else if (choice == "2")
//		{
//			int id;
//			tree1.displayFunc();
//			cout << "\n\nEnter the song frequency you want to play: ";
//			cin >> id;
//			tree1.playSong(id);
//
//		}
//		if (choice == "3")
//		{
//			tree1.displayFunc();
//		}
//		else if (choice == "4")
//		{
//			return 0;
//		}
//		cout << "\n\n-------------------------------------------------------\n\n";
//	} while (1);
//	return 0;
//}