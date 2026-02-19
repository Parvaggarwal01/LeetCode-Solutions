class

    Solution

{

public:
    std ::vector<std ::string>

    letterCombinations(std ::string digits)

    {

        std ::vector<std ::string> result;

        if

            (digits.empty())

        {

            return result;
        }

        // Using a std::string array for fixed, small range keys (digits
        // '2'-'9')

        // is slightly more efficient than std::unordered_map due to direct
        // indexing.

        std ::string phoneMap[10]

            =

                {

                    "",

                    // 0

                    "",

                    // 1

                    "abc",

                    // 2

                    "def",

                    // 3

                    "ghi",

                    // 4

                    "jkl",

                    // 5

                    "mno",

                    // 6

                    "pqrs",

                    // 7

                    "tuv",

                    // 8

                    "wxyz"

                    // 9

                };

        std ::string currentCombination;

        // To build combinations recursively

        backtrack(digits,

                  0, phoneMap, currentCombination, result);

        return result;
    }

private:
    void

    backtrack(const std ::string& digits,

              int index,

              const std ::string phoneMap[],

              std ::string& currentCombination,

              std ::vector<std ::string>& result)

    {

        // Base case: If we have processed all digits, a complete combination is
        // formed.

        if

            (index == digits.length())

        {

            result.push_back(currentCombination);

            return;
        }

        // Get the current digit character and convert it to an integer index.

        int digit = digits[index]

                    -

                    '0';

        // Retrieve the letters corresponding to this digit from the phone map.

        const std ::string& letters = phoneMap[digit];

        // Iterate through each letter available for the current digit.

        for

            (char letter : letters)

        {

            currentCombination.push_back(letter);

            // Add the letter to the current combination.

            // Recursively call backtrack for the next digit.

            backtrack(digits,
                      index +

                          1,
                      phoneMap, currentCombination, result);

            currentCombination.pop_back();

            // Backtrack: remove the last letter to explore other paths.
        }
    }
};