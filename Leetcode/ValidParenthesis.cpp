// https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <stack>
#include <unordered_map>
#include <stdio.h>

#define SOL 1

using std::string;
using std::stack;
using std::unordered_map;

/*
 * VALID EXAMPLES:
 * ({}[])
 * 
 * INVALID EXAMPLES:
 * Ex 1
 * ([)]
 * stack
 * ]
 * )
 * [
 * (
 * 
 * Ex 2
 * )(
 * stack
 * 
*/

class Solution {
public:
    bool isValid(string s) {
#if SOL == 1
        return Sol1(s);
#endif
    }

    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol1
     * 
     * BIG O:
     * f(n) = O(N^2)
     * 
     * PERFORMANCE:
     * Runtime - 4 ms, faster than 39.47% of c++ submissions
     * Memory - 6.8 MB, less than 5.43% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
#if SOL == 1
    bool Sol1(string s) {
        stack<char> myStack;
        unordered_map<char, char> brackets;
        char nextChar;
        char top;
        
        // map the left brackets to the right brackets
        brackets['{'] = '}';
        brackets['['] = ']';
        brackets['('] = ')';
        
        top = 'X'; // value that will never appear

        // If the string doesn't have an even number of characters,
        // there will be at least 1 unpaired bracket.
        if (s.length() % 2 != 0)
            return false;

        for (int i = 0; i < s.length(); i++)
        {
            nextChar = s[i];
            //printf("nextChar = %c\n", nextChar);
            
            top = myStack.empty() ? 'X' : myStack.top();
            
            // If a left side bracket is found, push complement to the stack 
            if (nextChar == '{' || nextChar == '[' || nextChar == '(')
            {
                //printf("Pushing %c\n", nextChar);
                myStack.push(brackets[nextChar]);
            }
            
            // If a right side bracket is found, check if it is closing the 
            // most recent left bracket.
            else if (nextChar == top)
            {
                //printf("Popping %c\n", nextChar);
                myStack.pop();
            }
        }

        // If stack still has elements then it is invalid
        return myStack.empty();
    }
#endif
};