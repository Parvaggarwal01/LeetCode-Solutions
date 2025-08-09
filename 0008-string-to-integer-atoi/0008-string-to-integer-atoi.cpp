class Solution{

public:
    int

    myAtoi(string s)

    {

        int sign =

            1;

        int result =

            0;

        int index =

            0;

        int n = s.size();

        // Discard leading whitespace

        while

            (index < n && s[index]

                              ==

                              ' ')

        {

            index++;
        }

        // Check for sign

        if

            (index < n &&

             (s[index]

                  ==

                  '+'

              || s[index]

                     ==

                     '-'))

        {

            sign =

                (s[index]

                 ==

                 '-')

                    ?

                    -1

                    :

                    1;

            index++;
        }

        // Convert number and avoid overflow

        while

            (index < n &&

             isdigit(s[index]))

        {

            int digit = s[index]

                        -

                        '0';

            // Check if overflow will occur

            if

                (result > INT_MAX /

                              10

                 ||

                 (result == INT_MAX /

                                10

                  && digit > INT_MAX %

                                 10))

            {

                return

                    (sign ==

                     1)

                        ? INT_MAX
                        : INT_MIN;
            }

            result = result *

                         10

                     + digit;

            index++;
        }

        return sign * result;
    }
};