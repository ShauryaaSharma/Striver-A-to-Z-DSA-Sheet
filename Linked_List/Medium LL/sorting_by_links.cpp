#include <iostream>
#include <vector>
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

    Node* sortingByLinksBruteForce(Node* head){
        int ZCnt = -1;
        int OCnt = -1;
        int TCnt = -1;
        Node* theZeros = head;
        Node* startZ = theZeros;
        Node* theOnes = head;
        Node* startO = theOnes;
        Node* theTwos = head;
        Node* startT = theTwos;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                if(ZCnt == -1){
                    theZeros = temp;
                    startZ = temp;
                    ZCnt++;
                }else{
                    theZeros->next = temp;
                    theZeros = theZeros->next;
                }
                temp = temp->next;
            }else if(temp->data == 1){
                if(OCnt == -1){
                    theOnes = temp;
                    startO = temp;
                    OCnt++;
                }else{
                    theOnes->next = temp;
                    theOnes = theOnes->next;
                }
                temp = temp->next;
            }else if(temp->data == 2){
                if(TCnt == -1){
                    theTwos = temp;
                    startT = temp;
                    TCnt++;
                }else{
                    theTwos->next = temp;
                    theTwos = theTwos->next;
                }
                temp = temp->next;
            }
        }

        Node* newHead = NULL;
        Node* tail = NULL;

        if(startZ != NULL){
            newHead = startZ;
            tail = theZeros;
        }
        if(startO != NULL){
            if(newHead == NULL){
                newHead = startO;
            }else{
                tail->next = startO;
            }
            tail = theOnes;
        }
        if(startT != NULL){
            if(newHead == NULL){
                newHead = startT;
            }else{
                tail->next = startT;
            }
            tail = theTwos;
        }
        if(tail != NULL) tail->next = NULL;

        return newHead;
    }
};

Node* buildList(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i = 1; i < (int)arr.size(); i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1, 2, 0, 1, 0, 2, 1, 0};
    Node* head = buildList(arr);

    cout << "Before: ";
    printList(head);

    Solution sol;
    head = sol.sortingByLinksBruteForce(head);

    cout << "After:  ";
    printList(head);

    return 0;
}