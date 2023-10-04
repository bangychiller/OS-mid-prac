#include <stdio.h>

typedef struct myProcess
{
    // int PID;    //Process ID
    int AT;     //Arrival Time
    int BT;     //Burst Time
    int CT;     //Completion Time
    int TAT;    //Turn Around Time
    int WT;     //Wating Time
    int RT;     //Reponse Time
    int ST;     //Starting Time
}MP;

void calculateCompletionTime(MP arr[], int n)
{
    arr[0].CT=arr[0].BT;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1].CT>arr[i].AT)
            arr[i].CT=arr[i].BT+arr[i-1].CT;
        else
            arr[i].CT=arr[i].BT+arr[i].AT;
    }
}
void calculateTurnAroundTime(MP arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i].TAT=arr[i].CT-arr[i].AT;
}
void calculateWaitingTime(MP arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i].WT=arr[i].TAT-arr[i].BT;
}
void calculateStartTime(MP arr[], int n)
{
    arr[0].ST=0;
    for(int i=1;i<n;i++)
        arr[i].ST=arr[i-1].CT>arr[i].AT?arr[i-1].CT:arr[i].AT;
        
}
void calculateResponseTime(MP arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i].RT=arr[i].ST-arr[i].AT;
}
// void calculateProcessID(MP arr[], int n)
// {
//     return;
// }

int main()
{
    int n;
    printf("Input the number of processes : ");
    scanf("%d",&n);
    MP arr[n];

    for(int i=0;i<n;i++)
    {   
        printf("Input arrival time for process no. %d : ",i+1);
        scanf("%d",&arr[i].AT);
        printf("Input burst time for process no. %d : ",i+1);
        scanf("%d",&arr[i].BT);
    }

    calculateCompletionTime(arr,n);
    calculateTurnAroundTime(arr,n);
    calculateWaitingTime(arr,n);
    calculateStartTime(arr,n);
    calculateResponseTime(arr,n);

    printf("Process No.     Process ID     Arrival Time     Start Time     Completion Time     Waiting Time     Turn Around Time     Response Time\n");

    for(int i=0;i<n;i++)
    {
        printf("     %d         %d          %d              %d               %d                %d                   %d                 %d\n",(i+1),1613033978,arr[i].AT,arr[i].ST,arr[i].CT,arr[i].WT,arr[i].TAT,arr[i].RT);
    }


    return 0;
}
