/*

You are given an array a of n integers a1,a2,…,an.
Your task is to response to the queries like "How many numbers' values are between l and r?".

*/


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
//=========================================

int bsearch(vector<int> &a, int n, int x, bool ok){
    if(ok == 0){

        int l = -1; // a[l] < x
        int r = n; // a[r] >= x
        while(l + 1 < r){
            int m = (l + r) / 2;
            if(a[m] < x)
                l = m;
            else
                r = m;
        }

        return (r + 1);

    }else{

        int l = -1; // a[l] <= x
        int r = n; // a[r] > x
        while(l + 1 < r){
            int m = (l + r) / 2;
            if(a[m] <= x)
                l = m;
            else
                r = m;
        }

        return (l + 1);
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

    int n, k, x;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // now answer k queries
    cin >> k;
    for(int q = 0; q < k; ++q){
        //cin >> x;
        // to find the number of elements in a in range[L, R];
        int L, R;
        cin >> L >> R;

        // so we find the minimum index i such that a[i] >= L
        // and we also find the maximum index j such that a[j] <= R
        // answer for query == (j - i + 1)

        int ans_query = 0, first_occ, sec_occ;
        first_occ = bsearch(a, n, L, 0);
        sec_occ = bsearch(a, n, R, 1);

        ans_query += (sec_occ - first_occ + 1);
        cout << ans_query << ' ';
    }

    cout << "\n";

    return 0;
}
