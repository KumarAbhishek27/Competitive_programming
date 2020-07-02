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

// Space Complexity: O(n)
int trap_rain_water1(vector<int> &a, int n){
    int volume = 0;

    if(n == 0) 
        return 0;
    // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself 
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 
    vector<int> left(n), right(n);

    // Fill left array 
    left[0] = a[0];
    for(int i = 1; i < n; ++i)
        left[i] = max(left[i - 1], a[i]);
    
    // Fill right array 
    right[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; --i)
        right[i] = max(right[i + 1], a[i]);

    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for(int i = 0; i < n; ++i){
        int x = min(left[i], right[i]);
        if(x > a[i]) volume += (x - a[i]);
    }

    return volume;
}

// Space Complexity: O(1)
int trap_rain_water2(vector<int> &a, int n){
    int left = 0, right = n - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;

    // So, we can say that if there is a larger bar at one end (say right), we are assured that the water trapped would be 
    // dependant on height of bar in current direction (from left to right).As soon as we find the bar at other 
    // end (right) is smaller, we start iterating in opposite direction (from right to left).
    while(left < right){
        if(a[left] < a[right]){
            a[left] >= left_max ? (left_max = a[left]) : ans += (left_max - a[left]);
            ++left;
        }
        else{
            a[right] >= right_max ? (right_max = a[right]) : ans += (right_max - a[right]);
            --right;
        }
    }

    return ans;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int max_vol = trap_rain_water1(a, n);
    int max_vol1 = trap_rain_water2(a, n);
    cout << max_vol << ' ' << max_vol1 << endl;
    
    return 0;
}
