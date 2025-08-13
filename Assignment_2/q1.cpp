#include <iostream>
using namespace std;

int main() {
    int a[100], n, key, low, high, mid, found = 0;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Enter key: ";
    cin >> key;
    low = 0; high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            cout << "Found at position " << mid + 1 << endl;
            found = 1;
            break;
        } else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    if (!found) cout << "Not found\n";
    return 0;
}
