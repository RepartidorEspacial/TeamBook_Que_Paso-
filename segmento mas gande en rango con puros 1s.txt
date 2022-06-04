#include "meetings.h"
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
using namespace std;
const int tam=100005;
int T[4*tam];
int B[4*tam];
int A[4*tam];
vi v;
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        A[nodo]=B[nodo]=T[nodo]=(v[b]==1);return;
    }
    init(L,b,mid);init(R,mid+1,e);
    A[nodo]=A[L],B[nodo]=B[R];
    if(A[L]==(mid-b+1))A[nodo]+=A[R];
    if(B[R]==e-mid)B[nodo]+=B[L];
    T[nodo]=max({T[L],T[R],B[L]+A[R]});
}
pair<ll,pair<ll,ll> > query(int nodo, int b, int e, int izq, int der){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b>=izq && e<=der)return {T[nodo],{A[nodo],B[nodo]}};
    if(der<=mid)return query(L,b,mid,izq,der);
    if(izq>=mid+1)return query(R,mid+1,e,izq,der);
    pair<ll,pair<ll,ll> >x=query(L,b,mid,izq,der);
    pair<ll,pair<ll,ll> >y=query(R,mid+1,e,izq,der);
    ll NA=x.S.F,NB=y.S.S;
    if(x.S.F==(mid-b+1)or(mid-izq+1==x.S.F))NA+=y.S.F;
    if(y.S.S==(e-mid)or(der-mid==y.S.S))NB+=x.S.S;
    ll TOT=max(x.F,y.F);
    TOT=max(TOT,x.S.S+y.S.F);
    return {TOT,{NA,NB}};
}
vector<long long> minimum_costs(vector<int> H,vector<int> L,vector<int> R){
    v=H;
    int n=H.size();
    int Q=L.size();
    init(0,0,n-1);
    vector<ll>C;
    for(int i=0;i<Q;i++){
        pair<int,pair<int,int> >aux=query(0,0,n-1,L[i],R[i]);
        ll res=(R[i]-L[i]+1)*2;
        res-=aux.F;
        C.pb(res);
    }
    return C;
}
//4 2 2 4 3 5 0 2 1 3
