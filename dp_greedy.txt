#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define vll vector<ll>
using namespace std;
const ll MOD=1000000007;
const int INF=1234567890;
const ll MAX=100003;
const double epsi=0.0000001;
//"\n"
int dp[10000];

bool comp1(pair<int,int> a,pair<int,int> b){
    return (a.F)<(b.F);
}
bool comp2(pair<int,int> a,pair<int,int> b){
    return (a.F+a.S)>(b.F+b.S);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,r,a,b;
    cin>>n>>r;
    vector<pair<int,int> >v,A,B;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b<0)B.pb({a,b});
        else A.pb({a,b});
    }
    sort(A.begin(),A.end(),comp1);
    sort(B.begin(),B.end(),comp2);
    for(int i=0;i<B.size();i++)A.pb(B[i]);
    for(int i=0;i<10000;i++)dp[i]=-INF;
    dp[0]=r;
    for(int i=1;i<=n;i++){
        pair<int,int> x=A[i-1];
        for(int j=i;j>=1;j--){
            if(dp[j-1]>=x.F){
                if((dp[j-1]+x.S)>=0){
                    dp[j]=max(dp[j],dp[j-1]+x.S);
                }
            }
        }
    }
    for(int i=n;i>=0;i--){
        if(dp[i]>=0){cout<<i<<endl;return 0;}
    }

    return 0;
}
