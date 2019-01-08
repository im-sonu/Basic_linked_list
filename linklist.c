#include<stdio.h>
#include<stdlib.h>

struct list{
    int data;
    struct list *link;
};

void printlist(struct list *head){
struct list *p=head;
while(p!=NULL){
printf("%d ",p->data);
p=p->link;
}

}

int search(struct list *head, int value){
//printf("baigan");
    while(head!=NULL){
        if(head->data==value)
            return 1;    
    head=head->link;
    }
return 0;
}


struct list *delete(struct list *head,int value)
{
if(head->data==value){
struct list *p=head;
head=head->link;
free(p);
return head;
}
struct list *p=head;
while(p->link->data!=value)
{
 p=p->link; 
}

struct list *q;
q=p->link->link;
p->link=q;
return head;
}

struct list *inserttohead(struct list *head,int key){
struct list *tmp=(struct list *)malloc(sizeof(struct list));
tmp->data=key;
tmp->link=head;
head=tmp;

return head;
}

struct list *insertafter(struct list *head,int key,int value){
struct list *p=head;
while(p->link->data!=key){
p=p->link;
}
p=p->link;
struct list *tmp=(struct list *)malloc(sizeof(struct list));
tmp->data=value;
tmp->link=p->link;
p->link=tmp;

return head;
}

struct list *inserttotail(struct list *head,int key){

    if(head==NULL){
        struct list *tmp=(struct list *)malloc(sizeof(struct list));
        tmp->data=key;
        tmp->link=NULL;
        head=tmp; 
        return head;       
    }
    else{
    struct list *p=head; 
        while(p->link!=NULL){
            p=p->link;
        }
    
        struct list *tmp=(struct list *)malloc(sizeof(struct list));
        tmp->data=key;
        tmp->link=NULL;
        p->link=tmp;

}

return head;
}
void reverseprint(struct list *head){
if(head==NULL)
return;
reverseprint(head->link);
printf("%d ",head->data);
}

int main(){
    printf("total number to insert: ");
    int n;
    scanf("%d",&n);
    printf("Numbers to insert\n");
    int i,key;
    struct list *head = NULL;
    for(i=0;i<n;i++){
    scanf("%d",&key);
    head=inserttotail(head,key);
}
printlist(head);
printf("\n");
reverseprint(head);
printf("\n");
int sea;
printf("NUMBER TO SEARCH: ");

scanf("%d",&sea);
//printf("aaloo");
if(search(head,sea)==1)
printf("Found");
else
printf("Not Found");
printf("\n");
printf("NUMBER TO DELETE: ");

scanf("%d",&sea);
head=delete(head,sea);
printlist(head);
printf("\n");
printf("Add to head: ");

scanf("%d",&sea);
head=inserttohead(head,sea);
printlist(head);
printf("\n");
printf("Insert after: ");
int value;
scanf("%d %d",&sea,&value);

head=insertafter(head,sea);
printlist(head);
}
