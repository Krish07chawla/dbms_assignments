#include <iostream>
using namespace std;

int main() {
    int a[100], n, t;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n / 2; i++) {
        t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
