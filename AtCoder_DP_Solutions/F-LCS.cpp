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
//const int N = 2e5+5, M = N;
//=========================================

const int MAXN = 3010;

string s, t;
int dp[MAXN][MAXN], N, M;
stack<char> resposta;

int solve(int a, int b){
    if(a < 0 || b < 0) return 0;

    if(dp[a][b] != -1) return dp[a][b];

    if(s[a] == t[b]) return dp[a][b] = 1 + solve(a - 1, b - 1);

    return dp[a][b] = max(solve(a - 1, b), solve(a, b - 1));
}

void build(int a, int b){
    if(a < 0 || b < 0) return;

    if(s[a] == t[b]){
        resposta.push(s[a]);
        build(a - 1, b - 1);
        return;
    }

    if(solve(a - 1, b) > solve(a, b - 1)) build(a - 1, b);
    else build(a, b - 1);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> s;
    cin >> t;
    N = (int)s.size();
    M = (int)t.size();

    build(N - 1, M - 1);

    while(!resposta.empty()){
        cout << resposta.top();
        resposta.pop();
    }

    cout << endl;

    return 0;
}
