#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str; 
    cout << "Enter string: ";
    cin >> str;

    stack<char> s;
    for (char c : str) s.push(c);

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    cout << "Reversed: " << rev << endl;
}