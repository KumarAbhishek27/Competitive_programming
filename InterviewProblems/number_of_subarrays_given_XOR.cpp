// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

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

// Time Complexity: O(n)
// Space complexity: O(n)

int numberofsubarrays_xor(vector<int> &a, int n, int m){

    int ans = 0;
    
    // Create a prefix xor-sum array such that 
    // xorArr[i] has value equal to XOR 
    // of all elements in arr[0 ..... i]
    vector<int> xorArr(n);

    // Create map that stores number of prefix array 
    // elements corresponding to a XOR value 
    unordered_map<int, int> mp;
    xorArr[0] = a[0];

    for(int i = 1; i < n; ++i)
        xorArr[i] = xorArr[i - 1] ^ a[i];

    // calculate the answer
    for(int i = 0; i < n; ++i){
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];
        
        // If above XOR exists in map, then there 
        // is another previous prefix with same 
        // XOR, i.e., there is a subarray ending 
        // at i with XOR equal to m. 
        ans = ans + mp[tmp];

        // If this subarray has XOR equal to m itself.
        if(xorArr[i] == m) ++ans;

        // Add the XOR of this subarray to the map 
        mp[xorArr[i]]++;
    }

    return ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)  
        cin >> a[i];

    int cnt = numberofsubarrays_xor(a, n, m);
    cout << cnt << "\n";
    
    return 0;
}
