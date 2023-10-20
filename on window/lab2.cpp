#include<iostream>
#include<string>


using namespace std;
int main()
{   
    int N ;
    string T ;
    int M;
    cin >> N ; 
    bool flag = false;
    while (N>0){
        if (flag) T ="." + T;
        M = N % 60;
        for(int i= 0; i < M %10; i++) T= "v" + T;
        for(int i= 0; i < M /10; i++) T= "<" + T;
        flag = true;        
        N /=60;
    }
    cout << T << endl;
    return 0;
}
