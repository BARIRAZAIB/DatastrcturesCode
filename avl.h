#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef AVL_H
#define AVL_H

// Content of avl.h

template <typename T>
class AVL;
template <typename T>
class Node;


template <typename T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    int height;
    Node(const T& value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    friend class AVL<T>;

};


template <typename T>
class AVL
{
private:
    Node<T>* root;

    int getHeight(Node<T>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBF(Node<T>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return (getHeight(node->left) - getHeight(node->right));
    }

    void height(Node<T>* node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    Node<T>* rotateRight(Node<T>* y)
    {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;
        x->right = y;
        y->left = T2;
        height(y);
        height(x);
        return x;
    }

    Node<T>* rotateLeft(Node<T>* x)
    {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;
        y->left = x;
        x->right = T2;
        height(x);
        height(y);
        return y;
    }
    Node<T>* balance(Node<T>* node)
    {
        height(node);
        int bf = getBF(node);
        if (bf > 1)
        {
            if (getBF(node->left) >= 0)
            {
                return rotateRight(node);
            }
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        else if (bf < -1)
        {
            if (getBF(node->right) <= 0)
            {
                return rotateLeft(node);
            }
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }

    Node<T>* insertion(Node<T>* node, const T& value)
    {
        if (node == nullptr)
        {
            return new Node<T>(value);
        }
        if (value < node->data)
        {
            node->left = insertion(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertion(node->right, value);
        }
        else
        {
            return node;
        }

        return balance(node);
    }

    void inorder(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    Node<T>* kthLargest(Node<T>* node, int& k)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node<T>* rightNode = kthLargest(node->right, k);
        if (rightNode != nullptr)
        {
            return rightNode;
        }
        if (--k == 0)
        {
            return node;
        }
        return kthLargest(node->left, k);
    }

    Node<T>* deletion(Node<T>* node, const T& value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (value < node->data)
        {
            node->left = deletion(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deletion(node->right, value);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deletion(node->right, temp->data);
            }
        }

        return balance(node);
    }

    Node<T>* findMin(Node<T>* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void preorder(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }


public:
    AVL()
    {
        root = nullptr;
    }
    Node<T>* getRoot()
    {
        return root;
    }
    void insert(const T& value)
    {
        root = insertion(root, value);
    }

    void inorderTraversal()
    {
        inorder(root);
    }

    void kthDeletion(int k)
    {
        Node<T>* kthLargestNode = kthLargest(root, k);
        if (kthLargestNode != nullptr)
        {
            root = deletion(root, kthLargestNode->data);
        }
    }

    void preorderTraversal()
    {
        preorder(root);
    }
    void postorderTraversal()
    {
        postorder(root);
    }
};

#endif // AVL_H