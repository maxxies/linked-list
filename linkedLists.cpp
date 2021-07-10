#include <iostream>
#include <cstdlib>

using namespace std;
/*
    Inserting elements into a singly linked list from the start implementing linked list
 */

/*
struct Node{
    int data;
    Node* next;
};
struct Node* head;

void Insert(int number);
void Print();
void Reverse();
void recursivePrint(Node* head);
void recursiveReverse(Node* p);

int main(){
    head = NULL;
    int n,x,i;

    cout << "Total numbers to store: "<<endl;
    cin >>n;
    for(i = 0;i<n;i++){
        cout<<"Enter number: ";
        cin >>x;
        Insert(x);
        Print();
        Reverse();
        Print();
        recursivePrint(head);
        recursiveReverse(head);
        Print();
    }
    return 0;
};

void Insert(int number){  //Creates nodes and put in the elements
    struct Node* temp = new Node();// (Node*)malloc(sizeof(struct Node));
    temp -> data = number;
    temp -> next = NULL;
    if(head != NULL){
        temp -> next = head;
    }
    head = temp;
}
void Print(){  //Prints out the elements of the nodes
    struct Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n"<<endl;
}
void Reverse(){  //Reverse the addresses of the nodes
    struct Node *prev, *current, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current -> next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void recursivePrint(Node* head){  //Recursive printing of elements
    if(head==NULL){
        return;
    }else{
    cout<<head->data;
    recursivePrint(head->next);
    }
}
void recursiveReverse(Node* p){
    if (p-> next == NULL){
        head = p;
        return;
    }
    recursiveReverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

*/

/*
    Inserting elements into a doubly linked list from the start implementing linked list
 */


 struct Node{
    int data;
    Node* prev;
    Node* next;
 };

 struct Node* head;

 struct Node* SetAtHead(int x);
 void InsertAtHead(int x);
 void Print();
 void reversePrint();
 void InsertAtPosition(int a,int b);
 int TotalElements();

 int main(){
    head = NULL;
    int x,n,i;
    cout<<"Total numbers to input: "<<endl;
    cin>>x;
    for(i = 0; i < x; i++){
       cout<<"Enter number: "<<endl;
       cin>>n;
       InsertAtHead(n);
       Print();
       reversePrint();
    }
    InsertAtPosition(4,4);
    Print();
    return 0;
 }

 struct Node* SetAtHead(int x){   //Creates nodes for the elements
    struct Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
 }
 void InsertAtHead(int x){
    struct Node* newNode = SetAtHead(x);
    if(head == NULL){ //Checks if its the first node
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
 }
 void Print(){  //Prints out the elements of the nodes
    struct Node* temp = head;
    cout<<"Forward: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n"<<endl;
}
void reversePrint(){
    struct Node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"Reverse: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<"\n"<<endl;
}
void InsertAtPosition(int a,int b){
    Node* posNode = new Node;
    struct Node *current, *temp;

    int totalElements = TotalElements();
    if ((b <= 0)||(b >(totalElements + 1))){
       cout<<"Invalid Position, try again."<<endl;
    }
    else{
        posNode->data = a;
        posNode->prev = NULL;
        posNode->next = NULL;
        if(b == 1){
            current = head;
            posNode->next = current;
            current->prev = posNode;
            head = posNode;
            return;
        }
        else if(b == totalElements + 1){
            temp = head;
            for(int m = 0; m <(b-2); m++){
              temp = temp->next;
            }
            temp->next = posNode;
            posNode->prev = temp;
        }
        else{
            temp = head;
            for(int m = 0; m <(b-2); m++){
              temp = temp->next;
            }
            current = temp->next;
            posNode->next = current;
            posNode->prev = temp;
            temp->next = posNode;
            current->prev = posNode;
        }
    }
}
int TotalElements(){
    int counter = 0;
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        counter ++;
    };
    return (counter+1);
}
