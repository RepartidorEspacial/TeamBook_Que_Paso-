#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
int dp[10002][2005];
//dp[i][j]=el rango minimo si ya recorri las primeras i posiciones y estoy parado a j del borde izquierdo
int a[10005];
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<2005;i++)dp[0][i]=i+i;
        int res=1e9;
        for(int i=1;i<=n;i++){
            for(int l=0;l<2005;l++){
                dp[i][l]=1e9;
                if(l-a[i]>=0)dp[i][l]=max(l,dp[i-1][l-a[i]]);
                if(l+a[i]<2003)dp[i][l]=min(dp[i][l],dp[i-1][l+a[i]]);
            }
        }
        for(int i=0;i<2000;i++)res=min(res,dp[n][i]);
        cout<<res<<endl;
    }
    return 0;
}
//tienes te mueves a[i] hacia la izq o der, hallar la minima diferencia entre el borde izq y der
//https://codeforces.com/contest/1579/problem/G ()