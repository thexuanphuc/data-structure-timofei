#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<typeinfo>
#include<algorithm>

using namespace std;
int main()
{
    int N;
    cin >> N;
    
    int A[100000];
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    int ip{0}, in{0};
    int M = N;
    while(M > 1){
        for(int k = 0; k< M; k++)
            if(A[k] >=0){
                ip = k;
                break;
            } 

        for(int k = 0; k< M; k++)
            if(A[k] < 0){
                in = k;
                break;
            } 
        for (int j = 0 ; j < M; j++){
            if(A[j] >= 0){
                
                if(A[ip] > A[j] ){
                    swap(A[ip], A[j]);
                    for(int k = 0; k <  N; k++){
                    cout<<A[k] <<" ";
                    }
                    cout << endl;
                }
                ip = j;
            }
            if(A[j] < 0){
                
                if (A[in] < A[j]){
                    swap(A[in], A[j]);
                    for(int k = 0; k <  N; k++){
                    cout<<A[k] <<" ";
                    }
                    cout << endl;
                }
                in = j;
            }
        }
        M--;
    }
    return 0;
}