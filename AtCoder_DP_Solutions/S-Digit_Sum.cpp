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
#define INF 100000000000
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int N = 2e5+5, M = N;
//=========================================

int dp[10005][105][2]; // dp[pos][sum_of_digits][flag]
vector<int> num;
string a, b; 
int k;
 
int call(int pos, int digit_sum, int flag){
    // Check if the digit_sum is divisible by D
    if(pos == (int)num.size()){
        return (digit_sum == 0);
    }
	
  	// Return if already computed
    if(dp[pos][digit_sum][flag] != -1)
        return dp[pos][digit_sum][flag];
    
    int ans = 0;
  	// set the limit of max digit for pos
    int LMT = (flag ? num[pos] : 9);
	
  	// calculate the answer
    for(int dgt = 0; dgt <= LMT; ++dgt){
        ans += call(pos + 1, (digit_sum + dgt) % k, flag && (dgt == LMT));
        ans %= mod;
    }

    return dp[pos][digit_sum][flag] = ans;
}

int solve(string a){
    
    num.clear();
  	// set the limit of max digit at each position
    for(int i = 0; i < (int)a.size(); ++i)
        num.push_back(a[i] - '0');
    
    memset(dp, -1, sizeof(dp));
  	// invoke the call function with flag = 1
  	// because digit at first pos has limit of num[0]
    int res = call(0, 0, 1) - 1;
  	if(res < 0) res += mod;
    return res;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  	// Input the number as a string
    cin >> a;
  
  	// Input D
    cin >> k;
    
    int ans = solve(a);
    cout << ans << endl;
    
    return 0;
}
