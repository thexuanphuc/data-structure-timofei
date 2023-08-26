//realization of finite avtomat with 2 state(in_word and out_word) to count number of words in a sentence
//out_word is the initialized state
#include<iostream>
#include<string>
#include<cctype>
enum tState{
    //by default, state will be from 0,1,2...
    out_word,
    in_word
};
bool is_alpha(char symbol){
    //return (std::tolower(symbol) >= 97 and std::tolower(symbol) < 122);
    //return (symbol >= 'a' and symbol <= 'z') or (symbol >= 'A' and symbol <= 'Z');
    return (std::isalpha(symbol) != 0); //another way to check if its alphabetic or not
}
int main()
{
    std::string s;
    getline(std::cin, s);
    int pos;
    int word_length;
    int number_of_words = 0;
    tState state = out_word;
    for(pos = 0; pos < s.length(); pos++){ // <= to cout the last word, but may crashed by undifined behavior.
        switch(state){ // this switch doesnt like iteration, it only run 1 time. 
            case out_word:
                if(is_alpha(s[pos])){
                    word_length = 1 ;
                    state = in_word;
                }else{
                    state = out_word;
                }
                break;//this is the last output of interation, compiler run code line by line, then if here not break, it will continue 
                        //to go to case in_word; all the case need to be break in the end
                    //You need to add break statements at the end of each case block in the switch statement to prevent fall-through behavior.
            case in_word:
                if(is_alpha(s[pos])){
                    word_length += 1;
                    state = in_word;
                }else{
                    std::cout<<"word length is " << word_length << '\n';
                    number_of_words += 1;
                    state = out_word;
                }   
                break;
        }
    }
    //checking if the last word is still in progress
    if(state == in_word){
        std::cout<<"word length is " << word_length << '\n';
        number_of_words += 1;
    }
    std::cout<<"number of words is: " << number_of_words << '\n';
    std::cout<< s <<'\n';

    return 0;
}