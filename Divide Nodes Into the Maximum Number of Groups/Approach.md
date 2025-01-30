**Problem Statement**
_____________________

Aapko ek positive integer n diya gaya hai jo ek undirected graph mein nodes ke number ko represent karta hai. Nodes ko 1 se n tak label kiya gaya hai.

Aapko ek 2D integer array edges bhi diya gaya hai, jahan edges[i] = [ai, bi] indicate karta hai ki nodes ai aur bi ke beech ek bidirectional edge hai. Yeh dhyaan rakhiye ki diya gaya graph disconnnected bhi ho sakta hai.

Objective:
Aapko nodes ko m groups (1-indexed) mein divide karna hai, jahan:

Har node graph mein exactly ek group ko belong karti hai.

Har pair of nodes jo edge [ai, bi] se connected hain, agar ai group x mein belong karti hai aur bi group y mein belong karti hai, to |y - x| = 1 hona chahiye.

Aapko maximum groups (m) return karne hain jinme aap nodes ko divide kar sakte hain. Agar given conditions ke sath grouping possible nahi hai, to -1 return karna hai.

Example Explanation:
Example 1:
Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]] Output: 4

Node 5 ko first group mein add karte hain.

Node 1 ko second group mein add karte hain.

Nodes 2 aur 4 ko third group mein add karte hain.

Nodes 3 aur 6 ko fourth group mein add karte hain. Is tarah se har edge ka condition satisfy hota hai. Agar fifth group create karte hain aur kisi bhi node ko third ya fourth group se fifth group mein move karte hain, to kam se kam ek edge unsatisfied rahegi.

Example 2:
Input: n = 3, edges = [[1,2],[2,3],[3,1]] Output: -1

Agar hum node 1 ko first group mein, node 2 ko second group mein aur node 3 ko third group mein add karte hain to pehli do edges satisfy hoti hain, lekin third edge unsatisfied rahegi.

Iska matlab hai ki koi grouping possible nahi hai jo conditions ko satisfy kar sake.

Constraints:
1 <= n <= 500

1 <= edges.length <= 104

edges[i].length == 2

1 <= ai, bi <= n

ai != bi

Maximum ek edge ho sakti hai kisi bhi pair of vertices ke beech.

__________________________________________________________________________________________________

**INTUITION**
------------
Is problem mein humein nodes ko aise groups mein divide karna hai ki jo nodes connected hain, woh consecutive groups mein belong karein. Yeh bipartite graph structure ki taraf hint karta hai jahan nodes ko alternating colors (0 aur 1) assign karte hain. Agar graph mein odd-length cycles hoti hain, to nodes ko required conditions ke sath divide karna impossible hota hai.

**APPROACH**
------------
Graph Construction Build an adjacency list from the given edges. Check Bipartiteness using DFS If a node is unvisited, start a DFS to assign colors (0 or 1). If a conflict arises (same color assigned to adjacent nodes), return −1. Find Maximum Depth in Each Component using BFS For each connected component, perform BFS from each node to determine the maximum depth. The largestdepth found across all BFS runs is the number of groups for that component. Sum the Maximum Depths The sum of the depths across all connected components gives the final answer.

___________________________________________________________________________________________________

**COMPLEXITY**
--------------
Graph Construction Complexity:
Graph Construction: Graph ko construct karne mein nodes aur edges ko add karna include hota hai. Yani, agar n nodes aur m edges hain, to graph construct karne ki complexity O(n + m) hoti hai.

Explanation: Har node aur edge ko ek baar process karte hain, isliye overall time complexity O(n + m) hoti hai.

DFS for Bipartiteness Check:
DFS (Depth-First Search): Graph ko bipartite check karne ke liye DFS algorithm use hota hai. Is process ki complexity bhi O(n + m) hoti hai.

Explanation: DFS har node aur edge ko ek baar traverse karta hai, jisme nodes aur edges ko visit karte hain. Isi liye complexity O(n + m) hoti hai.

BFS for Maximum Depth:

BFS (Breadth-First Search): Graph ke har connected component mein maximum depth find karne ke liye BFS algorithm use hota hai. Iski complexity bhi O(n + m) hoti hai.

Explanation: Har BFS operation graph ke sabhi edges aur nodes ko ek baar traverse karta hai. Jab hum BFS ko har node se perform karte hain, to har edge component mein sirf ek baar visit hota hai, isliye overall complexity O(n + m) hoti hai.

Note:
BFS Traversal: Har BFS operation graph ke edges aur nodes ko traverse karta hai, lekin har edge sirf ek baar visit hota hai har component mein.

Explanation: Isliye, BFS ki complexity har component ke liye O(n + m) hi rehti hai, jo puri graph ke liye bhi O(n + m) hoti hai.

Overall Complexity:
Total Complexity: Graph construction, DFS for bipartiteness check, aur BFS for maximum depth sabka combined complexity O(n + m) hota hai.

Explanation: Sabhi individual operations ka complexity O(n + m) hai, isliye overall complexity bhi O(n + m) hi rehti hai.

__________________________________________________________________________________________________

**How to Proceed !!**

Graph Construction:

Pehle graph ko adjacency list ke form mein banate hain. Har node ke neighbors ko store karte hain taki unhe access karna easy ho.

DFS for Bipartiteness Check:

Har node ka color set karte hain (0 ya 1) to check whether the graph is bipartite.

DFS algorithm use karke check karte hain ki koi odd-length cycle to nahi hai. Agar aisi cycle milti hai to graph bipartite nahi hai aur solution possible nahi hai, return -1.

Collecting Connected Components:

DFS se connected components ko collect karte hain. Har component ko ek separate list mein store karte hain.

BFS for Maximum Depth:

Har connected component ke nodes ki maximum depth find karte hain using BFS.

BFS traversal ka use karke sabse door nodes ko find karte hain aur depth ko update karte hain.

Har component ki maximum depth find karne ke baad, us depth ko total groups mein add kar dete hain.

___________________________________________________________________________________________________

                            Thanks for your Support :)