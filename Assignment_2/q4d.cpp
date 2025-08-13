#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[10][50], t[50];
    int n;
    cout << "How many strings: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) cin.getline(str[i], 50);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(t, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], t);
            }
        }
    }
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++) cout << str[i] << endl;
    return 0;
}

