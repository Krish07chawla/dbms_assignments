#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

void insertDoubly(DNode* &head, int val) {
    DNode* n = new DNode(val);
    if (!head) {
        head = n;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertCircular(CNode* &head, int val) {
    CNode* n = new CNode(val);
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
}

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    DNode* dh = NULL;
    CNode* ch = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertDoubly(dh, x);
        insertCircular(ch, x);
    }
    cout << "Size of Doubly Linked List: " << sizeDoubly(dh) << endl;
    cout << "Size of Circular Linked List: " << sizeCircular(ch) << endl;
}
