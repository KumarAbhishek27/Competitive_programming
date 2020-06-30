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
//const int N = 1e5+5, M = N;
//=========================================

const int MAXN = 3005;
double dp[MAXN][MAXN], P[MAXN];
int vis[MAXN][MAXN], N;

double solve(int pos, int heads){

    if(heads < 0) return 0.0;

    if(pos == 0)
        return (heads == 0);

    if(vis[pos][heads])
        return dp[pos][heads];

    vis[pos][heads] = 1;
    dp[pos][heads] = P[pos] * solve(pos - 1, heads - 1) + (1 - P[pos]) * solve(pos - 1, heads);

    return dp[pos][heads];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> P[i];

    double probability = 0;
    for(int heads = 0; heads <= N; ++heads){
        int tails = N - heads;
        if(heads > tails) probability += solve(N, heads);
    }

    cout << fixed << setprecision(10) << probability << endl;

    return 0;
}
