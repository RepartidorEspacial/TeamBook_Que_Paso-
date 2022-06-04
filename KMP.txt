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

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vi v;
    v.pb(0);
    for(int i=1;i<n;i++){
        int j=v[i-1];
        while(s[j]!=s[i] && j>0){
            j=v[j-1];
        }
        if(s[i]==s[j]){
            v.pb(j+1);
        }else{
            v.pb(0);
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }



    return 0;
}
