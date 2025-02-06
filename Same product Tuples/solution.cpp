#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Ek hashmap (unordered_map) banate hain jo product counts ko store karega
        unordered_map<int, int> mp;
        // ans variable ko 0 se initialize karte hain jo valid tuples ka count store karega
        int ans = 0, n = nums.size();

        // Pehla loop: Har element ke liye iterate karte hain
        for (int i = 0; i < n; i++)
            // Dusra loop: Current element ke baad ke elements ke liye iterate karte hain
            for (int j = i + 1; j < n; j++) {
                // Pair ka product calculate karte hain
                int product = nums[i] * nums[j];

                // Agar product hashmap mein pehle se exist karta hai,
                // toh ans ko update karte hain with 8 * frequency of that product
                ans += 8 * mp[product];

                // Product ko hashmap mein update karte hain
                // Agar pehle se nahi hai toh 1 set karte hain, aur agar hai toh +1 badhate hain
                mp[product]++;
            }

        // Final result return karte hain
        return ans;
    }
};