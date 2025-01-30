class Solution {
    magnificentSets(n, edges) {
        // Graph ko represent karne ke liye adjacency list banate hain
        const adj = Array.from({ length: n }, () => []);

        for (const [a, b] of edges) {
            adj[a - 1].push(b - 1);
            adj[b - 1].push(a - 1);
        }

        const color = Array(n).fill(-1);
        const components = [];

        for (let i = 0; i < n; ++i) {
            if (color[i] === -1) {
                components.push([]);
                if (!this.dfs(i, 0, adj, color, components[components.length - 1])) return -1;
            }
        }

        let maxGroups = 0;
        for (const comp of components) {
            maxGroups += this.bfsMaxDepth(comp, adj);
        }

        return maxGroups;
    }

    dfs(node, col, adj, color, comp) {
        color[node] = col;
        comp.push(node);

        for (const neighbor of adj[node]) {
            if (color[neighbor] === col) return false; // Agar neighbor ka color same hai to false return karo
            if (color[neighbor] === -1 && !this.dfs(neighbor, 1 - col, adj, color, comp)) return false; // Agar neighbor unvisited hai to DFS se check karo
        }

        return true;
    }

    bfsMaxDepth(comp, adj) {
        let maxDepth = 0;

        for (const start of comp) {
            const depth = Array(adj.length).fill(-1);
            const queue = [start];
            depth[start] = 0;

            for (let i = 0; i < queue.length; ++i) {
                const node = queue[i];
                for (const neighbor of adj[node]) {
                    if (depth[neighbor] === -1) {
                        depth[neighbor] = depth[node] + 1; // Depth increment karo
                        queue.push(neighbor); // Neighbor ko queue mein add karo
                    }
                }
            }

            maxDepth = Math.max(maxDepth, Math.max(...depth)); // Maximum depth ko update karo
        }

        return maxDepth + 1; // Total groups ka count return karo
    }
}