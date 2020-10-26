/*
You are given a road network of a country. The country has n cities in it and n−1 roads connecting them in such a way that there is exactly one way (path) to reach from a city to another. Two cities are said to be neighbours of each other if they are connected via a direct road (i.e. without passing through any other city) between them.

There are some terrorists that want to harm the country. The terrorists have developed two kinds of dangerous chemicals. When these chemicals come in contact with each other, it creates a huge explosion. They plan to infect two cities on the same day, one with chemical A and another with chemical B. With each passing day, these chemicals spread one node at time, to all neighbors of an infected city. That is, on the i-th day, every city which is a neighbor of a city infected with chemical A on day i-1, will now also be infected with chemical A. Similarly with chemical B as well.

To maximize suspense and terror among the public, the terrorists will select the starting two cities, so as to maximize the number of days before the big explosion happens. The big explosion happens when there is a city which is infected by both the chemicals.

Find out the number of days after the initial infections, when the explosion will happen.

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

const int mxN = 1e5 + 10;
vector<int> g[mxN];
bool vis[mxN];
int maxD, maxNode;

void dfs(int node, int d){
    vis[node] = true;
    if(d > maxD){
        maxD = d, maxNode = node;
    }
    for(int child : g[node]){
        if(!vis[child]){
            dfs(child, d + 1);
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

    int T;
    cin >> T;
    while(T--) {

        for(int i = 0; i < mxN; ++i) {
            g[i].clear();
        }

        int n,a,b;
        cin >> n;
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < n - 1; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        // dfs # 1
        maxD = -1;
        dfs(1,0);

        // dfs # 2
        memset(vis, false, sizeof(vis));
        maxD = -1;
        dfs(maxNode, 0);

        int maxTime = ceil(maxD * 1.0 / 2);
        //cout << maxD << "\n";

        cout << maxTime << "\n";
    }
    return 0;
}
