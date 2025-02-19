var getHappyString = function(n, k) {
    let n2 = n;  // n2 ko original n ke equal rakhte hain

    function dfs(prefix, n, k) {
        if (n === 0) return prefix;  // Agar n 0 hai to prefix return karte hain (base case)
        for (let c of ['a', 'b', 'c']) {  // Loop karte hain 'a', 'b', aur 'c' ke characters pe
            if (prefix.length > 0 && c === prefix[prefix.length - 1]) continue;  // Agar consecutive same characters hain to skip karte hain
            let cnt = 2 ** (n2 - prefix.length - 1);  // Valid strings ka count calculate karte hain using powers of 2
            if (cnt >= k) return dfs(prefix + c, n - 1, k);  // Agar count k ke barabar ya zyada hai to recursive DFS call karte hain
            else k -= cnt;  // Agar count k se kam hai to k me se count subtract karte hain
        }
        return "";  // Agar koi valid string nahi milti to empty string return karte hain
    }

    return dfs("", n, k);  // Initial call to dfs function with empty prefix
};