#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, ch, pos, val, key, found, i;
    while (1) {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter size: ";
            cin >> n;
            cout << "Enter elements: ";
            for (i = 0; i < n; i++) cin >> arr[i];
        }
        else if (ch == 2) {
            cout << "Array: ";
            for (i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else if (ch == 3) {
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            for (i = n; i >= pos; i--) arr[i] = arr[i - 1];
            arr[pos - 1] = val;
            n++;
        }
        else if (ch == 4) {
            cout << "Enter position: ";
            cin >> pos;
            for (i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
        }
        else if (ch == 5) {
            cout << "Enter element to search: ";
            cin >> key;
            found = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Found at position " << i + 1 << endl;
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Not found\n";
        }
        else if (ch == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
