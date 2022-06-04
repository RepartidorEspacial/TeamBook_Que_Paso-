//all permutations 
#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back

using namespace std;

int main()
{
    int n,x;
    vi v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    while(next_permutation(v.begin(),v.end())){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
