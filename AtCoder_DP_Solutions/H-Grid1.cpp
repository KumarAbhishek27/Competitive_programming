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
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

char a[1005][1005];
int dp[1005][1005];
int H, W;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j)
            cin >> a[i][j];
    }

    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            if((i == 1 && j == 1) || (a[i][j] == '#')) continue;
            dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]) % mod;
            dp[i][j] %= mod;
        }
    }

    cout << dp[H][W] << endl;
    return 0;
}
