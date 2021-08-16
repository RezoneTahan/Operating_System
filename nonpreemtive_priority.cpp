#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct process {
    int id;
    int arrival_time;
    int cpu_time;
    int priority;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;

}p[100];



int main() {

    int n;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    int is_completed[100] ={0};
    memset(is_completed,0,sizeof(is_completed));


    cout<<"Enter the number of processes: ";
    cin>>n;


    cout<<"Enter the CPU times: \n";
    for(int i = 0; i < n; i++) {


        cin>>p[i].cpu_time;

    }

    cout<<"Enter arrival time of process : \n";

    for(int i = 0; i < n; i++) {

        cin>>p[i].arrival_time;
        p[i].id = i+1;

    }

    cout<<"Enter the priority values : \n";

    for(int i = 0; i < n; i++) {


        cin>>p[i].priority;

    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;


    while(completed != n)
        {
        int px = -1;
        int mnm = 10000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(p[i].priority < mnm) {
                    mnm = p[i].priority;
                    px = i;
                }
                if(p[i].priority == mnm) {
                    if(p[i].arrival_time < p[px].arrival_time) {
                        mnm = p[i].priority;
                        px = i;
                    }
                }
            }
        }

        if(px != -1) {
            p[px].start_time = current_time;
            p[px].completion_time = p[px].start_time + p[px].cpu_time;
            p[px].turnaround_time = p[px].completion_time - p[px].arrival_time;
            p[px].waiting_time = p[px].turnaround_time - p[px].cpu_time;


            total_turnaround_time += p[px].turnaround_time;
            total_waiting_time += p[px].waiting_time;

            is_completed[px] = 1;
            completed++;
            current_time = p[px].completion_time;
            prev = current_time;
        }
        else {
            current_time++;
        }

    }


    double avg_waiting_time = total_waiting_time/n;
    double avg_turnaround_time =  total_turnaround_time/n ;



    for (int i = 0; i < n; i++)
    {
        cout << "Process " << p[i].id << ": Waiting Time: " << p[i].waiting_time << " Turnaround Time: " << p[i].turnaround_time << endl;
    }
    cout << fixed << setprecision(2)<< "Average Waiting time: " << avg_waiting_time << endl;
    cout << "Average Turnaround time: " << avg_turnaround_time << endl;






}


