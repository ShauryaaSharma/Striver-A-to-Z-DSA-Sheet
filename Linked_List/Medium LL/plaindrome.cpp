#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Solution
{
private:
    Node *reverseLL(Node *head)
    {
        Node *curr = head, *prevNode = nullptr;
        if (head == NULL)
        {
            return head;
        }
        else
        {
            while (curr != NULL)
            {
                Node *temp = curr->next;
                curr->next = prevNode;

                prevNode = curr;
                curr = temp;
            }
        }
        return prevNode;
    }

public:
    bool checkPalindromeBruteForce(Node *head)
    {
        stack<int> st;
        Node *temp = head;

        while (temp != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL)
        {
            if (temp->data != head->data)
            {
                return false;
            }
            temp = temp->next;
            head = head->next;
        }
        return true;
    }

    bool checkPalindromeOptimal(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseLL(slow);
        Node *check = secondHalf;
        while (check != NULL)
        {
            if (head->data == check->data)
            {
                head = head->next;
                check = check->next;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver function
int main()
{

    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution obj;
    if (obj.checkPalindromeOptimal(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}