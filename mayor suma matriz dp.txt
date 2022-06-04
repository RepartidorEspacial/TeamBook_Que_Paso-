#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define INF 1000000000
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;
using namespace std;
int M[10000][10000];
int dp[10000][10000];
int n,m;
int f(int i,int l){
    if(i>=n or l>=m){
        return -INF;
    }
    if(i==n-1 && l==m-1){
        return M[n-1][m-1];
    }
    if(dp[i][l]!=-INF){
        return dp[i][l];
    }
    dp[i][l]=M[i][l]+max(f(i,l+1),f(i+1,l));
    return dp[i][l];
}
int main()
{
    ///4 4 0 -2 -7 0 9 2 -6 2 -4 1 -4 1 -1 8 0 -2
    ///suma maxima de 0,0 hasta n-1 m-1
    int x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int l=0;l<m;l++){
            cin>>x;
            M[i][l]=x;
            dp[i][l]=-INF;
        }
    }
    f(0,0);
    cout<<dp[0][0]<<endl;
    return 0;
}
