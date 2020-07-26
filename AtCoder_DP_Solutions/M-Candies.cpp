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


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int dp[n + 1][k + 1];
    dp[0][0] = 1;

    for(int i = 1; i <= k; ++i)
        dp[0][i] = 0;

    for(int i = 1; i <= n; ++i){
        vector<int> sum(k + 1);
        sum[0] = dp[i - 1][0];

        for(int j = 1; j <= k; ++j)
            sum[j] = (sum[j - 1] % mod + dp[i - 1][j] % mod) % mod;

        for(int j = 0; j <= k; ++j){
            int tmp = sum[j];
            int unreachable = j - a[i] - 1;

            if(unreachable >= 0)
                tmp = (tmp - sum[unreachable] + mod) % mod;

            dp[i][j] = tmp;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
