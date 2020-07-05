// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

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

// [Time Complexity]: O(n * (2^n))
// Worst case,  since this is a rare worst case where all 
// decompositions turn out to be palindromic (a string of all 1 character).Our best case becomes greatly improved. 
// We are basically taking subsets so (2^n) and the O(n) time to copy array to our answer.

// [Space Complexity]: O(2^n) to store all the partitions in worst case
// recursion stack(complexity): O(n) At worst we will always go n stack frames deep in our recursion since an all single 
// character decomposition is always a palindromic decomposition. This does not include the output array in space.


bool isPalindrome(string s, int low, int high){
    while(low < high){
        if(s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void dfs(string &s, vector<vector<string> > &res, vector<string> &cur, int start, int n){
    
    if(start >= n){
        res.push_back(cur);
        return;
    }

    // Pick all possible ending points for substrings
    for(int i = start; i < n; ++i){
        // If substring s[start..i] is palindrome
        if(isPalindrome(s, start, i)){
            // Add the substring to result
            cur.push_back(s.substr(start, i - start + 1));

            // Recur for remaining substring
            dfs(s, res, cur, i + 1, n);

            // Remove substring str[start..i] from current partition
            cur.pop_back();  
        }
    }
}


vector<vector<string> > allPalindromePartitions(string s){
    
    vector<vector<string> > res;
    vector<string> cur;
    int n = s.size();
    // function to generate all valid partitions
    dfs(s, res, cur, 0, n);
    return res; 
} 
    
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    vector<vector<string> > ans = allPalindromePartitions(str);
    
    for(int i = 0; i < (int)ans.size(); ++i){
        cout << "[ ";
        for(int j = 0; j < (int)ans[i].size(); ++j)
            cout << ans[i][j] << ", ";
        cout << " ]\n";
    }

    return 0;
}
