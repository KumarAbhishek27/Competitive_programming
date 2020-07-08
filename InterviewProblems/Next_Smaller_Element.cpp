// https://www.geeksforgeeks.org/next-smaller-element/

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
    Time Complexity: O(n). The worst case occurs when all elements are sorted in increasing order. 
    If elements are sorted in increasing order, then every element is processed at most 4 times.
        a) Initially pushed to the stack.
        b) Popped from the stack when next element is being processed.
        c) Pushed back to the stack because next element is smaller.
        d) Popped from the stack in step 3 of algo.

    Space Complexity: O(n), in worst case
*/

void printNSE(vector<int> &arr, int n){ 
    stack<int> s; 
  
    /* push the first element to stack */
    s.push(arr[0]); 
  
    // iterate for rest of the elements 
    for (int i = 1; i < n; i++){ 
        if (s.empty()) { 
            s.push(arr[i]); 
            continue; 
        } 
  
        /* if stack is not empty, then 
        pop an element from stack. 
        If the popped element is smaller 
        than next, then 
        a) print the pair 
        b) keep popping while elements are 
        smaller and stack is not empty */
        while (s.empty() == false && s.top() > arr[i]) { 
            cout << s.top() << " --> " << arr[i] << endl; 
            s.pop(); 
        } 
  
        /* push next to stack so that we can find 
        next smaller for it */
        s.push(arr[i]); 
    } 
  
    /* After iterating over the loop, the remaining 
    elements in stack do not have the next smaller 
    element, so print -1 for them */
    while (s.empty() == false) { 
        cout << s.top() << " --> " << -1 << endl; 
        s.pop(); 
    } 
} 


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    cout << "#1 Solution using Stack(random order):\n";
    printNSE(a, n);

    // We can print the elements in the same order by traversing
    // the array from right to left similar to next greater element
    // Or in case of distinct elements we can use a map(hash table)
    // to keep track of the next smaller element of each element

    return 0;
}
