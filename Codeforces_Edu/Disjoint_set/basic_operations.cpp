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

const int mxN = 1e5 + 10;
int parent[mxN], SZ[mxN];

void make_set(int x){
    parent[x] = x;
    SZ[x] = 1;
}

int find_set(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void Unite(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(SZ[u] < SZ[v])
            swap(u, v);
        parent[v] = u;
        SZ[u] += SZ[v];
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        make_set(i);
        //cout << parent[i] << ' ';
    }
    //cout << endl;

    for(int i = 0; i < m; ++i){
        string query_type;
        int u, v;
        cin >> query_type >> u >> v;
        //cout << query_type << ' ' << u << ' ' << v << endl;
        if(query_type == "union"){
            //cin >> u >> v;
            Unite(u, v);
        }

        if(query_type == "get"){
            u = find_set(u);
            v = find_set(v);
            //cout << u << ' ' << v << endl;
            if(u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
