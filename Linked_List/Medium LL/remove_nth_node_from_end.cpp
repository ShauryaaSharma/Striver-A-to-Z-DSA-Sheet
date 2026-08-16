#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int data1, Node*next1){
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
    Node* removeNodeBruteForce(Node* head, int k){
        vector<int> myHash;
        Node* temp = head;
        
        while(temp != NULL){
            myHash.push_back(temp->data);
            temp = temp->next;
        }
        
        int n = myHash.size();
        temp = head;
        
        for(int i = 0; i < n-k; i ++){
            head = head->next;
        }

        head->next = head->next->next;
        return head;
    }
};