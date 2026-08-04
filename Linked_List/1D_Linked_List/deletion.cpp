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
    Node* deleteTail(Node* head){
        if(head == NULL || head -> next == NULL){
            delete head;
            return NULL;
        }

        Node* curr = head;
        while(curr -> next -> next != NULL){
            curr = curr -> next;
        }

        delete curr -> next;
        curr -> next = NULL;

        return head;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution obj;
    head = obj.deleteTail(head);

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}