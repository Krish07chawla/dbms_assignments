#include <iostream>
using namespace std;


int idxLT(int i, int j) {           
    return i*(i+1)/2 + j;           
}

int main() {
    int n; 
    cout << "Enter n: ";
    cin >> n;

    int sz = n*(n+1)/2;
    int lt[sz];
    for(int k=0;k<sz;k++) lt[k]=0;

    cout << "Enter lower triangular elements row-wise (i>=j):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> lt[idxLT(i,j)];
        }
    }

    cout << "\nLower Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i) cout << lt[idxLT(i,j)] << " ";
            else     cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}