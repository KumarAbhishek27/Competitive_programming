// https://www.geeksforgeeks.org/merging-intervals/

#include <bits/stdc++.h>
#define int long long int
using namespace std;
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)

struct Interval{
    int start;
    int end;
};

bool compare(Interval i1, Interval i2){
    return (i1.start < i2.start);
}

void merge_intervals(vector<Interval> &a, int n){

    if(n <= 0) return;

    stack<Interval> s;
    
    sort(a.begin(), a.end(), compare);

    s.push(a[0]);
    for(int i = 1; i < n; ++i){
        Interval top = s.top();
        // if the current interval is not overlapping with stack top,
        // push it to the stack
        if(top.end < a[i].start)
            s.push(a[i]);
        
        else if(top.end < a[i].end){
            top.end = a[i].end;
            s.pop();
            s.push(top);
        }
    }

    cout << "The Merged Intervals are: ";
    while(!s.empty()){
        Interval top = s.top();
        cout << "[" << top.start << ',' << top.end << "]" << endl;
        s.pop();
    }
}

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Interval> a(n);
    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        a[i].start = x;
        a[i].end = y;
    }

    merge_intervals(a, n);

    return 0;
}
