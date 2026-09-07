#include <iostream>
#include <vector>
#include <queue>
#include <climits>  
#include <unordered_map>
using namespace std;

class PrimsAlgo {
    unordered_map<int, vector<pair<int, int>>> adj;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    public:
    PrimsAlgo() {}

    int primsMST(vector<vector<int>>& edges, int V){
        //creating the adj List
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(V, INT_MAX);
        vector<int> MST(V, 0);
        vector<int> parents(V, -1);

        int src = 0;
        dist[src] = 0;
        parents[src] = -1;
        pq.push({0, 0}); //dist, node
        int minCnt = 0;
        while(!pq.empty()){
            auto [w, minNode] = pq.top();
            pq.pop();

            if(MST[minNode] == 1) continue;
            //mark included into MST
            MST[minNode] = 1;
            minCnt += w;

            //explore the neighbours
            for(auto& [nei, d] : adj[minNode]){
                if(MST[nei] == 0 && dist[nei] > d){
                    dist[nei] = d;
                    parents[nei] = minNode;
                    pq.push({d, nei});
                }
            }
        }
        return minCnt;
    }
};