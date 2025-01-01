#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int dir[8][2] = {{-1,-1},{1,1},{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=img[i][j];
                int count=1;
                for(auto it: dir){
                    if(i+it[0] >=0 && i+it[0]<n && j+it[1]>=0 && j+it[1]<m){
                        sum+=img[i+it[0]][j+it[1]];
                        count++;
                    }
                    
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};
