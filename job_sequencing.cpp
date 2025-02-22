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

Job create_job(int id, int deadline, int priority, int burst_time) 
{
    Job job;
    job.id = id;
    job.deadline = deadline;
    job.priority = priority;
    job.burst_time = burst_time;
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
        cout << " Processing job  " << job.id << "  with deadline " << job.deadline << "  waiting time : "<<T <<endl;
        T += job.burst_time;
    }
}

void merge(vector<int>& burst_time, vector<int>& id, vector<int>& priority, vector<int>& deadline, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L_burst_time(n1), R_burst_time(n2);
    vector<int> L_id(n1), R_id(n2);
    vector<int> L_priority(n1), R_priority(n2);
    vector<int> L_deadline(n1), R_deadline(n2);

    for (int i = 0; i < n1; i++) 
    {
        L_burst_time[i] = burst_time[left + i];
        L_id[i] = id[left + i];
        L_priority[i] = priority[left + i];
        L_deadline[i] = deadline[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R_burst_time[j] = burst_time[mid + 1 + j];
        R_id[j] = id[mid + 1 + j];
        R_priority[j] = priority[mid + 1 + j];
        R_deadline[j] = deadline[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L_priority[i] <= R_priority[j]) 
        {
            burst_time[k] = L_burst_time[i];
            id[k] = L_id[i];
            priority[k] = L_priority[i];
            deadline[k] = L_deadline[i];
            i++;
        } 
        else 
        {
            burst_time[k] = R_burst_time[j];
            id[k] = R_id[j];
            priority[k] = R_priority[j];
            deadline[k] = R_deadline[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        burst_time[k] = L_burst_time[i];
        id[k] = L_id[i];
        priority[k] = L_priority[i];
        deadline[k] = L_deadline[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        burst_time[k] = R_burst_time[j];
        id[k] = R_id[j];
        priority[k] = R_priority[j];
        deadline[k] = R_deadline[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& burst_time, vector<int>& id, vector<int>& priority, vector<int>& deadline, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        merge_sort(burst_time, id, priority, deadline, left, mid);
        merge_sort(burst_time, id, priority, deadline, mid + 1, right);
        merge(burst_time, id, priority, deadline, left, mid, right);
    }
}

int main() 
{
    printf("priority scheduling\n");
    Queue queue;
    init_queue(&queue);
    cout << "enter no of available jobs: ";
    int n;
    cin >> n;
    vector<int> id(n);
    vector<int> burst_time(n);
    vector<int> priority(n);
    vector<int> deadline(n);
    cout << "enter job profile in format <int id>-<int burst_time>-<int priority>-<int deadline>\n";
    for (int i = 0; i < n; i++) 
    {
        cout << i + 1 << "th process: ";
        scanf("%d-%d-%d-%d", &id[i], &burst_time[i], &priority[i], &deadline[i]);
    }

    merge_sort(burst_time, id, priority, deadline, 0, n - 1);

    int T = 0;
    for (int i = 0; i < n; i++) 
    {
        Job job = create_job(id[i], deadline[i], priority[i], burst_time[i]);
        if (job.deadline < T) 
        {
            cout << "job " << id[i] << " missed the deadline\n";
        } 
        else 
        {
            enqueue(&queue, job);
        }
        T = T + burst_time[i];
    }
    printf("-----job schedule-----\n");
    execute_job(&queue);
    return 0;
}
