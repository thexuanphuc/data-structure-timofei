#include<iostream>
#include<cassert>
typedef struct track{// here track is variable in struct-space
    int cost;
    bool path = true;
}track_test;// here track_test is variable in globle-space
void fill_up(int* arr, int n){
    assert(n>=0);
    for(int i=0; i< n; i++){
        arr[i] = rand()% 100+ -50;
    }
}
void print_array(int* arr, int n){
    assert(n>=0);
    for(int i=0; i< n; i++){
        std::cout << arr[i] <<'\t';
    }
    std::cout<< '\n';
}
void min_cost(int * price, int size){
    assert(size >= 0);
    track_test *track = new track_test[size];
    track[0].cost = 0;
    track[1].cost = price[1];
    track[2].cost = track[1].cost + price[2];
    for(int i = 3; i < size; i++){
        track[i].cost = price[i] + std::min(track[i-2].cost, track[i-1].cost);
    }
    for(int i = size-1; i > 1; i--){
        if(track[i-1].cost <= track[i-2].cost){
            track[i-2].path = false;
        }else if(track[i-1].cost > track[i-2].cost) {
            track[i-1].path = false; 
            i--;
        }else 
            throw -1;// it means 
    }
    int cost = 0;
    for(int i = 1; i<= size - 1; i++){
        if(track[i].path){
            std::cout<<" path:  "<< price[i] << '\t'; 
            cost += price[i];
        }
    }
    
    std::cout<< '\n';
    delete[] track;
    std::cout<<" min cost to go from 1 to n is: "<< track[size-1].cost << '\n'; // find min cost at array[n];
    std::cout<< '\n';
    std::cout<<" actual cost:  "<< cost << '\n'; // find min cost at array[n];

}


int main()
{
    std::cout<<" enter number n: \n" ; 
    int n; 
    std::cin>> n;
    int price[n+1]; 
    fill_up(price, n+1);// fill up from 0 to n
    print_array(price, n+1);// print from arr[0] to arr[n]
    min_cost(price,n+1);
    std::cout<< '\n';

    return 0;
}