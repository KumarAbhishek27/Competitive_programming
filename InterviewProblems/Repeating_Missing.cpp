// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include <bits/stdc++.h>
#define int long long int
using namespace std;
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;

// Time Complexity : O(N)
// Space Complexity : O(1)

pair<int, int> rep_miss(vector<int> &a, int n){
    
    int res = n;
    for(int i = 0; i < n; ++i)
        res = res ^ a[i] ^ i;
    
    int x = 0, y = 0;

    // res stores (x ^ y)
    // find the rightmost bit in res
    int k = log2(res & -res);

    // splitting the array into two subarrays
    for(int i = 0; i < n; ++i){
        // array elements that have kth bit set
        if(a[i] & (1 << k))
            x ^= a[i];
        // array elements that have kth bit unset
        else
            y ^= a[i];
    }

    // splitting the range[1-n] into two subranges
    for(int i = 1; i <= n; ++i){
        // if kth bit is set in i
        if(i & (1 << k))
            x ^= i;
        // if kth bit is unset in i
        else
            y ^= i;
    }

    return make_pair(x ,y);
}

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    pair<int,int> ans = rep_miss(a, n);
    cout << ans.first << ' ' << ans.second << "\n";

    return 0;
}
