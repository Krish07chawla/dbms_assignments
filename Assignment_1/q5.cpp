#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c, sum;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++) {
        sum = 0;
        for (int j = 0; j < c; j++) sum += a[i][j];
        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }
    for (int j = 0; j < c; j++) {
        sum = 0;
        for (int i = 0; i < r; i++) sum += a[i][j];
        cout << "Sum of col " << j + 1 << " = " << sum << endl;
    }
    
    return 0;
   
}
