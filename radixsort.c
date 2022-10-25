#include<stdio.h>
#include<stdlib.h>
typedef struct queue_node
{
int data;
struct queue_node *next;
}QueueNode;
typedef struct $__queue__$
{
int size;
QueueNode *start;
QueueNode *end;
}Queue;
void init(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isEmpty(Queue *queue)
{
return queue->start==NULL;
}
void addToQueue(Queue *queue,int data)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->data=data;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
int popFromQueue(Queue *queue)
{
QueueNode *t;
int data;
data=queue->start->data;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL)queue->end=NULL;
free(t);
queue->size--;
return data;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(!(isEmpty(queue)))
{
t=queue->start;
free(t);
queue->start=queue->start->next;
queue->size--;
}
queue->end=NULL;
queue->size=0;
}
int main()
{
int num,x[10],i,dc,largest,k,y,e,f;
Queue queues[10];
for(i=0;i<10;i++)init(&queues[i]);
for(i=0;i<10;i++)
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
for(largest=x[0],i=1;i<10;i++)
{
if(x[i]>largest)largest=x[i];
}
num=largest;
dc=1;
while(num>9)
{
num=num/10;
dc++;
}
k=1;
e=10;
f=1;
while(k<=dc)
{
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
y=0;
i=0;
while(y<=9)
{
while(!(isEmpty(&queues[y])))
{
num=popFromQueue(&queues[y]);
x[i]=num;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
for(i=0;i<10;i++)printf("%d\n",x[i]);
return 0;
}
