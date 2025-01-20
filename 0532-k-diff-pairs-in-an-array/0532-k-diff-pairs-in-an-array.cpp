class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int i=0;
        int j=i+1;
        int diff;
        int count=0;
        set<pair<int,int>> s;
        while(j<nums.size()){
            diff=nums[j]-nums[i];
            if(diff==k){
                s.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff>k){
                i++;
            }
            else{
                j++;
            }
            if(i==j){
                j++;
            }
        }
        return s.size();
    }
};