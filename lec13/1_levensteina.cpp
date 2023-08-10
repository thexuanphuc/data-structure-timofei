#include<iostream>
#include<cassert>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>
int levensteina_recursive(char a[], char b[], int i, int k){
    std::cout<<" i = "<< i<< "k = "<< k<<'\n'; 
    assert(i >= 0 && k >= 0);
    if ( i == 0 || k == 0){

        return std::max(i,k);
    }else{
        if(a[i-1] == b[k - 1]){
            return(levensteina_recursive(a, b, i-1, k-1));
        }else{
            

            return std::min({levensteina_recursive(a, b, i-1, k),
                levensteina_recursive(a, b, i, k-1)}) + 1;
        }    
    }
}
int levensteina_dynamics(char a[], char b[]){
    std::vector<std::vector<int>> L;
    for(int i = 0; i <= strlen(a); i++){
        L.push_back(std::vector<int>());
        L[i].push_back(i);
    }
    for(int i = 1; i <= strlen(b); i++){
        L[0].push_back(i);
    }
    
    for(int i = 1; i <= strlen(a); i++){
        for(int j = 1; j<= strlen(b); j++){
            if(a[i-1] == b[j - 1]){
                L[i].push_back(L[i-1][j-1]);
            }else{
                L[i].push_back(std::min({L[i-1][j-1],L[i-1][j], L[i][j-1]}) + 1);
            }    
        }
    }
    return L[strlen(a)][strlen(b)];
}
int main()
{

    char a[30],b[30];
    std::cin >> a >> b;
    std::fstream myFile;
    myFile.open("result.txt", std::ios::app);
    if(myFile.is_open()){
        //std::cout<<"use recursive: "<<levensteina_recursive(a,b, strlen(a), strlen(b))<< std::endl;
        myFile <<"use 2 dimension dynamics: "<<levensteina_dynamics(a,b)<< std::endl;
        myFile.close();
    }
    
    return 0;
}