#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    Node* intersectionCheckBruteForce(Node* head1, Node* head2){
        vector<int> myHash1;
        vector<int> myHash2;
        int intersectedValue = INT_MIN;
        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* result = new Node(-1);
        bool found = false;

        while(temp1 != NULL){
            myHash1.push_back(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            myHash2.push_back(temp2->data);
            temp2 = temp2->next;
        }

        int n1 = myHash1.size();
        int n2 = myHash2.size();

        for(int i = 0; i < n1 && !found; i ++){
            for(int j = 0; j < n2; j++){
                if(myHash1[i] == myHash2[j]){
                    intersectedValue = myHash1[i];
                    found = true;
                    break;
                }
            }
        }
        
        temp1 = head1;
        while(temp1 != NULL){
            if(temp1->data == intersectedValue){
                result = temp1;
                break;
            }
            temp1 = temp1->next;
        }

        return result;
    }
};

int main(){
    // Build list1: 3 -> 6 -> 9 -> 15 -> 30
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(30);

    // Build list2: 10 -> 15 -> 30 (intersects list1 at value 15)
    Node* head2 = new Node(10);
    head2->next = new Node(15);
    head2->next->next = new Node(30);

    Solution sol;
    Node* result = sol.intersectionCheckBruteForce(head1, head2);

    if(result != nullptr && result->data != -1){
        cout << "Intersection at value: " << result->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}