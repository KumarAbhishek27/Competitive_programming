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

// { LCA using Euler Tour }
// Time Complexity: O(N) preprocessing and answering queries in O(log(N))

struct LCA{

    vector<int> height, euler, first, segTree;
    vector<int> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0){
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(2 * n);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segTree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0){
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for(auto to : adj[node]){
            if(!visited[to]){
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e){
        if(b == e)
            segTree[node] = euler[b];
        else{
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segTree[node << 1], r = segTree[node << 1 | 1];
            segTree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R){
        if(b > R || e < L)
            return -1;
        if(b >= L && e <= R)
            return segTree[node];
        
        int mid = (b + e) >> 1;
        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if(left == -1) return right;
        if(right == -1) return left;
        return (height[left] < height[right]) ? left : right;
    }

    int lca(int u, int v){
        int left = first[u], right = first[v];
        if(left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }

};

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    //#endif
    
    /*
       ================== INSERT TESTING CODE =================
    */

    return 0;
}
