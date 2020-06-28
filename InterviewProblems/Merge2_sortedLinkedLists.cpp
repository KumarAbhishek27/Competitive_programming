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

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    
    Node* new_node = new Node();
    
    new_node->data = new_data;
    
    new_node->next = (*head_ref);
    
    (*head_ref) = new_node;
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the 
node from the front of the source, 
and move it to the front of the dest.  
It is an error to call this with the  
source list empty.  
  
Before calling MoveNode():  
source == {1, 2, 3}  
dest == {1, 2, 3}  
  
Affter calling MoveNode():  
source == {2, 3}  
dest == {1, 1, 2, 3} */

void MoveNode(Node** destRef, Node** sourceRef){
    
    Node* newNode = *sourceRef;
    assert(newNode != NULL);

    /* Advance the source pointer */
    *sourceRef = newNode->next;
    
    /* Link the old dest off the new node */
    newNode->next = *destRef;
    
    /* Move dest to point to the new node */
    *destRef = newNode; 
}

Node* SortedMerge(Node* a, Node* b){
    /* a dummy first node to hang the result on */
    Node dummy;  

    /* tail points to the last result node */
    //Node* tail = &dummy; 
    Node* tail = &dummy;

    /* so tail->next is the place to   
    add new nodes to the result. */
    dummy.next = NULL;
    while(1){
        if(a == NULL){
            tail->next = b;
            break;
        }
        else if(b == NULL){
            tail->next = a;
            break;
        }
        if(a->data <= b->data){
            MoveNode(&(tail->next), &a);
        }
        else{
            MoveNode(&(tail->next), &b);
        }

        tail = tail->next;
    }

    return (dummy.next);
}

Node* SortedMergeRecursive(Node* a, Node* b){  
    Node* result = NULL;  
      
    /* Base cases */
    if (a == NULL)  
        return(b);  
    else if (b == NULL)  
        return(a);  
      
    /* Pick either a or b, and recur */
    if (a->data <= b->data){  
        result = a;  
        result->next = SortedMerge(a->next, b);  
    }  
    else{  
        result = b;  
        result->next = SortedMerge(a, b->next);  
    }  
    return(result);  
}  


void printList(Node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* res = NULL;  
    Node* a = NULL;  
    Node* b = NULL;  
  
    /* Let us create two sorted linked lists   
    to test the functions  
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);  
    push(&a, 10);  
    push(&a, 5);  
  
    push(&b, 20);  
    push(&b, 3);  
    push(&b, 2);  
  
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);  
  
    cout << "Merged Linked List is: \n";  
    printList(res);  
  
    
    return 0;
}
