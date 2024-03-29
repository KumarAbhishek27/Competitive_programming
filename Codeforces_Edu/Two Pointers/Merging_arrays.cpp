/*

  For educational purposes, in the problems of this block, the time limit is large enough for the solution to pass in O(nlogn) time, but 
  try to write the solution in linear time, which we discussed in the lecture.  You are given two arrays, sorted in non-decreasing order. 
  Merge them into one sorted array.

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
//const int mod = 998244353;
const int mod = 1e9 + 7;
//const int N = 2e5+5, M = N;
//=========================================


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    int i = 0, j = 0, k = 0;
	  vector<int> c(n + m);

    while(i < n || j < m) {
      if(j == m || (i < n && a[i] < b[j])) {
        c[k++] = a[i++];
      } else {
        c[k++] = b[j++];
      }
    }

    for(auto x : c) {
      cout << x << ' ';
    }

    cout << '\n';


    return 0;
}
