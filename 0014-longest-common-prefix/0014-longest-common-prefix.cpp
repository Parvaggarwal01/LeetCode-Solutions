class

    Solution

{

public:
    std ::string longestCommonPrefix(std ::vector<std ::string>& strs)

    {

        if

            (strs.empty())

        {

            return

                "";
        }

        // Initialize the common prefix with the first string

        std ::string prefix = strs[0];

        // Iterate through the rest of the strings

        for

            (size_t i =

                 1;
             i < strs.size();

             ++i)

        {

            // While the current string strs[i] does not start with the current
            // prefix

            // (std::string::find returns 0 if the substring is found at the
            // beginning)

            while

                (strs[i].find(prefix)

                 !=

                 0)

            {

                // Shorten the prefix by removing the last character

                prefix = prefix.substr(0, prefix.length()

                                              -

                                              1);

                // If the prefix becomes empty at any point, there's no common
                // prefix

                if

                    (prefix.empty())

                {

                    return

                        "";
                }
            }
        }

        return prefix;
    }
};