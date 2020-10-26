/*
In a far away Galaxy of Tilky Way, there was a planet Tarth where the sport of Tompetitive Toding was very popular. According to legends, there lived a setter who loved giving optimized Dijkstra and Floyd Warshall algorithms in TCDSAP exams.

Commander Tresdin, having obtained stones, must hurry out of the abyss to save Stonehall! The abyss can be represented as an unweighted graph G containing N nodes and M edges. The abyss is chaotic, and hence G can be disconnected as well. K out of these N nodes are special nodes which have a portal to escape from the abyss.

Commander Tresdin met Rubik, the Grand Mage, who offered to help teleport her to the nearest portal. But for that, he needs to know the distance to the nearest portal (that is, the minimum number of edges that have to be traversed)! Hence, given Q queries, each giving a node u, i.e. the Node where Commander Tresdin and Rubik are, print the distance 
to reach the nearest special node. Print −1 if its not possible to reach a special node from their starting point.

′′We shall meet again after your conquest against the abyssal fire.′′
−Rubik
*/


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

const int mxN = 1e5 + 1;
vector<int> graph[mxN];
int dist[mxN];

void dijkstra(int n, vector<int> &special_nodes) {

    // Initialize the distances
    for(int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }

    // for applying multi-source dijkstra algorithm.
    priority_queue<pii, vpii, greater<pii> > pq;


    // mark the source nodes
    for(auto x : special_nodes) {
        dist[x] = 0;
        pq.push({dist[x], x});
    }

    while(!pq.empty()) {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if(curDist != dist[curNode]) continue;

        // visit adjacent nodes
        for(int nextNode : graph[curNode]) {
            if(dist[nextNode] > curDist + 1) {
                dist[nextNode] = curDist + 1;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int testcase;
    cin >> testcase;
    while(testcase--) {

        // initialization step
        for(int i = 0; i < mxN; ++i) {
            graph[i].clear();
        }

        int n, m, k, q;
        cin >> n >> m >> k;

        // input the edges
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }


        // Special Nodes
        vector<int> special_nodes;
        for(int i = 0; i < k; ++i) {
            int node; cin >> node;
            special_nodes.push_back(node);
        }

        // preprocess shortest distances from special nodes to non-special nodes
        dijkstra(n, special_nodes);

        // input queries
        cin >> q;
        while(q--) {
            int u; // starting node
            cin >> u;
            int minDist = (dist[u] == INF ? -1 : dist[u]);
            cout << minDist << "\n";
        }
    }

    return 0;
}
