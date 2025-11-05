#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) { data = v; next = NULL; }
};

Node* insert(Node *head, int val, int ref = -1, bool before = false) {
    Node *n = new Node(val);
    if (!head) { n->next = n; return n; }
    Node *t = head;
    if (ref == -1) {
        while (t->next != head) t = t->next;
        t->next = n; n->next = head;
        return head;
    }
    do {
        if (t->data == ref) {
            if (before) {
                Node *p = head;
                while (p->next != t) p = p->next;
                p->next = n; n->next = t;
                if (t == head) head = n;
            } else {
                n->next = t->next;
                t->next = n;
            }
            return head;
        }
        t = t->next;
    } while (t != head);
    cout << "Not found\n";
    delete n;
    return head;
}

Node* del(Node *head, int key) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == key) {
            if (curr == head && curr->next == head) {
                delete curr; return NULL;
            }
            if (curr == head) {
                while (head->next != curr) head = head->next;
                head->next = curr->next;
                Node *nh = curr->next;
                delete curr;
                return nh;
            }
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Not found\n";
    return head;
}

void search(Node *head, int key) {
    if (!head) { cout << "Empty\n"; return; }
    int i = 1; Node *t = head;
    do {
        if (t->data == key) { cout << "Found at " << i << endl; return; }
        t = t->next; i++;
    } while (t != head);
    cout << "Not found\n";
}

void display(Node *head) {
    if (!head) { cout << "Empty\n"; return; }
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << endl;
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
