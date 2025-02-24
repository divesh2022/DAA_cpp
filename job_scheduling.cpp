#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job 
{
    int id;
    int priority;
    int deadline;
    int burst_time;
    int profit;
};

struct node 
{
    Job job;
    node* next;
};

struct Queue 
{
    node* front;
    node* rear;
};

Job create_job(int id, int deadline, int priority, int burst_time, int profit) 
{
    Job job;
    job.id = id;
    job.deadline = deadline;
    job.priority = priority;
    job.burst_time = burst_time;
    job.profit = profit;
    return job;
}

node* create_node(Job job) 
{
    node* Node = new node;
    Node->job = job;
    Node->next = NULL;
    return Node;
}

void init_queue(Queue* queue) 
{
    queue->front = NULL;
    queue->rear = NULL;
}

int is_queue_empty(Queue* queue) 
{
    return queue->front == NULL;
}

void enqueue(Queue* queue, Job job) 
{
    node* Node = create_node(job);
    if (queue->rear == NULL) 
    {
        queue->front = queue->rear = Node;
    } 
    else 
    {
        queue->rear->next = Node;
        queue->rear = Node;
    }
}

Job dequeue(Queue* queue) 
{
    if (is_queue_empty(queue)) 
    {
        cout << "queue is empty\n";
        exit(1);
    }
    node* temp = queue->front;
    Job job = temp->job;
    queue->front = queue->front->next;
    if (queue->front == NULL) 
    {
        queue->rear = NULL;
    }
    delete temp; // Added to prevent memory leak
    return job;
}

void execute_job(Queue* queue) 
{
    int T = 0;
    while (!is_queue_empty(queue)) 
    {
        Job job = dequeue(queue);
        cout << " Processing job  " << job.id << "  with deadline " << job.deadline << "  waiting time : " << T << endl;
        T += job.burst_time;
    }
}

int main() {
    printf("priority scheduling\n");
    Queue queue;
    init_queue(&queue);
    cout << "enter number of available jobs: ";
    int n;
    cin >> n;
    int id, deadline, priority, burst_time, profit;
    vector <Job> jobs;
    cout << "enter job profile in format <int id>-<int burst_time>-<int priority>-<int deadline>-<int profit>\n";
    for (int i = 0; i < n; i++) 
    {
        cout << i + 1 << "th process : ";
        scanf("%d-%d-%d-%d-%d", &id, &burst_time, &priority, &deadline, &profit);
        Job new_job = create_job(id, deadline, priority, burst_time, profit);
        jobs.push_back(new_job);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) 
        {
            if(jobs[i].priority > jobs[j].priority)
            {
                swap(jobs[i],jobs[j]);
            }
        }
    }
    int T = 0;
    int P = 0;
    for (int i = 0; i < n; i++) {
        if(jobs[i].deadline < T){
            cout << "job " << jobs[i].id << " missed the deadline\n";
        }
        else
        {
            enqueue(&queue, jobs[i]);
            T = T + jobs[i].burst_time;
            P = P + jobs[i].profit;
        }
    }
    printf("-----job schedule-----\n");
    execute_job(&queue);
    printf("total time taken = %d\n", T);
    printf("total profit = %d\n", P);
    return 0;
}
