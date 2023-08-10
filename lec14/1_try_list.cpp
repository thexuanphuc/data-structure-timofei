#include<iostream>
#include<list>
#include<string>

int main()
{
    std::list<std::string> list_of_words;
    std::string word;
    getline(std::cin, word);
    std::list<std::string>::iterator p;
    p = list_of_words.begin();
    while(word != ""){
        list_of_words.insert(p,2,word);
        getline(std::cin, word);
    }
    for(p = list_of_words.begin(); p!= list_of_words.end(); ++p){
        std::cout << *p<< '\t';
    }   
    std::cout << std::endl;
    for( auto k = list_of_words.begin(); k!= list_of_words.end(); ++k){
        std::cout << *k<< '\t';
    }   
    std::cout << std::endl;
    for(auto k : list_of_words){ //here need to copy value when passing value
        std::cout << k << '\t';
    }   
    std::cout << std::endl;
    for(auto &k : list_of_words){//its not nescesserly copy value. its passed by reference
        std::cout << k << '\t';
    }   
    std::cout << std::endl;

    return 0;
}