#include <iostream>
using namespace std;

int main() {
    int a[100], n;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter sorted numbers: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    int diff = a[0] - 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - i != diff) {
            cout << "Missing number: " << i + diff << endl;
            break;
        }
    }
    return 0;
}

