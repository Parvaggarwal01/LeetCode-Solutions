class

    Solution

{

public:
    int

    countSubmatrices(vector<vector<int>>& grid,

                     int k)

    {

        int m = grid.size();

        int n = grid[0].size();

        // `current_row_prefix_sum[c]` stores the sum of `grid[0...r][0...c]`
        // for the current row `r`.

        vector<long

               long>

            current_row_prefix_sum(n,

                                   0);

        // `prev_row_prefix_sum[c]` stores the sum of `grid[0...(r-1)][0...c]`
        // from the previous row `r-1`.

        vector<long

               long>

            prev_row_prefix_sum(n,

                                0);

        int count =

            0;

        // Iterate through each cell (r, c) as a potential bottom-right corner

        for

            (int r =

                 0;
             r < m;

             ++r)

        {

            for

                (int c =

                     0;
                 c < n;

                 ++c)

            {

                long

                    long current_val = grid[r][c];

                // sum_from_above represents sum of submatrix (0,0) to (r-1, c)

                long

                    long sum_from_above =

                        (r >

                         0)

                            ? prev_row_prefix_sum[c]

                            :

                            0;

                // sum_from_left represents sum of submatrix (0,0) to (r, c-1)

                // This is taken from current_row_prefix_sum because it's
                // already computed for column c-1 in the current row r.

                long

                    long sum_from_left =

                        (c >

                         0)

                            ? current_row_prefix_sum[c -

                                                     1]

                            :

                            0;

                // sum_from_diag_top_left represents sum of submatrix (0,0) to
                // (r-1, c-1)

                // This is subtracted to correct for double-counting when adding
                // sum_from_above and sum_from_left.

                long

                    long sum_from_diag_top_left =

                        (r >

                             0

                         && c >

                                0)

                            ? prev_row_prefix_sum[c -

                                                  1]

                            :

                            0;

                // Calculate the sum of the submatrix from (0,0) to (r,c) using
                // the 2D prefix sum formula

                long

                    long submatrix_sum = current_val + sum_from_above +
                                         sum_from_left - sum_from_diag_top_left;

                // Store this calculated sum in the `current_row_prefix_sum` for
                // use in later columns of this row, or the next row.

                current_row_prefix_sum[c]

                    = submatrix_sum;

                // If the submatrix sum is within the limit, increment the count

                if

                    (submatrix_sum <= k)

                {

                    count++;
                }
            }

            // After completing a row, the `current_row_prefix_sum` (which holds
            // sums for row `r`)

            // becomes the `prev_row_prefix_sum` for the next iteration (row
            // `r+1`).

            prev_row_prefix_sum = current_row_prefix_sum;
        }

        return count;
    }
};