class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x = -1; // x ko -1 se initialize karte hain, jo pehle mismatch index ko track karega

        // s1 ke har character ko s2 ke corresponding character se compare karte hain
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) { // agar characters match nahi karte
                if (x == -1) {
                    x = i; // agar pehla mismatch hai, x ko current index pe set karte hain
                } else {
                    // agar dusra mismatch hai, to swap karte hain characters ko
                    swap(s1[i], s1[x]);

                    // swap ke baad check karte hain ki kya s1 aur s2 equal hain
                    return s1 == s2;
                }
            }
        }

        // agar koi mismatch nahi mila, to check karte hain ki kya s1 aur s2 already equal hain
        return s1 == s2;
    }
};