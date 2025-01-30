class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Graph ko represent karne ke liye adjacency list banate hain
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1); // Edge ko add karte hain (0-based index)
            adj[e[1] - 1].push_back(e[0] - 1); // Edge ko add karte hain (0-based index)
        }

        // Sab nodes ke colors ko initialize karte hain as -1 (unvisited)
        vector<int> color(n, -1);
        vector<vector<int>> components;

        // Har node ke liye check karte hain agar wo unvisited hai
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                components.emplace_back(); // Naya component banate hain
                if (!dfs(i, 0, adj, color, components.back())) return -1; // DFS se bipartiteness check karte hain
            }
        }

        int maxGroups = 0;
        // Har component ke liye maximum depth find karte hain
        for (const auto& comp : components) {
            maxGroups += bfsMaxDepth(comp, adj);
        }
        return maxGroups; // Maximum groups return karte hain
    }

private:
    // DFS function bipartiteness check karne ke liye
    bool dfs(int node, int col, const vector<vector<int>>& adj, vector<int>& color, vector<int>& comp) {
        color[node] = col; // Node ka color set karte hain
        comp.push_back(node); // Node ko component mein add karte hain
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) return false; // Agar neighbor ka color same hai, false return karte hain
            if (color[neighbor] == -1 && !dfs(neighbor, 1 - col, adj, color, comp)) return false; // DFS se color change karte hain
        }
        return true; // True return karte hain agar bipartite hai
    }

    // BFS function maximum depth find karne ke liye
    int bfsMaxDepth(const vector<int>& comp, const vector<vector<int>>& adj) {
        int maxDepth = 0;
        for (int start : comp) {
            vector<int> depth(adj.size(), -1);
            vector<int> queue = {start};
            depth[start] = 0;
            for (size_t i = 0; i < queue.size(); ++i) {
                int node = queue[i];
                for (int neighbor : adj[node]) {
                    if (depth[neighbor] == -1) {
                        depth[neighbor] = depth[node] + 1; // Depth increment karte hain
                        queue.push_back(neighbor); // Queue mein neighbor ko add karte hain
                    }
                }
            }
            maxDepth = max(maxDepth, *max_element(depth.begin(), depth.end())); // Maximum depth ko update karte hain
        }
        return maxDepth + 1; // Total groups ka count return karte hain
    }
};