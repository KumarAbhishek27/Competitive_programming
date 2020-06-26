// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

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
//#define mp make_pair
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

// Time Complexity: O(n)
// Space complexity: O(n)

int zeroSum(vector<int> &a, int n){

    unordered_map<int, int> pref_sum;

    int sum = 0, mx = 0;
    for(int i = 0; i < n; ++i){
        // add current element to the sum
        sum += a[i];
        if(a[i] == 0 && mx == 0) mx = 1;
        if(sum == 0) mx = max(mx, i + 1);

        // Look for this sum in Hash table 
        if(pref_sum.find(sum) != pref_sum.end()){
            // If this sum is seen before, then update max_len
            mx = max(mx, i - pref_sum[sum]);
        }else{
            pref_sum[sum] = i;
        }
    }

    return mx;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)  
        cin >> a[i];

    int longestSubarray = zeroSum(a, n);
    cout << longestSubarray << endl;
    
    return 0;
}
