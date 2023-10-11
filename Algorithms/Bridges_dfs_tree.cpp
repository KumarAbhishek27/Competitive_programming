#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define f first
#define s second
//#define ll long long int
#define lld long double
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
//#define F first
//#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF (1ll << 60l)
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
//const int mod = 998244353;
const int mod = 1e9 + 7;
//=========================================

const int maxn = 3e5 + 10;

int bridgec;
int lvl[maxn], dp[maxn];
vector<int> graph[maxn];

void dfs(int v) {
    dp[v] = 0;
    for (int u : graph[v]) {
        if (lvl[u] == 0) {
            // edge to child: tree-edge
            lvl[u] = lvl[v] + 1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lvl[u] < lvl[v]) {
            // back-edge
            dp[v]++;
        } else if (lvl[u] > lvl[v]) {
            // edge going down
            dp[v]--;
        }
    }

    // parent edge isn't a backedge, subtract 1 to compensate;
    dp[v]--;

    if(lvl[v] > 1 && dp[v] == 0) {
        bridgec += 1;
    }
}

void solve_test_case() {

    int vertexc, edgec;
    cin >> vertexc >> edgec;

    for (int i = 0; i <= vertexc; ++i) {
        graph[i].clear();
        dp[i] = 0;
        lvl[i] = 0;
    }

    for (int i = 0; i < edgec; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bridgec = 0;
    lvl[1] = 1;
    dfs(1);

    cout << bridgec << '\n';

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int testcase = 1;
    //cin >> testcase;
    for (int t = 1; t <= testcase; ++t) {
        //cout << "Case #" << t << ": ";
        solve_test_case();
    }

    return 0;        
}
