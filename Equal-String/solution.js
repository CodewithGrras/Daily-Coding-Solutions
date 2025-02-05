var areAlmostEqual = function(s1, s2) {
    // s1 ko array mein convert karte hain
    let arr = [...s1], x = -1; // x variable -1 se initialize karte hain

    // s1 ke har character ko compare karte hain s2 ke corresponding character se
    for (let i = 0; i < s1.length; i++) {
        if (arr[i] !== s2[i]) { // agar characters match nahi karte
            if (x === -1) x = i; // agar pehla mismatch hai, x ko current index pe set karte hain
            else {
                // agar dusra mismatch hai, to swap karte hain characters
                [arr[i], arr[x]] = [arr[x], arr[i]];

                // swap ke baad check karte hain ki arr s2 ke barabar hai ya nahi
                return arr.join('') === s2;
            }
        }
    }

    // agar koi mismatch nahi mila, to check karte hain ki s1 aur s2 already equal hain
    return s1 === s2;
};