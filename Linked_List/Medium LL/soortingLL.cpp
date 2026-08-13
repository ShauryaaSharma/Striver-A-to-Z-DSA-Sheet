#include <iostream>
#include <vector>
#include <algorithm>
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

    Node* sortBruteForce(Node* head){
        vector<int> arr;
        Node* temp = head;

        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();
        temp = head;

        for(int i = 0; i < n; i ++){
            temp->data = arr[i];
            temp = temp->next;
        }

        return head;
    }

    Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        
        Node* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummyNode->next;
    }

    Node* findMiddle(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* sortLLOptimalSolution(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* middle = findMiddle(head);

        Node* right = middle->next;
        middle->next = nullptr;
        Node* left = head;

        left = sortLLOptimalSolution(left);
        right = sortLLOptimalSolution(right);

        return mergeTwoSortedLinkedLists(left, right);
    }
};

Node* buildList(vector<int>& vals) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int v : vals) {
        Node* node = new Node(v);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {5, 2, 8, 1, 9, 3};
    Node* head = buildList(vals);

    cout << "Before sorting: ";
    printList(head);

    Solution sol;
    head = sol.sortLLOptimalSolution(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}