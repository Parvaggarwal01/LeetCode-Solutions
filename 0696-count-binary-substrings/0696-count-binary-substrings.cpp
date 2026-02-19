class

    Solution

{

public:
    int

    countBinarySubstrings(string s)

    {

        int ans =

            0;

        int prevCount =

            0;

        // Length of the previous consecutive group of characters

        int currCount =

            1;

        // Length of the current consecutive group of characters

        // Iterate through the string starting from the second character

        for

            (int i =

                 1;
             i < s.length();

             ++i)

        {

            if

                (s[i]

                 == s[i - 1])

            {

                // Current character is the same as the previous one, extend the
                // current group

                currCount++;

            }

            else

            {

                // Current character is different, a new group has started.

                // Add min(prevCount, currCount) to ans, as this is the number
                // of valid substrings

                // that can be formed by the previous two groups.

                ans += std ::min(prevCount, currCount);

                // The current group becomes the previous group for the next
                // iteration

                prevCount = currCount;

                // Reset current group count to 1 for the new character

                currCount =

                    1;
            }
        }

        // After the loop, add the min of the last two group counts.

        // This accounts for the pair of groups ending at the very end of the
        // string.

        ans += std ::min(prevCount, currCount);

        return ans;
    }
};