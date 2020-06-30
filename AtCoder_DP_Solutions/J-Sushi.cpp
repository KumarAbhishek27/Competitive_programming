#include<bits/stdc++.h>
#define ll double
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[301][301][301];
ll solve(int one, int two, int three, int& n)
{
    if(one < 0 || two < 0 || three < 0)
        return 0;
    if(three == 0 && two == 0 && one == 0)
        return 0;

    if(dp[one][two][three] > 0)
        return dp[one][two][three];

    int remaining = one + two + three;
    ll exp_val = n+one*solve(one-1,two,three,n) + two*solve(one+1,two-1,three,n) +
                    three*solve(one,two+1,three-1,n);

    return dp[one][two][three] = exp_val/remaining;
}

int main(){
    int i,j,t,n,m,p,k;
    //fast_io;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        int one=0,two=0,three=0;

        fr(0,n){
            int x;
            cin >> x;
            if(x == 1)one++;
            else if(x == 2)two++;
            else three++;
        }

        memset(dp, -1, sizeof dp);
        cout<<fixed<<setprecision(9)<<solve(one,two,three,n);
    }
    return 0;
}
