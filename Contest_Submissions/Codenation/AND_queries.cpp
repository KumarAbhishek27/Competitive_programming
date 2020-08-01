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
int cnt[mxN][32];
int a[mxN];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, L, R, s, t;
    cin >> n;

    //vector<int> a(n);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    memset(cnt, 0, sizeof(cnt));
    for(int bit = 31; bit >= 0; --bit){
        cnt[1][bit] = ((a[1] & (1 << bit)) ? 1 : 0);
        for(int i = 2; i <= n; ++i){
            cnt[i][bit] = cnt[i - 1][bit] + ((a[i] & (1 << bit)) ? 1 : 0);
        }
    }
    int garbage;
    cin >> q;
    cin >> garbage;
    for(int idx = 0; idx < q; ++idx){
        cin >> L >> R >> s >> t;
        int ans = 0;
        int tmpAnd = 0;
        int b = L, e = L + s - 1;
        while(e <= R){
            tmpAnd = 0;
            for(int bit = 31; bit >= 0; --bit){
                int val = cnt[e][bit] - cnt[b - 1][bit];
                if(val == s){
                    tmpAnd |= (1 << bit);
                }
            }

            if(tmpAnd >= t) ++ans;
            b++;
            e++;
        }

        cout << ans << endl;
    }

    return 0;
}
