#include <iostream>
using namespace std;


int idxUT(int n, int i, int j) {           
    int before = i*n - (i*(i-1))/2;        
    return before + (j - i);                
}

int main() {
    int n; 
    cout << "Enter n: ";
    cin >> n;

    int sz = n*(n+1)/2;
    int ut[sz];
    for(int k=0;k<sz;k++) ut[k]=0;

    cout << "Enter upper triangular elements row-wise (i<=j):\n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin >> ut[idxUT(n,i,j)];
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i) cout << ut[idxUT(n,i,j)] << " ";
            else     cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}