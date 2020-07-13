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

const int mxN = 500001;

int dp[mxN][2];
vector<int> tree[mxN];

void dfs(int src, int par, vector<int> &ancestors, int &dis, int aORb){
    dp[src][aORb] = 1;
    ancestors.push_back(src);

    for(int child : tree[src]){
        if(child == par) continue;
        dfs(child, src, ancestors, dis, aORb);
    }

    ancestors.pop_back();
    int totalAncestors = ancestors.size();
    if(totalAncestors >= dis){
        dp[ancestors[totalAncestors - dis]][aORb] += dp[src][aORb];
    }
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";

        int n, a, b;
        cin >> n >> a >> b;

        for(int i = 1; i <= n; ++i) tree[i].clear();

        for(int i = 0; i < n - 1; ++i){
            int x; cin >> x;
            tree[i + 2].push_back(x);
            tree[x].push_back(i + 2);
        }

        vector<int> dfsOfTree; // to store the ancestors of a node

        dfs(1, 0, dfsOfTree, a, 0);
        dfs(1, 0, dfsOfTree, b, 1);

        double ans = 0;
        for(int i = 1; i <= n; ++i){
            ans = (ans + n * (dp[i][0] + dp[i][1]));
            ans = (ans - (dp[i][0] * dp[i][1]));
        }
        
        double res = (double)ans / (double)(n*n);
        cout << fixed << setprecision(9) << res << "\n";
    }

    return 0;
}
