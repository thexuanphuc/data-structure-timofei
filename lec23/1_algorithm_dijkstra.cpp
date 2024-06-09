//in this lecture realisation algorithm find the shortest path
// (1) dijkstra
// (2) Flog warshall - from all vertices to all others vertices
// (3) Bellman-Ford - from particular vertex to all others vertices
#include <iostream>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <queue>
class graph_model
{
private:
    int num_ver;
    std::map<int, std::set<int>> list_adjacency;// main for storing node and weigh
    std::vector<std::vector<int>> matrix_weigh;
public:
    //the constructor
    graph_model(){
        std::cout<< "enter number of vertices: \n";
        int num;
        std::cin >> num_ver;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        matrix_weigh.resize(num_ver, std::vector<int>(num_ver,-1));
    }
    void input_list_of_egdes();
    void print_list_adjacency() const;
    void print_matrix_weight() const;
    void dijkstra() const;
    std::vector<std::vector<int>> floy_warshall () const;
    std::vector<int> bellman_ford() const;
    void matrix_destructor();
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
        for(auto set_iter = map_iter->second.cbegin(); set_iter != map_iter->second.cend(); set_iter ++){
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
void graph_model::matrix_destructor(){
    matrix_weigh.resize(0);
}
void graph_model::dijkstra() const{
    std::vector<bool> marked_matrix(num_ver, false);
    // matrix with distance and previous vertex
    // 0 is source
    std::vector<std::pair<int, int>> travel_matrix (num_ver, std::pair<int, int> {10000, -1});
    travel_matrix[0] = std::make_pair(0, -1);
    int cur = 0;
    int dist;
    bool flag = false;
    while(! flag){// if the graph is not fully connected, then infinity cycle!!!
        marked_matrix[cur] = true;
        for(int j = 1 ; j < num_ver; j++){
            if(matrix_weigh[cur][j] != -1){
                dist = travel_matrix[cur].first + matrix_weigh[cur][j];
                if(dist < travel_matrix[j].first){
                    travel_matrix[j].first = dist;
                    travel_matrix[j].second = cur;
                }
            }
        }
        flag  = true;
        for(int i = 1 ; i < num_ver; i++){
            flag = flag && marked_matrix[i];
            if((marked_matrix[i] == false) && (travel_matrix[i].first <= dist)){
                dist = travel_matrix[i].first;
                cur = i;
            }
        }
    }
    for(int i = 0; i< num_ver; i++){
        std::cout<< marked_matrix[i] << std::endl;
        std::cout<< i <<" vertex:+dist= "<< travel_matrix[i].first << "; previous vertex: "<< travel_matrix[i].second <<std::endl;
    }
}
std::vector<std::vector<int>> graph_model::floy_warshall() const{
    std::vector<std::vector<int>> floy_weigh(matrix_weigh);
    std::vector<std::vector<int>> previ (num_ver, std::vector<int> (num_ver, -1));
    for(int i = 0; i< num_ver; i++){
        if (floy_weigh[i][i] == -1){
            floy_weigh[i][i] = 0;
        } 
        for (int j = 0; j< num_ver; j++){
            if(floy_weigh[i][j] == -1){
                floy_weigh[i][j] = 1000;
            }else if(floy_weigh[i][j] > 0){
                previ[i][j] = i;
            }
        }
    }
    for(int i = 0; i< num_ver; i++){
        for (int j= 0; j< num_ver; j++){
            for(int k = 0; k< num_ver; k++){
                if(floy_weigh[i][j] > floy_weigh[i][k]+floy_weigh[k][j]){
                    floy_weigh[i][j] = floy_weigh[i][k]+floy_weigh[k][j];
                    previ[i][j] = k;
                }
            }
        }
    }

    for(int i = 0; i< num_ver; i++){
        for (int j = 0; j < num_ver; j++){
            std::cout<< previ[i][j] << "\t";
        }
        std::cout<< std::endl;
    }
    return  previ;   
}
std::vector<int> graph_model::bellman_ford() const {
    std::vector<int> dist(num_ver, 1000);
    std::vector<int> previ(num_ver, -1);
    dist[0] = 0;
    int count = num_ver-1;
    while(count > 0){
        for(int i = 0; i < num_ver; i++ ){
            for(int j = 0; j <num_ver; j++){
                if((matrix_weigh[i][j]!= -1)&& (dist[j] > dist[i]+ matrix_weigh[i][j])){
                    dist[j] = dist[i]+ matrix_weigh[i][j];
                    previ[j] = i;
                }
            }
        }
        count--;
    }
    for(int i = 0; i < num_ver; i++ ){
            for(int j = 0; j <num_ver; j++){
                if((matrix_weigh[i][j]!= -1)&& (dist[j] > dist[i]+ matrix_weigh[i][j])){
                    std::cout<<"this graph have some negative cycle!!!\n";
                }
            }
    }
    for(int i = 0; i < num_ver; i++ ){
        std::cout<<"min path from 0 to "<<i <<" is: "<< dist[i] << std::endl;
        std::cout<< "the actual path are:" ; 
        int cur = i;
        while(previ[cur] != -1){
            std::cout<< cur << "  ";
            cur = previ[cur];
        }
        std::cout<< std::endl;
    }
    return dist;
}
void print_path(int source, int destiny, std::vector<std::vector<int>> previ) {   // this function return path form u to v
    int  v = destiny;
    std::queue<int> path;
    while(previ[source][v] != -1) {
        path.push(v);
        v = previ[source][v];
    }
    path.push(source);
    std::cout<<"the path from "<<source << " to "<< destiny << " is: "<<std::endl;   
    while(path.size() > 0){
        std::cout<< path.front()<<"\t";
        path.pop();
    }
    std::cout<< std::endl;
}

int main(){
    graph_model my_graph;
    my_graph.input_list_of_egdes();
    my_graph.print_list_adjacency();
    my_graph.print_matrix_weight();
    //my_graph.dijkstra();
    //destructor of matrix_weigh
    //print_path(1, 6 , my_graph.floy_warshall());
    my_graph.bellman_ford();
    my_graph.matrix_destructor();
    return 0;
}