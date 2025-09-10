#include <iostream>
#include <string>
using namespace std;

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    char stack[100];
    int top = -1;
    bool ok = true;

    for (int i = 0; i < exp.size(); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
            stack[++top] = ch;
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { ok = false; break; }
            char open = stack[top--];
            if ((open == '(' && ch != ')') ||
                (open == '{' && ch != '}') ||
                (open == '[' && ch != ']')) {
                ok = false;
                break;
            }
        }
    }
    if (top != -1) ok = false;

    if (ok) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
