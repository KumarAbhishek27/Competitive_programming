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
int subTree[mxN];
 
void dfs(int v, int par = -1){
    subTree[v] = 1;
    for(int u : tree[v]){
        if(u == par) continue;
        dfs(u, v);
        subTree[v] += subTree[u];
    }
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //#ifndef ONLINE_JUDGE
    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    //#endif
 
    int n;
    cin >> n;
 
    for(int i = 2; i <= n; ++i){
        int x; cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
 
    memset(subTree, 0, sizeof(subTree));
    dfs(1, -1);
 
    for(int i = 1; i <= n; ++i)
        cout << subTree[i] - 1 << ' ';
    cout << endl;
 
    return 0;
}
