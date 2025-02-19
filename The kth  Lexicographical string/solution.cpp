class Solution {
    int n2;  // n2 ko original n ke equal rakhte hain
    string dfs(string prefix, int n, int k) {
        if (n == 0)  // Base case: Agar n 0 ho gaya toh prefix return karte hain
            return prefix;
        for (char c = 'a'; c <= 'c'; c++) {  // 'a', 'b', 'c' ke characters loop karte hain
            if (!prefix.empty() && c == prefix.back())  // Agar consecutive same characters hain toh skip karte hain
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));  // Valid strings ka count calculate karte hain using powers of 2
            if (cnt >= k)  // Agar count k ke barabar ya zyada hai toh recursive DFS call karte hain
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;  // Agar count k se kam hai toh k me se count subtract karte hain
        }
        return "";  // Agar koi valid string nahi milti toh empty string return karte hain
    }
public:
    string getHappyString(int n, int k) {
        n2 = n;  // n2 ko original n ke equal rakhte hain
        return dfs("", n, k);  // Initial call to DFS function with empty prefix
    }
};