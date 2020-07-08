// https://www.geeksforgeeks.org/next-greater-element/

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

// Time Complexity: O(N) 
// Space Complexity: O(N), for an auxillary array (or stack)

void printNGE(vector<int> &a, int n){
    stack<int> s;
    
    // push the first element to the stack 
    s.push(a[0]);

    // iterate for the rest of the elements
    for(int i = 1; i < n; ++i){
        if(s.empty()){
            s.push(a[i]);
            continue;
        }

        // if stack is not empty, then 
        // pop an element from stack. 
        // If the popped element is smaller 
        // than next, then 
        //    a) print the pair 
        //    b) keep popping while elements are 
        //       smaller and stack is not empty

        while(s.empty() == false && s.top() < a[i]){
            cout << s.top() << " --> " << a[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find 
        next greater for it */
        s.push(a[i]);
    }

    /* After iterating over the loop, the remaining 
    elements in stack do not have the next greater 
    element, so print -1 for them */
    while(s.empty() == false){
        cout << s.top() << " --> " << "-1\n";
        s.pop();
    }
}

void printNGE_sameOrder(vector<int> &arr, int n){

    stack<int> s; 
  
    int arr1[n]; 
  
    // iterating from n-1 to 0 
    for (int i = n - 1; i >= 0; i--){ 
        /*We will pop till we get the  
        greater element on top or stack gets empty*/
        while (!s.empty() && s.top() <= arr[i]) 
            s.pop(); 
  
        /*if stack gots empty means there  
        is no element on right which is greater  
        than the current element. 
        if not empty then the next greater  
        element is on top of stack*/
        if (s.empty())  
            arr1[i] = -1;          
        else 
            arr1[i] = s.top();         
  
        s.push(arr[i]); 
    } 
  
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ---> " << arr1[i] << endl; 

}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 0; i < n; ++i)
        cin >> A[i];

    // Stack Solution: printing the elements in random order
    cout << "#1 Solution using Stack:\n";
    printNGE(A, n);
    cout << endl;

    // stack solution : printing the elements in the given order
    cout << "#2 Solution using Stack(better):\n";
    printNGE_sameOrder(A, n);
    cout << endl;

    return 0;
}
