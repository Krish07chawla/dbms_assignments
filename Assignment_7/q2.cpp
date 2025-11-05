#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int start = 0, end = n - 1;
    while (start < end) {
        int minIdx = start, maxIdx = start;
        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIdx]) {
                minIdx = i;
            }
            if (a[i] > a[maxIdx]) {
                maxIdx = i;
            }
        }

        swap(a[start], a[minIdx]);

        if (maxIdx == start) {
            maxIdx = minIdx;
        }

        swap(a[end], a[maxIdx]);

        start++;
        end--;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
