#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n,val;
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

    temp->next=head;

    struct Node* curr=head;
    do{
        printf("%d ",curr->data);
        curr=curr->next;
    }while(curr!=head);

    return 0;
}
