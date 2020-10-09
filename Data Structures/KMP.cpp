#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
//#define pi(x)   printf("%d\n",x)
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
const int mod = 1000000007;
//=========================================

const int maxn = 1e5 + 10;

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[j] == s[i]){
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

int find_occurences(string &text, string &pattern) {
    string cur = pattern + "#" + text;
    int n = text.size(), m = pattern.size();

    vector<int> occ;
    vector<int> lps = prefix_function(cur);

    for(int i = m + 1; i <= n + m; ++i) {
        if(lps[i] == m) {
            occ.push_back(i - 2 * m);
        }
    }

    return (int)occ.size();
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string P, T;
    cin >> P >> T;

    // find the occurences of P in string T
    cout << find_occurences(T, P) << "\n";
    
    return 0;
}
