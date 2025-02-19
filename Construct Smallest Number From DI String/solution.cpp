#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string smallestNumber(string pattern) {
    int n = pattern.length();
    vector<char> result;
    stack<int> st;

    // 1 se n+1 tak ke digits loop ke through add karte hain
    for (int i = 0; i <= n; i++) {
        // Digit ko stack me push karte hain
        st.push(i + 1);

        // Agar pattern 'I' hai ya loop khatam hone wala hai
        if (i == n || pattern[i] == 'I') {
            // Stack se elements pop karke result me add karte hain
            while (!st.empty()) {
                result.push_back('0' + st.top());
                st.pop();
            }
        }
    }

    // Result ko string me convert karte hain aur return karte hain
    return string(result.begin(), result.end());
}

int main() {
    // Example 1
    string pattern1 = "IIIDIDDD";
    cout << smallestNumber(pattern1) << endl; // Output: "123549876"

    // Example 2
    string pattern2 = "DDD";
    cout << smallestNumber(pattern2) << endl; // Output: "4321"

    return 0;
}