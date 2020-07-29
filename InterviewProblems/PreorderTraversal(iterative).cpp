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

// Iterative Preorder Binary tree traversal
void preorderIterative(Node* root){
    if(root == NULL)
        return;
    
    // Create an empty stack and push root to it
    stack<Node* >s;
    s.push(root);

    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while(s.empty() == false){
        // Pop the top item from stack and print it
        Node* cur = s.top();
        s.pop();

        cout << cur->data << ' ';
        if(cur->right)
            s.push(cur->right);
        if(cur->left)
            s.push(cur->left);
    }
}


void preorderIterative_spaceOpt(Node* root){
    if (root == NULL) 
        return; 
  
    stack<Node*> st; 
  
    // start from root node (set current node to root node) 
    Node* curr = root; 
  
    // run till stack is not empty or current is  
    // not NULL 
    while (!st.empty() || curr != NULL) 
    { 
        // Print left children while exist 
        // and keep pushing right into the  
        // stack. 
        while (curr != NULL) 
        { 
            cout << curr->data << " "; 
  
            if (curr->right) 
                st.push(curr->right); 
  
            curr = curr->left; 
        } 
          
        // We reach when curr is NULL, so We 
        // take out a right child from stack 
        if (st.empty() == false) 
        { 
           curr = st.top(); 
           st.pop(); 
        }    
    } 
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->left->left = new Node(70); 
    root->left->right = new Node(50); 
    root->right->left = new Node(60); 
    root->left->left->right = new Node(80); 
    
    cout << "Normal Version: ";
    preorderIterative(root);
    cout << endl;
    cout << "Space Optimized Version: ";
    preorderIterative_spaceOpt(root); 

    return 0;
}
