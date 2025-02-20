class Solution {
    findDifferentBinaryString(nums) {
        let ans = '0'.repeat(nums.length);  // "000...0" se shuru karo

        if (!nums.includes(ans)) return ans;  // Check karo agar yeh already work karta hai

        for (let i = 0; i < nums.length; i++) {
            ans = ans.substring(0, i) + '1' + ans.substring(i + 1);  // Ek bit ko flip karo '1' mein
            if (!nums.includes(ans))
                return ans;  // Agar yeh valid hai, return kar do
            ans = ans.substring(0, i) + '0' + ans.substring(i + 1);  // Agar valid nahi hai toh wapas '0' kar do
        }
        return ans;  // Fallback case
    }
}