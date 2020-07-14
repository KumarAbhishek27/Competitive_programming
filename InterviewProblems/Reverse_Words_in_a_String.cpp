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

// function to reverse any part of string from i to j (just one word or entire string)
void reverseword(string &s, int i, int j){
    while(i<j){
        char t=s[i];
        s[i++]=s[j];
        s[j--]=t;
    } 
}
    
string reverseWords(string &s) {
        
    int i = 0, j = 0;
    int l = 0;
    int len = s.length();
    int wordcount = 0;
        
    while(true){
        while(i < len && s[i] == ' ') i++;  // skip spaces in front of the word
        if(i == len) break;
        if(wordcount) s[j++]=' ';
        l = j;
        while(i < len && s[i] != ' ') {s[j] = s[i]; j++; i++;} 
        reverseword(s, l, j - 1);                // reverse word in place
        wordcount++;
    }
        
    s.resize(j);                 // resize result string
    reverseword(s, 0, j - 1);    // reverse whole string
    
    return s;
}


// Kind of brute force solution
string reverseWords1(string s) {
    stack<string> stk;
    int pos = 0;
    string res;

    while (pos < s.length()) {
        int end, start;
            
        while(s[pos] == ' ' && pos < s.length())
            pos++;
            
        start = pos;
            
        while (s[pos] != ' ' && pos < s.length())
            pos++;
            
        end = pos;

        if (end == start)
            break;
            
        stk.push(s.substr(start, end - start));
    }

    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
        if (!stk.empty())
            res += " ";
    }

    return res;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    string reversed_string = reverseWords1(s);
    string reversed = reverseWords(s);

    cout << "Slower method with extra space: " << reversed_string << endl;
    cout << "Faster method wiht O(1) extra space: " << reversed << endl;

    return 0;
}
