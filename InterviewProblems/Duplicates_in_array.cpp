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

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    // using the original array as HashMap
    // because a[i] -> [0, n - 1]
    for(int i = 0; i < n; ++i){
        a[(a[i] % n)] = a[(a[i] % n)] + n;
    }

    cout << "Duplicate Elements are: ";
    for(int i = 0;  i < n; ++i){
        if(a[i] >= n * 2)
            cout << i << ' ';
    }

    cout << "\n";

    return 0;
}
