// https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

// Time Complexity: O(n). Index j will iterate n times.
// Space complexity (HashMap) : O(min(m,n)), m is the size of the charset.

int lengthOfLongestSubstring(string s){
    
    int n = s.size();
    int l = 0, r = 0, cnt = 0;
    
    map<char, int> mp;
    // current index of character
    // try to extend the range [i, j]
    
    for(int j = 0, i = 0; j < n; ++j){
        if(mp.count(s[j])){
            i = max(mp[s[j]], i);
        }
        cnt = max(cnt, j - i + 1);
        mp[s[j]] = j + 1;
    }
    return cnt;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    int cnt = lengthOfLongestSubstring(s);
    cout << cnt << "\n";
    
    return 0;
}
