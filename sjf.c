//SJF shortest job first

#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform SJF scheduling
void sjf(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burstTime > processes[j].burstTime) {
                swap(&processes[i].burstTime, &processes[j].burstTime);
                swap(&processes[i].id, &processes[j].id);
            }
        }
    }
    
    processes[0].waitingTime = 0;
    
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = 0;
        for (int j = 0; j < i; j++) {
            processes[i].waitingTime += processes[j].burstTime;
        }
    }
    
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }
    
    sjf(processes, n);
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    
    // Calculate and print throughput
    int totalBurstTime = 0;
    for (int i = 0; i < n; i++) {
        totalBurstTime += processes[i].burstTime;
    }
    
    float throughput = n / (totalBurstTime * 1.0);
    
    printf("Throughput: %.2f processes/unit time\n", throughput);
    
    return 0;
}
