#include <stdio.h>

struct Process {
    int id, burst, arrival, priority;
    int waiting, turnaround, remaining, completed;
};

void printGanttChart(int order[], int count) {
    printf("\nGantt Chart:\n");
    for(int i = 0; i < count; i++)
        printf("| P%d ", order[i]);
    printf("|\n");
}

// FCFS
void fcfs(struct Process p[], int n) {
    int time = 0, gc[50], gcCount = 0;

    printf("\n===== FCFS Scheduling =====\n");

    for(int i=0;i<n;i++) {
        if(time < p[i].arrival) time = p[i].arrival; 
        p[i].waiting = time - p[i].arrival;
        time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        gc[gcCount++] = p[i].id;
        printf("P%d: Waiting=%d  Turnaround=%d\n", p[i].id, p[i].waiting, p[i].turnaround);
    }

    printGanttChart(gc, gcCount);

    float avgW=0, avgT=0;
    for(int i=0;i<n;i++){ avgW+=p[i].waiting; avgT+=p[i].turnaround; }
    printf("\nAvg Waiting: %.2f\nAvg Turnaround: %.2f\n", avgW/n, avgT/n);
}

// SJF (Non-Preemptive)
void sjf(struct Process p[], int n) {
    int time = 0, done = 0, gc[50], gcCount=0;
    int mark[10]={0};

    printf("\n===== SJF Scheduling =====\n");

    while(done < n) {
        int idx=-1, minB=9999;
        for(int i=0;i<n;i++)
            if(!mark[i] && p[i].arrival <= time && p[i].burst < minB)
                minB=p[i].burst, idx=i;

        if(idx==-1) { time++; continue; }

        mark[idx]=1;
        p[idx].waiting = time - p[idx].arrival;
        time += p[idx].burst;
        p[idx].turnaround = p[idx].waiting + p[idx].burst;
        gc[gcCount++] = p[idx].id;
        done++;

        printf("P%d: Waiting=%d Turnaround=%d\n", p[idx].id, p[idx].waiting, p[idx].turnaround);
    }

    printGanttChart(gc, gcCount);

    float avgW=0, avgT=0;
    for(int i=0;i<n;i++){ avgW+=p[i].waiting; avgT+=p[i].turnaround; }
    printf("\nAvg Waiting: %.2f\nAvg Turnaround: %.2f\n", avgW/n, avgT/n);
}

// Round Robin
void rr(struct Process p[], int n, int q) {
    int time=0, remain=n, gc[100], gcCount=0;

    for(int i=0;i<n;i++) p[i].remaining = p[i].burst;

    printf("\n===== Round Robin (q=%d) =====\n",q);

    while(remain>0) {
        for(int i=0;i<n;i++) {
            if(p[i].remaining>0 && p[i].arrival <= time) {
                gc[gcCount++] = p[i].id;

                int run = (p[i].remaining > q) ? q : p[i].remaining;
                p[i].remaining -= run;
                time += run;

                if(p[i].remaining == 0) {
                    remain--;
                    p[i].waiting = time - p[i].arrival - p[i].burst;
                    p[i].turnaround = p[i].waiting + p[i].burst;
                    printf("P%d: Waiting=%d Turnaround=%d\n", p[i].id, p[i].waiting, p[i].turnaround);
                }
            }
        }
    }

    printGanttChart(gc, gcCount);

    float avgW=0, avgT=0;
    for(int i=0;i<n;i++){ avgW+=p[i].waiting; avgT+=p[i].turnaround; }
    printf("\nAvg Waiting: %.2f\nAvg Turnaround: %.2f\n", avgW/n, avgT/n);
}

// Priority
void priority(struct Process p[], int n) {
    int time = 0, done=0, gc[50], gcCount=0, mark[10]={0};

    printf("\n===== Priority Scheduling =====\n");

    while(done < n) {
        int idx=-1, best=9999;
        for(int i=0;i<n;i++)
            if(!mark[i] && p[i].arrival<=time && p[i].priority < best)
                best=p[i].priority, idx=i;

        if(idx==-1) { time++; continue; }

        mark[idx]=1;
        p[idx].waiting = time - p[idx].arrival;
        time += p[idx].burst;
        p[idx].turnaround = p[idx].waiting + p[idx].burst;
        gc[gcCount++] = p[idx].id;
        done++;

        printf("P%d: Waiting=%d Turnaround=%d\n", p[idx].id, p[idx].waiting, p[idx].turnaround);
    }

    printGanttChart(gc, gcCount);

    float avgW=0, avgT=0;
    for(int i=0;i<n;i++){ avgW+=p[i].waiting; avgT+=p[i].turnaround; }
    printf("\nAvg Waiting: %.2f\nAvg Turnaround: %.2f\n", avgW/n, avgT/n);
}

// ==== MAIN MENU ====
int main() {
    struct Process p[10];
    int n, choice, q;

    printf("\n===== OS CPU Scheduling Simulator =====\n");
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("\nEnter Arrival  Burst  Priority\n");
    for(int i=0;i<n;i++) {
        p[i].id=i+1;
        scanf("%d %d %d",&p[i].arrival,&p[i].burst,&p[i].priority);
    }

    printf("\n1.FCFS\n2.SJF\n3.Round Robin\n4.Priority\nSelect: ");
    scanf("%d",&choice);

    if(choice==3) {
        printf("Enter Time Quantum: ");
        scanf("%d",&q);
    }

    printf("----------------------------------------\n");

    switch(choice) {
        case 1: fcfs(p,n); break;
        case 2: sjf(p,n); break;
        case 3: rr(p,n,q); break;
        case 4: priority(p,n); break;
        default: printf("Invalid Option!\n");
    }

    printf("\n===== Simulation End =====\n");
    return 0;
}
