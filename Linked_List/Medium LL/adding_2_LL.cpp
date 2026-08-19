#include <iostream>
#include <vector>
#include <cmath>
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
    // private:

    // int ConverterToInt(vector<int>& myAdd){
    //     int myNum = 0;
    //     int n = myAdd.size();
    //     int multiplier = 1;
    //     for(int i = n-1; i >=0; i --){
    //         myNum = myNum + myAdd[i]*multiplier;
    //         multiplier = multiplier*10;
    //     }
    //     return myNum;
    // }

    // vector<int> convertToVec(int myNum){
    // vector<int> result;
    // if (myNum == 0) { 
    //     result.push_back(0); 
    //     return result; 
    // }
    // while (myNum > 0) {
    //     result.push_back(myNum % 10);
    //     myNum /= 10;
    // }
    // reverse(result.begin(), result.end());
    //     return result;
    // }
    // public:

    // Node* adding2LL(Node* l1, Node* l2){
    //     vector<int> myAdd;
    //     vector<int> myAdd2;
    //     Node* temp1 = l1;
    //     Node* temp2 = l2;

    //     while(temp1 != NULL){
    //         myAdd.push_back(temp1->data);
    //         temp1 = temp1->next;
    //     }

    //     while(temp2 != NULL){
    //         myAdd2.push_back(temp2->data);
    //         temp2 = temp2->next;
    //     }

    //     int initialN = myAdd.size();
    //     temp1 = l1;
    //     temp2 = l2;
    //     int l1data = ConverterToInt(myAdd);
    //     int l2data = ConverterToInt(myAdd2);
    //     int finalVal = l2data + l1data;
    //     vector<int> vecFinal = convertToVec(finalVal);

    //     int checkN = vecFinal.size();
    //     int extra = checkN - initialN; 

    //     for(int i = 0; i < extra; i++){
    //         Node* newHead = new Node(0);  
    //         newHead->next = l1;
    //         l1 = newHead;
    //     }
    //     temp1 = l1;
    //     for(int i = 0; i < checkN; i++){
    //         temp1->data = vecFinal[i];
    //         temp1 = temp1->next;
    //     }
    //     return l1;
    // }
    public:
    Node* adding2LL(Node* l1, Node* l2){
        Node* dummy1 = new Node(-1);
        Node* dummy2 = dummy1;
        Node* newNode = new Node(-1);
        int carry = 0;
        while((dummy1 != NULL || dummy2 != NULL) || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            Node* node = new Node(sum%10);
            dummy2->next = node;
            dummy2 = dummy2->next;
        }
        return dummy1->next;
    }
};

Node* buildList(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new Node(vals[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6, 7};

    Node* l1 = buildList(nums1);
    Node* l2 = buildList(nums2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    Node* result = sol.adding2LL(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}