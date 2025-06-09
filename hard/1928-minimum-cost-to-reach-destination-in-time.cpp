#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INF));
        dist[0][0] = passingFees[0];
        using State = tuple<int, int, int>; // cost, time, node
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(passingFees[0], 0, 0);
        
        while (!pq.empty()) {
            auto [cost, time, u] = pq.top();
            pq.pop();
            
            if (u == n - 1) {
                return cost;
            }
            
            if (cost > dist[u][time]) {
                continue;
            }
            
            for (auto& [v, t_edge] : adj[u]) {
                int new_time = time + t_edge;
                if (new_time > maxTime) {
                    continue;
                }
                int new_cost = cost + passingFees[v];
                if (new_cost < dist[v][new_time]) {
                    dist[v][new_time] = new_cost;
                    pq.emplace(new_cost, new_time, v);
                }
            }
        }
        
        return -1;
    }
};