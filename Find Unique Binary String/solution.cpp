class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string ans = string(nums.size(), '0');  // "000...0" se shuru karo
    
            if(find(nums.begin(), nums.end(), ans) == nums.end()) return ans;  // Check karo agar yeh already work karta hai
    
            for(int i = 0; i < nums.size(); i++) {
                ans[i] = '1';  // Ek bit ko flip karo '1' mein
                if(find(nums.begin(), nums.end(), ans) == nums.end())
                    return ans;  // Agar yeh valid hai, return kar do
                ans[i] = '0';  // Agar valid nahi hai toh wapas '0' kar do
            }
            return ans;  // Fallback case
        }
    };