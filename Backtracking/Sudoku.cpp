// https://www.geeksforgeeks.org/sudoku-backtracking-7/

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

// [Time Complexity]: O(9^(n*n)). For every unassigned index, there are 9 possible options 
// so the time complexity is O(9^(n*n)). The time complexity remains the same but there will 
// be some early pruning so the time taken will be much less than the naive algorithm but the 
// upper bound time complexity remains the same.

// [Space Complexity]: O(n*n)

#define UNASSIGNED 0
const int N = 9;

/* Searches the grid to find an entry that is  
still unassigned. If found, the reference  
parameters row, col will be set the location  
that is unassigned, and true is returned.  
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
    for(row = 0; row < N; ++row){
        for(col = 0; col < N; ++col){
            if(grid[row][col] == UNASSIGNED)
                return true;
        }
    }
    return false;
}

bool UsedInRow(int grid[N][N], int row, int num){
    for(int col = 0; col < N; col++){
        if(grid[row][col] == num) 
            return true; 
    }
    return false; 
}

bool UsedInCol(int grid[N][N], int col, int num){
    for(int row = 0; row < N; row++){
        if(grid[row][col] == num) 
            return true; 
    }
    return false; 
}


bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
    for(int row = 0; row < 3; ++row){
        for(int col = 0; col < 3; ++col){
            if(grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

/* Returns a boolean which indicates whether  
it will be legal to assign num to the given  
row, col location. */
bool isSafe(int grid[N][N], int row, int col, int num){
    /* Check if 'num' is not already placed in  
    current row, current column and current 3x3 box */
    return (!UsedInRow(grid, row, num) 
            && !UsedInCol(grid, col, num) 
            && !UsedInBox(grid, row - row%3, col - col%3, num)
            && grid[row][col] == UNASSIGNED);
}

bool SolveSudoku(int grid[N][N]){
    int row, col;
    // If there is no unassigned location, 
    // we are done 
    if (!FindUnassignedLocation(grid, row, col))
        return true; 

    // Consider digits 1 to 9
    for(int num = 1; num <= 9; ++num){
        // if it is a safe state
        if(isSafe(grid, row, col, num)){
            grid[row][col] = num;

            if(SolveSudoku(grid))
                return true;    
            
            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

/* A utility function to print grid */
void printGrid(int grid[N][N]) { 
    for(int row = 0; row < N; row++){ 
        for(int col = 0; col < N; col++) 
            cout << grid[row][col] << " "; 
        cout << endl; 
    } 
} 


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 0 means unassigned cells 
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 

    if (SolveSudoku(grid) == true) 
        printGrid(grid); 
    else
        cout << "No solution exists"; 

    return 0;
}
