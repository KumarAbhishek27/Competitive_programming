// https://leetcode.com/problems/longest-consecutive-sequence/

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

int longestConsecutive(vector<int> &a){

    int n = a.size();
    unordered_set<int> hashMap;
    
    int mx = 0;
    // insert all the elements in the hashmap
    for(int i = 0; i < n; ++i)
        hashMap.insert(a[i]);

    // check each possible sequence from 
    // the start then update optimal length 
    for(int i = 0; i < n; ++i){
        // if current element is the starting 
        // element of a sequence
        if(hashMap.find(a[i] - 1) == hashMap.end()){
            // Then check for next elements 
            // in the sequence 
            int j = a[i];
            while(hashMap.find(j) != hashMap.end()) ++j;

            // update  optimal length if 
            // this length is more 
            mx = max(mx, j - a[i]);
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

    int ans = longestConsecutive(a);
    cout << ans << endl;
    
    return 0;
}
