var queryResults = function(limit, queries) {
    // `ball` map har ball ke current color ko track karta hai
    const ball = new Map(),
          // `color` map har color ka frequency track karta hai
          color = new Map(),
          // `ans` array result ko store karega
          ans = [];

    let distinct = 0; // Distinct colors ka count

    for (const [pos, c] of queries) { // Har query ko process karo
        if (ball.has(pos)) { // Agar ball `pos` already color hai
            let cnt = color.get(ball.get(pos)) - 1; // Purane color ka count decrement karo
            if (cnt === 0) {
                color.delete(ball.get(pos)); // Agar count zero ho gaya to us color ko delete karo
                distinct--; // Distinct color ka count decrement karo
            } else {
                color.set(ball.get(pos), cnt); // Nahi to updated count set karo
            }
        }

        ball.set(pos, c); // Ball `pos` ko naya color `c` assign karo
        let cnt = (color.get(c) || 0) + 1; // Naye color `c` ka count increment karo
        color.set(c, cnt); // Updated count set karo
        if (cnt === 1) distinct++; // Agar naye color ka count 1 hai to distinct color ka count increment karo

        ans.push(distinct); // Result array mein distinct color count add karo
    }

    return ans; // Final result return karo
};