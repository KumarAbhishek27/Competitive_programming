// https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/

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

// Time Complexity : O(m * n)
// Space Complexity : O(1)

void merge_arrays(vector<int> &X, vector<int> &Y, int m, int n){

    // consider each element of X and ignore the element 
    // if it is already in correct order or else swap it with
    // the next smallest element in Y, which is the first element of Y
    for(int i = 0; i < m; ++i){
        if(X[i] > Y[0]){
            
            swap(X[i], Y[0]);
            int fi = Y[0];
            int k;
            for(k = 1; k < n && Y[k] < fi; ++k)
                Y[k - 1] = Y[k];
            
            Y[k - 1] = fi;
        }
    }
}

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m;

    vector<int> X(m);
    for(int i = 0; i < m; ++i) 
        cin >> X[i];

    cin >> n;
    vector<int> Y(n);
    for(int i = 0; i < n; ++i) 
        cin >> Y[i];

    merge_arrays(X, Y, m, n);

    for(auto &element : X)
        cout << element << ' ';
    cout << "\n";

    for(auto &element : Y)
        cout << element << ' ';
    cout << "\n";

    return 0;
}
