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
using namespace std;
//suma en rangos con segment tree
vi T,v;
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        T[nodo]=v[b];return;
    }
    init(L,b,mid);init(R,mid+1,e);
    T[nodo]=min(T[L],T[R]);
}

int c=0;
void update(int pos,int val,int nodo,int b,int e){
    int L=2*nodo+1,R=2*nodo+2,mid=(b+e)/2;
    if(b==e && b==pos){
        T[nodo]=val;
        return;
    }
    if(pos>=b && pos<=mid){
        update(pos,val,L,b,mid);
    }else{
        update(pos,val,R,mid+1,e);
    }
    T[nodo]=T[L]+T[R];
}
int query(int nodo, int b, int e, int izq, int der){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b>=izq && e<=der)return T[nodo];
    if(der<=mid)return query(L,b,mid,izq,der);
    if(izq>=mid+1)return query(R,mid+1,e,izq,der);
    return min(query(L,b,mid,izq,der),query(R,mid+1,e,izq,der));
}
int main()
{
    int n,x;
    cin>>n;
    T.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    init (0,0,n-1);
    cout<<query(0,1,3,0,n-1)<<endl;
    cout<<query(0,2,3,0,n-1)<<endl;
    update(2,4,0,0,n-1);
    cout<<query(0,1,3,0,n-1)<<endl;
    cout<<query(0,2,3,0,n-1)<<endl;

    return 0;
}
