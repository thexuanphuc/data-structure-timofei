// for const we read left to right
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <utility>
typedef std::set<std::pair<int,int>> list_edges;

struct pair_hash { 
    template <class T1, class T2> // that mean now T1, T2 is template parameter of class, without type? but what class here??
    std::size_t operator () (const std::pair<T1, T2>& p) const { // now we declare the pair of type <T1, T2>
                                                                // then we call this overloaded operation()
                                                                // we put in this operation the reference of pair p from outside
        auto h1 = std::hash<T1>{}(p.first); // then h1 is the hashed result of p.first with type T1
        auto h2 = std::hash<T2>{}(p.second); //the result of hash is size_t
                                            // the {} is the functional cast, or just uniform initialization
                                            // that we need to construct the hash funciton, then call it with (parameter)

        // Simple hash combining algorithm
        return h1 ^ h2;
    }
};
struct my_pair_hash{
    template<class T1, class T2> // define type-variable T1 and T2
    std::size_t operation() (const std::pair<T1, T2>& p) const{ // the first const indicate that p is reference of type pair that is constant
                                                                // mean we cant use this reference to change the value of p
                                                                // the second const indicate that the p itself cant be changed explicitly by
                                                                // some operation like += or  
        size_t h1 = std::hash<T1>{} (p.first);
        size_t h2 = std::hash<T2>{} (p.second);
        return h1^h2;
    }
}
class abstract_graph
{
protected:
    int number_vertices;
    list_edges my_list_edges;
    std::vector<std::vector<int>> matrix_adjacency;
    mutable std::map<int, std::set<int>> list_adjacency; // main to store
    std::vector<int> neighbor_matrix;
    std::vector<int> offset_matrix;
public:
    // the constructor
    // but need constructor for matrix, list?
    abstract_graph(){
        std::cout<<" enter number of vertices: \n";
        std::cin>> number_vertices;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    virtual void input_list_of_egdes() = 0;
    virtual void add_edge(int a, int b) = 0;
    virtual void print_list() const = 0;
    virtual void print_matrix() const = 0;
    virtual void print_list_adjacency() const = 0;
    virtual void print_list_edges_from_compact_form() const = 0;
};
class graph_compact : public abstract_graph
{
public:
    void input_list_of_egdes() final{
        std::cout<<"enter list of edges: \n ";
        int a, b;
        while(1)
        {
            std::cin >> a >> b;
            if(a == -1 && b ==-1){
                break;
            }
            if(list_adjacency[a].find(b) == list_adjacency[a].end()){
                list_adjacency[a].insert(b);
                list_adjacency[b].insert(a);
                std::cout <<" succesfully inserted \n";
            } else{
                std::cout<< " this pair has already stored!\n";
            }
        };
    }
    void add_edge(int a, int element)final{        
        if(list_adjacency[a].find(element) == list_adjacency[a].end()){
            list_adjacency[a].insert(element);
        }else{
            std::cout<< "the pair("<<a << ","<< element <<") already existed! \n";
        }        
    }
    // we dont need repeated pair in print!!
    void print_list() const final{
        std::cout<<" the list of pair is: \n";
        std::pair<int, int> pair_print;
        std::unordered_set<std::pair<int, int>, pair_hash> printed_edges;         // we use unordered_set, mean we need to match the whole pair, not just the first key
        for(std::map<int, std::set<int>>::const_iterator element = list_adjacency.cbegin(); element != list_adjacency.cend(); element++){ // element is iterator!!
            for(std::set<int>::const_iterator element_2 = element->second.cbegin() ; element_2 != element->second.end(); element_2 ++){
                if(element->first < *element_2){
                    pair_print = {element->first, *element_2};
                }else {
                    pair_print = {*element_2,element->first};
                }
                if(printed_edges.find(pair_print) == printed_edges.end()){
                    std::cout<<"("<< pair_print.first << "," << pair_print.second<<"); ";
                    printed_edges.insert(pair_print);
                }
            }
            std::cout << std::endl;
        }
        printed_edges.clear();
    }
    void print_matrix() const final{
        std::cout<< " the adjacency matrix is : \n";
        for(int i = 0; i< number_vertices; i++){
            for(int j =0; j< number_vertices; j++){
                if(list_adjacency[i].find(j) != list_adjacency[i].end()){ // error because the operator [] can potentially
                                                                         // insert a new key in map if its not found the key                   
                    std::cout<< " 1 ";
                }else{
                    std::cout<< " 0 ";
                }
            }
            std::cout << std::endl;
        }
    }
    void print_list_adjacency() const final{
        std::cout<<"the list adjacency is :  \n";

        for(std::map<int, std::set<int>>::const_iterator element = list_adjacency.cbegin(); element != list_adjacency.cend(); element++){ // element is iterator!!
            std::cout << element->first << ": ";
            for(std::set<int>::const_iterator element_2 = element->second.cbegin() ; element_2 != element->second.end(); element_2 ++){
                std::cout << *element_2 <<" ";
            }
            std::cout<< "; \n";
        }
    }
    void transform_to_compact_form(){
        offset_matrix.clear();
        neighbor_matrix.clear();
        for(std::map<int, std::set<int>>::const_iterator element = list_adjacency.cbegin(); element != list_adjacency.cend(); element++){ // element is iterator!!
            offset_matrix.push_back(neighbor_matrix.size());
            for(std::set<int>::const_iterator element_2 = element->second.cbegin() ; element_2 != element->second.end(); element_2 ++){
                neighbor_matrix.push_back(*element_2);
            }
        }
        offset_matrix.push_back(neighbor_matrix.size());// this element for iretation
    }
    void print_list_edges_from_compact_form() const final{
        std::cout<<"The compact form is:  \n";
        for(int ver = 0; ver < number_vertices ; ver ++){
            std::cout<< ver <<": ";
            for(int i = offset_matrix[ver]; i< offset_matrix[ver+1]; i++){
                std::cout<< neighbor_matrix[i] << " ";
            }
            std::cout<< std::endl;
        }
    }
    void print_offset_matrix(){
        for(auto& element : offset_matrix){
            std::cout<< element << " ";
        }
    }
};

int main()
{
    graph_compact graph1;
    graph1.input_list_of_egdes();
    graph1.add_edge(2, 4);
    graph1.print_list();
    graph1.print_matrix();
    graph1.print_list_adjacency();
    graph1.transform_to_compact_form();
    graph1.print_list_edges_from_compact_form();
    graph1.print_offset_matrix();
    return 0;
}