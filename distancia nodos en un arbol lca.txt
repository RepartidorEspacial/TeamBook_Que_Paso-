
#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;
//gcd(a,b)= ax + by
//lCB x&-x
//set.erase(it) - ersases the element present at the required index//auto it = s.find(element)
//set.find(element) - iterator pointing to the given element if it is present else return pointer pointing to set.end()
//set.lower_bound(element) - iterator pointing to element greater than or equal to the given element
//set.upper_bound(element) - iterator pointing to element greater than the given element
// | ^
//__builtin_popcount(x)
using namespace std;
const int tam=50005;
vector<vector<pair<int,int> > >G;
int dis[tam];
int depth[tam];
int dp[tam][20];
int n;
void init(int nodo, int p, int d, int w){
    dis[nodo]=w;
    dp[nodo][0]=p;
    depth[nodo]=d;
    for(auto it : G[nodo]){
        if(it.F!=p){
            init(it.F,nodo,d+1,w+it.S);
        }
    }
}
void initLCA(){
    for(int i=0;i<tam;i++){
        for(int l=0;l<20;l++){
            dp[i][l]=-1;
        }
    }
    init(0,-1,0,0);
    for(int pot=1;pot<20;pot++){
        for(int v=0;v<n;v++){
            if(dp[v][pot-1]==-1)continue;
            dp[v][pot]=dp[dp[v][pot-1]][pot-1];
        }
    }
}
int LCA(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    int diff=depth[b]-depth[a];
    for(int i=19;i>=0;i--){
        if(diff&(1<<i)){
            b=dp[b][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];b=dp[b][i];
        }
    }
    return dp[a][0];
}
int main()
{
    int a,b,c;
    cin>>n;
    G.assign(n+2,vector<pair<int,int >  >());
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    initLCA();
    int q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        int lca=LCA(a,b);
        cout<<dis[a]+dis[b]-2*dis[lca]<<endl;
    }
    
    
    return 0;
}

