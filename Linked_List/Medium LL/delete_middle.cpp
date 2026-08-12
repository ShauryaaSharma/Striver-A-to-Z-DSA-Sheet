#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Solution{
    public:
    Node* bruteForce(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        if (head == nullptr || head->next == nullptr) {
            return nullptr;   
        }

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};