#include "graph.hpp"
void algo_dfs(const graph_model& graph,const int cur){ // we need to use reference to avoid copying element
                                                        // while the graph shouldnt be changed
    graph.marked[cur] = true;   // need to handle case of std::out_of_range, it already stop the program!! 
    std::cout<< cur << "\t";
    if(not graph.list_adjacency.at(cur).empty()){ // this at function already return a reference to the mapped value, in our case, its the set already
        for(auto& ver : graph.list_adjacency.at(cur)){
        //auto set_1 = graph.list_adjacency;
        //for(std::set<int>::iterator &ver = set_1.cbegin(); ver  != graph.list_adjacency.at(cur).cend(); ver ++){// cant use auto *ver = ---long, not a named variable----.begin()
            if(graph.marked[ver] == false){ 
                algo_dfs(graph, ver);
            }
        }
    }
}
int main(){
    graph_model my_graph;
    my_graph.input_list_of_egdes();
    my_graph.print_list_adjacency();
    my_graph.print_matrix_weight();
    std::cout<< "enter the first vertex: \n";
    int first_vertex;
    std::cin>>first_vertex;
    algo_dfs(my_graph, first_vertex);
    std::cout<< std::endl;
    return 0;
}