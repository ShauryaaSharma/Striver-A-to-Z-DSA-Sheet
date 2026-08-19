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
    private:

    int converterNum(vector<int>& myNum){
        int n = myNum.size();
        int result = 0;
        int multiplier = 1;
        for(int i = n-1; i >= 0; i --){
            int additionVal = myNum[i] * multiplier;
            result = result + additionVal;
            multiplier = multiplier * 10;
        }
        return result+1;
    }

    vector<int> converterVec(int finalNum, int n){
        vector<int> finalVec;
        int divi = 1;
        for(int i = 0; i < n; i++){
            int val = (finalNum/divi) % 10;
            divi *= 10;
            finalVec.push_back(val);
        }

        return finalVec;
    }

    public:

    Node* addingOne(Node* head){
        vector<int> myNum;
        Node* temp = head;

        while(temp != NULL){
            myNum.push_back(temp->data);
            temp = temp->next;
        }

        int tempN = myNum.size();

        int finalNum = converterNum(myNum);

        int finalN = tempN;
        int countNum = finalNum;
        int digitCount = 0;
        while(countNum > 0){
            digitCount++;
            countNum /= 10;
        }
        if(digitCount > tempN){
            finalN = digitCount;
        }

        vector<int> finalVec = converterVec(finalNum, finalN);
        temp = head;

        if(finalN > tempN){
            Node* newHead = new Node(finalVec[finalN - 1]);
            newHead->next = head;
            head = newHead;
            temp = head->next; 
            for(int i = finalN - 2; i >= 0; i--){
                temp->data = finalVec[i];
                temp = temp->next;
            }
        } else {
            for(int i = finalN - 1; i >= 0; i--){
                temp->data = finalVec[i];
                temp = temp->next;
            }
        }

        return head;
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
    vector<int> nums = {1, 2, 3}; // represents 123
    Node* head = buildList(nums);

    cout << "Original: ";
    printList(head);

    Solution sol;
    Node* result = sol.addingOne(head);

    cout << "After +1: ";
    printList(result);

    return 0;
}