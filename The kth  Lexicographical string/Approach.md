PROBLEM STATEMENT
_________________

Ek “happy string” ek aisa string hai jo:

Sirf letters [‘a’, ‘b’, ‘c’] ke set se hi banta hai.

s[i] != s[i + 1] har ek value ke liye from 1 to – 1. (Yeh string 1-indexed hai.)

For example, yeh strings “abc”, “ac”, “b” aur “abcbabcbcb” sab happy strings hain, lekin strings “aa”, “baa” aur “ababbc” happy strings nahi hain.

Ab, do integers n aur k diye gaye hain, to humein list ka consider karna hai jismein sab happy strings of length n lexicographical order mein sorted hain.

Humein is list ka kth string return karna hai ya fir return karna hai empty string agar wahan pe k se kam happy strings of length n hain.

Examples:

Example 1:

Input: n = 1, k = 3

Output: “c”

Explanation: List [“a”, “b”, “c”] contains all happy strings of length 1. Tisra string hai “c”.

Example 2:

Input: n = 1, k = 4

Output: “”

Explanation: Sirf 3 happy strings hain length 1 ke.

Example 3:

Input: n = 3, k = 9

Output: “cab”

Explanation: Total 12 different happy strings of length 3 hain [“aba”, “abc”, “aca”, “acb”, “bab”, “bac”, “bca”, “bcb”, “cab”, “cac”, “cba”, “cbc”]. Aapko 9th string milegi “cab”.

Constraints:

1 <= n <= 10

1 <= k <= 100

Pract


_______________________________________________________________________________________________________

Yeh solution <strong>DFS</strong> (Depth-First Search) ka use karta hai taaki sab possible happy strings generate ki ja sake aur k-th smallest string return ki ja sake:

<strong>DFS Traversal:</strong> DFS use karke recursively sab combinations of happy strings explore karte hain.

<strong> Lexicographical Order:</strong>  Search ko 'a', 'b', aur 'c' se start karte hain taaki order maintain ho.

<strong> String Construction:</strong>  Search ke dauran consecutive same characters avoid kiye jaate hain.

<strong> Efficient Search Pruning:</strong>  Valid strings ki counting har step pe powers of 2 ke use se ki jaati hai. Aur pruning karke unnecessary exploration avoid karte hain based on remaining k.

<strong> DFS over Backtracking:</strong>  DFS ko backtracking ke upar prefer kiya jaata hai kyunki yeh unnecessary exploration eliminate karta hai by counting valid strings har level pe.
_______________________________________________________________________________________________________

<strong> Approach</strong> 
<br>
<strong> Time Complexity: O(3^n)</strong>  — Without pruning, sab possible combinations generate kiye jaate hain. Matlab, har character ke liye 3 choices (a, b, c). Lekin pruning se effective search reduce ho jaata hai kyunki kuch paths reject kar diye jaate hain jo valid happy strings nahi ban sakte.

<strong> Space Complexity: O(n)</strong>  — Yeh space mainly recursion stack aur prefix string ke kaaran use hoti hai. Recursion stack mein n levels hoti hain kyunki maximum n length ka string generate ho raha hai.