#include<iostream>
using namespace std;
void print_array2d(int* A[], int N, int M){
    for (int i= 0; i< N; i++){
        for(int j = 0; j < M; j++){
            cout << A[i][j]  << "\t";                //cout<< A[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int N,M;
    cin >> N >> M;
    int **A;
    A = new int* [N]; 
    for(int  i = 0; i < N; i++){
        A[i] = new int[M]; // this is a pointer to fisrt element of an array, then A[0] = *A
        for(int j = 0; j<M; j++){
            *(A[i]+j) = i*M+j;
        }
    }
    
    // using reinterpret, convert array2d to normal array1d
    //int* p = reinterpret_cast<int*>(A);
    print_array2d(A,N,M);
    for (int i = 0; i< N; i++){
        delete[] A[i];
    }
    
    return 0;
}
