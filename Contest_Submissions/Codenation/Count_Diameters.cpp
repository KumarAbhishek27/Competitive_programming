#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 25;

vector<int> gr[N], gr1[N];
int dis[N], vis[N], res[N];

void dfs(int cur, int par) {
    vis[cur] = 1;
    for (auto x : gr1[cur]) {
        if (x != par) {
            dis[x] = dis[cur] + 1;
            dfs(x, cur);
        }
    }
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        m = n - 1;
        for (i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        for (i = 1; i < (1 << n); i++) {
            vector<int> v;
            for (j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    v.pb(j);
                    for (auto x : gr[j]) {
                        if ((i >> x) & 1) {
                            gr1[j].pb(x);
                        }
                    }
                }
            }
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            for (auto x : v) {
                if (!vis[x]) {
                    dfs(x, -1);
                    cnt++;
                }
            }
            if (cnt > 1) {
                for (j = 0; j < n; j++) {
                    gr1[j].clear();
                }
                continue;
            }
            ans = v[0];
            for (auto x : v) {
                if (dis[x] > dis[ans]) ans = x;
            }
            memset(dis, 0, sizeof(dis));
            dfs(ans, -1);
            ans = v[0];
            for (auto x : v) {
                if (dis[x] > dis[ans]) ans = x;
            }
            res[dis[ans]]++;
            for (j = 0; j < n; j++) {
                gr1[j].clear();
            }
        }
        for (i = 1; i < n; i++) {
            cout << res[i] << '\n';
        }
    }
}