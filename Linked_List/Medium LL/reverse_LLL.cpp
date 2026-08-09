#include <iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution{
    public:

    Node* reverseLinkedList(Node* head){
        if(head == NULL){
            return head;
        }else{
            Node* curr = head, *prev = nullptr;
            while(curr != NULL){
                Node* temp = curr->next;
                curr -> next = prev;

                prev = curr;
                curr = temp;
            }
            return prev;
        }
    }
};

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution obj;
    head = obj.reverseLinkedList(head);

    printList(head);
    cout << endl;

    return 0;
}