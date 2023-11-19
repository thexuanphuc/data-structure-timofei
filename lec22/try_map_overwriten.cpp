#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Inserting key-value pairs
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Printing the initial contents of the map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Attempting to insert a new pair with an existing key
    myMap[2] = "New Two";  // This will not create a new pair, but update the existing one

    // Printing the contents of the map after the attempted insertion
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::pair<std::map<int, std::string>::iterator, bool> result;
    
    // dont use make_part or std::pair<int, int>(1,2). because of this method need additional conversion -> slow down code
    // result = myMap.insert(std::make_pair(3, "new three")); 
    
    result = myMap.insert(std::map<int, std::string>::value_type(3, "new three"));
    // or use this for more consice and readable:
                // result = myMap.insert({3, "new three"});
    if(result.second == false){
        std::cout<<"this key 3 have already existed!    \n";
    }
    // Printing the contents of the map after the attempted insertion
    for(const auto& pair: myMap){
        std::cout<< pair.first <<": "<< pair.second << "\n";
    }

    return 0;
}