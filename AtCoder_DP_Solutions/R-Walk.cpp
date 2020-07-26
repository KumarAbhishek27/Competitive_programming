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

const int SZ = 55;

struct matrix{
    int mat[SZ][SZ];

    matrix(int idd = 0){
        for(int i = 0; i < SZ; ++i){
            for(int j = 0; j < SZ; ++j)
                mat[i][j] = (idd ? (i == j) : 0);
        }
    }

    matrix operator*(const matrix& other)const{
        matrix ans;
        for(int i = 0; i < SZ; ++i){
            for(int j = 0; j < SZ; ++j){
                for(int k = 0; k < SZ; ++k){
                    ans.mat[i][j] += mat[i][k] * other.mat[k][j];
                    if(ans.mat[i][j] > mod) ans.mat[i][j] %= mod;
                }
            }
        }

        return ans;
    }
};


matrix exponentiation(matrix base, int K){
    matrix ans(1);

    while(K){
        if(K & 1)
            ans = ans * base;
        base = base * base;
        K >>= 1;
    }

    return ans;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    matrix base;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            cin >> base.mat[i][j];
    }
    
    matrix ans = exponentiation(base, K);

    int paths = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            paths = (paths + ans.mat[i][j]) % mod;
    }

    cout << paths << "\n";

    return 0;
}
