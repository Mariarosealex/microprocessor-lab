#include<stdio.h>
void main()
{
  int choice,limit,n,time=0,completed=0,f=1;
  printf("Enter the number of processes\n");
  scanf("%d",&limit);
  int p[limit],bt[limit],wt[limit],tat[limit],rem[limit],prt[30];
  prt[0]=0;
   int temp,tq;
  int pr[limit];
  int tot_wt,tot_tat;
  float avg_wt,avg_tat;
  while(n==0){
  printf("\n1.Fcfs\n2.Sjf\n3.priority\n4.Roundrobin\nEnter the choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   printf("Enter the processes \n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time\n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&bt[i]);
  }
   wt[0]=0;
   tat[0]=bt[0];
   for(int i=1;i<limit;i++)
   {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=tat[i-1]+bt[i];
   }
   printf("Process\tBt\tWt\tTat\n");
   for(int i=0;i<limit;i++)
   {
    tot_wt+=wt[i];
    tot_tat+=tat[i];
    printf("p%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
   }
   printf("Total waiting time=%d\nTotat turn around time=%d\n",tot_wt,tot_tat);
   avg_wt=(float)tot_wt/limit;
   avg_tat=(float)tot_tat/limit;
   printf("Average waiting time:%f\naverage turn around time:%f\n",avg_wt,avg_tat);
   for(int i=0;i<limit;i++)
   {
    printf("\tp%d|\t",p[i]);
   }
   printf("\n");
   for(int i=0;i<limit;i++)
   {
    printf("%d\t\t",wt[i]);
   }
   printf("%d",tat[limit-1]);
   break;
   case 2:
   printf("Enter the processes \n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time\n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&bt[i]);
  }
   for(int i=0;i<limit;i++)
   {
    for(int j=i+1;j<limit;j++)
    {
    if(bt[i]>bt[j])
    {
      temp=bt[i];
      bt[i]=bt[j];
      bt[j]=temp;
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
    }
   }
   }
   wt[0]=0;
   tat[0]=bt[0];
   for(int i=1;i<limit;i++)
   {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=tat[i-1]+bt[i];
   }
   printf("Process\tBt\tWt\tTat\n");
   for(int i=0;i<limit;i++)
   {
    tot_wt+=wt[i];
    tot_tat+=tat[i];
    printf("p%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
   }
   printf("Total waiting time=%d\nTotat turn around time=%d\n",tot_wt,tot_tat);
   avg_wt=(float)tot_wt/limit;
   avg_tat=(float)tot_tat/limit;
   printf("Average waiting time:%f\naverage turn around time:%f\n",avg_wt,avg_tat);
   for(int i=0;i<limit;i++)
   {
    printf("\tp%d|\t",p[i]);
   }
   printf("\n");
   for(int i=0;i<limit;i++)
   {
    printf("%d\t\t",wt[i]);
   }
   printf("%d",tat[limit-1]);
   break;
   case 3:
   printf("Enter the processes \n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time\n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&bt[i]);
  }
   printf("Enter the priority \n");
   for(int i=0;i<limit;i++)
   {
    scanf("%d",&pr[i]);
   }
   for(int i=0;i<limit;i++)
   {
    for(int j=i+1;j<limit;j++)
    {
    if(pr[i]>pr[j])
    {
      temp=bt[i];
      bt[i]=bt[j];
      bt[j]=temp;
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
      temp=pr[i];
      pr[i]=pr[j];
      pr[j]=temp;
    }
   }
   }
    wt[0]=0;
   tat[0]=bt[0];
   for(int i=1;i<limit;i++)
   {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=tat[i-1]+bt[i];
   }
   printf("Process\tPriorityBt\tWt\tTat\n");
   for(int i=0;i<limit;i++)
   {
    tot_wt+=wt[i];
    tot_tat+=tat[i];
    printf("p%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
   }
   printf("Total waiting time=%d\nTotat turn around time=%d\n",tot_wt,tot_tat);
   avg_wt=(float)tot_wt/limit;
   avg_tat=(float)tot_tat/limit;
   printf("Average waiting time:%f\naverage turn around time:%f\n",avg_wt,avg_tat);
   for(int i=0;i<limit;i++)
   {
    printf("\tp%d|\t",p[i]);
   }
   printf("\n");
   for(int i=0;i<limit;i++)
   {
    printf("%d\t\t",wt[i]);
   }
   printf("%d",tat[limit-1]);
   break;
   case 4:
   printf("Enter the processes \n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time\n");
  for(int i=0;i<limit;i++)
  {
    scanf("%d",&bt[i]);
    rem[i]=bt[i];
  }
  printf("Enter the time quantum\n");
  scanf("%d",&tq);
 
  while(completed<limit)
  {
   for(int i=0;i<limit;i++)
   {
   if(rem[i]>0)
   {
    if(rem[i]>tq)
    {
     
     time=time+tq;
     rem[i]=rem[i]-tq;
     printf("  p%d\t",p[i]);
     prt[f]=time;
     f++;
    }
    else
    {
    
    time=time+rem[i];
    tat[i]=time;
    wt[i]=time-bt[i];
    rem[i]=0;
    completed++;
    printf("  p%d\t",p[i]);
    prt[f]=time;
     f++;
    }
    }
   }
  }
  
  
  printf("\n");
  for(int i=0;i<f;i++)
  {
   printf("%d\t",prt[i]);
  }
   printf("\nProcess\tBt\tWt\tTat\n");
   for(int i=0;i<limit;i++)
   {
    tot_wt+=wt[i];
    tot_tat+=tat[i];
    printf("p%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
   }
   printf("Total waiting time=%d\nTotat turn around time=%d\n",tot_wt,tot_tat);
   avg_wt=(float)tot_wt/limit;
   avg_tat=(float)tot_tat/limit;
   printf("Average waiting time:%f\naverage turn around time:%f\n",avg_wt,avg_tat);
  
   break;
   default:
   n=1;
   printf("Invalid choice\n");
   
   break;
  }
  }
} 

