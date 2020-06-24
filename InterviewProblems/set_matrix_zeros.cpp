// https://leetcode.com/problems/set-matrix-zeroes/

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

// Time Complexity : O(n * m)
// Space Complexity : O(1)

void set_matrix_zeros(vector<vector<int> > &matrix){
    int R = matrix.size();
    int C = matrix[0].size();

    bool is_col = false;

    for(int i = 0; i < R; ++i){
        //check for the first column.
        if(matrix[i][0] == 0) is_col = true;
        // mark the first cell of corresponding row and column if matrix[i][j] == 0
        for(int j = 1; j < C; ++j){
            if(matrix[i][j] == 0)
                matrix[0][j] = 0, matrix[i][0] = 0;
        }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for(int i = 1; i < R; ++i){
        for(int j = 1; j < C; ++j){
            if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
        }
    }

    // See if the first row needs to be set to zero as well
    if(matrix[0][0] == 0){
        for(int i = 0; i < C; ++i)
            matrix[0][i] = 0;
    }

    // See if the first column needs to be set to zero as well
    if(is_col){
        for(int i = 0; i < R; ++i)
            matrix[i][0] = 0;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    set_matrix_zeros(a);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
