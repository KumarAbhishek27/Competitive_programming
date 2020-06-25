// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================

// Time Complexity : O(n * k)
// Space Complexity : O(n * k)

// profit using unlimited transactions
int greedy(vector<int>& prices){
        int len = prices.size();
        int profit = 0;
        for (int i = 1; i < len; i++){
          if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
        }
        return profit;
}

// profit using atmost k transactions
int find_max_profit(vector<int> &price, int k){
    
    int n = price.size();
    if(n == 0 || n == 1) return 0;

    if(k >= n / 2)
        return greedy(price);

    int dp[k + 1][n + 1];

    for(int i = 0; i <= k; ++i){
        int prev_diff = INT_MIN;
        for(int j = 0; j < n; ++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                prev_diff = max(prev_diff, dp[i - 1][j - 1] - price[j - 1]);
                dp[i][j] = max(dp[i][j - 1], price[j] + prev_diff);
            }
        }
    }

    return dp[k][n - 1];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int ans = find_max_profit(a, k);
    cout << ans << endl;

    return 0;
}
