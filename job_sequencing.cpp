#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Job 
{
    int id;
    int priority;
    int deadline;
    int burst_time;
};

Job create_job(int id, int deadline, int priority, int burst_time) 
{
    return {id, priority, deadline, burst_time};
}

int main() 
{
    cout << "priority scheduling\n";
    int n;
    cout << "enter number of available jobs: ";
    cin >> n;
    
    vector<Job> jobs(n);
    cout << "enter job profile in format <int id>-<int burst_time>-<int priority>-<int deadline>\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << i + 1 << "th process: ";
        cin >> jobs[i].id >> jobs[i].burst_time >> jobs[i].priority >> jobs[i].deadline;
    }
    
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) 
    {
        return a.priority < b.priority;
    });
    
    queue<Job> job_queue;
    int T = 0;
    for (const auto& job : jobs) 
    {
        if (job.deadline < T) 
        {
            cout << "job " << job.id << " missed the deadline\n";
        } 
        else 
        {
            job_queue.push(job);
        }
        T += job.burst_time;
    }

    cout << "-----job schedule-----\n";
    T = 0;
    while (!job_queue.empty()) 
    {
        Job job = job_queue.front();
        job_queue.pop();
        cout << " Processing job " << job.id << " with deadline " << job.deadline << " waiting time: " << T << endl;
        T += job.burst_time;
    }
    return 0;
}

