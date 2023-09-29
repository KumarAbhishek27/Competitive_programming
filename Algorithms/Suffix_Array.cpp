#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define f first
#define s second
//#define ll long long int
#define lld long double
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
//#define F first
//#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF (1ll << 60l)
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
//const int mod = 998244353;
const int mod = 1e9 + 7;
//=========================================

// Time Complexity: O(n * (log(n)^2))

void generateSuffixArray() {

    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    // array p contains idx for suffix strings in lexicographical order
    vector<int> p(n), c(n); // ci -> equivalence group of substring starting from pi

    {
        // k = 0
        vector<pair<char, int> > a(n);
        for (int i = 0; i < n; ++i) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) < n) {
        // k -> k + 1
        vector<pair<pair<int, int>, int> > a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }   

        k++;
    }


    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ' << s.substr(p[i], n - p[i]) << '\n';
    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int testcase = 1;
    //cin >> testcase;
    for (int t = 1; t <= testcase; ++t) {
        //cout << "Case #" << t << ": ";
        generateSuffixArray();
    }

    return 0;        
}
