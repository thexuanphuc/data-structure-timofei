#include<iostream>
#include<string>
#include<set>
#include<unordered_set>

void set_example()//this function is using std::set to storage data,
                    //u can see that date can automatically storage in
                    // alphabet (for string) or increasing (for int..)
{
    std::set<std::string> name;
    std::string word;
    while(getline(std::cin, word)){
        name.insert(word);
    }
    for(std::set<std::string>::iterator p = name.begin(); p!= name.end(); p++){// this is the address, then we need to use *p
                                                                                // address mean it used iterator, not reference
        std::cout << *p<< '\t';
    }
    /*for(word:name){// this method need to copy value???
        std::cout<<word<<'\t';
    }*/
    std::cout <<std::endl;

    std::cout<<"enter key to find:"<< '\n';
    std::cin >> word;
    
    if(name.find(word) != name.end()){
        std::cout<<" find this key: " << *name.find(word)<< '\n';
        name.erase(name.find(word));
    }
    /*else if(name.find(word) == false){
        std::cout<<" in your set have 2 elements with the same key, probaly they are the same!"<<'\n';
    }*/else{
        std::cout<< "cant find this key in this set!"<<'\n';
    }
    for(auto word:name){// this method dont pass adress of variables, it provide the reference of variable word!!!
                    // here auto is type of reference of std::string, that mean auto == std::string&
        std::cout<<word<<'\t';
    }
    std::cout <<std::endl;

}
void unordered_set_example()//this function is using std::set to storage data,
                    //u can see that date CAN NOT automatically storage in
                    // alphabet (for string) or increasing (for int..)
{
    std::unordered_set<std::string> name_unordered;
    std::string word;
    while(getline(std::cin, word)){
        name_unordered.insert(word);
    }
    for(std::unordered_set<std::string>::iterator p = name_unordered.begin(); p!= name_unordered.end(); p++){
        std::cout << *p<< '\t';
    }
    std::cout <<std::endl;
    for(auto word:name_unordered){// this method dont pass adress of variables, it provide the reference of variable word!!!
                        // here auto is type of reference of std::string, that mean auto == std::string&
        std::cout<<word<<'\t';
    }
    std::cout <<std::endl;
}
int main()
{   
    set_example();
    //unordered_set_example();
    return 0;
}
