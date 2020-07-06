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

vector<int> fact, digits;

// Time Complexity: O(n^2), T(n) = T(n - 1) + n for method1(using maths)
// Space Complexity: O(n) , for storing the answer

void solve(string &ans, int n, int k){
    if(n == 1){ // Insert Whatever digit is left at the end
        ans += to_string(digits.back());
        return;
    }

    // This runs if we have more than 1 digits in digits array
    int index = k / fact[n - 1]; // Defines the number of blocks to skip(each block of size fact[n-1])
    if(k % fact[n - 1] == 0) // We need to convert 1-based indexing to 0-based. So, decrease index by 1.
        index--;

    ans += to_string(digits[index]); // Add new Character
    digits.erase(digits.begin() + index); // Erase digit after using

    k -= fact[n - 1] * index; // Decrease k value
    solve(ans, n - 1, k); // Recur for remaining n value
}

string getPermutation(int n, int k){
    // Store all factorials from 0 to n
    fact.push_back(1);
    int f = 1;
    for(int i = 1; i < n; ++i){
        f *= i;
        fact.push_back(f);
    }

    // push your digits in array
    for(int i = 1; i <= n; ++i)
        digits.push_back(i);

    string ans = "";
    solve(ans, n, k);
    
    return ans;
}

// Time Complexity: O(n!)
// Space Complexity: O(n)

// Backtracking solution: count every time reach the leaves
string ans;

void DFS(int n, int &k, vector<char> &str, vector<bool> &used, int index){
    if(index == n){
        if(--k == 0){
            string s(str.begin(), str.end());
            ans = s;
            //ans = "1";
        }
        return;
    }

    for(int i = 0; i < n; ++i){
        if(!used[i]){
            // Select
            str[index] = (char)('0' + i + 1);
            used[i] = true;

            DFS(n, k, str, used, index + 1);

            // !!: Return immediately after the kth is found
            if(k == 0) return;
            
            // Unselect, str[i] would be wiped out in next iteration
            used[i] = false;
        }
    }
}

string getPermutation2(int n, int k){
    
    vector<char> str(n);
    vector<bool> used(n, false);

    // Using Backtracking
    DFS(n, k, str, used, 0);
    return ans;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string ans1 = getPermutation(n, k);
    string ans2 = getPermutation2(n, k);
    
    cout << "#1 " << ans1 << endl;
    cout << "#2 " << ans2 << endl;

    return 0;
}
