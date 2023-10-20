#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    double S = 0;
    for (int i = 0; i < n; i++){
        cin>> A[i];
        S += A[i];
    }
    int Big = 0;
    for (int i = 0; i < n; i++){
        if(A[i] > S/n )
        Big += A[i];
    }
    cout << Big << endl;

    return 0;
}