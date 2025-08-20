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
    int sym[sz];
    for(int k=0;k<sz;k++) sym[k]=0;

    cout << "Enter elements for LOWER triangle (including diagonal):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> sym[idxLT(i,j)];
        }
    }

    cout << "\nSymmetric Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j) cout << sym[idxLT(i,j)] << " ";
            else     cout << sym[idxLT(j,i)] << " "; 
        }
        cout << "\n";
    }
    return 0;
}