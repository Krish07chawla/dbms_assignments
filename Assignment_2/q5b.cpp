#include <iostream>
using namespace std;
void setTriDiagonal(int arr[], int n, int i, int j, int val) {
    if(i == j) {
        arr[i-1] = val;   
    }
    else if(i - j == 1) {
        arr[(n-1) + (i-2)] = val;  
    }
    else if(j - i == 1) {
        arr[(2*n - 2) + (i-1)] = val;  
    }
}
int getTriDiagonal(int arr[], int n, int i, int j) {
    if(i == j) {
        return arr[i-1];   
    }
    else if(i - j == 1) {
        return arr[(n-1) + (i-2)];  
    }
    else if(j - i == 1) {
        return arr[(2*n - 2) + (i-1)];  
    }
    else {
        return 0;   
    }
}
void display(int arr[], int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getTriDiagonal(arr, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = 3*n - 2;   
    int arr[size];
    for(int i=0; i<size; i++) arr[i] = 0;  

    cout << "Enter elements of the tridiagonal matrix:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            if(i==j || i-j==1 || j-i==1) {
                setTriDiagonal(arr, n, i, j, val);
            }
        }
    }

    cout << "\nTri-diagonal Matrix is:\n";
    display(arr, n);

    return 0;
}