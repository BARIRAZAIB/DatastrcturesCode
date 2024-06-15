#include <iostream>
#include <string>
using namespace std;
struct task 
{
    string name;
    int priority;
    int height; 
    task* left;
    task* right;

    task(const string& n, int p) 
    {
        name = n;
        priority = p;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
class timeTable 
{
private:
    task* root;
    task* insertion(task* node, const string& n, int p) 
    {
        if (node == nullptr) 
        {
            return new task(n, p);
        }
        if (p < node->priority)
        {
            node->left = insertion(node->left, n, p);
        }
        else if (p > node->priority)
        {
            node->right = insertion(node->right, n, p);
        }
        else 
        {
            node->left = insertion(node->left, n, p);
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bal = getbal(node);
        if (bal > 1 && p < node->left->priority)
        {
            return rotateR(node);
        }
        if (bal < -1 && p > node->right->priority)
        {
            return rotateL(node);
        }
        if (bal > 1 && p > node->left->priority)
        {
            node->left = rotateL(node->left);
            return rotateR(node);
        }
        if (bal < -1 && p < node->right->priority) 
        {
            node->right = rotateR(node->right);
            return rotateL(node);
        }

        return node;
    }
    task* deletion(task* node, int priority)
    {
        if (node == nullptr) 
        {
            return nullptr;
        }

        if (priority < node->priority) 
        {
            node->left = deletion(node->left, priority);
        }
        else if (priority > node->priority)
        {
            node->right = deletion(node->right, priority);
        }
        else 
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                task* temp = node->left ? node->left : node->right;
                if (temp == nullptr) 
                {
                    temp = node;
                    node = nullptr;
                }
                else 
                {
                    *node = *temp;
                }
                delete temp;
            }
            else 
            {
                task* temp = minValue(node->right);
                node->name = temp->name;
                node->priority = temp->priority;
                node->right = deletion(node->right, temp->priority);
            }
        }
        if (node == nullptr)
        {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getbal(node);
        if (balance > 1 && getbal(node->left) >= 0)
        {
            return rotateR(node);
        }
        if (balance > 1 && getbal(node->left) < 0)
        {
            node->left = rotateL(node->left);
            return rotateR(node);
        }
        if (balance < -1 && getbal(node->right) <= 0)
        {
            return rotateL(node);
        }
        if (balance < -1 && getbal(node->right) > 0)
        {
            node->right = rotateR(node->right);
            return rotateL(node);
        }

        return node;
    }
    task* rotateL(task* y)
    {
        task* x = y->right;
        task* T2 = x->left;
        x->left = y;
        y->right = T2;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }
    task* rotateR(task* x) 
    {
        task* y = x->left;
        task* T2 = y->right;
        y->right = x;
        x->left = T2;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }
    int getHeight(task* node) 
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    int getbal(task* node) 
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    task* minValue(task* node)
    {
        task* current = node;
        while (current->left != nullptr) 
        {
            current = current->left;
        }
        return current;
    }
    void inorder(task* node)
    {
        if (node == nullptr) 
        {
            return;
        }
        inorder(node->right);
        cout << "task: " << node->name;
        cout << " priority: " << node->priority << endl;
        inorder(node->left);
    }

public:
    timeTable() 
    {
         root = nullptr;
    }
    void addTask(const string& name, int priority)
    {
        root = insertion(root, name, priority);
    }
    void deletion(int priority) 
    {
        root = deletion(root, priority);
    }
    void displayTasks() 
    {
        cout << "inorder of priority queue:" << endl;
        inorder(root);
    }
};
int main()
{
    timeTable T;
    string ch;
    do 
    {
        cout << "task timetable system"<<endl;
        cout << "1. add a task" << endl;
        cout << "2. remove a task" << endl;
        cout << "3. display tasks" << endl;
        cout << "4. exit" << endl;
        cout << "enter your choice: ";
        cin >> ch;
        if (ch == "1") 
        {
            string name;
            int priority;
            cout << "enter task name: ";
            cin >> name;
            cout << "enter task priority: ";
            cin >> priority;
            T.addTask(name, priority);
        }
        else if (ch == "2")
        {
            int priority;
            cout << "enter priority of task to remove: ";
            cin >> priority;
            T.deletion(priority);
        }
        else if (ch == "3")
        {
            T.displayTasks();
        }
        else if (ch == "4") 
        {
            cout << "exiting program" << endl;
            break;
        }
        else 
        {
            cout << "invalid choice" << endl;
        }
    } 
    while (true);
}


