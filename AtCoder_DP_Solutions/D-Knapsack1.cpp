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
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

int weight[105], value[105];
int dp[105][N];

int knapsack(int n, int W){

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= W; ++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(weight[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i-1]], dp[i - 1][j]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    cin >> n >> W;

    for(int i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];


    int ans = knapsack(n, W);

    cout << ans << endl;
    return 0;
}
