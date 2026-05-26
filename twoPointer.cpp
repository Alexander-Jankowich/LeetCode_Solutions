#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**Classic Container With Most Water Solution */
    int maxx = 0;
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            maxx = std::max(maxx, std::min(height[l], height[r]) * (r - l));
            if(height[l] < height[r]){
                l+=1;
            }else{
                r-=1;
            }
        }
        return maxx;
    }
    /**Classic isSubsequence Solution */
    bool isSubsequence(string s, string t) {
        int k = 0;
        if (s == ""){
            return true;
        }
        for(int i = 0; i < (int)(t.length()); i++){
            if(k >= (int)s.length()){
                return true;
            }
            if(t[i] == s[k]){
                k += 1;
            }
        }
        return k == (int)s.length();
    }
};