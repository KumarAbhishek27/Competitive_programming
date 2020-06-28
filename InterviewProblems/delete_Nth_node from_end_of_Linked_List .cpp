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
// Space Complexity: O(1)

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

Node* deleteNodefromEnd(Node* head, int key){
    
    // First pointer will point to 
    // the head of the linked list 
    Node *first = head; 
  
    // Second pointer will point to the 
    // Nth node from the beginning 
    Node *second = head; 

    // so when second points at the end of the list
    // the first pointer will be pointing to the nth node from
    // the end because distance between the 2 pointers is n.

    for(int i = 0; i < key; ++i){
        // If count of nodes in the given 
        // linked list is <= N 
        if (second->next == NULL){ 
            // If count = N i.e. 
            // delete the head node 
            if (i == key - 1) 
                head = head->next; 
                return head; 
        } 
        second = second->next; 
    }

    // Increment both the pointers by one until 
    // second pointer reaches the end 
    while(second->next != NULL){
        first = first->next;
        second = second->next;
    }

    // First must be pointing to the 
    // Nth node from the end by now 
    // So, delete the node first is pointing to
    first->next = first->next->next;
    return head;
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

    Node* head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    head = deleteNodefromEnd(head, 3);
    cout << "List after deleting the 3rd Node from end: \n";
    printList(head);
    
    return 0;
}
