#include<iostream>
#include<cassert>
#include<vector>

void find_max_packing(int max_cap,int n, int* mass,int* value){
    assert(max_cap > 0);
    std::vector<std::vector<int>> tab;
    for(int i = 0; i<= max_cap; i++){
        tab.push_back(std::vector<int>());// for first collumn
        tab[i].push_back(0);
    }
    for(int i = 1; i<= n; i++){
        tab[0].push_back(0);// for first row
    }
    for(int i = 1; i<= max_cap; i++){
        for(int j = 1; j<= n; j++){
            if((i - mass[j] >= 0)  and (tab[i][j-1] <= tab[i - mass[j]][j-1] + value[j])){
                tab[i].push_back(tab[i - mass[j]][j-1] + value[j]);
            } else tab[i].push_back(tab[i][j-1]);
        }
    }
    for(int i = 0; i<= max_cap; i++){
        for(int j = 0; j<= n; j++){
            std::cout<<tab[i][j] <<'\t';
        }
        std::cout<<'\n';
    }
    std::cout<<"the bigget value can be brought out is "<< tab[max_cap][n]<<'\n';
}
void fill_up(int arr[], int n, int max){
    for(int i = 0; i < n; i++){
        arr[i] = rand()% max + 0;
    }
}
void print_array(int arr[], int n){
    for(int i = 0; i< n; i++)
        std::cout<<arr[i]<<'\t';
    std::cout<< '\n';
}

int main()
{
    std::cout<<"enter number of items and max capability: ";
    int n, max_cap; 
    std::cin>>n>>max_cap;
    int mass[n+1];
    int value[n+1];
    fill_up(mass, n+1, max_cap/2);
    fill_up(value, n+1, 6);
    print_array(mass,n+1);
    print_array(value,n+1); 
    std::cout<<'\n';
    find_max_packing(max_cap,n, mass, value);
    
    return 0;
}