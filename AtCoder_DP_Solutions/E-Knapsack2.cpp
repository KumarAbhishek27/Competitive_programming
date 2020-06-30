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
const int mod = 1000000007;
const int N = 2e5+5, M = N;
//=========================================

const int MAXV = 1e5 + 10;
const int MAXN = 1e3 + 10;

int dp[MAXV];
int n, W, V, wi[MAXN], value[MAXN];


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int n, W;
    cin >> n >> W;

    for(int i = 1; i <= n; ++i){
        cin >> wi[i] >> value[i];
        V += value[i];
    }

    for(int i = 1; i <= V; ++i) dp[i] = 1e13;
    dp[0] = 0;

    for(int item = 1; item <= n; ++item){
        int w = wi[item], v = value[item];
        for(int i = V; i >= v; --i)
            dp[i] = min(dp[i], dp[i - v] + w);
    }

    for(int i = V; i >= 0; --i){
        if(dp[i] <= W){
            cout << i << endl;
            break;
        }
    }


    return 0;
}
