// difinition: the bridge in graph(моста) is an graph edge that is used after dfs
// mean if we delete that edge, the number of connected component in graph increase
#include "graph.hpp"
#include <algorithm>
void algo_dfs(const graph_model& graph,const int cur, int& time, int(& enter)[], int(& ret)[]){ // we need to use reference to avoid copying element
                                                        // while the graph shouldnt be changed
    time = time + 1;
    enter[cur] = time;// the time to compare that have others edge go faster or not
    ret[cur] = time; // the time after recalculating if(we find others route or we expand with recursive dfs) 
    graph.marked[cur] = true;   // need to handle case of std::out_of_range, it already stop the program!! 
    std::cout<< cur << "\t";
    if(not graph.list_adjacency.at(cur).empty()){ // this at function already return a reference to the mapped value, in our case, its the set already
        for(auto& ver : graph.list_adjacency.at(cur)){
        //auto set_1 = graph.list_adjacency;
        //for(std::set<int>::iterator &ver = set_1.cbegin(); ver  != graph.list_adjacency.at(cur).cend(); ver ++){// cant use auto *ver = ---long, not a named variable----.begin()
            if(ver == cur) 
                continue;
            if(graph.marked[ver] == true){// the case that is back edge,we find the shortest time hyerrachy
                                            //others edge with longer time hyerrachy shouldnt involve in our tree
                ret[cur] = std::min(ret[cur], enter[ver]); 
            }
            if(graph.marked[ver] == false){ 
                algo_dfs(graph, ver, time, enter, ret); 
                ret[cur] = std::min(ret[cur], ret[ver]);
            }
            if(ret[ver] > enter[cur]){ 
                std::cout<< "\n the edge ("<< cur << "," << ver <<") is a bridge!\n";
            }else {
                //std::cout<< "the edge ("<< cur << "," << ver <<") is not a bridge!\n";
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
    int enter[15] = {-1};
    int ret[15] = {-1};
    int time  = 0;
    algo_dfs(my_graph, first_vertex, time, enter, ret);// if in grpah have more than one notconnected part, then we need to check all each of them
    std::cout<< std::endl;
    return 0;
}