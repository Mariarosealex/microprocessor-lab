#include<stdio.h>
#include<stdlib.h>
void main()
{
  int num,head,range,total=0,choice,n=1,rq[30];
  float avg;
  while(n==1){
  printf("1.Fcfs\t2.Scan\t3.C-scan\nEnter the choice\n");
  scanf("%d",&choice);
  if(choice==1){
     printf("Enter the number of requests\n");
     scanf("%d",&num);
     printf("Enter the head position\n");
     scanf("%d",&head);
     printf("Enter the maximum range\n");
     scanf("%d",&range);
     
     printf("Enter the disc requests\n");
     for(int i=0;i<num;i++)
     {
       scanf("%d",&rq[i]);
     }
     printf("Head movement from %d to %d = %d\n",head,rq[0],abs(head-rq[0]));
     total+=abs(head-rq[0]);
     for(int i=0;i<num-1;i++)
     {
        printf("Head movement from %d to %d = %d\n",rq[i],rq[i+1],abs(rq[i+1]-rq[i]));
        total+=abs(rq[i+1]-rq[i]);
     }
    printf("Total head movement = %d\n",total);
    avg=(float)total/num;
    printf("Average head movement = %f\n",avg);
    }
   else if(choice==2){
     int j,temp1=0,temp2=0,queue1[20],queue2[20],queue[30],num,temp;
     printf("Enter the number of requests\n");
     scanf("%d",&num);
     printf("Enter the head position\n");
     scanf("%d",&head);
     printf("Enter the maximum range\n");
     scanf("%d",&range);
    
     printf("Enter the disc requests\n");
     for(int i=0;i<num;i++)
     {
       scanf("%d",&rq[i]);
     }
     for(int i=0;i<num;i++){
     if(rq[i]<=head)
     {
       queue1[temp1]=rq[i];
       temp1++;
     }
     else
     {
       queue2[temp2]=rq[i];
       temp2++;
     }
    } 
    for(int i=0;i<temp1;i++)
    { 
      for(int j=i+1;j<temp1;j++)
      {
        if(queue1[j]>queue1[i])
        {
        temp=queue1[i];
        queue1[i]=queue1[j];
        queue1[j]=temp;
        }
      }
    }
    for(int i=0;i<temp2;i++)
    { 
      for(int j=i+1;j<temp2;j++)
      {
        if(queue2[j]<queue2[i])
        {
        temp=queue2[i];
        queue2[i]=queue2[j];
        queue2[j]=temp;
        }
      }
    }
    for(int i=0;i<temp2;i++)
    {
      queue[i]=queue2[i];
    }
    queue[temp2]=range;
    j=temp2;
    j++;
    for(int i=0;i<temp1;i++)
    {
      queue[j]=queue1[i];
      j++;
    }
    printf("Head movement from %d to %d = %d\n",head,queue[0],abs(head-queue[0]));
     total+=abs(head-queue[0]);
     for(int i=0;i<num;i++)
     {
        printf("Head movement from %d to %d = %d\n",queue[i],queue[i+1],abs(queue[i+1]-queue[i]));
        total+=abs(queue[i+1]-queue[i]);
     }
    printf("Total head movement = %d\n",total);
    avg=(float)total/num;
    printf("Average head movement = %f\n",avg);
   }
   else if(choice==3)
   {
     int j,temp1=0,temp2=0,queue1[20],queue2[20],queue[30],num,temp;
     printf("Enter the number of requests\n");
     scanf("%d",&num);
     printf("Enter the head position\n");
     scanf("%d",&head);
     printf("Enter the maximum range\n");
     scanf("%d",&range);
    
     printf("Enter the disc requests\n");
     for(int i=0;i<num;i++)
     {
       scanf("%d",&rq[i]);
     }
     for(int i=0;i<num;i++){
     if(rq[i]<=head)
     {
       queue1[temp1]=rq[i];
       temp1++;
     }
     else
     {
       queue2[temp2]=rq[i];
       temp2++;
     }
    } 
    for(int i=0;i<temp1;i++)
    { 
      for(int j=i+1;j<temp1;j++)
      {
        if(queue1[j]<queue1[i])
        {
        temp=queue1[i];
        queue1[i]=queue1[j];
        queue1[j]=temp;
        }
      }
    }
    for(int i=0;i<temp2;i++)
    { 
      for(int j=i+1;j<temp2;j++)
      {
        if(queue2[j]<queue2[i])
        {
        temp=queue2[i];
        queue2[i]=queue2[j];
        queue2[j]=temp;
        }
      }
    }
    j=0;
    for(int i=0;i<temp2;i++)
    {
      queue[j]=queue2[i];
      j++;
    }
    queue[j]=range;
    
    j++;
    queue[j]=0;
    j++;
    for(int i=0;i<temp1;i++)
    {
      queue[j]=queue1[i];
      j++;
    }
    printf("Head movement from %d to %d = %d\n",head,queue[0],abs(head-queue[0]));
     total+=abs(head-queue[0]);
     for(int i=0;i<=num;i++)
     {
        printf("Head movement from %d to %d = %d\n",queue[i],queue[i+1],abs(queue[i+1]-queue[i]));
        total+=abs(queue[i+1]-queue[i]);
     }
    printf("Total head movement = %d\n",total);
    avg=(float)total/num;
    printf("Average head movement = %f\n",avg);
   }
   
  else{
  n=0;
   printf("Invalid choice\n");
   break;
   }
  }
}

