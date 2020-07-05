// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

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

// Time Complexity: O(m^V) There are total O(m^V) combination of colors. 
// So time complexity is O(m^V). The upperbound time complexity remains the same but the average time taken will be less.

// Space Complexity: O(V)

int n;

bool isSafe(int v, vector<vector<int> > &graph, vector<int> &color, int c){
    for(int i = 0; i < n; ++i){
        if(graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

/* A recursive utility function  
to solve m coloring problem */
bool graphColoringUtil(vector<vector<int> > &graph, int m, vector<int> &color, int v){
    // base case: If all vertices are  
    //   assigned a color then return true
    if(v == n)
        return true;
    
    // Consider this vertex v and  
    // try different colors 
    for(int c = 1; c <= m; ++c){
        // Check if assignment of color  
        // c to v is fine
        if(isSafe(v, graph, color, c)){
            color[v] = c;
            // recur to assign colors to  
            // rest of the vertices
            if(graphColoringUtil(graph, m, color, v + 1))
                return true;
            
            // If assigning color c doesn't 
            // lead to a solution then remove it
            color[v] = 0;
        }
    }

    return false;
}

void printSolution(vector<int> &color){
    cout << "Solution Exists: ";
    for(int i = 0; i < n; ++i)
        cout << color[i] << ' ';
    cout << endl;
}

void graphColoring(vector<vector<int> > &graph, int m){
    // Initialize all color values as 0. 
    // This initialization is needed 
    // correct functioning of isSafe()
    vector<int> color(n, 0);

    // Call graphColoringUtil() for vertex 0
    if(graphColoringUtil(graph, m, color, 0) == false)
        cout << "Solution Doesn't Exist\n";
    else
        printSolution(color);
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;
    vector<vector<int> > graph(n, vector<int> (n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> graph[i][j];
    }

    graphColoring(graph, m);

    return 0;
}
