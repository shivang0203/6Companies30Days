#include<iostream>
using namespace std;

class Solution {
public:
    map<vector<int>,int>mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans=0;
        if(mp.count(needs) !=0){
            return mp[needs];
        }
        for(int i=0;i<price.size();i++){
            ans+= (price[i]*needs[i]);
        }

        for(int i=0;i<special.size();i++){
            bool isValid=true;
            for(int j=0;j<needs.size();j++){
                if(needs[j]<special[i][j]){
                    isValid=false;
                    break;
                }
            }

            if(isValid){
                for(int j=0;j<needs.size();j++){
                    needs[j] -=special[i][j];
                }
                int tempAns =special[i].back() + shoppingOffers(price,special,needs);
                ans = min(ans,tempAns);
                for(int j=0;j<needs.size();j++){
                    needs[j] +=special[i][j];
                }
            }
        }
        return mp[needs]=ans;
    }
};