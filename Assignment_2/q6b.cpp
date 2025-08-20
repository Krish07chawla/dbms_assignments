#include <iostream>
using namespace std;

int main() {
    int A[10][3] = { {3,3,3}, {0,0,5}, {1,1,8}, {2,2,10} };
    int B[10][3] = { {3,3,3}, {0,1,7}, {1,1,3}, {2,0,6} };
    int C[20][3];

    
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible\n";
        return 0;
    }

    int t1 = A[0][2], t2 = B[0][2];
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i=1, j=1, k=1;

    
    while(i<=t1 && j<=t2) {
        if(A[i][0] < B[j][0] || 
          (A[i][0]==B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if(B[j][0] < A[i][0] || 
               (A[i][0]==B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    
    while(i<=t1) { C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++; }
    while(j<=t2) { C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++; }

    C[0][2] = k-1;


    cout << "Addition (A+B) in triplet form:\n";
    cout << "Row Col Val\n";
    for(int x=0; x<=C[0][2]; x++) {
        cout << C[x][0] << " " << C[x][1] << " " << C[x][2] << endl;
    }
    return 0;
}