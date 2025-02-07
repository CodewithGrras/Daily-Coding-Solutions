class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            // `ball` map har ball ka current color track karta hai
            unordered_map<int, int> ball,
            // `color` map har color ka frequency track karta hai
                                   color;
            // `ans` vector result ko store karega
            vector<int> ans;
            // `ans` vector ka size reserve karna queries ke size ke equal
            ans.reserve(queries.size());
            // Distinct colors ka count
            int distinct = 0;
    
            for (auto &q : queries) { // Har query ko process karo
                int pos = q[0], c = q[1]; // Query ke position aur color ko assign karo
    
                if (ball.count(pos)) // Agar ball already colored hai
                    if (--color[ball[pos]] == 0) { // Purane color ka count decrement karo
                        color.erase(ball[pos]); // Agar count zero ho gaya to us color ko remove karo
                        distinct--; // Distinct color ka count decrement karo
                    }
                // Ball ko naya color do aur `ball` map update karo
                ball[pos] = c;
                // Naye color ka count increment karo
                if (++color[c] == 1)
                    distinct++; // Agar naye color ka count 1 hai to distinct color ka count increment karo
    
                // Result vector mein distinct colors count add karo
                ans.push_back(distinct);
            }
    
            // Final result return karo
            return ans;
        }
    };