// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k-using-stack-in-on-time/?ref=rp

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
    Time Complexity: O(n).
        It seems more than O(n) at first look. It can be observed that every element of array is 
        added and removed at most once. So there are total 2n operations.  
    
    Auxiliary Space: O(k). Elements stored in the dequeue take O(k) space.
*/
// A Dequeue (Double ended queue) based method for printing maximum element of 
// all subarrays of size k 
void printKMax1(vector<int> &a, int n, int k){

    // Create a Double Ended Queue, Qi that will store indexes of array elements 
    // The queue will store indexes of useful elements in every window and it will 
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    deque<int> Q(k);

    /* Process first k (or first window) elements of array */
    int i = 0;
    for(i = 0; i < k; ++i){
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi
        while((!Q.empty()) && (a[i] >= a[Q.back()]))
            Q.pop_back(); // remove from rear
        
        // Add new element at rear of queue
        Q.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for(; i < n; ++i){  
        // The element at the front of the queue is the largest element of 
        // previous window, so print it
        cout << a[Q.front()] << ' ';

        // Remove the elements which are out of this window
        while((!Q.empty()) && (Q.front() <= (i - k)))
            Q.pop_front(); // Remove from front of queue 
        
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements)
        while((!Q.empty()) && (a[i] >= a[Q.back()]))
            Q.pop_back();
        
        // Add current element at the rear of Qi 
        Q.push_back(i);
    }

    cout << a[Q.front()] << endl;
}

/*
    Time Complexity: O(n).
    Only two traversal of the array is needed. So Time Complexity is O(n).
    
    Space Complexity: O(n).
    Two extra space of size n is required.

    For every index calculate the index upto which the current element is maximum when the subarray starts from this 
    index, i.e For every index i an index j ≥ i such that max(a[i], a[i + 1], … a[j]) = a[i]. Lets call it max_upto[i].
    Then the maximum element in the sub-array of length k starting from ith index, can be found by checking every 
    index starting from i to i + k – 1 for which max_upto[i] ≥ i + k – 1 (last index of that window). Stack data-structure 
    can be used to store the values in an window, i.e. the last visited or the previous inserted element will be 
    at the top (element with closest index to current element).


*/

void printKMax2(vector<int> &a, int n, int k){
    // max_upto array stores the index 
    // upto which the maximum element is a[i] 
    // i.e. max(a[i], a[i + 1], ... a[max_upto[i]]) = a[i] 
  
    int max_upto[n]; 
    // Update max_upto array similar to 
    // finding next greater element
    stack<int> s;
    s.push(0);

    for(int i = 1; i < n; ++i){
        while((!s.empty()) && (a[s.top()] < a[i])){
            max_upto[s.top()] = i - 1;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        max_upto[s.top()] = n - 1;
        s.pop();
    }

    int j = 0;
    for(int i = 0; i <= n - k; ++i){
        // j < i is to check whether the 
        // jth element is outside the window
        while(j < i || max_upto[j] < i + k - 1)
            ++j;
        
        cout << a[j] << ' ';
    }
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    // method #1 using deque
    cout << "Method #1: ";
    printKMax1(a, n, k);
    cout << endl;

    // method #2 using stack
    cout << "Method #2: ";
    printKMax2(a, n, k);
    cout << endl;

    return 0;
}
