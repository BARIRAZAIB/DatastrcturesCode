//#include <iostream>
//#include <stack>
//#include"avl.h"
//using namespace std;
//template <typename T>
//void inorderDescending(Node<T>* root) 
//{
//    if (root == nullptr)
//        return;
//    stack<Node<T>*> st;
//    Node<T>* current = root;
//
//    while (current != nullptr || !st.empty())
//    {
//        while (current != nullptr)
//        {
//            st.push(current);
//            current = current->right;
//        }
//        current = st.top();
//        st.pop();
//        cout << current->data << " ";
//        current = current->left;
//    }
//}
//
//int main() {
//    AVL<int> tree;
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(30);
//    tree.insert(40);
//    tree.insert(50);
//    tree.insert(25);
//
//    cout << "Descending order traversal: ";
//    inorderDescending(tree.getRoot()); // Provide the root of the AVL tree
//    cout << endl;
//
//    return 0;
//}
