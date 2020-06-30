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

vector<int> g[N];
int dp[N], vis[N];

int solve(int node){
    if(vis[node]) return dp[node];

    vis[node] = 1;
    int temp_best = 0;

    for(int child : g[node]){
        temp_best = max(temp_best, 1 + solve(child));
    }

    return dp[node] = temp_best;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }

    int best = 0;
    for(int i = 1; i <= n; ++i)
        best = max(best, solve(i));

    cout << best << endl;

    return 0;
}
