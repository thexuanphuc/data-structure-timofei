// this is the header file to define grpah_libarary
// here for this task(broad/deep search), when only use the list adjacency!!!
#ifndef _GRAPH_HPP__
#define _GRAPH_HPP__
#include <iostream>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <queue>
#include <list>

class graph_model
{
public:
    int num_ver;
    std::map<int, std::set<int>> list_adjacency;// main for storing node and weigh
    std::vector<std::vector<int>> matrix_weigh;
    mutable std::vector<int> marked; // this marked value is the mutable, it allows we can change it value, despite declaring const
                                        // the purpose is for caching the caculated value in the implementation details in bfs function
    //the constructor
    graph_model(){
        std::cout<< "enter number of vertices: \n";
        std::cin >> num_ver;
        // practical prefer using vector, not this raw new
        // but the advantage of this new(may be disadvantage) is when created, it is only related to whole application,
        //not only this class, then we can access, change it from outside of class, despite the class we call is const
        //like we pass the reference to particular memory address, are iterating with the memory address, not through the class
        // means the memory allocated on heap is seperated from the class 

        //marked = new bool[num_ver];// we cant use this, it only initialize first element of array
        //std::fill_n( marked, num_ver, false );
        marked.resize(num_ver, false);
        matrix_weigh.resize(num_ver, std::vector<int>(num_ver,-1));
    }
    // this is destructor
    ~graph_model(){
        matrix_weigh.resize(0);
        marked.resize(0);
    }
    void input_list_of_egdes();
    void print_list_adjacency() const;
    void print_matrix_weight() const;
};
void graph_model::input_list_of_egdes(){
    std::cout<<"enter list of edges: \n";
    int a,b, m;
    while (true)
    {
        std::cin >> a>> b>>m;
        if((a == -1 && b == -1) or (std::max(a,b) >= num_ver)){
            break;
        }
        if(a > b){
            std::swap(a,b);
        }
        if(list_adjacency[a].find(b) == list_adjacency[a].end()){
            list_adjacency[a].insert(b);
            list_adjacency[b].insert(a);
            //insert to matrix m
            matrix_weigh[a][b] = m;
            matrix_weigh[b][a] = m;
            std::cout<<" inserted successfully! \n";
        }else{
            std::cout<<" this pair is already existed!\n";
        }
    }
}
void graph_model::print_list_adjacency() const{
    for(auto map_iter = list_adjacency.cbegin(); map_iter != list_adjacency.cend(); ++map_iter){
        std::cout<< map_iter->first << " ";
        for(auto set_iter = map_iter->second.cbegin(); set_iter != map_iter->second.cend(); set_iter ++){// why we cant use auto&
            std::cout<< *set_iter << " ";
        }
        std::cout<< std::endl;
    }
}
void graph_model::print_matrix_weight()const{
    for(int i = 0; i< num_ver; i++){
        for(int j = 0; j < num_ver; j++){
            std::cout<< matrix_weigh[i][j] <<"\t";
        }
        std::cout<< std::endl;
    }
}
#endif //_GRAPH_HPP