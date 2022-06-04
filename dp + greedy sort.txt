#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
using namespace std;
const int tam=1005;
int W[tam],S[tam],V[tam];
ll dp[50005];//valor maximo si tengo hasta este peso
int main(){
    int n,w,s,v;
    cin>>n;
    vector<pair<int,int> >E;
    for(int i=1;i<=n;i++){
        cin>>W[i]>>S[i]>>V[i];//peso, resistencia y valor
        E.pb({W[i]+S[i],i}); 
    }
    sort(E.begin(),E.end());
    //apilar de forma de conseguir el valor maximo
    ll res=0;
    for(int i=0;i<n;i++){
        int ind=E[i].S;
        w=W[ind],s=S[ind],v=V[ind];
        for(int l=s;l>=0;l--){
            if(dp[w+l]>dp[l]+v)continue;
            dp[w+l]=dp[l]+v;
            res=max(res,dp[w+l]);
        }
    }
    cout<<res<<endl;
    return 0;
}