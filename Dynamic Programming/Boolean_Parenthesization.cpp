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

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

int calculateNumberOfWays(string &operands, string &operators){
    int numOperands = operands.size();
    int F[numOperands][numOperands];
    int T[numOperands][numOperands];

    for(int i = 0; i < numOperands; ++i){
        F[i][i] = (operands[i] == 'F'? 1 : 0);
        T[i][i] = (operands[i] == 'T'? 1 : 0);
    }

    for(int L = 2; L <= numOperands; ++L){
        for(int i = 0; i < numOperands - L + 1; ++i){
            int j = i + L - 1;
            T[i][j] = F[i][j] = 0;
            for(int k = i; k <= j - 1; ++k){
                int totalIK = T[i][k] + F[i][k];
                int totalKJ = T[k + 1][j] + F[k + 1][j];

                if(operators[k] == '&'){
                    T[i][j] += T[i][k] * T[k + 1][j];
                    F[i][j] += ((totalIK * totalKJ) - (T[i][k] * T[k + 1][j]));
                } 
                if(operators[k] == '|'){
                    F[i][j] += F[i][k] * F[k + 1][j];
                    T[i][j] += ((totalIK * totalKJ) - (F[i][k] * F[k + 1][j])); 
                }
                if(operators[k] == '^'){
                    T[i][j] += F[i][k] * T[k + 1][j] + T[i][k] * F[k + 1][j];
                    F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                }
            }
        }
    }

    return T[0][numOperands-1];

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string operands = "TTFT";
    string operators = "|&^";

    cout << "Number of ways to parenthesize expression: ";
    cout << calculateNumberOfWays(operands, operators) << endl;


    return 0;
}
