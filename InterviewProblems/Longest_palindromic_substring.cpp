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

/*
    [Time complexity: O(n^2)]. Two nested traversals are needed.
    [Auxiliary Space: O(n^2)]. Matrix of size n*n is needed to store the dp array.
*/

string longestPalindromicSubstring(string str){
    int n = str.size();

    // make a dp table where dp[i][j] is true if s[i..j] a is palindrome and false otherwise
    vector<vector<bool> > dp(n, vector<bool> (n, 0));

    int maxLen = 1; // all substrings of length 1 are palindromes
    for(int i = 0; i < n; ++i)
        dp[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for(int i = 0; i + 1 < n; ++i){
        if(str[i] == str[i + 1]){
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check for lengths greater than 2. 
    // len is length of substring
    for(int len = 3; len <= n; ++len){
        for(int i = 0; i < n - len + 1; ++i){
            // Get the ending index of substring from 
            // starting index i and length k 
            int j = i + len - 1;

            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            if(dp[i + 1][j - 1] && str[i] == str[j]){
                dp[i][j] = true;
                if(len > maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
    } 

    return str.substr(start, maxLen);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    string max_Len = longestPalindromicSubstring(str);
    cout << "The Longest palindromic Substring is: " << max_Len << endl;

    return 0;
}
