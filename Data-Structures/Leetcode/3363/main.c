int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int ans = 0;
    int n = fruitsSize;

    /* Adds fruits collected by the child starting from (0,0)
    on the main diagonal (0,0) -> (1,1) -> ... -> (n-1,n-1). */
    for (int i = 0; i < n; ++i) ans += fruits[i][i];

    /*Local helper function to calculate the maximum fruits
     collected by one of the other children, given the current state
     of the fruits grid, works for both (0, n-1) and (n-1, 0). */
    int dp() {
        // prev[j] = best fruits collected so far if the child is in column j of the current row
        // curr[j] = updated DP values for the next row
        int* prev = malloc(sizeof(int) * n);
        int* curr = malloc(sizeof(int) * n);

        // Initialize DP with impossible values (INT_MIN)
        for (int i = 0; i < n; ++i) prev[i] = INT_MIN;

        // Base case: starting point for the child at (0, n-1)
        prev[n - 1] = fruits[0][n - 1];

        // Process rows from 1 to n-2 (last move will land at (n-1, n-1))
        for (int i = 1; i < n - 1; ++i) {
            // Reset current row DP values
            for (int j = 0; j < n; ++j) curr[j] = INT_MIN;

            // Column start limit: child can’t enter diagonal rooms too early
            int startCol = (n - 1 - i > i + 1 ? n - 1 - i : i + 1);

            // Loop through allowed columns for this row
            for (int j = startCol; j < n; ++j) {
                int best = prev[j]; // Stay in the same column
                if (j - 1 >= 0) best = best > prev[j - 1] ? best : prev[j - 1]; // Move left
                if (j + 1 < n) best = best > prev[j + 1] ? best : prev[j + 1];   // Move right
                curr[j] = best + fruits[i][j]; // Add fruits from current cell
            }

            // Swap prev and curr arrays for next iteration
            int* tmp = prev;
            prev = curr;
            curr = tmp;
        }

        // Result = best fruits reaching column n-1 at row n-1
        int result = prev[n - 1];
        free(prev);
        free(curr);
        return result;
    }

    // Add fruits collected by the child starting from (0, n-1)
    ans += dp();

    /*Transpose the grid to reuse the same dp()
     for the child starting from (n-1, 0). */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = fruits[j][i];
            fruits[j][i] = fruits[i][j];
            fruits[i][j] = temp;
        }
    }

    // Add fruits collected by the child starting from (n-1, 0)
    ans += dp();

    //Return total maximum fruits collected by all three children
    return ans;
}

