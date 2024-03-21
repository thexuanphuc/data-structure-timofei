#include "graph.hpp"
void algo_bfs(const graph_model& graph, std::queue<int>& q){// dont use recursive, just the property of queue
    graph.marked[q.front()] =  true;
    while(! q.empty()){
        int cur =  q.front();
        std::cout<< cur << "\t";    
        q.pop();
        for(auto& ver : graph.list_adjacency.at(cur)){
            if(graph.marked[ver] == false){
                graph.marked[ver] = true;
                q.push(ver);
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
    char ch;
    while((ch = std::cin.get()) != '\n'){
        std::cout<< static_cast<char>(ch);
    }
    int first_vertex;
    std::cin>>first_vertex;
    std::cout<< first_vertex<<std::endl;
    std::queue<int> line_up;
    line_up.push(first_vertex);
    //algo_dfs(my_graph, first_vertex);
    algo_bfs(my_graph, line_up);
    std::cout<< std::endl;
    return 0;
}