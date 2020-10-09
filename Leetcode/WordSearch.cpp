// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>
#include <stdio.h>
#include <utility>

using std::vector;
using std::string;
using std::pair;
using std::make_pair;

#define SOL 3

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return Sol(board, word);
    }

#if SOL == 3
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * DESCRIPTION: Sol
     * This is not my original work. This is the solution submitted
     * in the discussion comments by user 'tsuih805.' I am uploading
     * this code as a reference for later since it gave me a better
     * understanding of how to use backtracking.
     * 
     * Time Complexity:
     * ??
     * 
     * Space Complexity:
     * ??
     * 
     * PERFORMANCE:
     * Runtime - 48 ms, faster than 93.09% of c++ submissions
     * Memory - 11 MB, less than 90.33% of c++ submissions
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    */
// Backtracking implmentation
    bool Sol(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    // X X X X X 
    // X X X X X 
    // X X # X X 
    // X X # X X
    // X X X X X
    
    bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if(index == word.size()) return true; // end condition
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix
        if(board[i][j] != word[index]) return false; // do not match

        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch =  adjacentSearch(board, word, i+1, j, index+1) || // up
                              adjacentSearch(board, word, i-1, j, index+1) || // down
                              adjacentSearch(board, word, i, j-1, index+1) || // left
                              adjacentSearch(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back!
        return furtherSearch;
    }
#endif

#if SOL == 2
    bool Sol(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                printf("CHECKING NEXT LOCATION\n\n");
                
                // If the first character of the string is found, start a 
                // recursive search at this location.
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c)
    {
        // Whole word has been found (base case)
        if (i == word.length())
            return true;

        if (c-1 > 0 && word[i+1] == board[r][c-1]) // check left
            return dfs(board, word, i+1, r, c-1);
        
        if (c+1 < board.size()-1 && word[i+1] == board[r][c+1]) // check right
            return dfs(board, word, i+1, r, c+1);

        if (r-1 > 0 && word[i+1] == board[r-1][c]) // check up
            return dfs(board, word, i+1, r-1, c);

        if (r+1 < board.size()-1 && word[i+1] == board[r+1][c]) // check up
            return dfs(board, word, i+1, r+1, c);

        // Word was not found
        return false;
    }
#endif

/*
 * Brute force solution (not passing)
 * Awful O(n^4) 
*/
#if SOL == 1
    bool Sol(vector<vector<char>>& board, string word)
    {
        char nextChar;

        int wordSize = word.size();
        int numRows = board.size();
        int numCols = board[0].size();
        vector<pair<int, int>> prevCoords(wordSize); // max num prev coords == size of word
        int prevCoordsIdx = -1;
        int rS, cS;

        // Search the whole board
        for (int r = 0; r < numRows; r++)
        {
            for (int c = 0; c < numRows; c++)
            {
                nextChar = board[r][c];
                
                // Look for the first letter of the word
                if (nextChar == word[0])
                {
                    printf("First letter found!\n");
                    rS = r;
                    cS = c;
                    
                    // Search for entire word starting at this coordinate
                    for (int i = 0; i < wordSize; i++)
                    {
                        bool passed = true;
                        printf("Next Char: %c\n", word[0]);
                        pair<int, int> nextCoord = SearchSurrounding(board, word[1], rS, cS);

                        // If the next character was found AND the coordinate was not visited yet,
                        // the nextCoord pair passes
                        if (nextCoord.first != -1)
                        {
                            for (int j = 0; j <= wordSize; j++)
                            {
                                if (nextCoord == prevCoords[j])
                                {
                                    printf("Already searched %d, %d\n", nextCoord.first, nextCoord.second);
                                    passed = false;
                                    break;
                                }
                            }
                        }
                        
                        // Add coordinate
                        if (passed)
                        {
                            prevCoordsIdx++; // next save coordinate
                            printf("Adding: %d, %d\n", nextCoord.first, nextCoord.second);
                            prevCoords[prevCoordsIdx] = nextCoord;  
                            
                            // set next pair of coordinates to search
                            rS = nextCoord.first;
                            cS = nextCoord.second;
                        }
                        
                        // Restart search at next r/c
                        else
                        {
                            // Restart search for first letter of the word
                            prevCoordsIdx = -1; 
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }

    pair<int, int>& SearchSurrounding(vector<vector<char>>&board, char target, int r, int c)
    {
        pair<int, int> coord = make_pair(-1, -1);

        // Next coords to search
        #define UP      c - 1
        #define DOWN    c + 1
        #define LEFT    r - 1
        #define RIGHT   r + 1

        // Board boundaries
        int leftBound   = 0;
        int rightBound  = board[0].size();
        int topBound    = 0;
        int bottomBound = board.size();

        if (UP >= topBound)
        {
            if (board[r][UP] == target)
                coord = {r, UP};
        } 

        else if (DOWN <= bottomBound)
        {
            if (board[r][DOWN] == target)
                coord = {r, DOWN};
        }

        else if (LEFT >= leftBound)
        {
            if (board[LEFT][c] == target)
                coord = {LEFT, c};
        }

        else if (RIGHT <= rightBound)
        {
            if (board[RIGHT][c] == target)
                coord = {RIGHT, c};
        }
        return coord;
    }
#endif
};