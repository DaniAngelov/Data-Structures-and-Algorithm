// github.com/DaniAngelov

#include <bits/stdc++.h>

using namespace std;

int sum = 0;

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


	void leaves(Node *root) 
    {
		if(root == NULL)
            return;
        
        if(root->leftNode != NULL)
            leaves(root->leftNode);
        if(root->leftNode == NULL && root->rightNode == NULL && root->data % 2 == 1)
        {
            sum += root->data;
        }
        if(root->rightNode != NULL)
            leaves(root->rightNode);
        
         
        
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
  
	myTree.leaves(root);
    cout << sum;
    return 0;
}
