// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

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

// Time Complexity : O(n)
// Space Complexity : O(1)

int kadane_algo(vector<int> &a, int n){
    
    int max_so_far = a[0];
    int cur_max = a[0];

    for(int i = 1; i < n; ++i){
        cur_max = max(a[i], cur_max + a[i]);
        max_so_far = max(max_so_far, cur_max);
    }

    return max_so_far;
}

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int max_sum = kadane_algo(a, n);
    cout << max_sum << "\n";

    return 0;
}
