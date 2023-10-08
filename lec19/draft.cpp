#include <iostream>
#include <unordered_set>
#include <string>

struct NameNumberPair {
    std::string name;
    std::string number;

    // Custom hash function for NameNumberPair
    size_t operator()(const NameNumberPair& pair) const {
        size_t nameHash = std::hash<std::string>{}(pair.name);
        size_t numberHash = std::hash<std::string>{}(pair.number);
        return nameHash ^ numberHash;
    }

    // Custom equality operator for NameNumberPair
    bool operator==(const NameNumberPair& other) const {
        return name == other.name && number == other.number;
    }
};

int main() {
    std::unordered_set<NameNumberPair, NameNumberPair> byName;
    std::unordered_set<NameNumberPair, NameNumberPair> byNumber;

    // Insert pairs into both sets
    byName.insert({"John Doe", "(555) 123-4567"});
    byNumber.insert({"(555) 123-4567", "John Doe"});

    // Example: Find a pair by name
    std::string searchName = "John Doe";
    auto foundByName = byName.find({searchName, ""});
    if (foundByName != byName.end()) {
        std::cout << "Found by name: " << foundByName->name << " | " << foundByName->number << std::endl;
    } else {
        std::cout << "Pair not found by name." << std::endl;
    }

    // Example: Find a pair by number
    std::string searchNumber = "(555) 123-4567";
    auto foundByNumber = byNumber.find({"", searchNumber});
    if (foundByNumber != byNumber.end()) {
        std::cout << "Found by number: " << foundByNumber->name << " | " << foundByNumber->number << std::endl;
    } else {
        std::cout << "Pair not found by number." << std::endl;
    }

    return 0;
}
