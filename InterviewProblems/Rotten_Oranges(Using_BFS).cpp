// https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

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

/*
    Complexity Analysis:
        [Time Complexity]: O(R*C). Each element of the matrix can be inserted into the queue only once 
        so the upperbound of iteration is O(R*C), i.e. the number of elements. So time complexity is O(R *C).
        
        [Space Complexity]: O(R*C).
        To store the elements in a queue O(R*C) space is needed.
*/


int R, C;

// function to check whether a cell is valid / invalid 
bool isValid(int x, int y){
    return (x >= 0 && x < R && y >= 0 && y < C);
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int R, C;
    cin >> R >> C;

    vector<vector<int> > a(R, vector<int> (C));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            cin >> a[i][j];
    }

    // Using Multi-Source BFS for this problem;
    queue<pair<pii, int> > q; // pair -> ({x, y}, distance_from_source)
    
    // all cells with a[i][j] == 2 are source nodes
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(a[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }

    // Initializing the ans;
    int ans = 0;

    // Standard BFS
    // After reaching a fresh cell from a rotten cell update its distance(or time) from the source.
    // The cell with maximum time or distance from its respective source will be the answer
    // because till that time all fresh cells will be rotten (if possible otherwise ans == -1)

    while(!q.empty()){
        // current cell
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        // Check for adjacent cells
        for(int j = 0; j < 4; ++j){
            int u = x + dx[j];
            int v = y + dy[j];
            // check if it is a valid and fresh cell
            if(isValid(u, v) && a[u][v] == 1){
                a[u][v] = 2; // change to rotten cell
                q.push({{u, v}, d + 1});
                ans = max(ans, d + 1); // update ans
            }
        }
    }

    bool ok = 1;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(a[i][j] == 1){
                ok = 0;
                break;
            }
        }
    }

    if(!ok) cout << "All oranges cannot be rotten: -1\n";
    else cout << "Time required for all oranges to rot => " << ans << endl;

    return 0;
}
