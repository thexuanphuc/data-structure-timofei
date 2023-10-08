#include<iostream>
#include<fstream>
#include<string> 
#include<unordered_set>
struct pair_name_num{
    std::string name;
    std::string number;
};
struct hash_by_number{
    //overwrite operator to hash a new type pair
    size_t operator()(const pair_name_num &pair){
        size_t hash_num = std::hash<std::string>{}(pair.number);
        size_t hash_name = std::hash<std::string>{}(pair.name);
        return hash_num ^ hash_name;
    }
};

int main()
{
    std::fstream myfile;
    myfile.open("data_input.txt", std::fstream::in);
    std::string line;
    std::string name, number;
    std::unordered_set<std::string> hash_table;

    if(myfile.is_open()){
        for(std::string& line : myfile){ 
            std::string::size_type pos = line.find(" - ",0);
            if (pos != std::string::npos){
                name = line.substr(0, pos);
                number = line.substr(pos+3);
                hash_table.insert({name, number});
            }
        }
    }
    /*std::fstream outdata;
    outdata.open("data_output.txt",std::fstream::in | std::fstream::app);
    outdata.seek(0);
    pair_name_num person_A;
    std::string sample;
    sample = outdata.getline();
    std::string::size_type pos = sample.find(" - ");
    person_A.name = sample.substr(0, pos);
    person_A.number = sample.substr(pos+3);
    auto filter = hash_table.find({person_A.name ,person_A.number}); // this is iterator of std::unordered_set
    if(filter != hash_table.end()){
        outdata << "find that "<< filter-> name << " with phone number "<< filter-> number << std::endl;
    }
    */
    outdata.flush();
    outdata.close();
    myfile.flush();
    myfile.close();
    return 0;
}