
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<pair<int,int>> job(n);

    cout << "Enter deadline and profit of each job:\n";

    for(int i=0; i<n; i++){
        cin >> job[i].first >> job[i].second;
    }

    // Sort jobs in descending order of profit
    sort(job.begin(), job.end(),
        [](pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        });

    int maxDeadline = 0;

    for(int i=0; i<n; i++){
        maxDeadline = max(maxDeadline, job[i].first);
    }

    vector<int> slot(maxDeadline+1, -1);

    int totalProfit = 0;

    for(int i=0; i<n; i++){

        // Find the latest available slot
        for(int j=job[i].first; j>=1; j--){

            if(slot[j] == -1){
                slot[j] = i;
                totalProfit += job[i].second;
                break;
            }
        }
    }

    cout << "\nSelected Jobs: ";

    for(int i=1; i<=maxDeadline; i++){
        if(slot[i] != -1){
            cout << "J" << slot[i]+1 << " ";
        }
    }

    cout << "\nMaximum Profit: " << totalProfit;

    return 0;
}

// . Explanation to write in exam
// 1. Job Sequencing is an optimization problem solved using the Greedy approach.
// 2. Each job has a deadline and an associated profit.
// 3. First, sort all jobs in descending order of their profits.
// 4. Select the job with the highest profit first.
// 5. Assign each job to the latest available time slot before or on its deadline.
// 6. If no slot is available, reject that job.
// 7. Finally, calculate the total profit of the selected jobs.
// 5. Complexity Analysis
// Let n be the number of jobs and d be the maximum deadline.
// Operation	Complexity
// Sorting jobs	O(n log n)
// Finding available slots	O(n × d)
// Overall Time	O(n log n + n × d)
// Space Complexity	O(n + d)
