#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N;cin>>N;
        int arr[2][100001];
        int dp[2][100001];

        for(int i = 0; i<2; i++){
            for(int j= 0; j<N; j++){
                cin>>arr[i][j];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];

        if(N>1){
            dp[0][1] = max(arr[1][0] + arr[0][1],arr[0][0]);
            dp[1][1] = max(arr[0][0] + arr[1][1],arr[1][0]);
        }
        for(int i = 2; i<N; i++){
            dp[0][i] = max(dp[1][i-1]+arr[0][i], max(dp[0][i-2]+arr[0][i],dp[1][i-2]+arr[0][i]));
            dp[1][i] = max(dp[0][i-1]+arr[1][i], max(dp[0][i-2]+arr[1][i],dp[1][i-2]+arr[1][i]));
        }
        cout<<max(dp[0][N-1],dp[1][N-1])<<'\n';
    }    
}