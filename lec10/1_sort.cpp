/*relisation of permutation from n number(0-n):
we dont use statics variable or globle variables, it not safe for parallel computing process!
*/

#include <iostream>

void permutation(int16_t digit, int16_t n,int16_t buffer[],bool used[]){
    
    if(digit == n){
        for(int16_t i = 0; i < n; i++){
            std::cout<< buffer[i] <<'\t';
        }
        std::cout<< std::endl;
    }else{
        for(int16_t i = 0; i < n; i++){
            if(true){
                buffer[digit] = i;
                used[i] = true;
                permutation(digit+1, n, buffer, used);
                used[i] = false;

            }
        }

    }
}
int main()
{
    int16_t n;
    std::cout << "enter the length of num: "; std::cin >> n;
    int16_t buffer[n];
    bool used[n] = {false};
    
    permutation(0, n, buffer, used);
    std::cout << std::endl;
}   