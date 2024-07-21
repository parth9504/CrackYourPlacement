class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);
        int sum = 0;
        // Start with node 0, weight 0
        pq.push({0, 0});
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visited[node] == 1) continue;

            // Add the edge's weight to the sum
            sum += wt;
            visited[node] = 1;

            // Visit all adjacent vertices
            for (auto& it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
    }
};
