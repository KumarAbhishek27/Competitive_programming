// https://leetcode.com/problems/max-consecutive-ones-iii/

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
// Space Complexity: O(1)

/*
        Approach:
        1. The question translates to finding the max length of subArray with at most K 0s.
        2. Use sliding window technique.
        3. Keep count of the number of 0s found in the current window.
        4. If the count is > K, then increment l until the count goes to <=K.
        5. At each iteration find the maxLen.
        6. Time complexity: O( N ).
    
*/

int longestOnes(vector<int> &a, int k){
    int n = a.size();
    int zeroCount = 0, l = 0;
    int maxLen = 0;

    for(int r = 0; r < n; ++r){
        if(a[r] == 0) ++zeroCount;
        while(zeroCount > k){
            if(a[l] == 0) --zeroCount;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int mx_ones = longestOnes(a, k);
    cout << mx_ones << endl;

    return 0;
}
