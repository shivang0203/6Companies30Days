#include<iostream>
using namespace std;


// all testcases passed
class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> ans;

        for (auto& e : envelopes) {
            if (ans.size() == 0 || e[1] > ans.back()) {
                ans.push_back(e[1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), e[1]) - ans.begin();
                ans[index] = e[1];
            }
        }
        return ans.size();
    }
};



// 53/87 test cases passed by using priority Queue minheap on comparing 1st width then heigh
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // First compare the first values, then compare the second values if the first values are equal
        // if (a.first != b.first) {
        //     return a.first > b.first; // Smaller first value gets higher priority
        // }
        // return a.second > b.second; // If first values are equal, smaller second value gets higher priority
        return a.first + a.second > b.first + b.second;
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for(auto it:envelopes){
            pq.push({it[0],it[1]});
        }
        int w=pq.top().first;
        int h=pq.top().second;
        pq.pop();
        
        int count=1;
        while(!pq.empty()){
            int nw=pq.top().first;
            int nh=pq.top().second;
            pq.pop();
            if(nw>w && nh>h){
                count++;
                w=nw;
                h=nh;
            }
        }
        return count;
    }
};

// 84/87 test cases passed by using DP O(n2) got TLE
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n,1);
        int maxi = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] 
                && envelopes[i][1] > envelopes[j][1]  
                && 1+dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                    if(maxi<dp[i])maxi =dp[i];
                }
            }
        }
        return maxi;
    }
};


