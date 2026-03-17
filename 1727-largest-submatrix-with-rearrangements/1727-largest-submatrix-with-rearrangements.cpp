
class

    Solution

{

public:
    int

    largestSubmatrix(std ::vector<std ::vector<int>>& matrix)

    {

        int m = matrix.size();

        int n = matrix[0].size();

        int max_area =

            0;

        // Step 1: Transform the matrix into a heights matrix in-place.

        // matrix[i][j] will store the count of consecutive 1s ending at (i, j)
        // upwards.

        // If matrix[i][j] is 0, its height is 0. If it's 1, its height is 1 +
        // height of cell above it.

        for

            (int i =

                 0;
             i < m;

             ++i)

        {

            for

                (int j =

                     0;
                 j < n;

                 ++j)

            {

                if

                    (matrix[i][j]

                         ==

                         1

                     && i >

                            0)

                {

                    matrix[i][j]

                        += matrix[i - 1][j];
                }
            }
        }

        // Step 2: For each row, sort its heights and calculate the maximum
        // area.

        // The ability to rearrange columns means that for any given row `i`, we
        // can treat `matrix[i]`

        // as a histogram and sort its bars (column heights) to maximize the
        // rectangle area.

        for

            (int i =

                 0;
             i < m;

             ++i)

        {

            // Get the current row's heights. We make a copy to sort, as
            // modifying `matrix[i]`

            // in-place might affect subsequent rows' height calculations if
            // they were not already done.

            // However, since heights are computed row by row, `matrix[i]`
            // stores the final heights for row `i`.

            std ::vector<int> current_row_heights = matrix[i];

            // Sort the heights in non-decreasing order.

            // This is the key step that leverages the column rearrangement
            // property.

            std ::sort(current_row_heights.begin(), current_row_heights.end());

            // Calculate the largest rectangle in this sorted histogram.

            // For a bar of height h located at index k (0-indexed after
            // sorting),

            // it implies that there are (n - k) columns that have at least this
            // height h.

            // Therefore, a rectangle of height 'h' can be formed with a width
            // of 'n - k'.

            for

                (int k =

                     0;
                 k < n;

                 ++k)

            {

                int height = current_row_heights[k];

                int width = n - k;

                // Number of columns that have a height >=
                // current_row_heights[k]

                max_area = std ::max(max_area, height * width);
            }
        }

        return max_area;
    }
};