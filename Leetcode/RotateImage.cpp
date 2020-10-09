// https://leetcode.com/problems/rotate-image/

#include <vector>
#include <utility>
#include <stdio.h>

using std::vector;
using std::pair;
using std::make_pair;

#define SOL 1

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        return Sol(matrix);
    }
    
    /*
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     * SOL 1:
     * This solution breaks the matrix down into frames. For example, in the 7x7 matrix below, the characters
     * X, Y, Z, and W show the 4 different frames that would make up the 7x7 matrix.
     * 
     * X X X X X X X
     * X Y Y Y Y Y X
     * X Y Z Z Z Y X
     * X Y Z W Z Y X
     * X Y Z Z Z Y X
     * X Y Y Y Y Y X
     * X X X X X X X 
     * 
     * To simplify the problem, the solution rotates each frame 90 degrees before moving to the next
     * inner frame. 
     * 
     * Time Complexity: O(N)*O(N) = O(N^2) where N represents matrix dimensions (NxN). 
     * W = word length-1
     * N = height
     * M = width
     * O(N^2)*O(W) => O(N^2) [W is a constant]
     * 
     * Space Complexity: 
     * 
     * Performance
     * Runtime - 4 ms, faster than 66.23% of c++ submissions
     * Memory - 7.3 MB, less than 43.34% of c++ submissions
     * The main downfall of this is the memory.. I think this might be due to the recursion and this
     * solution saving a matrix value for the next iteration.
     * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
     */
#if SOL == 1
    void Sol(vector<vector<int>>& matrix) {
        
        int dims = matrix.size();
        
        pair<int, int> rows         = make_pair(0, dims-1);
        pair<int, int> cols         = make_pair(0, dims-1);
        
        // Rotate each frame starting fromo the outside frame, working towards
        // the inner frames.
        for (int frameDim = dims; frameDim > 1; frameDim-=2) // >= 3 doesn't allow dimensions to go to 1
        {
            // Rotating frame 90 degrees == rotating right DIMENSION number of times.
            // e.g. 4x4 frame needs to be rotated 4 times for a 90 degree rotation.
            for (int j = 0; j < frameDim-1; j++)
            {
                pair<int, int> nextCoord    = make_pair(rows.first, cols.first+1);
                pair<int, int> startingDir  = make_pair(0, 1);
                int savedValue              = matrix[rows.first][cols.first];
                
                RotateFrameRightRecursive(
                    matrix,
                    rows, cols,
                    nextCoord,
                    startingDir,
                    savedValue
                );
            }
            
            // Adjust starting/ending rows/cols
            rows.first++;
            rows.second--;
            cols.first++;
            cols.second--;
        }
    }

    void RotateFrameRightRecursive(
        vector<vector<int>>& matrix, 
        pair<int, int>& row, 
        pair<int, int>& col,
        pair<int, int>& coord,
        pair<int, int>& dir,
        int saved
    )
    {
        // Save the next value for next recursive call
        int newSaved = matrix[coord.first][coord.second];

        // Replace the next value
        matrix[coord.first][coord.second] = saved;

        // RECURSIVE CALLS
        if (coord.first == row.first && coord.second == col.second) {dir = {1, 0};}         // If at the end of the top row, go down.
        else if (coord.first == row.second && coord.second == col.second) {dir = {0, -1};}  // If at the end of the right col, go left.
        else if (coord.first == row.second && coord.second == col.first) {dir = {-1, 0};}   // If at the end of the bottom row, go up.
        else if (coord.first == row.first && coord.second == col.first) {return;}           // If at the end of the left col, return (BASE CASE).

        // Continue moving in the same direction
        coord.first += dir.first;
        coord.second += dir.second;
        RotateFrameRightRecursive(matrix, row, col, coord, dir, newSaved);
    }
#endif
};