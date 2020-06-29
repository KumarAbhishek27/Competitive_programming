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

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

class Node{
public:
    int data;
    Node* next;
};

Node* newNode(int data){ 
    Node* new_node = new Node(); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 

void push(Node** head_ref, int new_data){
    
    Node* new_node = new Node();
    
    new_node->data = new_data;
    
    new_node->next = (*head_ref);
    
    (*head_ref) = new_node;
}

/* Adds contents of two linked lists and  
return the head node of resultant list */
Node* addTwoLists(Node* first, Node* second){
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    // while both list exits
    while(first != NULL || second != NULL){
        // Calculate value of next 
        // digit in resultant list. 
        // The next digit is sum of 
        // following things 
        // (i) Carry 
        // (ii) Next digit of first 
        // list (if there is a next digit) 
        // (ii) Next digit of second 
        // list (if there is a next digit) 

        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        
        // update carry for next calulation 
        carry = (sum >= 10) ? 1 : 0; 

        // update sum if it is greater than 10 
        sum = sum % 10; 

        // Create a new node with sum as data 
        temp = newNode(sum); 

        // if this is the first node then 
        // set it as head of the resultant list 
        if(res == NULL) res = temp;

        // If this is not the first 
        // node then connect it to the rest. 
        else prev->next = temp; 

        // Set prev for next insertion 
        prev = temp; 

        // Move first and second pointers
        // to next nodes
        if(first) first = first->next;
        if(second) second = second->next;
    }

    if(carry > 0) 
        temp->next = newNode(carry);
    
    return res;
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
    Node* first = NULL; 
    Node* second = NULL; 
  
    // create first list 7->5->9->4->6 
    push(&first, 6); 
    push(&first, 4); 
    push(&first, 9); 
    push(&first, 5); 
    push(&first, 7); 
    printf("First List is "); 
    printList(first); 
  
    // create second list 8->4 
    push(&second, 4); 
    push(&second, 8); 
    cout << "Second List is "; 
    printList(second); 
  
    // Add the two lists and see result 
    res = addTwoLists(first, second); 
    cout << "Resultant list is: "; 
    printList(res); 
    
    return 0;
}
