// github.com/DaniAngelov

#include <bits/stdc++.h>

using namespace std;

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



	void print(Node *root,Node* rootStart) 
    {
      
        
		if(root == NULL)
            return;
        
        
        if(root->rightNode != NULL)
        print(root->rightNode,rootStart);
      
        if(root->leftNode != NULL)
        print(root->leftNode,rootStart);
        
         cout << root->data;
        if(root != rootStart)
          cout  << ";" ;
      
        
        
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
  
	myTree.print(root,root);
    return 0;
}
