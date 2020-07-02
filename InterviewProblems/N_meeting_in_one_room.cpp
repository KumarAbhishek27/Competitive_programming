// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

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

// Time Complexity: O(n*log(n))
// Space Complexity: O(n)

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2){
    return m1.end < m2.end;
}

vector<int> max_meetings(vector<int> &s, vector<int> &t, int n){
    struct meeting meet[n];

    for(int i = 0; i < n; ++i){
        meet[i].start = s[i];
        meet[i].end = t[i];
        meet[i].pos = i + 1;
    }

    // Sorting of meeting according to their finish time. 
    sort(meet, meet + n, comparator); 

    // Vector for storing selected meeting. 
    vector<int> m; 
  
    // Initially select first meeting. 
    m.push_back(meet[0].pos); 
  
    // time_limit to check whether new  
    // meeting can be conducted or not. 
    int time_limit = meet[0].end; 
  
    // Check for all meeting whether it  
    // can be selected or not.
    for(int i = 1; i < n; ++i){
        if(meet[i].start >= time_limit){
            // Push selected meeting to vector 
            m.push_back(meet[i].pos);
            // Update time limit. 
            time_limit = meet[i].end;
        }
    }

    return m;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> s(n), t(n);
        
        for(int i = 0; i < n; ++i)
            cin >> s[i];
        
        for(int i = 0; i < n; ++i)
            cin >> t[i];

        vector<int> ans = max_meetings(s, t, n);
        
        for(auto &x : ans)
            cout << x << ' ';
        cout << endl;
    }
    

    return 0;
}
