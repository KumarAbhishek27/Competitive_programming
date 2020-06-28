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


void deleteNode(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev;

    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;
    prev->next = temp->next;
    delete temp;
}

// fast and slow pointer technique
void printMiddle(Node* head){
    Node* fastptr = head;
    Node* slowptr = head;

    if(head != NULL){
        while(fastptr != NULL && fastptr->next != NULL){
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        cout << "The Middle of the List is: " << slowptr->data << "\n\n";
    }
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

    /* Start with the empty list */
	Node* head = NULL; 

    // Iterate and add element  
    for (int i = 5; i > 0; i--){  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
    
    return 0;
}
