#define LSOne(s) ( (s) & -(s))


int n; 
double cost[20][20] , memo[1<<20]; 

//min-cost perfect matching for regular graph 
//complexity O( n * 2^n * m  )  n <= 20 

double dp(int mask )
{
    double &ans = memo[mask ]; 
    if(ans > -0.5) return ans ; 
    if(mask == 0 ) return 0 ; 
    ans = 1e9 ; 
    int tp1 = LSOne(mask);
    int p1 = __builtin_ctz(tp1);
    int m = mask - tp1 ; 
    while(m){
        int tp2 = LSOne(m); 
        int p2 = __builtin_ctz(tp2);
        ans = min(ans , cost[p1][p2] + dp(mask^ tp1^ tp2));
        m -= tp2 ;  
    } 
    return ans; 
}


