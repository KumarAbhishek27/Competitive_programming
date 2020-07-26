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
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================

const int MAXN = 405;
int n;
int a[MAXN], pre[MAXN];
int dp[MAXN][MAXN];

int slimes(int i, int j){
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = LLONG_MAX;
    for(int k = i; k <= j; ++k){
        int x = (pre[k] - pre[i - 1]);
        int y = (pre[j] - pre[k]);
        x += y;
        dp[i][j] = min(dp[i][j], slimes(i, k) + slimes(k + 1, j) + x);
    }

    return dp[i][j];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    memset(pre, 0, sizeof(pre));

    pre[0] = a[0];
    for(int i = 1; i < n; ++i)
        pre[i] = (pre[i - 1] + a[i]);

    cout << slimes(0, n - 1) << endl;

    return 0;
}
