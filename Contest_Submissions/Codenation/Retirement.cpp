#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int            int
#define ld             long double
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       _f (#VA_ARGS, __VA_ARGS_)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1005;
int a[N], n, m, k;
int cache[N][N][27];
string s;

int dp(int i, int j, int pre)
{
     if (i >= j)
          return 0;

     int &ans = cache[i][j][pre + 1];
     if (ans != -1)
          return ans;

     if (s[i] == s[j] && pre != s[i] - 'a')
          ans = max(ans, 2 + dp(i + 1, j - 1, s[i] - 'a'));

     ans = max(ans, dp(i + 1, j, pre));
     ans = max(ans, dp(i, j - 1, pre));
     return ans;

}

void solve()
{
     cin >> s;
     n = sz(s);

     memset(cache, -1, sizeof cache);
     cout << dp(0, n - 1, -1);

}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

     cout << setprecision(9) << fixed;
     clock_t z = clock();
     solve();
     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

     return 0;
}