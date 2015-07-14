//dfa
class Solution
{
public:
    bool isNumber(const char *s)
    {
        enum InputType
        {
            INVALID, // 0
            SPACE, // 1
            SIGN, // 2
            DIGIT, // 3
            DOT, // 4
            EXPONENT, // 5
            NUM_INPUTS // 6
        };
        const int transitionTable[][NUM_INPUTS] =
        {
            -1, 0, 3, 1, 2, -1, // next states for state 0
            -1, 8, -1, 1, 4, 5, // next states for state 1
            -1, -1, -1, 4, -1, -1, // next states for state 2
            -1, -1, -1, 1, 2, -1, // next states for state 3
            -1, 8, -1, 4, -1, 5, // next states for state 4
            -1, -1, 6, 7, -1, -1, // next states for state 5
            -1, -1, -1, 7, -1, -1, // next states for state 6
            -1, 8, -1, 7, -1, -1, // next states for state 7
            -1, 8, -1, -1, -1, -1, // next states for state 8
        };
        int state = 0;
        for (; *s != '\0'; ++s)
        {
            InputType inputType = INVALID;
            if (isspace(*s))
                inputType = SPACE;
            else if (*s == '+' || *s == '-')
                inputType = SIGN;
            else if (isdigit(*s))
                inputType = DIGIT;
            else if (*s == '.')
                inputType = DOT;
            else if (*s == 'e' || *s == 'E')
                inputType = EXPONENT;
            // Get next state from current state and input symbol
            state = transitionTable[state][inputType];
            // Invalid input
            if (state == -1) return false;
        }
        // If the current state belongs to one of the accepting (final) states,
        // then the number is valid
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};
