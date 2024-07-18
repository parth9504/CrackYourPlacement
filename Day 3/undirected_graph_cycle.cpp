class Solution {
public:
    bool bfs(int src, vector<int> adj[], vector<int>& visited, vector<int>& parent) {
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        parent[src] = -1; // starting node has no parent
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (!visited[it]) { // if not visited
                    q.push(it);
                    visited[it] = 1;
                    parent[it] = node;
                } else if (visited[it] && parent[node] != it) {
                    // if the node is already visited and not the parent of the current node
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> parent(V, -1);
        
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfs(i, adj, visited, parent)) {
                    return true;
                }
            }
        }
        return false;
    }
};
