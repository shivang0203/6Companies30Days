#include<iostream>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int sum = accumulate(nums.begin(),nums.end(),0);
        // int cnt=0;
        // for(auto it:nums){
        //     if(it !=0)cnt++;
        // }
        sort(nums.begin(),nums.end());
        // long long avg = sum/nums.size();

        // cout<<avg<<endl;
        // long long mini=INT_MAX;
        int common=nums[nums.size()/2];
        // for(int i=0;i<nums.size();i++){
        //     long long diff = abs(avg-nums[i]);
        //     if(diff<mini){
        //         mini=diff;
        //         common= nums[i];

        //     }
        // }


        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-common);
        }
        return ans;

    }
};
// 22/4
// 5.5 =5,4+3+4+5
// 2
// 9-2=7
// 10-2=8
// 2-1= 1