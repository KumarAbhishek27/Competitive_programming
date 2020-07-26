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
const int N = 1e5+5, M = N;
//=========================================

vector<int> adj[N];
int dp[N][2];

// dp[node][0] --> number of ways to build a valid subtree if node is white
// dp[node][1] --> number of ways to build a valid subtree if node is black

void dfs(int v, int par = -1){
    dp[v][0] = dp[v][1] = 1;
    for(int u : adj[v]){
        if(u == par) continue;
        dfs(u, v);
      	// if the current node is white then the color of the child doesn't matter
        dp[v][0] = (dp[v][0] * ((dp[u][0] + dp[u][1]) % mod)) % mod;
        // if the current node is painted black then each child must be white.
      	dp[v][1] = (dp[v][1] * dp[u][0]) % mod;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // calling dfs on the root of the tree
    dfs(1, -1);

    cout << (dp[1][0] + dp[1][1]) % mod << endl;

    return 0;
}
