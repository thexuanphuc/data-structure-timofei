#include <iostream>
using namespace std;
const int max_size = 1000;
int main()
{
    int N = max_size;
    int A[N];
    for(int j = 0; j< N;j++){
        A[j] = 1000-j;
    }
    int i = 0;
    bool is_sort = false;
    int m = 0;
    int64_t S = 0; 
    while(not is_sort){
        is_sort = true;
        for (int i = 0; i < N-1-m; i++){
            
            if (A[i] > A[i+1]){
                int tpm = A[i];
                A[i] = A[i+1];
                A[i+1] = tpm;
                is_sort = false;
                S ++;
                cout << i<< "check"<< endl;
            }
            else continue;
        }
        m++;
    }
    for(int i = 0; i < N; i++) {
        cout << A[i] <<'\t';
    }
    cout << S << endl;
    return 0;
}