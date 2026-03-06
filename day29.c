#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n,k,val;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newNode;

    for(int i=0;i<n;i++){
        scanf("%d",&val);

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=val;
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    scanf("%d",&k);

    if(head==NULL || k==0){
        temp=head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return 0;
    }

    int len=1;
    temp=head;
    while(temp->next){
        temp=temp->next;
        len++;
    }

    temp->next=head;

    k = k % len;
    int steps = len - k;

    struct Node* curr=head;
    for(int i=1;i<steps;i++)
        curr=curr->next;

    head=curr->next;
    curr->next=NULL;

    temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
