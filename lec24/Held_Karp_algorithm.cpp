/*we still can use travelling salemans problem if we equivalent
all nondefined edge to infinity. then apply algorithm to find
shortest path in graph to guarantee triangle triangle inequality before held karp
-> then we will have a new completed graph, in that the path
 the shortest path through others note is save*/

/*2 problem
1) find the shortest path between each pair of note floy_warshall
2) solve PTD problem, probaly using Held Karp  */
#include "graph.hpp"

/* idea: for all notes that are not adjacent, set weight to inf,
iterate through all pair of note, replace path between them with smaller path
time comlexity O(v^3)
space complexity O(v^2) -> if we only want to track the value shortest path*/
std::vector<int> floy_warshall(const  graph_model& graph, vector<std::vector<int>>& floy_weigh){
    floy_weigh = graph.matrix_weigh;
    // std::vector<std::vector<int>> pre_note (graph.num_ver, std::vector<int> (graph.num_ver, -1));
    std::vector<int> pre_note(graph.num_ver , -1);
    for(int i = 0; 0 < graph.num_ver; i++){
        if(floy_weigh[i][i] == -1){
            flor_weigh[i][i] = 0;
        }
        for(int j = 0; j< graph.num_ver; j++){
            if (floy_weigh[i][j] == -1) {
                floy_weigh[i][j] == 10000;
            }else pre_note[j] = i;
        }
    }

    // iterative through graph
    for(int i = 0; i < graph.num_ver; i++){
        for(int j = 0; j < graph.num_ver; j++){
            for(int k = 0; k < graph.num_ver; k++){
                if(floy_weigh[i][j] > floy_weigh[i][k] + floy_weigh[k][j]){
                    floy_weigh[i][j] = floy_weigh[i][k] + floy_weigh[k][j];
                    pre_note[j] = k;
                    pre_note[k] = i;
                }
            }
        }
    }

    // print out the path that we replaced
        // for (int i = 0; i < graph.num_ver; i++){
        //     for (int j = 0; j < graph.num_ver; j++){
        //         std::cout<< pre_note[j] << "\t";
        //     }
        //     std::cout<< std::endl;
        // }
    return pre_note;
}

/* goal vertex_start -> vertex_end(==vertex_start)
+idea: using dynamic programmning to go from vertex_start -> vertex_end (because 
if the graph is directive, then DP only know the cost along that its executed, not the path forward)
time complexity O(v^2 * 2^n)*/ 
void held_karp(const  graph_model& graph, vector<std::vector<int>> weigh_max, int start){
    
    // terminal cost = cost directly from vertex_start to vertex i
    // size of siries_ver is one now
    std::vector<int>  cost(graph.num_ver, 1000);
    std::vector<std::vector<int>> series_ver (graph.num_ver, std::vector<int> (start)); // initialize only with one element on each vector

    // initialize the cost
    for(int i = 0; i< graph.num_ver; i++){
        cost[i] = weigh_max[start][graph.num_ver];
        // series_ver[i] = start;
    }
    
    // loop untill we need the start vertex again, means after the size i of series reached N+1
    for(int i = 1; i <= graph.num_ver + 1; i++){
        // loop for each vertex
        for (int j = 0; j< graph.num_ver; j++){
            //find and update min cost from A to each vertex
            
                cost[j] = weigh_max[start][graph.num_ver];
                series_ver[j].push_back(previous_vertex);

        }
    }

    return cost;
}

int main(){
    graph_model my_graph;
    my_graph.input_list_of_egdes();
    my_graph.print_list_adjacency();
    my_graph.print_matrix_weight();
    vector<std::vector<int>> new_weigh;
    // replace_inf(mygraph);
    floy_warshall(my_graph,new_weigh);
    std::cout <<"enter first vertex: \n";
    char ch;
    while((ch = std::cin.get()) != '\n'){}
    int home_town;
    std::cin>> home_town;
    std::cout << home_town << std::endl;
    
    // in this, we compare, if using the replaced path, we need to print these note we go through
    held_karp(my_graph, new_weigh, home_town);

    
    return 0;
}
