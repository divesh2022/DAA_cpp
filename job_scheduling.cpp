// shortest job come first
#include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int priority;
    int deadline;
    int burst_time;
};

struct node {
    Job job;
    node* next;
};

struct Queue {
    node* front;
    node* rear;
};

Job create_job(int id, int deadline, int priority, int burst_time) {
    Job job;
    job.id = id;
    job.deadline = deadline;
    job.priority = priority;
    job.burst_time = burst_time;
    return job;
}

node* create_node(Job job) {
    node* Node = new node;
    Node->job = job;
    Node->next = NULL;
    return Node;
}

void init_queue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int is_queue_empty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, Job job) {
    node* Node = create_node(job);
    if (queue->rear == NULL) {
        queue->front = queue->rear = Node;
    } else {
        queue->rear->next = Node;
        queue->rear = Node;
    }
}

Job dequeue(Queue* queue) {
    if (is_queue_empty(queue)) {
        cout << "queue is empty\n";
        exit(1);
    }
    node* temp = queue->front;
    Job job = temp->job;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    delete temp; // Added to prevent memory leak
    return job;
}

void execute_job(Queue* queue) {
    int T = 0;
    while (!is_queue_empty(queue)) {
        Job job = dequeue(queue);
        cout << " Processing job  " << job.id << "  with deadline " << job.deadline << "  waiting time : "<<T <<endl;
        T += job.burst_time;
    }
}


int main() {
    printf("priority scheduling\n");
    Queue queue;
    init_queue(&queue);
    cout << "enter no of available jobs : ";
    int n;
    cin>> n;
    vector<int> id(n);
    vector<int> burst_time(n);
    vector<int> priority(n);
    vector<int> deadline(n);
    cout << "enter job profile in format <int id>-<int brust_time>-<int priority>-<int deadline>\n";
    for (int i = 0; i < n; i++) {
        cout<<i+1<<"th process : ";
        scanf("%d-%d-%d-%d", &id[i], &burst_time[i], &priority[i], &deadline[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                swap(burst_time[i], burst_time[j]);
                swap(id[i], id[j]);
                swap(priority[i],priority[j]);
                swap(deadline[i],deadline[j]);
            }
        }
    }
    int T = 0;
    for (int i = 0; i < n; i++) {
        Job job = create_job(id[i], deadline[i], priority[i], burst_time[i]);
        if(job.deadline < T){
            cout << "job " << id[i] << " missed the deadline\n";
        }
        else{
            enqueue(&queue, job);
        }
        T = T + burst_time[i];
    }
    printf("-----job schedule-----\n");
    execute_job(&queue);
    return 0;
}
// Output
/*
priority scheduling
enter no of available jobs : 5
enter job profile in format <int id>-<int brust_time>-<int priority>-<int deadline>
1th process : 1-3-2-10
2th process : 2-1-3-8
3th process : 3-2-1-12
4th process : 4-4-2-6
5th process : 5-1-1-14
job 2 missed the deadline
-----job schedule-----
 Processing job  3  with deadline 12  waiting time : 0
 Processing job  5  with deadline 14  waiting time : 2
 Processing job  4  with deadline 6  waiting time : 3
 Processing job  1  with deadline 10  waiting time : 7
*/
