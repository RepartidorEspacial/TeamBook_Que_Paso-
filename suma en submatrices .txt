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
    int n,m,x;
    cin>>n>>m;
    int M[n+1][m+1];
    int res[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            cin>>M[i][l];
            res[i][l]=0;
            res[i-1][l]=0;
            res[i][l-1]=0;
            if(i==1){
                continue;
            }
            M[i][l]+=M[i-1][l];
        }
    }
    res[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int l=1;l<=n;l++){
            res[l][i]=res[l][i-1]+M[l][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            cout<<res[i][l]<<" ";
        }
        cout<<endl;
    }
    int q,y,xx,yy;
    ///x,y=coordenadas del primer punto xx,yy=coordenadas del segundo punto

    cin>>q;
    while(q--){
        cin>>xx>>yy>>x>>y;
        cout<<res[xx][yy]-res[xx][y-1]-res[x-1][yy]+res[x-1][y-1]<<endl;
    }
    //3 4 1 3 4 7 4 3 5 5 6 5 4 2


    return 0;
}
