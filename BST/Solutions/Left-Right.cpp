// github.com/DaniAngelov

#include <bits/stdc++.h>

using namespace std;


 int counter1 = 0;
int counter2 = 0;
        

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

   

	void leftRight(Node *root) 
    {
        
		if(root == NULL)
            return;
        if(root->rightNode != NULL)
        {
        leftRight(root->rightNode);
            counter1++;
        }
        if(root->leftNode != NULL)
        {
            leftRight(root->leftNode);
            counter2++;
        }
        
        
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leftRight(root);
    cout << "[" << counter2 << "," << counter1 << "]";
    return 0;
}
