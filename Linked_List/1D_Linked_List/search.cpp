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
    bool presentOrNot(Node* head, int val){
        while(head != NULL){
            if(head -> data == val){
                return true;
            }
            head = head -> next;
        }
        return false;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Solution obj;
    if (obj.presentOrNot(head, 20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}