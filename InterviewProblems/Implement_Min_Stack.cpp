// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

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


// Time Complexity: O(1)
// Space Complexity: O(1) extra space

/*

    How does this approach work?
    When element to be inserted is less than minEle, we insert “2x – minEle”. The important thing to notes is, 
    2x – minEle will always be less than x (proved below), i.e., new minEle and while popping out this element
    we will see that something unusual has happened as the popped element is less than the minEle. 
    So we will be updating minEle.

    How 2*x - minEle is less than x in push()? 
    x < minEle which means x - minEle < 0

    // Adding x on both sides
    x - minEle + x < 0 + x 

    2*x - minEle < x 

    We can conclude 2*x - minEle < new minEle 
    While popping out, if we find the element(y) less than the current minEle, we find the new minEle = 2*minEle – y.

    How previous minimum element, prevMinEle is, 2*minEle - y
    in pop() is y the popped element?

    // We pushed y as 2x - prevMinEle. Here 
    // prevMinEle is minEle before y was inserted
    y = 2*x - prevMinEle  

    // Value of minEle was made equal to x
    minEle = x .
        
    new minEle = 2 * minEle - y 
                = 2*x - (2*x - prevMinEle)
                = prevMinEle // This is what we wanted

*/


// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct SpecialStack{

    stack<int> s;
    int minEle;

    // Prints minimum element of MyStack
    void getMin(){
        if (s.empty()) 
            cout << "Stack is empty\n"; 
        // variable minEle stores the minimum element 
        // in the stack.
        else
            cout << "Minimum Element in the stack is: " << minEle << "\n";
    }

    // Prints top element of MyStack
    void peek(){
        if (s.empty()){ 
            cout << "Stack is empty "; 
            return; 
        } 

        int t = s.top(); // Top element
        cout << "Top Most Element is: ";
        // If t < minEle means minEle stores 
        // value of t. 
        (t < minEle)? cout << minEle: cout << t;
    }

    // Remove the top element from MyStack 
    void pop(){
        if (s.empty()){ 
            cout << "Stack is empty\n"; 
            return; 
        } 

        cout << "Top Most Element Removed: "; 
        int t = s.top(); 
        s.pop();
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if(t < minEle){
            cout << minEle << "\n";
            minEle = 2 * minEle - t;
        }

        else cout << t << "\n";
    }

    // Removes top element from MyStack 
    void push(int x){
        // Insert new number into the stack 
        if (s.empty()){ 
            minEle = x; 
            s.push(x); 
            cout <<  "Number Inserted: " << x << "\n"; 
            return; 
        }

        // If new number is less than minEle
        if(x < minEle){
            s.push(2 * x - minEle);
            minEle = x;
        } 
        else s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Sample Run
    SpecialStack s; 
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop(); 
    s.peek(); 

    return 0;
}
