// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

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

// Time Complexity : O(n)
// Space Complexity : O(n)


int find_max_profit(vector<int> &price, int n){
    
    vector<int> profit(n);
    profit[n - 1] = 0;

    int max_so_far = price[n - 1];
    for(int i = n - 2; i >= 0; --i){
        // update profit[i] to the maximum profit earned by a single stock
        // transaction from day i to day n - 1
        profit[i] = max(profit[i + 1], max_so_far - price[i]);
        // update the maximum price seen so far
        max_so_far = max(max_so_far, price[i]);
    }

    int min_so_far = price[0];
    for(int i = 1; i < n; ++i){
        // update profit[i] by taking maximum of:
        // 1. profit[i - 1] which represents maximum profit so far
        // 2. total profit obtained by closing the first transaction on day i
        // and performing another transaction from day i to n - 1.
        profit[i] = max(profit[i - 1], price[i] - min_so_far + profit[i]);
        // update the minimum price seen so far
        min_so_far = min(min_so_far, price[i]);
    }

    // the last element of profit[] stores the result
    return profit[n - 1];
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int ans = find_max_profit(a, n);
    cout << ans << endl;

    return 0;
}
