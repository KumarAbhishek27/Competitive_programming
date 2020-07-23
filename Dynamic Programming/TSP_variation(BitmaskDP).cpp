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
//#define INF 1e9+7
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

// Time Complexity: O(n*n * 2^n)
/*
    Consider the number of houses to be n. So, there are n * (2^n) states and at every state, we are looping over n houses 
    to transit over to next state and because of memoization we are doing this looping transition only once for each state. 
    Therefore, our Time Complexity is O(n*n * 2^n).
*/

#define INF 99999999 
#define MAXR 12 
#define MAXC 12 
#define MAXMASK 2048 
#define MAXHOUSE 12

// stores distance taking source as every house
int dist[MAXR][MAXC][MAXHOUSE];

// cache for memoization
int dp[MAXHOUSE][MAXMASK];

// stores coordinates for houses
vector<pair<int, int> > dirty;

char arr[21][21];

// len : number of dirty tiles + 1 
// limit : 2 ^ len -1 
// r, c : number of rows and columns 
int len, limit, r, c; 

// Returns true if current position 
// is safe to visit 
// else returns false 
// Time Complexity : O(1) 
bool safe(int x, int y){
    if(x >= r || y >= c || x < 0 || y < 0)
        return false;
    if(arr[x][y] == '#')
        return false;
    return true;
}

// runs BFS traversal at tile idx 
// calulates distance to every cell 
// in the grid 
// Time Complexity : O(r*c) 
void getDist(int idx){
    // visited array to track visited cells 
    bool vis[21][21]; 
    memset(vis, false, sizeof(vis)); 

    // getting current position
    int cx = dirty[idx].first;
    int cy = dirty[idx].second;

    // initializing queue for bfs 
    queue<pair<int, int> > pq;
    pq.push({cx, cy});

    // initializing the dist to max 
    // because some cells cannot be visited 
    // by taking source cell as idx 
    for(int i = 0; i <= r; ++i){
        for(int j = 0; j <= c; ++j)
            dist[i][j][idx] = INF;
    }

    vis[cx][cy] = true;
    dist[cx][cy][idx] = 0;

    while(!pq.empty()){
        auto x = pq.front();
        pq.pop();

        for(int i = 0; i < 4; ++i){
            cx = x.first + dx[i];
            cy = x.second + dy[i];
            // check if the cell is valid
            if(safe(cx, cy)){
                if(vis[cx][cy]) continue;
                vis[cx][cy] =  true;
                dist[cx][cy][idx] = dist[x.first][x.second][idx] + 1;
                pq.push({cx, cy});
            }
        }
    }
}

// Dynamic Programming state transition recursion 
// with memoization. Time Complexity: O(n*n * 2^n) 

int solve(int idx, int mask){
    // goal state
    if(mask == limit)
        return dist[0][0][idx];

    // if already visited state
    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ret = LLONG_MAX;

    // state transition relation
    for(int i = 0; i < len; ++i){
        if((mask & (1 << i)) == 0){
            int new_mask = (mask | (1 << i));
            ret = min(ret, solve(i, new_mask) + dist[dirty[i].first][dirty[i].second][idx]);
        }
    }

    return dp[idx][mask] = ret;
}

void init(){
    // initializing containers
    memset(dp, -1, sizeof(dp));
    dirty.clear();

    // populating dirty tile positions
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(arr[i][j] == '*')
                dirty.push_back({i, j});
        }
    }

    // inserting ronot's location at the 
    // beginning of the dirty tile 
    dirty.insert(dirty.begin(), {0, 0});
    len = dirty.size();

    // calculating LIMIT_MASK
    limit = (1 << len) - 1;
    
    // precalculating distances from all 
    // dirty tiles to each cell in the grid
    for(int i = 0; i < len; ++i)
        getDist(i);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test case #1: 
    //     .....*. 
    //     ...#... 
    //     .*.#.*. 
    //     ....... 
  
    char A[4][7] = {{'.', '.', '.', '.', '.', '*', '.'}, 
                    {'.', '.', '.', '#', '.', '.', '.'}, 
                    {'.', '*', '.', '#', '.', '*', '.'}, 
                    {'.', '.', '.', '.', '.', '.', '.'} 
                   }; 
  
    r = 4; c = 7; 
  
    cout << "The given grid : " << endl; 
  
    for (int i = 0;i<r;i++){ 
        for (int j = 0;j<c;j++){ 
            cout << A[i][j] << " "; 
            arr[i][j] = A[i][j]; 
        } 
        cout << endl; 
    } 
  
    // - initializitiation 
    // - precalculations 
    init(); 
  
    int ans = solve(0, 1); 
  
    cout << "Minimum distance for the given grid : "; 
    cout << ans << endl; 
  
  
    // Test Case #2 
    //     ...#... 
    //     ...#.*. 
    //     ...#... 
    //     .*.#.*. 
    //     ...#... 
  
    char Arr[5][7] = {  {'.', '.', '.', '#', '.', '.', '.'}, 
                        {'.', '.', '.', '#', '.', '*', '.'}, 
                        {'.', '.', '.', '#', '.', '.', '.'}, 
                        {'.', '*', '.', '#', '.', '*', '.'}, 
                        {'.', '.', '.', '#', '.', '.', '.'} 
                }; 
  
    r = 5; c = 7; 
  
    cout << "The given grid : " << endl; 
  
    for (int i = 0;i<r;i++){ 
        for (int j = 0;j<c;j++){ 
            cout << Arr[i][j] << " "; 
            arr[i][j] = Arr[i][j]; 
        } 
        cout << endl; 
    } 
  
    // - initializitiation 
    // - precalculations 
    init(); 
    ans = solve(0, 1); 
    cout << "Minimum distance for the given grid : "; 
    if (ans >= INF) cout << "not possible" << endl; 
    else cout << ans << endl; 
  
    return 0;
}
