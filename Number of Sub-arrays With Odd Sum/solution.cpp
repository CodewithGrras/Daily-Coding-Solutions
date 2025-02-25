
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            long long oddCount = 0, prefixSum = 0;
    
            // Har element ko array mein iterate karna
            for(int a : arr) {
                // Prefix sum ko update karna
                prefixSum += a;
                // Check karna agar prefix sum odd hai
                oddCount += prefixSum % 2;
            }
    
            // Total odd count ko calculate karna
            oddCount += (arr.size() - oddCount) * oddCount;
    
            // Answer ko modulo 1'000'000'007 ke saath return karna
            return oddCount % 1'000'000'007;
        }
    };
    