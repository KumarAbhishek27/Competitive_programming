#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long int
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
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 2e3, M = N;
//=========================================

/*
     [Time Complexity]: In Kruskal’s algorithm, most time consuming operation is sorting 
     because the total complexity of the Disjoint-Set operations will be O(Elog(V)), 
     which is the overall Time Complexity of the algorithm.
*/

struct edge{
    int u;
    int v;
    int w;
};

edge ar[1000005];
int parent[100005];
int Rank[100005];

void make_set(int v){
    parent[v] = v;
    Rank[v] = 0;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void merge(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Rank[a] < Rank[b])
            swap(a,b);
        parent[b] = a;
        if(Rank[a] == Rank[b])
            ++Rank[a];
    }
}

bool cmp(edge a, edge b){
    if(a.w < b.w){
        return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++) make_set(i);

    int sum = 0;

    for(int i = 0; i<m; i++) cin >> ar[i].u >> ar[i].v >> ar[i].w;

    sort(ar, ar + m, cmp);

    for(int i = 0 ; i<m; i++){    
        int x, y;
        x = ar[i].u; y = ar[i].v;
        x = find_set(x);
        y = find_set(y);
        if(x != y){
            sum += ar[i].w;
            merge(x,y);
        }
    }

    cout << sum << endl;

    return 0;
}
