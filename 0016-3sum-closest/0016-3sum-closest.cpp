class

    Solution

{

public:
    int

    threeSumClosest(vector<int>& nums,

                    int target)

    {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize closestSum with the sum of the first three elements.

        // This ensures closestSum has a valid initial value and difference.

        int closestSum = nums[0]

                         + nums[1]

                         + nums[2];

        for

            (int i =

                 0;
             i < n -

                     2;

             ++i)

        {

            // Optimization: Skip duplicate elements for the first pointer

            // to avoid redundant calculations, though not strictly necessary

            // for correctness given 'exactly one solution' and closestSum
            // logic.

            // If (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i +

                       1;

            int right = n -

                        1;

            while

                (left < right)

            {

                int currentSum = nums[i]

                                 + nums[left]

                                 + nums[right];

                if

                    (currentSum == target)

                {

                    return target;

                    // Found the exact sum, which is the closest possible
                }

                // Update closestSum if currentSum is closer to target

                if

                    (abs(currentSum - target)

                     <

                     abs(closestSum - target))

                {

                    closestSum = currentSum;
                }

                if

                    (currentSum < target)

                {

                    left++;

                    // Sum is too small, need to increase it. Move left pointer
                    // right.

                    // Optional: Skip duplicate elements for the left pointer

                    // while (left < right && nums[left] == nums[left - 1])
                    // left++;

                }

                else

                {

                    // currentSum > target

                    right--;

                    // Sum is too large, need to decrease it. Move right pointer
                    // left.

                    // Optional: Skip duplicate elements for the right pointer

                    // while (left < right && nums[right] == nums[right + 1])
                    // right--;
                }
            }
        }

        return closestSum;
    }
};