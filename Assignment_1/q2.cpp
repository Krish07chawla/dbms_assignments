#include <iostream>
using namespace std;

int main() {
    int a[100], n, i, j, k;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (k = j; k < n - 1; k++) a[k] = a[k + 1];
                n--;
                j--;
            }
        }
    }
    cout << "Array with unique elements: ";
    for (i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
