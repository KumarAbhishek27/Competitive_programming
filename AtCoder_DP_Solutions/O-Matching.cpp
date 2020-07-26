#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 100000000000
#define BLK 555
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int MOD = 998244353;
const int N = 2e5+5, M = N;
//=========================================
 
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cin >> a[i][j];
        }
 
        int dp[1ll << n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
 
        for(int mask = 0; mask < (1ll << n); ++mask){
            int topics_taken = __builtin_popcount(mask);
            for(int j = 0; j < n; ++j){
                if(a[topics_taken][j] == 0 || (mask & (1ll << j)))
                    continue;
                dp[mask|(1ll << j)] = (dp[mask|(1ll << j)] + dp[mask]) % mod;
            }
        }
 
        cout << dp[(1ll << n) - 1] << endl;
    }
 
    return 0;
}
