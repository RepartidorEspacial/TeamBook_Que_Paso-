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
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;

using namespace std;

int main()
{
    //calculate all subsets

    int n,x;
    cin>>n;
    vi v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    for(int i=0;i<(1<<n);i++){
        vi vv;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                vv.pb(v[j]);
            }
        }
        for(int l=0;l<vv.size();l++){
            cout<<vv[l]<<" ";
        }
        cout<<endl;

    }


    return 0;
}
