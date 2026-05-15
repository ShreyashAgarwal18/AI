#include<bits/stdc++.h>
using namespace std;

struct Job{

    public:
        int jobId;
        int deadline;
        int profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}

int findMaxDeadline(Job jobs[], int n){
    int maxDeadline = 0;

    for(int i = 0; i<n; i++){
        if(jobs[i].deadline > maxDeadline){
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

void jobScheduling(Job jobs[], int n){

    sort(jobs, jobs+n, compare);

    int maxDeadline = findMaxDeadline(jobs, n);

    int result[maxDeadline];
    int slots[maxDeadline];

    int totalProfit = 0;

    for(int i = 0; i<maxDeadline; i++){
        slots[i] = false;
    }

    for(int i = 0; i<n; i++){
        for(int j = jobs[i].deadline - 1; j>=0; j--){
            if(slots[j] == false){
                slots[j] = true;
                result[j] = jobs[i].jobId;
                totalProfit += jobs[i].profit;
                break;
            }
        }

    }


    cout<<"Scheduled Jobs: "<<endl;

    for(int i = 0; i<maxDeadline; i++){
        if(slots[i]){
            cout<<result[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"Total Profit is: "<<totalProfit<<endl;
}

int main(){
     int n;
    cout<<"Enter number of jobs: ";
    cin>>n;

    Job jobs[n];

    for(int i = 0; i<n; i++){
        cout<<"Enter jobId: ";
        cin>>jobs[i].jobId;

        cout<<"Enter Deadline: ";
        cin>>jobs[i].deadline;

        cout<<"Enter Profit: ";
        cin>>jobs[i].profit;
    }

    jobScheduling(jobs,n);

    return 0;
}


/*
Enter number of jobs: 5

Enter Job ID: 1
Enter Deadline: 2
Enter Profit: 100

Enter Job ID: 2
Enter Deadline: 1
Enter Profit: 19

Enter Job ID: 3
Enter Deadline: 2
Enter Profit: 27

Enter Job ID: 4
Enter Deadline: 1
Enter Profit: 25

Enter Job ID: 5
Enter Deadline: 3
Enter Profit: 15
*/