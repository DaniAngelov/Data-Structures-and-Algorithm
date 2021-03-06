// github.com/DaniAngelov

#include <iostream>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }


SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    SinglyLinkedListNode* start = head;
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* prev = nullptr;
  
   
    
    for(int i = 1;i <= position ;i++)
    {
        prev = head;
        head = head->next;
    }
   
    prev->next = temp;
    temp->next = head;
    
    
    return start;

}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) 
{

    SinglyLinkedListNode* start= head;
    SinglyLinkedListNode* prev = nullptr;
    
    
   
    
    for(int i = 1;i<= position;i++)
    {
        prev = head;
        head = head->next;
    }
    if(position != 0)
    prev->next = head->next;
    
    if(position == 0)
    {
    start = start->next;
    }
    return start;

}


int main()
{



int _;
cin >> _;
return 0;
}


