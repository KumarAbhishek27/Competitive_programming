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

const int mxN = 2e5 + 10;
vector<int> tree[mxN];
int up[mxN][20];
int level[mxN];

void dfs(int v, int par, int lvl = 0){
    level[v] = lvl;
    for(int u : tree[v]){
        if(u == par) continue;
        dfs(u, v, lvl + 1);
    }
}

void binary_lifting(int src, int par){
    up[src][0] = par; // direct parent

    // calculate every parent at distance 2^i above
    for(int i = 1; i < 20; ++i){
        if(up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else up[src][i] = -1;
    }

    for(int child : tree[src]){
        if(child == par) continue;
        binary_lifting(child, src);
    }
}

int lift_node(int node, int jump_required){
    for(int i = 19; i >= 0; --i){
        if(jump_required == 0 || node == -1)
            break;

        if(jump_required >= (1 << i)){
            jump_required -= (1 << i);
            node = up[node][i];
        }
    }

    return node;
}


// LCA using binary Search
// Time Complexity: O(log(n) * log(n))

int LCA1(int u, int v){
    if(level[u] < level[v])
        swap(u, v);

    u = lift_node(u, level[u] - level[v]);

    int lo = 0, hi = level[u];
    //int ans;
    while(lo != hi){
        int mid = (lo + hi) / 2;
        int x1 = lift_node(u, mid);
        int x2 = lift_node(v, mid);
        if(x1 == x2)
            hi = mid;
        else
            lo = mid + 1;
    }

    return lift_node(u, lo);
}

// LCA using binary lifting
// Time Complexity: O(log(n))

int LCA2(int u, int v){
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

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    //#endif

    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; ++i){
        int x; cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }


    // For calculating the level of each node
    dfs(1, -1, 0);

    // For filling the parent array(up array)
    binary_lifting(1, -1);

    while(q--){
        int u, v;
        cin >> u >> v;

        int parent = LCA2(u, v);
        //int parent = LCA1(u, v);
        cout << parent << endl;
    }

    return 0;
}
