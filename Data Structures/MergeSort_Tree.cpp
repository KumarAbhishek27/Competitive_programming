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

// Merge Sort Tree

const int mxN = 1005;
vector<int> tree[4 * mxN];
int a[mxN];

void build(int v, int tl, int tr){
    if(tl == tr){
        tree[v] = vector<int>(1, a[tl]);
    }
    else{
        int tm = (tl + tr) / 2;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        // now merge the two children similar to merge_sort
        merge(tree[v<<1].begin(), tree[v<<1].end(), tree[v<<1|1].begin(), tree[v<<1|1].end(), back_inserter(tree[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int k){
    if(l > r)
        return 0;
    if(l == tl && r == tr){
        auto it = upper_bound(tree[v].begin(), tree[v].end(), k - 1);
        int res = 0; 
        if(it != tree[v].end())
            res = it - tree[v].begin();
        return res;
    }

    int tm = (tl + tr) / 2;
    int left = query(v << 1, tl, tm, l, min(r, tm), k);
    int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, k);

    return (left + right);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    //#endif

    // problem: for each query of type L R K -> find the number of elements strictly less than k
    // in range [L, R] in the given array;

    int n, q, L, R, K;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    // Build the merge sort tree
    build(1, 1, n);

    // Input the queries
    for(int i = 0; i < q; ++i){
        cin >> L >> R >> K;
        int ans_query = query(1, 1, n, L, R, K);
        cout << ans_query << endl;
    }


    return 0;
}
