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

class Node{
public:
    int data;
    Node* next;
};

Node* newNode(int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// A utility function to print a linked list 
void printList(Node* head){ 
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    cout << endl; 
} 

/*

1) i = m + p * n + k (Tortoise)
2) 2i = m + q * n + k (Hare)

m + k = ( q - 2p ) n

Then, if we let them move m + k steps, tortoise would have to arrive at the point they met 
originally (k steps away from the cycle beginning - see in the figure). Previously we showed that m + k = (q - 2p) n. 
Since m + k steps is a multiple of cycle length n, hare, in the mean time, would go through the cycle (q-2p) times 
and would come back to the same point (k steps away from the cycle beginning).Now, instead of letting them move m + k steps, 
if we let them move only m steps, tortoise would arrive at the cycle beginning. Hare would be k steps short of completing 
(q-2p) rotations. Since it started k steps in front of the cycle beginning, hare would have to arrive at the cycle beginning.

*/


Node* detectAndRemoveLoop(Node* head){
    // if the list is empty or contains only one node
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* slow = head, *fast = head;
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next;

    while(fast && fast->next){
        if(slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop doesn't exist
    if(slow != fast)
        return NULL;

    // If loop exists. Start slow from 
    // head and fast from meeting point
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    Node* res = detectAndRemoveLoop(head); 

    if (res == NULL) 
        cout << "Loop does not exist"; 
    else
        cout << "Loop starting node is " << res->data;

    return 0;
}
