#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    /** The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
    The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
    Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
    To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
    Return the knight's minimum initial health so that he can rescue the princess.
    Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
    
    This is a pretty classic dynamic programming problem "bottom-up"*/
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        std::vector<std::vector<int>> matrix(dungeon.size() + 1,std::vector<int>(dungeon[0].size() + 1, INF));
        int needed = std::max(1, 1 - dungeon[dungeon.size() - 1][dungeon[0].size() - 1]);
        matrix[dungeon.size() - 1][dungeon[0].size() - 1] = needed;
        for (int i = dungeon.size() - 1; i >= 0; i--){
            for(int j = dungeon[0].size() - 1; j >= 0; j--){
                if(matrix[i][j] == INF){
                    needed = std::max(1, std::min(matrix[i+1][j],matrix[i][j+1]) - dungeon[i][j]);
                    matrix[i][j] = needed;
                }
               
            }
        }
        return matrix[0][0];
    }
};