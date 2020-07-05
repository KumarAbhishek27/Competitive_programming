// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

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
const int N = 2e5+5, M = N;
//=========================================

// Time Complexity: O(2^(n^2)). The recursion can run upperbound 2^(n^2) times.
// Space Complexity: O(n^2)

int n;

bool isSafe(vector<vector<int> > &maze, int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solveMazeUtil(vector<vector<int> > &maze, int x, int y, vector<vector<int> > &sol){
    // If (x, y) is goal return true
    if(x == n - 1 && y == n - 1 && maze[x][y] == 1)
        return true;
    
    if(isSafe(maze, x, y)){
        // mark x, y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if(solveMazeUtil(maze, x + 1, y, sol))
            return true;
        
        /* If moving in x direction 
           doesn't give solution then  
           Move down in y direction  */
        if(solveMazeUtil(maze, x, y + 1, sol))
            return true;
        
        /* If none of the above movements  
           work then BACKTRACK: unmark  
           x, y as part of solution path */
        sol[x][y] = 0; 
        return false; 
    }

    return false;
}


bool solveMaze(vector<vector<int> > &maze){
    vector<vector<int> > sol(n, vector<int> (n , 0));
    
    if(solveMazeUtil(maze, 0, 0, sol) == false){
        cout << "Solution doesn't Exist";
        return false;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << sol[i][j] << ' ';
        cout << endl;
    }

    return true;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int n;
    cin >> n;

    vector<vector<int> > maze(n, vector<int> (n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> maze[i][j];
    }

    bool ok = solveMaze(maze);
    
    if(ok)
        cout << "Found Solution\n";
    else
        cout << "Better Luck next time\n";

    return 0;
}
