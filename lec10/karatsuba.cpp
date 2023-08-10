#include<iostream>
#include<cmath>
uint get_num(int x){
    return (x > 0)? (int) log10 ((double) x) + 1 : 1;
}
static int count = 0;

int karatsuba(int A, int B){
    int n;
    if(A >= B){
         n = get_num(A);
    }else n = get_num(B);
    
    if(n == 1){
        count ++;
        std::cout << "we have mutilpled " << count << " times!"<<'\n';
        return A*B;
    }else{
        int a, b, c, d, t ;
        t = n/2;
        a = A / pow(10, t);
        b = A - a*pow(10, t);
        c = B / pow(10, t);
        d = B - c*pow(10, t);
        int result = karatsuba(a,c) *(pow(10, t) - 1) * pow(10,t) + 
             karatsuba(b,d)*(1 - pow(10, t)) +   karatsuba(a+b, c+d)* pow(10, t);
        
        return result;
    }
}


int main()
{
    std::cout<<" enter 2 numbers:  ";
    int A, B, n;
    std::cin >> A >> B;
    std::cout << karatsuba(A,B) << '\n' ;
    return 0;
}