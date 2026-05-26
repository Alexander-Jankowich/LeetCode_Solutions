#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    /**Solution for Keys and Rooms this problem is quite fun just a simple graph dfs */
    std::set<int> visited;
    void dfs(vector<vector<int>>& rooms, int current){
        if(visited.find(current) != visited.end()){
            return;
        }
        visited.insert(current);
        for(int k : rooms[current]){
            dfs(rooms, k);
            visited.insert(k);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() == 0){
            return true;
        }
        dfs(rooms,0);
        return visited.size() == rooms.size();
    }
};