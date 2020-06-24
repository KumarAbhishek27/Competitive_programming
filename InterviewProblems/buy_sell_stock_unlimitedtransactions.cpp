// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
// Space Complexity : O(1)

/*

find all the increasing sequences and add the difference 
between the start and end element of each increasing sequence
to the profit
                        or

find the all peaks following a valley and add
the difference to the total profit

*/

int sell_stock(vector<int> &a){
    
    int n = a.size();
    int profit = 0;

    int j = 0;
    for(int i = 1; i < n; ++i){
        if(a[i - 1] > a[i]) 
            j = i;
        if(a[i - 1] <= a[i] && (i + 1 == n || a[i] > a[i + 1]))
            profit += (a[i] - a[j]);
    }

    return profit;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int ans = sell_stock(a);
    cout << ans << endl;

    return 0;
}
