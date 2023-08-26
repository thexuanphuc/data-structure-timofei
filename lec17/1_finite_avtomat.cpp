//realization of finite avtomat with 2 state(in_word and out_word) to count number of words in a sentence
//out_word is the initialized state
//here were gonna use switch
#include<iostream>
#include<string>
bool is_alpha(char symbol){
    //return (std::tolower(symbol) >= 97 or std::tolower(symbol) < 122);
    return (symbol >= 'a' and symbol <= 'z') or (symbol >= 'A' and symbol <= 'Z');
}
int main()
{
    std::string s;
    getline(std::cin, s);
    int pos = 0;
    int word_length;
    int number_of_words = 0; 
out_word:
    if(pos >= s.length()) goto the_end;
    if(is_alpha(s[pos++])){
        word_length = 1;
        goto in_word;
    }else{
        goto out_word;
    }
in_word:
    if(pos >= s.length()) goto the_end;
    if(is_alpha(s[pos++]) and pos < s.length()){     // cheking if the last word is still in progress by pos< s.length()
        word_length += 1;
        goto in_word;
    }else{
        std::cout<<"word length is " << word_length << '\n';
        number_of_words += 1;
        goto out_word;
    }
the_end:

    std::cout<<"number of words is: " << number_of_words << '\n';
    std::cout<< s <<'\n';

    return 0;
}
