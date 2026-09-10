#include <iostream>
#include <set>
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

    Node* cycleCheckBruteForce(Node* head){
        Node* temp = head;
        set<Node*> myMap;

        if (head == NULL) return NULL;

        while(temp != NULL && temp->next != NULL){
            if(myMap.find(temp) != myMap.end()){
                return temp;
            }
            myMap.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }

    Node* cycleCheckOptimal(Node* head){
        Node* temp = head;
        Node* Hare = temp;
        Node* Tortoise = temp;

        while(Hare!= NULL && Hare->next != NULL){
            Hare = Hare->next->next;
            Tortoise = Tortoise->next;
            if(Hare == Tortoise){
                Node* ptr = head;
                while (ptr != Tortoise) {
                    ptr = ptr->next;
                    Tortoise = Tortoise->next;
                }
                return ptr;
            }
        }

        return NULL;
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

    Node* result = obj.cycleCheckOptimal(head);
    if (result != NULL){
        cout << result->data << endl;
    }
    else{
        cout << "NULL" << endl;
    }
    cout << endl;

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}