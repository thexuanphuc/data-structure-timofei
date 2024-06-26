#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// using namespace std;

const int INF = 10000;

int heldKarp(const std::vector<std::vector<int>>& dist) {
    int n = dist.size();
    std::vector<int> series (n, -1);
    int END_STATE = (1 << n) - 1;

    // memoization table to store the minimum cost of visiting all nodes in a subset
    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, INF));
    
    // Base case: starting from the first city
    dp[0][0] = 0;
    series[0] = 1;


    // Iterate over all subsets of the set of cities
    for (int subset = 1; subset <= END_STATE; subset += 1) {
        for (int next = 1; next < n; ++next) {
            if ((subset & (1 << next)) == 0) continue;

            int subsetWithoutNext = subset ^ (1 << next);
            for (int end = 0; end < n; ++end) {
                if (end == next || (subset & (1 << end)) == 0) continue;
                

                if(dp[next][subset] > dp[end][subsetWithoutNext] + dist[end][next]){
                    int b = dp[end][subsetWithoutNext] + dist[end][next];
                    dp[next][subset] = b;
                    series[next] = end;
                    std::cout<< "print1";
                }
            }
        }
    }

    // Calculate the minimum cost to return to the starting city
    int minCost = 10000;
    for (int i = 1; i < n; ++i) {
        if(minCost > dp[i][END_STATE] + dist[i][0]){
            minCost = dp[i][END_STATE] + dist[i][0];
            series[END_STATE] = n+1;
        }

    }
    int k = n+1;
    for(int i = 0; i <= n+1; i++){
        std::cout<< i <<":"<< series[k] << "\t";
        k = series[k];
    }
    std::cout<<std::endl;

    return minCost;
}

int main() {
    // Example adjacency matrix for the distances between the cities
     std::vector<std::vector<int>> dist = {
        {0, 3, 6, 9, 11, 14, 12, 15, 6, 1, 2, 2, 3, 9, 11, 19, 3},
        {3, 0, 3, 6, 7, 10, 8, 5, 3, 2, 3, 3, 4, 10, 12, 15, 4},
        {6, 3, 0, 3, 5, 8, 6, 4, 2, 5, 6, 6, 7, 13, 15, 13, 7},
        {9, 6, 3, 0, 2, 5, 3, 6, 5, 8, 9, 9, 10, 16, 18, 10, 10},
        {11, 7, 5, 2, 0, 3, 1, 4, 4, 9, 9, 10, 10, 16, 18, 8, 11},
        {14, 10, 8, 5, 3, 0, 4, 7, 7, 12, 12, 13, 13, 19, 21, 11, 14},
        {12, 8, 6, 3, 1, 4, 0, 3, 5, 10, 8, 11, 9, 15, 16, 7, 12},
        {15, 5, 4, 6, 4, 7, 3, 0, 2, 6, 5, 7, 6, 12, 14, 10, 8},
        {6, 3, 2, 5, 4, 7, 5, 2, 0, 5, 6, 6, 7, 13, 15, 12, 7},
        {1, 2, 5, 8, 9, 12, 10, 6, 5, 0, 1, 1, 2, 8, 10, 16, 2},
        {2, 3, 6, 9, 9, 12, 8, 5, 6, 1, 0, 2, 1, 7, 9, 15, 3},
        {2, 3, 6, 9, 10, 13, 11, 7, 6, 1, 2, 0, 3, 9, 11, 17, 3},
        {3, 4, 7, 10, 10, 13, 9, 6, 7, 2, 1, 3, 0, 6, 8, 16, 4},
        {9, 10, 13, 16, 16, 19, 15, 12, 13, 8, 7, 9, 6, 0, 14, 22, 10},
        {11, 12, 15, 18, 18, 21, 16, 14, 15, 10, 9, 11, 8, 14, 0, 9, 12},
        {19, 15, 13, 10, 8, 11, 7, 10, 12, 16, 15, 17, 16, 22, 9, 0, 18},
        {3, 4, 7, 10, 11, 14, 12, 8, 7, 2, 3, 3, 4, 10, 12, 18, 0}
    };

    int minTourCost = heldKarp(dist);
    std::cout << "The minimum cost of the tour from 0 to 0 is: " << minTourCost << std::endl;

    return 0;
}

