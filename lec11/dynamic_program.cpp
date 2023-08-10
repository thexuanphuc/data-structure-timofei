#include<iostream>
#include<cassert>


uint64_t fab_dynamics(int n){
    assert(n >= 0);
    uint64_t* storage = new uint64_t[n+1];
    storage[0] = 0;
    storage[1] = 1;
    for(int i = 2; i < n+1; i++){
        storage[i] = storage[i-1] + storage[i-2];

    }
    uint64_t result = storage[n];
    delete[] storage;
    return result;
}
uint64_t fab_recursive(int n){
    //not now
    return 0;
}

int main()
{

    std::cout<< "take a choice dynamic(1) or recursive(2@)\n";
    int n; std::cin>> n;
    uint64_t (*fab)(int);

    if(n == 1)
        fab = fab_dynamics;
    else if( n == 2)
        fab = fab_recursive;

    for (int i = 0; i < 100; i++){
        std::cout<< i<<'\t' << fab(i) << '\n';
    }
    return 0;
}
