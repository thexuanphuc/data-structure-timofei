#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const int INF = 1000;

int heldKarp(const vector<vector<int>>& dist) {
    int n = dist.size();
    int END_STATE = (1 << n) - 1;

    // memoization table to store the minimum cost of visiting all nodes in a subset
    vector<vector<int>> dp(n, vector<int>(1 << n, INF));
    
    // Base case: starting from the first city
    dp[0][1] = 0;

    // Iterate over all subsets of the set of cities
    for (int subset = 1; subset <= END_STATE; subset += 2) {
        for (int next = 1; next < n; ++next) {
            if ((subset & (1 << next)) == 0) continue;
            
            int subsetWithoutNext = subset ^ (1 << next);
            std::cout << subsetWithoutNext << std::endl;
            for (int end = 0; end < n; ++end) {
                if (end == next || (subset & (1 << end)) == 0) continue;
                // dp[next][subset] = min(dp[next][subset], dp[end][subsetWithoutNext] + dist[end][next]);
                if(dp[next][subset] >= dp[end][subsetWithoutNext] + dist[end][next]){
                    dp[next][subset] = dp[end][subsetWithoutNext] + dist[end][next];
                }
            }
        }
    }

    // Calculate the minimum cost to return to the starting city
    int minCost = INF;
    for (int i = 1; i < n; ++i) {
        minCost = min(minCost, dp[i][END_STATE] + dist[i][0]);
    }

    return minCost;
}

int main() {
    // Example adjacency matrix for the distances between the cities
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minTourCost = heldKarp(dist);
    cout << "The minimum cost of the tour is: " << minTourCost << endl;

    return 0;
}

