#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;

    if(head==NULL) return newNode;

    struct Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
    return head;
}

int length(struct Node* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

int main(){
    int n,m,x;
    struct Node *l1=NULL,*l2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        l1=append(l1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        l2=append(l2,x);
    }

    int len1=length(l1);
    int len2=length(l2);

    struct Node *p1=l1,*p2=l2;

    if(len1>len2){
        for(int i=0;i<len1-len2;i++) p1=p1->next;
    }else{
        for(int i=0;i<len2-len1;i++) p2=p2->next;
    }

    while(p1 && p2){
        if(p1->data==p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");
    return 0;
}
