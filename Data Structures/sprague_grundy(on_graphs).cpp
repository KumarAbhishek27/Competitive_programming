#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define INF 1e9+7
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;

const int mxN = 1e5 + 10;
int grundy[mxN];
vector<int> adj[mxN];

int calculateMex(unordered_set<int> &s){
    int mex = 0;
    while(s.find(mex) != s.end())
        ++mex;
    return (mex);
}

int get_grundy(int v){
    if(grundy[v] != -1)
        return grundy[v];

    bool ok = 0;
    unordered_set<int> s;
    for(int u : adj[v]){
        if(ok == 0) ok = 1;
        s.insert(get_grundy(u));
    }

    grundy[v] = calculateMex(v);
    return (grundy[v]);
}

void declareWinner(vector<int> &stones){
    int xorValue = 0;
    memset(grundy, -1, sizeof grundy);

    int m = stones.size();
    for(int i = 0; i < m; ++i)
        xorValue ^= get_grundy(stones[i]);

    if(xorValue)
        cout << "Player1 Wins\n";
    else
        cout << "Player2 Wins\n";
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int q;
    cin >> q;
    vector<int> pts(q);
    for(int i = 0; i < q; ++i)
        cin >> pts[i];
    
    declareWinner();
    cout << endl;

    return 0;
}
