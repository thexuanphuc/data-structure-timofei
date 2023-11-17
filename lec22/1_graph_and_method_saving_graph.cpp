#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <typeinfo> // only check at compile time ??
#include <cassert> // usually for checking logical assumption during development,not for checking type variable
                    // cassert is enable when NDEBUG is not definded?

typedef std::set<int> list_of_vertexs;// this will be all the existent vertex

class graph_storage_1 // using list of edges
{
    list_of_vertexs vertexs;
    std::set<std::pair<int,int>> list_of_edges;
public:
    void input()
    {
        std::cout<<" enter list of vertexs: \n";
        vertexs.clear();// clear all element, set size to 0; if use erase -> only some specified element
        std::string input_string;
        std::getline(std::cin, input_string);
        std::stringstream ss_input_string(input_string);
        int input_value;
        //ss_input_string << input_string; //why here i cant initialize like this
        while(ss_input_string >> input_value)  { //like cin >> x, mean from the value entered, saved by cin, then assign to x
                //check for matching type
            vertexs.insert(input_value);  
        }
        std::cout<<"enter list of edges, pair by enter!!\n" ;
        int first, second;
        while(std::cin >> first >> second){
            list_of_edges.insert(std::make_pair(first, second));
        }
        
    };

    void print() const
    {
        //print out vertices
        std::cout<<"list of vertices are \n (";

        for(auto& element : vertexs){
            std::cout << element <<"\t"; 
        }
        std::cout<<")\n";
        // print out edges
        std::cout<< "edges are: \n";
        for(auto& element : list_of_edges){ // here we use reference, avoiding unecessary of coping value to function to print
            std::cout <<"("<< element.first <<"," << element.second << ")\t";
        }
        std::cout << "\n";
    };
};

int main()
{
    graph_storage_1 my_graph1;
    my_graph1.input();
    my_graph1.print();
    

    return 0;
}