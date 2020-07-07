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

const int MAX = 1005;

class Stack{
    int top;

public:
    int a[MAX]; // Maximum size of the stack

    Stack(){ top = -1;}
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack :: push(int x){
    if(top >= MAX - 1){
        cout << "Stack Overflow";
        return false;
    }
    else{
        a[++top] = x;
        cout << x << " Pushed into the stack\n";
        return true;
    }
}

int Stack :: pop(){
    if(top < 0){
        cout << "Stack is Empty";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack :: peek(){
    if(top < 0){
        cout << "Stack is Empty";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack :: isEmpty(){
    return (top < 0);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 


    return 0;
}
