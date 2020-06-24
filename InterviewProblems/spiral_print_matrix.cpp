// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

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

// Time Complexity : O(m * n)
// Space Complexity : O(1)

void spiral_print(vector< vector<int> > &a, int m, int n){

    int i, k = 0, l = 0;
    /* k - starting row index  
        m - ending row index  
        l - starting column index  
        n - ending column index  
        i - iterator  
    */

    while(k < m && l < n){
        // print the first row from the remaining rows
        for(i = l; i < n; ++i)
            cout << a[k][i] << ' ';
        
        k++;

        // print the last column from the remaining columns
        for(i = k; i < m; ++i)
            cout << a[i][n - 1] << ' ';
        
        n--;

        // print the last row from the remaining rows
        if(k < m){
            for(i = n - 1; i >= l; --i)
                cout << a[m - 1][i] << ' ';
            
            m--;
        }

        // print the first column from the remaining columns
        if(l < n){
            for(i = m - 1; i >= k; --i)
                cout << a[i][l] << ' ';
            
            l++;
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector< vector<int> > a(m, vector<int> (n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    }

    // printing matrix in spiral form
    spiral_print(a, m, n);
    cout << "\n";

    return 0;
}
