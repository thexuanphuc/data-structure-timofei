/* this program uses z-function to find how many substring in string
assummed z[0] = 0;
z[i] = maximal length of substring, begin from i, and equal to prefix of string(from 0)

    

*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>


void z_algorithm(std::string A, int m){
    std::ofstream output_data;
    output_data.open("output.txt", std::ios::out | std::ios::app);
    int n = A.length();
    std::vector<int> z (n, 0);
    int l = 0;
    int r = 0;
    int i = 1;
    for(int i = 1; i< n; i++){
        //case in the boundary [left, right]
        if(i <= r){
            z[i] = std::min(z[i-l], r-i+1);   
        }
        //if in boundary(z[i] < r-i+1), i+z[i] is the last element of matched substring, therefore while interator doesnt run!
        while(i + z[i] < n && A[i+z[i]] == A[z[i]]){  
            z[i]++;
        }
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;//if z[i] > 0, that means at least element A[i] == A[0], then left boundary is equal i
        }
        // but in case if z[i] = 0, then right < left and ??
    }

    for(int i = 0; i < A.length(); i++ ){
        output_data << z[i];
    }
    output_data<< '\n';
    for(int i = 0; i < A.length(); i++ ){
        if(z[i] == m){
            output_data<<"the template is found at positions(begin from 0) from " << i - m + 1 <<" to "<< i + 1  << '\n'; 
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
    z_algorithm(merged, temp.length());   
    input_data.close();
    return 0;
}
