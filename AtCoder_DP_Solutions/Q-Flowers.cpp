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
//const int N = 2e5+5, M = N;
//=========================================

// This problem is a variation of Longest Increasing Subsequence
// so we optimize the complexity using fenwick tree

const int MAXN = 2e5 + 10;
int N;
int dp[MAXN], h[MAXN], a[MAXN];
int bit[MAXN];

// update the fenwick tree
void update(int idx, int val){
    while(idx <= N){
        bit[idx] = max(bit[idx], val);
        idx += (idx & -idx);
    }
}

// answer the query for idx
int query(int idx){
    int result = 0;
    while(idx > 0){
        result = max(result, bit[idx]);
        idx -= (idx & -idx);
    }
    return result;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i)
        cin >> h[i];

    for(int i = 1; i <= N; ++i)
        cin >> a[i];

    for(int i = 1; i <= N; ++i){
        // dp[i] --> stores the max total beauty if the increasing sequence
        // ended at a flower of height i.

        // query(h[i] - 1) --> returns the maximum value of beauty of an increasing sequence in range [0, h[i] - 1].
        dp[i] = query(h[i] - 1) + a[i]; // add beauty of the current flower to the max sequence

        // update the max beauty value at index h[i] i.e, the value for increasing sequence ending at this flower.
        update(h[i], dp[i]);
    }

    int best = 0;
    for(int i = 1; i <= N; ++i){
        // find the max value by traversing through total beauty values
        // of each flower height.
        best = max(best, dp[i]);
    }

    // Print the max possible answer.
    cout << best << "\n";

    return 0;
}
