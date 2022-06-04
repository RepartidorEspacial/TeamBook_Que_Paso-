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
//productor escalar x1*x2+y1*y2  si es 0 es pq son perpendiculares
//al producto cruz A^B es mayor a 0 si B esta a la izquierda de A 
struct point{
    ll x;
    ll y;
    point(int x=0,int y=0):x(x),y(y){}
    point operator -(point p){return point(x-p.x,y-p.y);}
    point operator +(point p){return point(x+p.x,y+p.y);}

    ll operator *(point p){return x*p.x+y*p.y;}
    ll operator ^(point p){return x*p.y-p.x*y;}
};
int main()
{
    
    return 0;
}