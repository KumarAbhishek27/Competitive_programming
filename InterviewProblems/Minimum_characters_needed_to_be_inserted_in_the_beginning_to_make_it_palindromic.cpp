// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
//#define pi(x)   printf("%d\n",x)
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
#define INF 100000000000
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

// Time Complexity: O(n), using lps array of KMP algo
// Space Complexity: O(n), extra space for lps array

vector<int> prefix_function(string &s){
    int n = s.size();
    vector<int> pi(n);

    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }

    return pi;
}

int getMinCharToAddedToMakeStringPal(string &s){
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    
    // Get concatenation of string, special character 
    // and reverse string 
    string concat = s + "#" + revStr;
    //  Get LPS array of this concatenated string
    vector<int> lps = prefix_function(concat);
    
    // By subtracting last entry of lps vector from 
    // string length, we will get our result 
    int ans = (int)s.size() - lps.back();
    return ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int min_chars = getMinCharToAddedToMakeStringPal(str);
    cout << "Minimum characters added to the front of the string to make it palindrome: " << min_chars << endl;

    return 0;
}
