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
std::vector<int> floy_warshall(const  graph_model& graph, std::vector<std::vector<int>>& floy_weigh){
    floy_weigh = graph.matrix_weigh;
   
    // std::vector<std::vector<int>> pre_note (graph.num_ver, std::vector<int> (graph.num_ver, -1));
    
    // prepare for floy warshall
    std::vector<int> pre_note(graph.num_ver , -1);
    for(int i = 0; i < graph.num_ver; i++){
        if(floy_weigh[i][i] == -1){
            floy_weigh[i][i] = 0;
        }
        for(int j = 0; j< graph.num_ver; j++){
            if (floy_weigh[i][j] == -1) {
                floy_weigh[i][j] = 1000000;
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
    
    
    return pre_note; // note that we updated to new weight value already
}

/* goal vertex_start -> vertex_end(==vertex_start)
+idea: using dynamic programmning to go from vertex_start -> vertex_end (because 
if the graph is directive, then DP only know the cost along that its executed, not the path forward)
time complexity O(v^2 * 2^n)*/
void held_karp(const  graph_model& graph, std::vector<std::vector<int>> weigh_max, int start){
    
    // terminal cost = cost directly from vertex_start to vertex i
    // size of series vertex is one now
    std::vector<int>  cost(graph.num_ver, 1000); // the min cost from start vertex to any others i-vertex
    std::vector<std::list<int>> series_ver (graph.num_ver, std::list<int> (1, start)); // initialize only with one element on each vector

    // initialize the cost go back from start to i
    for(int i = 0; i< graph.num_ver; i++){
        cost[i] = weigh_max[start][i];
        // series_ver[i] = start; // already have the first vertex when initialized
    }
    
    // loop untill we reach all others vertex, mean the number vertices in series reach n
    for(int n = 1; n < graph.num_ver; n++){

        // loop for each vertex, from start to all others vertices j, after go through n
        for (int j = 0; j< graph.num_ver; j++){
            if(j != start){

                int d = 0;  // d != j (because we need to extend the visited list)
                            // d != start (because if we return to start, the number of vertices we went through is not n)
                            // d from the list 
                cost[j] = cost[d] + weigh_max[d][j];
                // relaxation, get min cost(start->j) by checking all the vertex
                for(int k = 1; k < graph.num_ver; k++){
                    if(cost[j] < cost[k] + weigh_max[k][j]){
                        d = k;
                        cost[j] = cost[d] + weigh_max[d][j];
                    } 
                }
                series_ver[j].assign(series_ver[d].begin(), series_ver[d].end());
                series_ver[j].push_back(j);
            }
        }
    
    }
    
    // // now from all vertex we go back to vertex start
    // i = graph.num_ver + 1

    // return cost;
}

int main(){
    graph_model my_graph;
    my_graph.input_list_of_egdes();
    my_graph.print_list_adjacency();
    my_graph.print_matrix_weight();
    std::vector<std::vector<int>> new_weigh;
    // replace_inf(mygraph);
    floy_warshall(my_graph, new_weigh);
    for(int i = 0; i< my_graph.num_ver; i++){
        for(int j = 0; j < my_graph.num_ver; j++){
            std::cout<< new_weigh[i][j] <<"\t";
        }
        std::cout<< std::endl;
    }
    std::cout <<"enter first vertex: \n";
    char ch;
    while((ch = std::cin.get()) != '\n'){}
    int home_town;
    std::cin>> home_town;
    std::cout << home_town << std::endl;
    
    // in this, we compare, if using the replaced path, we need to print these note we go through
    // held_karp(my_graph, new_weigh, home_town);

    
    return 0;
}
// test git log
