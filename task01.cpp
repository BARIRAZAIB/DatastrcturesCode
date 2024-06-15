//#include <iostream>
//#include <algorithm>
//using namespace std;
//template <typename T>
//class AVL;
//template <typename T>
//class Node 
//{
//public:
//    T data;
//    Node<T>* left;
//    Node<T>* right;
//    int height;
//
//    Node(const T& value) 
//    {
//        data = value;
//        left = nullptr;
//        right = nullptr;
//        height = 1;
//    }
//
//    friend class AVL<T>;
//};
//
//template <typename T>
//class AVL 
//{
//private:
//    Node<T>* root;
//
//    int getHeight(Node<T>* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        return node->height;
//    }
//
//    int getBF(Node<T>* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        return (getHeight(node->left) - getHeight(node->right));
//    }
//
//    void height(Node<T>* node) 
//    {
//        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
//    }
//    Node<T>* rotateRight(Node<T>* y) 
//    {
//        Node<T>* x = y->left;
//        Node<T>* T2 = x->right;
//        x->right = y;
//        y->left = T2;
//        height(y);
//        height(x);
//        return x;
//    }
//    Node<T>* rotateLeft(Node<T>* x)
//    {
//        Node<T>* y = x->right;
//        Node<T>* T2 = y->left;
//        y->left = x;
//        x->right = T2;
//        height(x);
//        height(y);
//        return y;
//    }
//
//    Node<T>* balance(Node<T>* node)
//    {
//        height(node);
//        int BF = getBF(node);
//        if (BF > 1)
//        {
//            if (getBF(node->left) >= 0)
//            {
//                return rotateRight(node);
//            }
//            else
//            {
//                node->left = rotateLeft(node->left);
//                return rotateRight(node);
//            }
//        }
//        else if (BF < -1)
//        {
//            if (getBF(node->right) <= 0)
//                return rotateLeft(node);
//            else
//            {
//                node->right = rotateRight(node->right);
//                return rotateLeft(node);
//            }
//        }
//        return node;
//    }
//
//    Node<T>* insertion(Node<T>* node, const T& value)
//    {
//        if (node == nullptr)
//        {
//            return new Node<T>(value);
//        }
//
//        if (value < node->data)
//        {
//            node->left = insertion(node->left, value);
//        }
//        else if (value > node->data)
//        {
//            node->right = insertion(node->right, value);
//        }
//        else
//        {
//            return node;
//        }
//
//        return balance(node);
//    }
//
//    void inoerder(Node<T>* node) 
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        inoerder(node->left);
//        cout << node->data << " ";
//        inoerder(node->right);
//    }
//
//    void preorder(Node<T>* node) 
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        cout << node->data << " ";
//        preorder(node->left);
//        preorder(node->right);
//    }
//
//    void postorder(Node<T>* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        postorder(node->left);
//        postorder(node->right);
//        cout << node->data << " ";
//    }
//
//public:
//    AVL()
//    {
//        root = nullptr;
//    }
//
//    void insert(const T& value) 
//    {
//        root = insertion(root, value);
//    }
//
//    void inorderTraversal()
//    {
//        inoerder(root);
//    }
//
//    void preorderTraversal() 
//    {
//        preorder(root);
//    }
//
//    void postorderTraversal()
//    {
//        postorder(root);
//    }
//};
//
//int main()
//{
//    AVL<int> tree;
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(30);
//    tree.insert(40);
//    tree.insert(50);
//    tree.insert(25);
//    cout << "inorder traversal: ";
//    tree.inorderTraversal();
//    cout << endl;
//    cout << "preorder traversal: ";
//    tree.preorderTraversal();
//    cout << endl;
//    cout << "postorder traversal: ";
//    tree.postorderTraversal();
//    cout << endl;
//}
//a