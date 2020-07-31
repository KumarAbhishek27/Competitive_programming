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
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

const int mxN = 1e5 + 10;

int n, m;
vector<int> tree[mxN];
int dp[mxN][300], bit[300];

int dfs(int x, int par, int mask){
    if(dp[x][mask] != -1)
        return dp[x][mask];
    
    int result = 0;
    for(int i = 1; i <= m; ++i){
        int flag = 1;
        int p = 1;
        for(int u : tree[x]){
            if(u == par) continue;
            p = (p * dfs(u, x, mask & bit[i])) % mod;
            flag = 0;
        }

        if(flag){
            if((mask & bit[i]) == 0) ++result;
        }
        else result = (result + p) % mod;
    }

    return dp[x][mask] = result;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //int n, m;
    cin >> n >> m;

    for(int i = 0; i < n - 1; ++i){
        int x, y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    memset(bit, 0, sizeof(bit));
    int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    for(int i = 1; i <= m; ++i){
        for(int j = 0; j < 8; ++j){
            if(i % prime[j] == 0) bit[i] |= (1 << j);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(1, -1, 255) << endl;
    
    
    return 0;
}
