#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[100], t;
    cout << "Enter string: ";
    cin.getline(s, 100);
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
    cout << "Reversed: " << s << endl;
    return 0;
}
