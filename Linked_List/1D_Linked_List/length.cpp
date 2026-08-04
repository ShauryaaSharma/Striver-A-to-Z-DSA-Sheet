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
    int checkLength(Node* head){
        int length = -1;
        if(head == NULL || head -> next == NULL){
            length = 0;
        }else{
            while(head != NULL){
                length ++;
                head = head->next;
            }
        }

        return length + 1;
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Solution obj;

    cout << "Length of Linked List: " << obj.checkLength(head) << endl;

    return 0;
}