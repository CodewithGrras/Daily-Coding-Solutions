function smallestNumber(pattern) {
    let n = pattern.length;
    let result = [];
    let stack = [];
  
    // 1 se n+1 tak ke digits loop ke through add karte hain
    for (let i = 0; i <= n; i++) {
      // Digit ko stack me push karte hain
      stack.push(i + 1);
  
      // Agar pattern 'I' hai ya loop khatam hone wala hai
      if (i === n || pattern[i] === 'I') {
        // Stack se elements pop karke result me add karte hain
        while (stack.length > 0) {
          result.push(stack.pop());
        }
      }
    }
  
    // Result ko string me convert karte hain aur return karte hain
    return result.join('');
  }
  
  // Example 1
  let pattern1 = "IIIDIDDD";
  console.log(smallestNumber(pattern1)); // Output: "123549876"
  
  // Example 2
  let pattern2 = "DDD";
  console.log(smallestNumber(pattern2)); // Output: "4321"