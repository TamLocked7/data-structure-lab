#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
struct node *next;
};

typedef struct node *NODE;

NODE createNodeInCLL(int data){
NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
return temp;
}

NODE createCLL(int n){
  if(n<=0) return NULL;
NODE first=NULL,temp,last=NULL;
int x;
  for(int i=0;i<n;i++){
scanf("%d",&x);
  temp=createNodeInCLL(x);
  if(first==NULL){
    first=temp;
    last=temp;
    last->next=first;
}else{
    last->next=temp;
    last=temp;
    last->next=first;
}
}
return first;
}

void traverseListInCLL(NODE first){
NODE cur=first;
do{
printf("%d -> ",cur->data);
    cur=cur->next;
}
  while(cur!=first);
printf("\n");
}

NODE insertAtPositionInCLL(NODE first,int pos,int x){
NODE temp=createNodeInCLL(x);
  if(first==NULL && pos==1){
    temp->next=temp;
return temp;
}
NODE curr=first;
int count=1;
  if(pos==1){
  while(curr->next!=first) curr=curr->next;
    temp->next=first;
    curr->next=temp;
    first=temp;
return first;
}
    curr=first;
    count=1;
  while(count<pos-1 && curr->next!=first){
    curr=curr->next;
    count++;
}
  if(count!=pos-1){
printf("Position not found\n");
return first;
}
    temp->next=curr->next;
    curr->next=temp;
return first;
}

NODE deleteAtPositionInCLL(NODE first,int pos){
NODE curr=first,prev=NULL;
int count=1;
  if(pos==1){
  while(curr->next!=first) curr=curr->next;
NODE temp=first;
printf("Deleted element: %d\n",temp->data);
  if(first->next==first){
    free(first);
return NULL;
}
    first=first->next;
    curr->next=first;
    free(temp);
return first;
}
    curr=first;
  while(count<pos && curr->next!=first){
    prev=curr;
    curr=curr->next;
    count++;
}
  if(count!=pos){
printf("Position not found\n");
return first;
}
printf("Deleted element: %d\n",curr->data);
    prev->next=curr->next;  
    free(curr);
    return first;
}

NODE reverseCLL(NODE first){
NODE prev=NULL,cur=first,next;
NODE start=first;
do{
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
}
  while(cur!=start);
    first->next=prev;
    first=prev;
return first;
}

NODE concatCLL(NODE first,NODE second){
  if(first==NULL) return second;
  if(second==NULL) return first;
NODE last1=first,last2=second;
  while(last1->next!=first) last1=last1->next;
  while(last2->next!=second) last2=last2->next;
    last1->next=second;
    last2->next=first;
return first;
}

int main(){
NODE first=NULL,second=NULL;
int x,pos,op,n;
  while(1){
printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
printf("choice: ");
scanf("%d",&op);
    switch(op){
case 1:
printf("How many nodes? ");
scanf("%d",&n);
first=createCLL(n);
break;
case 2:
printf("Position: ");
scanf("%d",&pos);
if(pos<=0){
printf("Position not found\n");
}else{
printf("Element: ");
scanf("%d",&x);
first=insertAtPositionInCLL(first,pos,x);
}
break;
case 3:
if(first==NULL){
printf("CLL is empty\n");
}else{
printf("Position: ");
scanf("%d",&pos);
first=deleteAtPositionInCLL(first,pos);
}
break;
case 4:
if(first==NULL){
printf("CLL is empty\n");
}else{
printf("Elements in CLL are: ");
traverseListInCLL(first);
}
break;
case 5:
if(first==NULL){
printf("CLL is empty\n");
}else{
first=reverseCLL(first);
printf("CLL reversed\n");
traverseListInCLL(first);
}
break;
case 6:
printf("Creating second CLL to concatenate...\n");
printf("How many nodes in second CLL? ");
scanf("%d",&n);
second=createCLL(n);
first=concatCLL(first,second);
printf("Concatenated CLL:\n");
traverseListInCLL(first);
break;
case 7:
exit(0);
}
}
}
