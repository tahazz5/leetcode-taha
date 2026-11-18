class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> fr ;
        int n = grid.size();
        vector<int> ans = {-1,-1} ;
        for(auto a : grid) {
            for(auto v : a ){
                fr[v]++;
            }
        }
        for(int i =1 ;i<=n*n ;i++) {
            if(fr[i]==2 ) ans[0]= i ;
            if(fr[i]==0) {
               ans[1]=i ;
            }
            if(ans[0]!=-1 && ans[1]!=-1) break;
        }
        return ans ;
        
    }
};