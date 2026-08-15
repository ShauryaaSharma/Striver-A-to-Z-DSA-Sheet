#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    };

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Solution{
    public:

    Node* segrigateBruteForce(Node* head){
        Node* oddHead = head;           
        Node* evenHead = head->next;    
        Node* odd = oddHead;
        Node* even = evenHead;
        int count = 0;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;   
            odd = odd->next;
            even->next = odd->next;   
            even = even->next;
        }

        odd->next = evenHead;  
        return oddHead;
    }
};