#include<iostream>
using namespace std;

class Solution {
public:
    bool check(int start,int end,vector<int> &nums){
        vector<int> curr;
        for(int i=0;i<start;i++){
            curr.push_back(nums[i]);
        }
        for(int i=end+1;i<nums.size();i++){
            curr.push_back(nums[i]);
        }
        // {6,6}
        for(int i=1;i<curr.size();i++){
            if(curr[i-1]>=curr[i])return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)return 1;
        if(n==2)return 3;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,nums)){
                    ans++;
                    cout<<i<<j<<endl;
                }
            }
        }
        return ans;
    }
};