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

// Time Complexity: 
//    1. Push operation: O(1).
//       Same as pop operation in stack.
//    2. Pop operation: O(N).
//       In the worst case we have empty whole of stack 1 into stack 2

// Space Complexity: O(N), Use of stack for storing values.

struct Queue { 
    stack<int> s1, s2; 
  
    // Enqueue an item to the queue 
    void enQueue(int x) { 
        // Push item into the first stack 
        s1.push(x); 
    } 
  
    // Dequeue an item from the queue 
    int deQueue(){ 
        // if both stacks are empty 
        if (s1.empty() && s2.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        // if s2 is empty, move 
        // elements from s1 
        if (s2.empty()) { 
            while (!s1.empty()) { 
                s2.push(s1.top()); 
                s1.pop(); 
            } 
        } 
  
        // return the top item from s2 
        int x = s2.top(); 
        s2.pop(); 
        return x; 
    } 
}; 

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 

    return 0;
}
