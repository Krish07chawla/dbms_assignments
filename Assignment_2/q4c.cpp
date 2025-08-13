#include <iostream>
using namespace std;

int main() {
    char s[100];
    cout << "Enter string: ";
    cin.getline(s, 100);
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            s[j++] = s[i];
    }
    s[j] = '\0';
    cout << "Without vowels: " << s << endl;
    return 0;
}
