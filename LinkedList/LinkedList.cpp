#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void insertAthead(Node * &head , int data) // passing head by reference to avoid creating copy
{
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node* n = new Node(data);
    n->next = head;
    head = n;

}
void insertInMiddle(Node *head , int data , int pos)
{
    if(pos == 0)
    {
        insertAthead(head  , data);
    }else{

        Node *temp = head;
        for(int i = 1 ; i<= pos-1 ;i++)
        {
            temp = temp->next;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

}
int Length_of_LinkedList(Node *head )
{
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
void insertAtend(Node *head , int data)
{
    int sz = Length_of_LinkedList(head);
    for(int i = 1 ; i<= sz-1 ; i++){
        head = head->next;
    }
    Node* n = new Node(data);
    n->next = NULL;
    head->next = n;
}
void DeleteANode(Node*head , int pos)
{
       for(int jumps = 1 ; jumps <= pos-1 ; jumps++){
        head = head->next;
       }
       Node* current = head;
       current->next= (current->next)->next;
}
void print_LinkedList(Node * head)
{
    while(head != NULL){
        if(head->next != NULL)
            cout<<head->data<<"-->";
        else
            cout<<head->data<<"-->NULL";
        head = head->next;
    }
    cout<<"\n";
}
Node* IterativeReversal(Node* head )
{
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
Node* RecursiveReversal(Node* head)
{
    if(head == NULL or head->next == NULL)
        return head;

    Node* shead = RecursiveReversal(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}
Node* KReverse(Node *head , int k)
{
    if(head == NULL)
        return NULL;

    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    int cnt = 1;

    while(currptr!=NULL and cnt <= k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        cnt++;
    }
    if(nextptr!= NULL)
    {
        head->next = KReverse(nextptr , k);
    }
    return prevptr;
}
Node* ReverseKNodesofLL(Node* head , int k)
{
    /*Traversal till Kth Node*/
     Node* tmp = head;
    int cnt = 1;
    while(cnt < k){
        tmp = tmp->next;
        cnt++;
    }
    Node* jp = tmp->next;
    tmp->next = NULL;
    Node* sec  = IterativeReversal(head);
    head = sec;
    Node* v = head;
    while(v->next!= NULL)
    {
        v = v->next;
    }
    v->next = jp;
    return head;
}
Node* ExactlyKReversals(Node* head,  int k) // :Leetcode Hard Question: 
{
    int n = Length_of_LinkedList(head);
    int rem = n % k;
    if(rem != 0)
    {
        int totalNodesToTravel = n;
        Node* p = head;
        Node* cp = head;
        int k1= rem+1;
        while(k1 < totalNodesToTravel)
        {
            p = p->next;
            k1++;
        }
        print_LinkedList(p);
        Node* joint = p->next;
        Node* prevptr = NULL;
        Node* currptr = p->next;
        Node* nextptr;
        p->next = NULL;
        print_LinkedList(head);
        head = KReverse(head , k);
        print_LinkedList(head);
        Node* aa = head;
        while(head->next!=NULL)
        {
            head = head->next;
        }
        head->next = joint;
        return aa;
    }

        Node* ans = KReverse(head , k);
        return ans;

}
Node* printMiddle(Node* head)
{
    int count = 0;
    Node* mid = head;
 
    while (head != NULL)
    {
         
        // Update mid, when 'count'
        // is odd number
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    // If empty list is provided
    return mid;
}
 
Node* Merge(Node* l1 , Node* l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    Node* ans;
    if(l1->data <= l2->data)
    {
        ans = l1;
        ans->next = Merge(l1->next , l2);
    }
    else
    {
        ans = l2;
        ans->next = Merge(l1 , l2->next);
    }
    return ans;
}
Node* MergeSort(Node* head)
{
    if(head == NULL or head->next == NULL)
        return head;

    Node* mid = printMiddle(head);
    Node*a = head;
    Node*b = mid->next;
    a = MergeSort(a);
    b = MergeSort(b);

    return Merge(a , b);
}

void solve()
{
     int n;
     cin>>n;
     Node* head = NULL;
     for(int i = 0 ; i< n  ; ++i)
     {
        int x;
        cin>>x;
        insertAthead(head , x);
     }
     print_LinkedList(head);
     head = MergeSort(head);
     print_LinkedList(head);
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
          freopen("error.txt" , "w" , stderr);
    #endif
    solve();
    return 0;
}
