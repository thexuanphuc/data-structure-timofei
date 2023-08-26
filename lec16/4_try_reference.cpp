#include<iostream>

int main()
{
    int a = 6;
    int b = 8;
    int& refa = a;
    int& refb = b;
    std::cout << refa << '\t' << refb << '\t' << b << '\n';
    return 0;
}