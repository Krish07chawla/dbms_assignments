#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char c) {
        data = c;
        prev = next = NULL;
    }
};

void insertEnd(Node* &head, char c) {
    Node* n = new Node(c);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* end = head;
    while (end->next)
        end = end->next;
    while (head != end && end->next != head) {
        if (head->data != end->data)
            return false;
        head = head->next;
        end = end->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    string s;
    cout << "Enter characters: ";
    cin >> s;
    for (char c : s)
        insertEnd(head, c);
    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
