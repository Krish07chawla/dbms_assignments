#include <iostream>
using namespace std;

int main() {
    int A[10][3] = { {3,3,3}, {0,0,5}, {1,1,8}, {2,2,10} };
    int B[10][3] = { {3,3,3}, {0,1,7}, {1,1,3}, {2,0,6} };
    int C[20][3];

    
    if(A[0][1] != B[0][0]) {
        cout << "Multiplication not possible\n";
        return 0;
    }

    int t1 = A[0][2], t2 = B[0][2];
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    int k = 1;
    for(int i=1; i<=t1; i++) {
        for(int j=1; j<=t2; j++) {
            if(A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

            
                int found = 0;
                for(int x=1; x<k; x++) {
                    if(C[x][0]==row && C[x][1]==col) {
                        C[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    C[k][0] = row;
                    C[k][1] = col;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }

    C[0][2] = k-1;

    
    cout << "Multiplication (A*B) in triplet form:\n";
    cout << "Row Col Val\n";
    for(int x=0; x<=C[0][2]; x++) {
        cout << C[x][0] << " " << C[x][1] << " " << C[x][2] << endl;
    }
    return 0;
}