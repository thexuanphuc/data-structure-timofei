#include<iostream>
#include<string>
#include<sstream>
#include <vector>




using namespace std;
int main()
{
    string n0;
    int N;
    getline(cin, n0);
    N = stoi(n0);
    vector<int> A;
    string str_input;
    getline(cin, str_input);
    stringstream stream_input(str_input);
    int d;
    while(stream_input >> d ){
        A.push_back(d);
        if(stream_input.peek() == ' ')
            stream_input.ignore();
    }
  
    int i,j,min;
    for( i =  0; i < N; i++){
        min = i;
        for( j = i; j < N; j++){
            if(A[min] > A[j] )
            min = j;
        }
        swap(A[min], A[i]);
    }
    
    int S = 0;
    
    while( S <3 ){
        for (i = 0; i < N-1; i++){
            if(A[i] == A[i+1]) S+=1;
        }
    }
    if (S < 2) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
