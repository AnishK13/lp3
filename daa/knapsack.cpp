#include<bits/stdc++.h>
using namespace std;

int rec(int idx, vector<int>&weight, vector<int>&value, int maxWeight, int currWeight, int dp[100][100]){
    //base case
    if(idx>=weight.size()){
        return 0;
    }
    if(dp[idx][currWeight] != -1) return dp[idx][currWeight];
    
    // dont take
    int ans = rec(idx+1,weight,value,maxWeight,currWeight,dp);

    // take
    if(currWeight+weight[idx] <= maxWeight){
        ans = max(ans, value[idx]+rec(idx+1,weight,value,maxWeight,currWeight+weight[idx],dp));
    }

    return dp[idx][currWeight] = ans;
}

int main(){
    vector<int>weight = {3,1,2,4,1};
    vector<int>value = {5,5,2,3,3};
    int maxWeight = 7;
    int idx = 0, currWeight = 0;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<rec(idx,weight,value,maxWeight,currWeight,dp);

}