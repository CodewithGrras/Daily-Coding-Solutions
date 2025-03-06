function findRepeatingAndMissingNumbers(grid) {
    const n = grid.length;  // size of the grid
    const max_value = n * n;

    // Initialize the count array
    const count = new Array(max_value + 1).fill(0);

    // Count occurrences of each number in the grid
    for (let row of grid) {
        for (let num of row) {
            count[num]++;
        }
    }

    // Identify the repeating and missing numbers
    let repeating = -1, missing = -1;
    for (let num = 1; num <= max_value; num++) {
        if (count[num] === 2) {
            repeating = num;
        } else if (count[num] === 0) {
            missing = num;
        }
    }

    return [repeating, missing];
}

// Example usage
const grid1 = [[1, 3], [2, 2]];
console.log(findRepeatingAndMissingNumbers(grid1));  // Output: [2, 4]

const grid2 = [[9, 1, 7], [8, 9, 2], [3, 4, 6]];
console.log(findRepeatingAndMissingNumbers(grid2));  // Output: [9, 5]