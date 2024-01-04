// in this task, assumed that the vertices of graph is numbered from 0 to n-1
// input task is done
// synchronization between each method. which method is primarly to store graph???

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <limits>
#include <typeinfo> // only check at compile time ??
#include <cassert> // usually for checking logical assumption during development,not for checking type variable
                    // cassert is enable when NDEBUG is not definded?

typedef std::set<int> list_of_vertexs;// this will be all the existent vertex
class abstract_graph
{
protected:
    int number_of_vertices = 0;
    std::set<std::pair<int,int>> list_of_edges;//how
    std::vector<std::vector<bool>> adjacency_matrix;
    std::map<int,std::set<int>> adjacency_list;

public :
    // all these initializations need to be put in a default fucntion(is called constructor)
    abstract_graph(){ // this is constructor
        std::cout << " enter numbers of adjacency matrix: \n";
        std::cin >> number_of_vertices;
        // Clear the newline character from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//wow ?
    }
    // declaring 2 virtual function in a abstract class(abstract_graph in our case)
    // we need to write this, to indicate that we will implement it in a derived class of this abstract class
    // always write with 0; if we dont write =0, then it not require to write implementation in derived class
    // we only write this virtual keyword in base class, them these function are implicitly virtual and overridable
    virtual void input() = 0;
    // fuction print means convert to this type, then print it out
    virtual void print_list_edges() const = 0;
    virtual void print_adjacency_matrix() const = 0;
    virtual void print_adjacency_list() const = 0;
    
};
// using list of edges
// 
class graph_storage_1 : public abstract_graph
{
public:
    // graph_storage_1() default case (constructor)

    // override indicate that this function input in this derived class will override input function in abstact_graph
    void input() override
    {   
        list_of_edges.clear();
        std::cout<<"enter list of edges, pass by enter!!\n" ;
        int first, second;
        int count = 0;
        while(count < number_of_vertices){
            std::cin >> first >> second;
            list_of_edges.insert(std::set<std::pait<int, int>>::value_type(first, second));
            count ++;
        }
    };

    void print_list_edges() const override
    {
        // print out edges
        std::cout<< "edges are: \n";
        for(const auto& element : list_of_edges){ // here we use reference, avoiding unecessary of coping value to function to print
            std::cout <<"("<< element.first <<"," << element.second << ")\t";
        }
        std::cout << "\n";
    };
    void print_adjacency_matrix() const override
    {
        
    };
};
// using adjacency matrix
// this method allows quickly lookups whether there is an edge between 2 vertices;
// but this method is not very memory-efficient, especially for sparse graph(relatively few edges)
class graph_storage_2 : public graph_storage_1
{
public:
    // override indicate that this function input in this derived class will override input function in graph_storage_1
    void input() override
    {   
        list_of_edges.clear();
        // resize and set all element of matrix to false
        adjacency_matrix.resize(number_of_vertices);
        for(auto& row : adjacency_matrix){
            row.resize(number_of_vertices, false);
        }
        std::cout<< "enter the list of adjoining vertices: \n";
        int first, second;
        for(int i = 0; i < number_of_vertices; i++)
        {
            std::cin >> first >> second;
            list_of_edges.insert(std::make_pair(first, second));
            adjacency_matrix[first][second] = true;
            adjacency_matrix[second][first] = true;
        }
    };

    void print() const override
    {
        std::cout<< "adjacency matrix is: \n";
        for(auto& row : adjacency_matrix){ 
            for(const auto& element : row){
                std::cout << element << "  ";
            }
            std::cout<< std::endl;
        }
        std::cout << "\n";
    };
};

//using adjacency list
// memory efficient(especially for sparse graph) but less effective when traversing the edges
class graph_storage_3 : public graph_storage_2
{

public:
    //this is the last derived class-> dont use virtual keyword
    // final indicate that this function input in this derived class will override input function in graph_storage_2,
    // and this is the last function, others function in others derived class cant override this function
    void input() final
    { 
        int lead_vertex = 0;
        int input_value;
        list_of_vertexs list_vertexs;
        while(lead_vertex < number_of_vertices){
            std::cout<< "Enter the list of vertices are connected with the " << lead_vertex << " vertex(enter for passing)\n";
            std::string input_str;
            std::getline(std::cin, input_str);
            std::stringstream input_ss(input_str);
            list_vertexs.clear();
            while(input_ss >> input_value){     //insert input_value to list_vertexs
                list_vertexs.insert(input_value);
            }
            adjacency_list.insert(std::map<int, std::set<int>>::value_type(lead_vertex, list_vertexs));
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     //ignore the enter if these have
            lead_vertex++;
        }
    }
    void print() const final
    {
        for(std::map<int, std::set<int>>::const_iterator p = adjacency_list.cbegin(); p != adjacency_list.cend(); ++p ){     // iterator is pointer
            std::cout<< p->first << ": ";
            for(std::set<int>::const_iterator q = p->second.cbegin(); q != p->second.cend(); ++q){
                std::cout << *q << " ";
            }  
            std::cout<< std::endl;
        }
    }
};
int main()
{
    graph_storage_1 my_graph1;
    my_graph1.input();
    my_graph1.print();
    graph_storage_2 my_graph2;
    my_graph2.input();
    my_graph2.print();
    graph_storage_3 my_graph3;
    my_graph3.input();
    my_graph3.print();
    return 0;
}