#include <iostream>
using namespace std;

class Node {
    public:
    
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution{
    public:
    Node* findMiddleBruteForce(Node* head, int k){
        Node* newNode = new Node(k);
        int count = 1;
        Node* temp = head;
        if (head == nullptr) {
            return newNode;
        }
        while(temp->next != NULL){
            count++;
            temp = temp -> next;
        }
        int cnt = (count / 2);
        while(cnt > 0){
            head = head->next;
            cnt--;
        }
        
        return head;
    }

    Node* findMiddleOptimal(Node* head, int k){
        Node* newNode = new Node(k);
        Node* Hare = head;
        Node* Tortoise = head;

        if(head == NULL){
            return newNode;
        }

        while(Hare != NULL && Hare -> next != NULL){
            Hare = Hare->next->next;
            Tortoise = Tortoise->next;
        }
        
        while(head->next != Tortoise->next){
            head = head->next;
        }

        return head;
    }
};

// ---- helpers ----
Node* buildList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Test case 1: odd length -> expect 3
    int arr1[] = {1, 2, 3, 4, 5};
    Node* head1 = buildList(arr1, 5);
    cout << "List 1: ";
    printList(head1);

    Solution sol;
    Node* mid1 = sol.findMiddleOptimal(head1, 0); // k unused by the actual middle logic
    cout << "Middle (expected 3): " << (mid1 ? mid1->data : -1) << endl << endl;

    // Test case 2: even length -> expect 4
    int arr2[] = {1, 2, 3, 4, 5, 6};
    Node* head2 = buildList(arr2, 6);
    cout << "List 2: ";
    printList(head2);

    Node* mid2 = sol.findMiddleOptimal(head2, 0);
    cout << "Middle (expected 4): " << (mid2 ? mid2->data : -1) << endl;

    return 0;
}