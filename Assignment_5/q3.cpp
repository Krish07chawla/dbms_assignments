#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

Node* insertEnd(Node *head, int val) {
    Node *n = new Node(val);
    if (head == NULL) return n;
    Node *t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
    return head;
}

int findMiddle(Node *head) {
    if (head == NULL) return -1;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void display(Node *head) {
    Node *t = head;
    while (t != NULL) {
        cout << t->data;
        if (t->next) cout << "->";
        t = t->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    int n, x;
    cout << "How many nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insertEnd(head, x);
    }

    cout << "Linked List: ";
    display(head);

    int mid = findMiddle(head);
    if (mid != -1)
        cout << "Middle node: " << mid << endl;
    else
        cout << "List is empty.\n";
}
