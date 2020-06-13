// problem link :- https://open.kattis.com/problems/magicalcows
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

const int MAX_DAYS = 50;
int C, N, M;
int dp[55][1005];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    cin >> C >> N >> M;
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < N; ++i){
        int x; cin >> x;
        dp[0][x]++;
    }

    for(int day = 0; day < MAX_DAYS; ++day){
        for(int i = 1; i <= C; ++i){

            if(i <= C / 2){
            // Cow count on farm with size `i` doubled, but the number of farms did not.
                dp[day + 1][i * 2] += dp[day][i];
            }
            else{
            // The number of cows per farm on the farm with size `i` exceeds the
            // permitted limit, so double the number of farms.
                dp[day + 1][i] += 2 * dp[day][i];
            }
        }
    }


    for(int i = 0; i < M; ++i){
        int day; cin >> day;
        int answer_query = 0;
        for(int cnt = 0; cnt <= C; ++cnt)
            answer_query += dp[day][cnt];

        cout << answer_query << endl;
    }

    return 0;
}
