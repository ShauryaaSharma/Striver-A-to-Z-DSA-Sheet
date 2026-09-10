#include <iostream>
#include <map>
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

    bool cycleCheckBruteForce(Node* head){
        Node* temp = head;
        map<Node*, int> myMap;

        while(temp->next != NULL){
            if(myMap.find(temp) != myMap.end()){
                return true;
            }
            myMap[temp] = 1;
            temp = temp->next;
        }

        return false;
    }

    bool cycleCheckOptimal(Node* head){
        Node* temp = head;
        Node* Hare = temp;
        Node* Tortoise = temp;

        while(Hare!= NULL && Hare->next != NULL){
            Hare = Hare->next->next;
            Tortoise = Tortoise->next;
            if(Hare == Tortoise){
                return true;
            }
        }

        return false;
    }
};

int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    Solution obj;

    if (obj.cycleCheckOptimal(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}