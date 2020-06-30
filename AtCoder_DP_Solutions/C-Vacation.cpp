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
#define INF 100000000000
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

int a[N][3], dp[N][3];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    memset(dp, 0, sizeof(dp));

    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];

    for(int i = 2; i <= n; ++i){
        dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}
