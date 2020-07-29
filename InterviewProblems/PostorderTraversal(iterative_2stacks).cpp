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

struct Node{
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val){
        this->data = val;
        this->left = this->right = NULL;
    }
};

void postOrderIterative(Node* root){
    if(root == NULL)
        return;
    
    // Create two stacks
    stack<Node* > s1, s2;

    // push root to first stack
    s1.push(root);
    Node* node;

    // Run while first stack is not empty 
    while(!s1.empty()){
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children 
        // of removed item to s1 
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }

    // Print all the elements of second stack
    while(!s2.empty()){
        node = s2.top();
        s2.pop();
        cout << node->data << ' ';
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = NULL; 
    root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
  
    postOrderIterative(root); 
    return 0;
}
