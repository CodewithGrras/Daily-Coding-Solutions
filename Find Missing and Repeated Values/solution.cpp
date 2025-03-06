#include <iostream>
#include <vector>
using namespace std;

vector<int> findRepeatingAndMissingNumbers(vector<vector<int>>& grid) {
    int n = grid.size();  // size of the grid
    int max_value = n * n;

    // Initialize the count array
    vector<int> count(max_value + 1, 0);

    // Count occurrences of each number in the grid
    for (const auto& row : grid) {
        for (int num : row) {
            count[num]++;
        }
    }

    // Identify the repeating and missing numbers
    int repeating = -1, missing = -1;
    for (int num = 1; num <= max_value; num++) {
        if (count[num] == 2) {
            repeating = num;
        } else if (count[num] == 0) {
            missing = num;
        }
    }

    return {repeating, missing};
}

int main() {
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<int> result1 = findRepeatingAndMissingNumbers(grid1);
    cout << "Repeated: " << result1[0] << ", Missing: " << result1[1] << endl;  // Output: 2, 4

    vector<vector<int>> grid2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> result2 = findRepeatingAndMissingNumbers(grid2);
    cout << "Repeated: " << result2[0] << ", Missing: " << result2[1] << endl;  // Output: 9, 5