// https://leetcode.com/problems/word-break-ii/

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
//const int N = 2e5+5, M = N;
//=========================================

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
/*
    In the worst case the runtime of this algorithm is O(2^n).
    Consider the input "aaaaaa", with wordDict = ["a", "aa", "aaa", "aaaa", "aaaaa", "aaaaa"]. 
    Every possible partition is a valid sentence, and there are 2^n-1 such partitions. 
    It should be clear that the algorithm cannot do better than this since it generates all valid sentences. 
    The cost of iterating over cached results will be exponential, as every possible partition will be cached, 
    resulting in the same runtime as regular backtracking. Likewise, the space complexity 
    will also be O(2^n) for the same reason - every partition is stored in memory.
*/

// DP + bactracking Solution

vector<string> helper(const string &s, int n, unordered_set<string> &dict, int max_len, unordered_map<int, vector<string>>& mp){
    if(mp.count(n))
        return mp[n];
    
    string str;
    for(int i = n; i < s.size() && str.size() <= max_len; ++i){
        str += s[i];
        if(dict.count(str)){
            if(i == s.size() - 1)
                mp[n].push_back(str);
            else{
                vector<string> vs = helper(s, i + 1, dict, max_len, mp);
                for(auto &a : vs)
                    mp[n].push_back(str + " " + a);
            }
        }
    }

    return mp[n];
}

vector<string> wordBreak(string s, vector<string> &wordDict){
    int max_len = 0;
    unordered_set<string> dict;
    for(string &str : wordDict){
        dict.insert(str);
        max_len = max(max_len, (int)str.size());
    }

    unordered_map<int, vector<string> > mp;
    return helper(s, 0, dict, max_len, mp);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input the test string
    string s;
    cin >> s;

    // Setup the dictionary
    vector<string> dict;
    dict.push_back("i");
    dict.push_back("love");
    dict.push_back("sam");
    dict.push_back("sung");
    dict.push_back("samsung");

    // Call the WordBreak() function
    vector<string> ans = wordBreak(s, dict);

    for(string &x : ans)
        cout << x << ' ' << endl;
    
    cout << endl;

    return 0;
}
