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

struct node{
    int num=0;
    map<char,int>child;
};
vector<node>t;
void _insert(string s){
    int curr=0;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(t[curr].child.count(c)){
            curr=t[curr].child[c];
        }else{
            t[curr].child[c]=t.size();
            t.pb(node());
            curr=t[curr].child[c];            
        }
        t[curr].num++;
    }
}
int query(string s){
    int curr=0;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(t[curr].child.count(c)){
            curr=t[curr].child[c];
        }else{
            return 0;
        }
    }
    return t[curr].num;
}
int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    t.pb(node());
    for(int i=0;i<n;i++){
        cin>>s;
        _insert(s);
    }
    while(q--){
        cin>>s;
        cout<<query(s)<<endl;
    }
    

    return 0;
}
