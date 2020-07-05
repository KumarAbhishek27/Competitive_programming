//

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

// Time Complexity: O(N!)
// Space Complexity: O(size * size)

int board[1005][1005];

bool attacked(int x, int y, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == x || j == y || (i+j) == (x+y) || (i-j) == (x-y)){
                if(board[i][j] == 1){
                    return true;
                }
            }
        }
    }
    return false;
}

bool N_Queen(int size, int n){
    if(n == 0)
        return true;
        
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            if(attacked(i, j, size)) continue;
            
            board[i][j] = 1;
            if(N_Queen(size, n-1)){
                return true;
            }
            // backtrack if no solution found..
            board[i][j] = 0;
        }
    }
    
    return false;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    int size = N;
    
    memset(board, 0, sizeof(board));
    
    if(N_Queen(size, N)){
        cout << "YES\n";
        for(int i = 0; i<size; i++){
            for(int j = 0; j<size; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}
