#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename T>
struct Node
{
    T word;
    T meaning;
    Node* left;
    Node* right;
    int height;
};

template<typename T>
class AVLTree 
{
private:
    Node<T>* root;
    int getHeight(Node<T>* node)
    {
        if (node == nullptr)
            return -1;
        return node->height;
    }
    int getBalanceFactor(Node<T>* node) 
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node<T>* rotateRight(Node<T>* y)
    {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }
    Node<T>* rotateLeft(Node<T>* x)
    {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    Node<T>* insertWord(Node<T>* node, T word, T meaning)
    {
        if (node == nullptr)
        {
            Node<T>* newNode = new Node<T>;
            newNode->word = word;
            newNode->meaning = meaning;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 0;
            return newNode;
        }
        if (word < node->word)
        {
            node->left = insertWord(node->left, word, meaning);
        }
        else if (word > node->word)
        {
            node->right = insertWord(node->right, word, meaning);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);
        if (balance > 1 && word < node->left->word)
        {
            return rotateRight(node);
        }
        if (balance < -1 && word > node->right->word)
        {
            return rotateLeft(node);
        }
        if (balance > 1 && word > node->left->word) 
        {
            node->left = rotateLeft(node->left);
            {
                return rotateRight(node);
            }
        }
        if (balance < -1 && word < node->right->word)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    void printInorder(Node<T>* node)
    {
        if (node == nullptr)
            return;
        printInorder(node->left);
        cout << node->word << " : " << node->meaning << endl;
        printInorder(node->right);
    }
    void destroyTree(Node<T>* node) 
    {
        if (node == nullptr)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    bool isPrefix(T prefix, T word)
    {
        if (prefix.length() > word.length())
            return false;
        return word.substr(0, prefix.length()) == prefix;
    }
    void suggestWordsUtil(Node<T>* node, T prefix) 
    {
        if (node == nullptr)
        {
            return;
        }
        if (isPrefix(prefix, node->word))
        {
            cout << node->word << endl;
        }
        if (prefix < node->word)
        {
            suggestWordsUtil(node->left, prefix);
        }
        else
        {
            suggestWordsUtil(node->right, prefix);
        }
    }

    void findMeaningUtil(Node<T>* node, T word)
    {
        if (node == nullptr) 
        {
            cout << "word not found." << endl;
            return;
        }
        if (word == node->word) 
        {
            cout << "Meaning of \"" << word << "\": " << node->meaning << endl;
            return;
        }
        if (word < node->word)
        {
            findMeaningUtil(node->left, word);
        }
        else
        {
            findMeaningUtil(node->right, word);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T word, T meaning) 
    {
        root = insertWord(root, word, meaning);
    }
    void dispaly() 
    {
        printInorder(root);
    }
    void suggestWords(T prefix)
    {
        suggestWordsUtil(root, prefix);
    }
    void findMeaning(T word)
    {
        findMeaningUtil(root, word);
    }
    ~AVLTree()
    {
        destroyTree(root);
    }
};

int main()
{
    AVLTree<string> d;
    ifstream file("Dictionary.txt");
    if (!file.is_open()) {
        cerr << "error opening file." << endl;
        return 1;
    }
    string word, meaning;
    while (file >> word >> ws && getline(file, meaning)) 
    {
        d.insert(word, meaning);
    }
    file.close();
    int choice;
    string query;

    do 
    {
        cout << "1. print dictionary"<<endl;
        cout << "2. suggest words" << endl;;
        cout << "3. find meaning" << endl;;
        cout << "4. exit" << endl;;
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "dictionary:" << endl;
            d.dispaly();
            break;
        case 2:
            cout << "enter word to suggest: ";
            cin >> query;
            cout << "suggestions:" << endl;;
            d.suggestWords(query);
            break;
        case 3:
            cout << "enter word to find meaning: ";
            cin >> query;
            d.findMeaning(query);
            break;
        case 4:
            cout << "exiting " << endl;;
            break;
        default:
            cout << "invalid choice" << endl;;
        }
    } while (choice != 4);

    return 0;
}
