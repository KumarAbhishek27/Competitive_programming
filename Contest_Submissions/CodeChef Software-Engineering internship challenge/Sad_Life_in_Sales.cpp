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
#define INF (1ll << 60l)
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
//=========================================

const int mxN = 2e5 + 1;
vector<pair<int, int> > tree[mxN];
int up[mxN][20];
int level[mxN], dist[mxN];

void dfs(int v, int par, int lvl, int curd) {
    level[v] = lvl;
    dist[v] = curd;

    // visit children nodes
    for(auto edge : tree[v]) {
        int u = edge.first;
        int len = edge.second;
        if(u == par) continue;
        dfs(u, v, lvl + 1, curd + len);
    }
}


void binary_lifting(int src, int par) {
    up[src][0] = par; // mark the direct parent
    for(int i = 1; i < 20; ++i) {
        if(up[src][i - 1] != -1) {
            up[src][i] = up[up[src][i - 1]][i - 1];
        } else {
            up[src][i] = -1;
        }
    }

    // do the same for children
    for(auto edge : tree[src]) {
        int child = edge.first;
        if(child == par) continue;
        binary_lifting(child, src);
    }
}

int lift_node(int node, int jump_required) {
    for(int i = 19; i >= 0; --i) {
        if(jump_required == 0 || node == -1)
            break;

        if(jump_required >= (1 << i)) {
            jump_required -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}

int LCA(int u, int v){
    if(level[u] < level[v])
        swap(u, v);

    u = lift_node(u, level[u] - level[v]);
    if(u == v)
        return u;

    for(int i = 19; i >= 0; --i){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return lift_node(u, 1);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) {

        for(int i = 0; i < mxN; ++i) {
            tree[i].clear();
        }

        int N, Q, R;
        cin >> N >> Q >> R;

        for(int i = 0; i + 1 < N; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }

        // for calculating level and distance of each node from the root
        dfs(R, -1, 0, 0);

        // perform binary lifting
        binary_lifting(R, -1);

        // Now answer the queries
        while(Q--) {
            int u, v;
            cin >> u >> v;

            int parent = LCA(u, v);
            int ansQuery = dist[u] + dist[v] - 2 * dist[parent];
            cout << ansQuery << "\n";
        }
    }

    return 0;
}
