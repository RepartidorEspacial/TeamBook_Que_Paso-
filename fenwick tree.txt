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
using namespace std;
///suma en rangos con updates
vi vv,v;
int n;
int query(int x){
    int res=0;
    while(x>0){
        res+=v[x];
        x-=x&-x;
    }
    return res;
}
void update(int x,int y){
    while(x<=n){
        v[x]+=y;
        x+=x&-x;
    }
}
int main()
{
    cin>>n;
    vv.pb(0);
    int x;
    v.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>x;
        update(i,x);
        vv.pb(x);
    }
    int q,y,c;
    cin>>q;
    while(q--){
        cin>>c>>x>>y;
        if(c==0){
            cout<<query(y)-query(x-1)<<endl;
        }else{
            update(x,-vv[x]);
            update(x,y);
            vv[x]=y;
        }
    }
    return 0;
}
