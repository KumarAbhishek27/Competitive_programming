// https://leetcode.com/problems/unique-paths-iii/

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
const int N = 1e5+5, M = N;
//=========================================

// Time Complexity: O(4^n)
// Space Complexity: O(n)

int dfs(vector<vector<int> > &g, int i, int j, int s, int steps){
    if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] == -1)
        return 0;

    if(g[i][j] == 2)
        return (s == steps ? 1 : 0);
    
    g[i][j] = -1;
    int cnt = 0;
    for(int k = 0; k < 4; ++k){
        int x = i + dx[k];
        int y = j + dy[k];
        cnt += dfs(g, x, y, s + 1, steps);
    }

    g[i][j] = 0;
    return cnt;
}

int uniquePaths(vector<vector<int> > &grid){
    int n = grid.size();
    int m = grid[0].size();

    int sx = 0, sy = 0, steps = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1) sx = i, sy = j;
            if(grid[i][j] != -1) ++steps;
        }
    }

    return dfs(grid, sx, sy, 1, steps);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    int cnt = uniquePaths(grid);
    cout << cnt << endl;

    return 0;
}
