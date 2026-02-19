class

    Solution

{

public:
    int count =

        0;

    std ::vector<bool> colUsed;

    // Tracks if a column is occupied

    std ::vector<bool> diag1Used;

    // Tracks if a main diagonal (row - col = const) is occupied

    std ::vector<bool> diag2Used;

    // Tracks if an anti-diagonal (row + col = const) is occupied

    void

    backtrack(int n,

              int row)

    {

        // Base case: If all n queens are placed successfully

        if

            (row == n)

        {

            count++;

            return;
        }

        // Iterate through each column in the current row

        for

            (int col =

                 0;
             col < n;

             ++col)

        {

            // Calculate indices for diagonals

            // Main diagonal: row - col. To make it non-negative and unique for
            // indexing, we use row - col + n - 1.

            // The range for row - col is (0 - (n-1)) to ((n-1) - 0), i.e.,
            // -(n-1) to n-1.

            // Adding n-1 shifts it to 0 to 2*n - 2.

            int mainDiagIdx = row - col + n -

                              1;

            // Anti-diagonal: row + col. The range is 0 to 2*n - 2.

            int antiDiagIdx = row + col;

            // Check if the current position (row, col) is safe (column and both
            // diagonals are free)

            if

                (!colUsed[col]

                 &&

                 !diag1Used[mainDiagIdx]

                 &&

                 !diag2Used[antiDiagIdx])

            {

                // Place queen: Mark column and diagonals as used

                colUsed[col]

                    =

                        true;

                diag1Used[mainDiagIdx]

                    =

                        true;

                diag2Used[antiDiagIdx]

                    =

                        true;

                // Recurse for the next row

                backtrack(n, row +

                                 1);

                // Backtrack: Unmark column and diagonals to explore other
                // possibilities

                colUsed[col]

                    =

                        false;

                diag1Used[mainDiagIdx]

                    =

                        false;

                diag2Used[antiDiagIdx]

                    =

                        false;
            }
        }
    }

    int

    totalNQueens(int n)

    {

        // Resize boolean vectors based on n

        colUsed.resize(n,

                       false);

        diag1Used.resize(2

                                 * n -

                             1,

                         false);

        // N main diagonals (row - col + N - 1 maps unique values to indices)

        diag2Used.resize(2

                                 * n -

                             1,

                         false);

        // N anti-diagonals (row + col maps unique values to indices)

        // Start the backtracking process from the first row (row 0)

        backtrack(n,

                  0);

        return count;
    }
};