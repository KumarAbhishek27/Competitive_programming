#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;

//const int maxN = 100001;
const int BLK = 700;
const int maxN = 21;

vector<int> g[100001];

int nodeF[100001] , eleF[100001] , level[100001];
int LCA[100001][maxN] , val[100001] , res[200001];

int S[100001] , T[100001] , ft[200002];
int timer;

struct query{
    int l;
    int r;
    int c;
    int idx;
    int lca;
};

query Q[200001];

void dfs(int v, int par, int lvl){

    level[v] = lvl;
    LCA[v][0] = par;

    S[v] = timer;
    ft[timer] = v;
    timer++;

    for(int u : g[v]){
        if(u != par)
            dfs(u, v, lvl + 1);
    }

    T[v] = timer;
    ft[timer] = v;
    timer++;
}

void init(int n){
	
    for(int j = 1; j < maxN; ++j){
        for(int i = 1; i <= n; ++i){
            if(LCA[i][j-1] != -1){
                LCA[i][j] = LCA[LCA[i][j-1]][j-1];
            }
        }
    }
}

int getLCA(int a, int b){

    if(level[a] > level[b])
        swap(a, b);

    int d = level[b] - level[a];
	
	int f = 0;
 
	while(d)
	{
		if(d & 1)
		b = LCA[b][f];
 
		d >>= 1;
		f++;
	}

    if(a == b)
        return a;

    for(int i = maxN - 1; i >= 0; --i){
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
            a = LCA[a][i], b = LCA[b][i];
    }

    return LCA[a][0];
}

bool comp(query a , query b)
{
	int x = a.l / BLK;
	int y = b.l / BLK;
 
	if(x != y) return x < y;
	else
	return a.r < b.r;
}


void add(int idx){

    int node = ft[idx];
    //int c = col[node];
    nodeF[node]++;

    if(nodeF[node] == 1){
        int c = val[node];
        eleF[c]++;
    }

    else{
        int c = val[node];
        eleF[c]--;
    }
}

void remove(int idx){

    int node = ft[idx];
    //int c = val[node];
    nodeF[node]--;

    if(nodeF[node] == 1){
        int c = val[node];
        eleF[c]++;
    }

    else{
        int c = val[node];
        eleF[c]--;
    }
}



int main() {

    //ios_base::sync_with_stdio(false);

    int n, q, a, b, c;
    int t = 0;
    while(cin >> n){

        if(t > 0) cout << endl;
        t++;
        cin >> q;

        // Initialize
        for(int i = 0; i <= n; ++i)
            g[i].clear(), eleF[i] = 0, nodeF[i] = 0;

        for(int i = 1; i <= q; ++i)
            res[i] = 0;

        for(int i = 1; i <= n; ++i)
            cin >> val[i];

        for(int i = 0; i < n-1; ++i){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        timer = 1;
        memset(LCA, -1, sizeof(LCA));
        dfs(1, -1, 0);
        init(n);

        for(int i = 1; i <= q; ++i){
            cin >> a >> b >> c;

            if(S[a] > S[b])
                swap(a, b);

            int lca = getLCA(a, b);
            Q[i].idx = i;
            Q[i].c = c;

            // First type of query
            if(a == lca)
                Q[i].l = S[a], Q[i].r = S[b], Q[i].lca = -1;

            // Second type of query
            else
                Q[i].l = T[a], Q[i].r = S[b], Q[i].lca = lca;
        }

        sort(Q + 1, Q + 1 + q, comp);

        int ML = 1, MR = 0;

        for(int i = 1; i <= q; ++i){
            int L = Q[i].l;
            int R = Q[i].r;
            int c = Q[i].c;
            int idx = Q[i].idx;
            int lca = Q[i].lca;

            // Extending the Range
            while(ML > L) ML--, add(ML);
            while(MR < R) MR++, add(MR);

            // Reducing the Range
            while(ML < L) remove(ML), ML++;
            while(MR > R) remove(MR), MR--;

            if(eleF[c] > 0)
                res[idx] = 1;

            if(lca != -1 && (val[lca] == c))
                res[idx] = 1;
        }

        for(int i = 1; i <= q; i++){

            if(res[i] == 1){
                cout << "Find" << endl;
            }else{
                cout << "NotFind" << endl;
            }
        }
    }

    return 0;
}
