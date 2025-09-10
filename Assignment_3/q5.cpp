#include <iostream>
#include <string>
using namespace std;

int main() {
    string post;
    cout << "Enter postfix (single-digit): ";
    cin >> post;

    int stack[100];
    int top = -1;

    for (int i = 0; i < post.size(); i++) {
        char ch = post[i];
        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int res;
            if (ch == '+') res = a + b;
            else if (ch == '-') res = a - b;
            else if (ch == '*') res = a * b;
            else if (ch == '/') res = a / b;
            stack[++top] = res;
        }
    }
    cout << "Result: " << stack[top] << endl;
    return 0;
}
