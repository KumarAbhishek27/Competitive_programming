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
const int N = 1e5+5, M = N;
//=========================================

// method-1
string column_name1(int n){
    
    string res;   
    while(n > 0){
        int rem = n % 26;

        // If remainder is 0, then a 'Z' must be there in output
        if(rem == 0){
            res.push_back('Z');
            n = (n / 26) - 1;
        }
        // If remainder is non-zero
        else{
            res.push_back(rem - 1 + 'A');
            n /= 26;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}


// method-2
string column_name2(int n){
    
    vector<int> arr(100001);
    int i = 0;
    
    // Step 1: Converting to base26 number assuming 
    // 0 in number system
    while(n){
        arr[i] = n % 26;
        n = n / 26;
        ++i;
    }

    // Step 2: Getting rid of 0, as 0 is 
    // not part of number system 
    // In decimal number system to deal with zero we borrow 10, and subtract 1 from next significant.
    // In Base 26 Number System to deal with zero we borrow 26 and subtract 1 from next significant bit.
    for(int j = 0; j < i - 1; ++j){
        if(arr[j] <= 0){
            arr[j] += 26;
            arr[j + 1] -= 1;
        }
    }

    string ans;
    for(int j = i; j >= 0; --j){
        if(arr[j] > 0)
            ans.push_back(char((arr[j] - 1) + 'A'));
    }

    return ans;
}


// convert excel column name to column num
int column_num(string s){
    // This process is similar to  
    // binary-to-decimal conversion 
    // result = 26*result + (s[i] - 'A' + 1)
    int res = 0;
    for(auto &c : s){
        res *= 26;
        res += (c - 'A' + 1);
    }

    return res;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    cin >> n >> s;

    string ans = column_name1(n);
    string ans1 = column_name2(n);
    int num = column_num(s);
    
    cout << "Excel column name using method-1: " << ans << endl;
    cout << "Excel column name using method-2: " << ans1 << endl;
    cout << "Excel column number from column name: " << num << endl;
    return 0;
}
