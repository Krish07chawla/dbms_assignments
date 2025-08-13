#include <iostream>
using namespace std;

int main() {
    int a[100], n, cnt = 0;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) { found = true; break; }
        }
        if (!found) cnt++;
    }
    cout << "Distinct elements: " << cnt << endl;
    return 0;
}
