#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution{
    public:
    Node* convertArr2DLL(vector<int> arr) {
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i], nullptr, prev);
    
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
    
    void print(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    Node* reverseDLL(Node* head){
        if(head == NULL){
            return head;
        }else{
            Node* tail = head;
            while(tail != NULL){
                Node* temp = tail->next;
                tail->next = tail->prev;
                tail->prev = temp;

                head = tail;          
                tail = temp;
            };

            return head;
        }
    }
};

int main() {
    vector<int> arr = {10, 20, 30, 40};

    Solution obj;

    Node* head = obj.convertArr2DLL(arr);

    head = obj.reverseDLL(head);

    obj.print(head);

    return 0;
}