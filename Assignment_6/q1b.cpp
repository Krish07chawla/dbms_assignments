#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int v) { data = v; prev = next = NULL; }
};

Node* insert(Node *head, int val, int ref = -1, bool before = false) {
    Node *n = new Node(val);
    if (!head) return n;
    Node *t = head;
    if (ref == -1) {
        while (t->next) t = t->next;
        t->next = n; n->prev = t;
        return head;
    }
    while (t && t->data != ref) t = t->next;
    if (!t) { cout << "Not found\n"; delete n; return head; }
    if (before) {
        n->prev = t->prev; n->next = t;
        if (t->prev) t->prev->next = n; else head = n;
        t->prev = n;
    } else {
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }
    return head;
}

Node* del(Node *head, int key) {
    if (!head) return NULL;
    Node *t = head;
    while (t && t->data != key) t = t->next;
    if (!t) { cout << "Not found\n"; return head; }
    if (t->prev) t->prev->next = t->next; else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
    return head;
}

void search(Node *head, int key) {
    int i = 1;
    while (head) {
        if (head->data == key) { cout << "Found at " << i << endl; return; }
        head = head->next; i++;
    }
    cout << "Not found\n";
}

void display(Node *head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    int ch, v, ref;
    do {
        cout << "\n1.IF 2.IL 3.IB 4.IA 5.D 6.S 7.P 8.X\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Val: "; cin >> v; head = insert(head, v, head ? head->data : -1, true); break;
            case 2: cout << "Val: "; cin >> v; head = insert(head, v); break;
            case 3: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, true); break;
            case 4: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, false); break;
            case 5: cout << "Del: "; cin >> v; head = del(head, v); break;
            case 6: cout << "Search: "; cin >> v; search(head, v); break;
            case 7: display(head); break;
        }
    } while (ch != 8);
}
