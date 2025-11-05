#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) { data = v; next = NULL; }
};

Node* insertEnd(Node *head, int val) {
    Node *n = new Node(val);
    if (!head) { n->next = n; return n; }
    Node *t = head;
    while (t->next != head) t = t->next;
    t->next = n; n->next = head;
    return head;
}

void display(Node *head) {
    if (!head) { cout << "Empty"; return; }
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data;
}

int main() {
    Node *head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insertEnd(head, x);
    }
    display(head);
}
