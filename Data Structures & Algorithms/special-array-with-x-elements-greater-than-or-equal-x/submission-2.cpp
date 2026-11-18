class Solution {
public:
    int specialArray(vector<int>& nums) {
       
        for(int x =0 ;x<= nums.size() ;x++){
            int n =0 ;
            for(int i =0 ;i<nums.size();i++) {
                if(x<=nums[i]) n++;  
            }
            if(x==n) return x;

        }
        return -1;
        
        
    }
};