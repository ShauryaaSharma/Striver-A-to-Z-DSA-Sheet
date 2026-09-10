#include <iostream>
#include <set>
#include <unordered_set>
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

    Node* intersectionByNodeBruteForce(Node* headA, Node* headB){
        Node* tempA = headA;
        Node* tempB = headB;
        Node* result = new Node(-1);
        bool found = false;

        while(tempA != NULL && !found){
            tempB = headB;
            while(tempB != NULL){
                if(tempA == tempB){
                    result = tempA;
                    found = true;
                    break;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }

        return result;
    }

    Node* intersectionByNodeBetterApproch1(Node* headA, Node* headB){
        set<Node*> myHashA;
        set<Node*> myHashB;
        Node* tempA = headA;
        Node* tempB = headB;
        Node* result = nullptr;
        bool found = false;

        while(tempA != NULL){
            myHashA.insert(tempA);
            tempA = tempA->next;
        }
        while(tempB != NULL){
            myHashB.insert(tempB);
            tempB = tempB->next;
        }
        
        for(auto add1:myHashA){
            if(found){
                break;
            }
            for(auto add2:myHashB){
                if(add1 == add2){
                    result = add2;
                    found = true;
                    break;
                }
            }
        }
        return result;
    }
    
    Node* intersectionByNodeBetterApproch2(Node* headA, Node* headB){
        unordered_set<Node*> myHash;
        Node* tempA = headA;
        Node* tempB = headB;

        while(tempA != NULL){
            myHash.insert(tempA);
            tempA = tempA->next;
        }

        while(tempB != NULL){
            if(myHash.count(tempB)){
                return tempB;
            }
            tempB = tempB->next;
        }

        return nullptr;
    }

    Node* intersectionByNodeOptimalApproch(Node* headA, Node* headB){
        int lenA = 0, lenB = 0;
        Node *curA = headA, *curB = headB;

        while (curA != NULL || curB != NULL) {
            if (curA != NULL) {
                ++lenA;
                curA = curA->next;
            }
            if (curB != NULL) {
                ++lenB;
                headB = curB->next;
            }
        }

        int diff = lenA - lenB;
    
        if (diff < 0){
            while (diff++ != 0){
                headB = headB->next;
            }
        }
        else{
            while (diff-- != 0){
                headA = headA->next;
            }
        }
        while (headA != NULL) {
            if (headA == headB) return headA;  
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};

int main(){
    Node* shared = new Node(8);
    shared->next = new Node(4);
    shared->next->next = new Node(5);

    Node* headA = new Node(3);
    headA->next = new Node(6);
    headA->next->next = new Node(9);
    headA->next->next->next = shared;

    Node* headB = new Node(1);
    headB->next = shared;

    Solution sol;
    Node* result = sol.intersectionByNodeOptimalApproch(headA, headB);

    if(result != nullptr && result->data != -1){
        cout << "Intersection at node with value: " << result->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}