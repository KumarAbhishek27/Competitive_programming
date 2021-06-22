#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
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
//const int mod = 998244353;
const int mod = 1e9 + 7;
//=========================================


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int nodes, edges;
    cin >> nodes >> edges;

    // adjacency list
    vector<pair<int, int> > graph[nodes];

    // input graph edges
    for(int i = 0; i < edges; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	graph[u].push_back({v, w});
    	graph[v].push_back({u, w});
    }


    int parent[nodes], key[nodes];
    bool mstSet[nodes];

    // initialize values
    for(int i = 0; i < nodes; ++i) {
    	key[i] = INT_MAX;
    	mstSet[i] = false;
    }

    // priority queue for getting node with minimum weight
    priority_queue<pii, vpii, greater<pii>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
     
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
  
    while(!pq.empty()) { 
        int u = pq.top().second; 
        pq.pop(); 
        
        // include the node in MST
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    }

    // print the MST
    for(int i = 1; i < nodes; ++i) {
    	cout << parent[i] << " - " << i << '\n';
    }

    return 0;
}

