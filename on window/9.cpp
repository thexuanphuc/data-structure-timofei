#include<iostream>
const int max_digits = 100;
void generate(int n){
    static int digits_combination[max_digits]; 
    static int number_of_digits = 0;
    if (n == 0){
        for(int i = 0; i < number_of_digits; i++){
            std::cout << digits_combination[i] << '\t' ;
        }
        std::cout << std::endl;;
    } else{
        digits_combination[number_of_digits++] = 0;
        generate(n-1);/* in 1 cirlce when the first limb is generating, we keep length of combination increase,
         but when we generated, we need to decrease it for the new generating of another limb!*/
        number_of_digits--;
        
        digits_combination[number_of_digits++] = 1;
        generate(n-1);
        number_of_digits--;

        

;    }
}


int main()
{   
    int n;
    std::cin >> n;
    generate(n);
    
    return 0;
}