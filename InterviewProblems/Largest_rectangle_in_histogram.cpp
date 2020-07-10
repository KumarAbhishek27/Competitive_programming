// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

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

// Time Complexity: O(n), Since every bar is pushed and popped only once.
// Space Complexity: O(n), for using stack.

int getMaxArea(vector<int> &hist, int n){

    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s;

    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar as the smallest bar 

    // Run through all bars on the histogram
    int i = 0;
    while(i < n){
        // If this bar is higher than the bar on top  
        // stack, push it to stack
        if(s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else{
            tp = s.top();
            s.pop();

            // Calculate the area with hist[tp] stack  
            // as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : (i - s.top() - 1));

            // Update the max_area
            max_area = max(max_area, area_with_top);
        }
    }

    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while(!s.empty()){
        tp = s.top();
        s.pop();

        // Calculate the area with hist[tp] stack  
        // as smallest bar
        area_with_top = hist[tp] * (s.empty() ? i : (i - s.top() - 1));

        // Update the max_area
        max_area = max(max_area, area_with_top);
    }

    return max_area;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int largest_rectangle = getMaxArea(a, n);
    cout << "Maximum area is: " <<  largest_rectangle << endl;

    return 0;
}
