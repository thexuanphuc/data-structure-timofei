/* program will add up template and line, in which we need to find exist or not this template
then use kmp-algorithm to find the if in added up line has some repetition or not
further optimization:
    +only save tab[n] of n-first elements;
    

*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>


void kmp_algorithm(std::string A, int n){
    std::ofstream output_data;
    output_data.open("output.txt", std::ios::out | std::ios::app);
    std::vector<int> tab;
    tab.push_back(0);
    int k;
    for(int i = 1; i < A.length(); i++){
        k = tab[i-1];
        while( k>0 and A[i] != A[k]){
            k = tab[k-1];
        }
        if(A[i] == A[k]){
                tab.push_back(k + 1);
        }else {
            tab.push_back(0);
        }
    }
    for(int i = 0; i < A.length(); i++ ){
        output_data << tab[i];
    }
    output_data<< '\n';
    for(int i = 0; i < A.length(); i++ ){
        if(tab[i] == n){
            output_data<<"the template is found at positions(begin from 0) from " << i-n+1 <<" to "<<i<< '\n'; 
        }
    }
    output_data.close();

}

int main()
{
    std::ifstream input_data;
    input_data.open("input.txt", std::ios::in);
    

    std::string line, temp, merged;
    if(input_data.is_open()){
        getline(input_data, line);
        getline(input_data, temp);
    }
    merged = temp + '#' + line;
    kmp_algorithm(merged, temp.length());   

    input_data.close();

    return 0;
}
