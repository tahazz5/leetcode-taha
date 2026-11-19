class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int l = 0 , r=nums.size()-1 ;
        while(res.size()!=nums.size()){
            if(nums[l]*nums[l]<nums[r]*nums[r]){
                res.push_back(nums[r]*nums[r]);
                r--;
            }
            else{
                res.push_back(nums[l]*nums[l]);
                l++;

            }
        }
        reverse(res.begin(), res.end()) ;
      
        return res ;
        
    }
};