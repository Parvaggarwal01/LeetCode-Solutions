class

    Solution

{

public:
    std ::string intToRoman(int num)

    {

        // Pairs of (value, Roman symbol) in descending order.

        // The subtractive cases (e.g., 900, 400, 90, 40, 9, 4) must come before

        // their larger additive parts (e.g., 1000, 500, 100, 50, 10, 5) to be

        // processed correctly by the greedy approach.

        std ::vector<std ::pair<int, std ::string>> value_roman_map =

            {

                {1000,

                 "M"},

                {900,

                 "CM"},

                {500,

                 "D"},

                {400,

                 "CD"},

                {100,

                 "C"},

                {90,

                 "XC"},

                {50,

                 "L"},

                {40,

                 "XL"},

                {10,

                 "X"},

                {9,

                 "IX"},

                {5,

                 "V"},

                {4,

                 "IV"},

                {1,

                 "I"}

            };

        std ::string roman_numeral =

            "";

        for

            (const

             auto& pair : value_roman_map)

        {

            int value = pair.first;

            std ::string symbol = pair.second;

            // While the current number is greater than or equal to the value,

            // append the symbol and subtract the value from the number.

            while

                (num >= value)

            {

                roman_numeral += symbol;

                num -= value;
            }
        }

        return roman_numeral;
    }
};