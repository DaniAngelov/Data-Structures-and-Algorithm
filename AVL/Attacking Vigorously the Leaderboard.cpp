-- github.com/DaniAngelov

#include <iostream>
#include <algorithm>
#include <string>



using namespace std;

struct Node
{
    double key;
    Node *left ;
    Node *right ;
    int height;

};

class AVLTree
{
private:
    Node *root = NULL;

   
    
    int height(Node* N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    
    Node* newNode(double key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
    
    Node* rotateLeft(Node* x)
    {
        if(!x->right)
        {
            return x;
        }
        
        Node* y = x->right;
        Node* tmp = y->left;

        y->left = x;
        x->right = tmp;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }



    Node* rotateRight(Node* x)
    {
        
         if(!x->left)
        {
            return x;
        }
        
        Node* y = x->left;
        Node* tmp = y->right;

        y->right = x;
        x->left = tmp;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }





    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
       
        return height(N->left) - height(N->right);
    }

    Node* insert(Node* node,  double key)
    {
        if (node == NULL)
            return newNode(key);
        if (key < node->key )
        {
           
            node->left = insert(node->left, key);
            
        }
        else if (key > node->key)
        {
            
            node->right = insert(node->right, key);
            
        }
        else
        {
            cout << node->key << " already added" << endl;
            return node;
        }


        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && node->left != NULL && key < node->left->key)
        {
            return rotateRight(node);
        }
        if (balance < -1 && node->right != NULL && key > node->right->key)
        {
            return rotateLeft(node);
        }
        if (balance > 1 && node->left != NULL && key > node->left->key)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 &&  node->right != NULL && key < node->right->key)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValue(Node* root)
    {
        
        if(root == NULL)
            return NULL;
        
        Node* curr = root;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    
  

    Node* remove(Node* node, double key)
    {

        if (node == NULL)
        {
            return node;
        }

        if (key < node->key )
        {
            
           
            node->left = remove(node->left, key);
            
        }
        else if (key > node->key)
        {
             
            node->right = remove(node->right, key);
             
        }
        else
        {

            if ( (node->left == NULL) || (node->right == NULL))
            {
                Node* temp = node->left ? node->left : node->right;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;
                
                free(temp);
            }
            else
            {
                Node* temp = minValue(node->right);
                node->key = temp->key;
                
                
                node->right = remove(node->right, temp->key);
            }


            if (node == NULL)
                return node;

            node->height = 1 + max(height(node->left), height(node->right));

            int balance = getBalance(node);

            if (balance > 1 &&  node->left != NULL && getBalance(node->left) >= 0)
                return rotateRight(node);

            if (balance < -1 && node->right != NULL && getBalance(node->right) <= 0)
                return rotateLeft(node);

            if (balance > 1 && node->left != NULL && getBalance(node->left) < 0)
            {
                
                node->left = rotateLeft(node->left);
                return rotateRight(node);
                
            }

            if (balance < -1 && node->right != NULL && getBalance(node->right) > 0)
            {
                
                node->right = rotateRight(node->right);
                return rotateRight(node);
                
            }

        }

        return node;
    }
    bool containsRecursive(Node *current,double value)
    {
        if (current == NULL)
        {
            return false;
        }

        if (current->key == value)
        {
            return true;
        }

        else if (value < current->key)
        {
            return containsRecursive(current->left, value);
        }
        else
        {
            return containsRecursive(current->right, value);
        }
    }

    void printRecursive(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        printRecursive(current->left);
        cout << current->key << " ";
        printRecursive(current->right);
    }

public:
    AVLTree()
    {
        this->root = NULL;
    }

    void add(long double value)
    {
        
        root = insert(root, value);
        
    }

    void remove(long double value)
    {
     
        root = remove(root, value);
    }

    bool contains(long double value)
    {
        Node* curr = root;
        return containsRecursive(curr, value);
    }

    void print()
    {
        Node* curr = root;
        printRecursive(curr);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    
    string operation;
     long double number;
    int N;

    cin >> N;
    cout << fixed;

    for (size_t i = 0; i < N; i++)
    {
        cin >> operation;
        if (operation != "print")
        {
            cin >> number;
        }

        if (operation == "add")
        {
            tree.add(number);
        }
        else if (operation == "remove")
        {
            if (tree.contains(number))
            {
                tree.remove(number);
            }
            else
            {
                cout << number << " not found to remove" << endl;
                continue;
            }
            
        }
        else if (operation == "contains")
        {
            if (tree.contains(number))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (operation == "print")
        {
            tree.print();
        }
    }

    return 0;
}
