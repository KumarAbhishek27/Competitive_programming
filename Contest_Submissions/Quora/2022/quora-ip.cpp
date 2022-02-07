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

struct IpAddress {
    int a, b, c, d;
    int prefix;
    int address;

    IpAddress(int a, int b, int c, int d, int prefix, int address) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
        this -> d = d;
        this -> prefix = prefix;
        this -> address = address;
    }

    bool operator < (const IpAddress &other) const {
        return (address < other.address);
    }
};

int convertIpToDecimal(int a, int b, int c, int d) {
    int res = 0;
    res += a * pow(256, 3);
    res += b * pow(256, 2);
    res += c * pow(256, 1);
    res += d;
    return res;
}

pair<int, int> findIpRange(int address, int prefix) {
    //cout << "Finding Range: " << address << " with /prefix " << prefix << '\n';
    int l = 0, r = 0;
    int rem = 32 - prefix;

    l = address;
    r = address;

    for (int bit = 0; bit < rem; ++bit) {
        l &= ~(1ll << bit);
    }

    for (int bit = 0; bit < rem; ++bit) {
        r |= (1ll << bit);
    }

    return {l, r};
}

void solve() {

    int n, a, b, c, d, bits;
    cin >> n;

    vector<IpAddress> ips;
    for (int i = 0; i < n; ++i) {
        string ip; cin >> ip;
        stringstream s(ip);
        char ch;
        s >> a >> ch >> b >> ch >> c >> ch >> d >> ch >> bits;
        int curIpInDecimal = convertIpToDecimal(a, b, c, d);
        IpAddress cur(a, b, c, d, bits, curIpInDecimal);
        ips.push_back(cur);
        //cout << a << ' ' << b << ' ' << c << ' ' << d << "/" << bits << '\n';
    } 

    vector<pair<pii, int> > ipRanges;
    for (int i = 0; i < n; ++i) {
        pair<int, int> range = findIpRange(ips[i].address, ips[i].prefix);
        //cout << range.first << ' ' << range.second << '\n';
        ipRanges.push_back({range, i});
    }

    sort(all(ipRanges), [] (const pair<pii, int> &a, const pair<pii, int> &b){
        if (a.first.first == b.first.first)
            return (a.first.second < b.first.second);
        return (a.first.first < b.first.first);
    });

    stack<IpAddress> st;
    st.push(ips[ipRanges[0].second]);

    for (int i = 1; i < n; ++i) {
        IpAddress prev = st.top(); st.pop();
        pii prevRange = findIpRange(prev.address, prev.prefix);

        IpAddress cur = ips[ipRanges[i].second];
        pii curRange = findIpRange(cur.address, cur.prefix);

        bool lastAddress = false;
        if (i == n - 1 || (abs(curRange.s - ipRanges[i+1].f.f) > 1)) {
            lastAddress = true;
        }

        int mask = (prev.address & cur.address);
        int count;// = 32 - __builtin_ctz(mask);
        for (int x = 31; x >= 0; --x) {
            bool l = (bool)(prev.address & (1ll << x));
            bool r = (bool)(cur.address & (1ll << x));
            if (l != r) {
                //cout << "Mismatching bit: " << x << '\n';
                count = x + 1;
                break;
            }
        }
        pii newRange = findIpRange(mask, 32 - count);
        
        int a = (mask >> 24) & 0xFF;
        int b = (mask >> 16) & 0xFF;
        int c = (mask >> 8) & 0xFF;
        int d = mask & 0xFF;
        //cout << a << '.' << b << '.' << c << '.' << d << '/' << count << endl;
        IpAddress newAdd(a, b, c, d, 32 - count, mask);
        
        if (lastAddress) {
            if (newRange.f == prevRange.f && newRange.s == curRange.s) {
                st.push(newAdd);
            } else {
                st.push(prev); st.push(cur);
            }
        } else {
            if (newRange.f == prevRange.f && newRange.s >= curRange.s) {
                // input new range
                st.push(newAdd);
            } else {
                st.push(prev); st.push(cur);
            }
        }
    }

    while (!st.empty()) {
        IpAddress cur = st.top(); st.pop();
        cout << cur.a << '.' << cur.b << '.' << cur.c << '.' << cur.d << '/' << cur.prefix << '\n';
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
        solve();
    }

    return 0;        
}

