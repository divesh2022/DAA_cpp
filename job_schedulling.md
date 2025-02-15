What is Job Scheduling?
Job scheduling is a method by which jobs (tasks or processes) are assigned to resources (such as a CPU) that complete them. Efficient scheduling is critical to ensure optimal performance and resource utilization in computer systems. It is widely used in operating systems, data centers, and cloud computing environments to manage and allocate resources effectively.

How is Job Scheduling Done?
Job scheduling can be performed using different algorithms, each with its own set of rules and objectives. Some common job scheduling algorithms include:

First-Come, First-Served (FCFS): Jobs are executed in the order they arrive.

Shortest Job Next (SJN) or Shortest Job First (SJF): The job with the shortest execution time is selected next.

Priority Scheduling: Jobs are assigned priorities, and the job with the highest priority is executed first.

Round Robin (RR): Each job is assigned a fixed time slot (quantum) in a cyclic order.

Multilevel Queue Scheduling: Jobs are placed in different queues based on their priority or type, and each queue has its own scheduling algorithm.

Algorithm for First-Come, First-Served (FCFS):
Create a queue to hold the jobs.

Enqueue jobs as they arrive.

Dequeue and execute jobs in the order they arrived.

Pseudocode for FCFS in C:
# c

#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id; // Job ID
    int burst_time; // Burst time
} Job;

typedef struct Node {
    Job job;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new job
Job create_job(int id, int burst_time) {
    Job job;
    job.id = id;
    job.burst_time = burst_time;
    return job;
}

// Function to create a new node
Node* create_node(Job job) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->job = job;
    node->next = NULL;
    return node;
}

// Function to initialize a queue
void init_queue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int is_empty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue a job
void enqueue(Queue* queue, Job job) {
    Node* node = create_node(job);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to dequeue a job
Job dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* temp = queue->front;
    Job job = temp->job;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return job;
}

// Function to execute jobs using FCFS scheduling
void execute_jobs(Queue* queue) {
    while (!is_empty(queue)) {
        Job job = dequeue(queue);
        printf("Executing job %d with burst time %d\n", job.id, job.burst_time);
    }
}

int main() {
    Queue queue;
    init_queue(&queue);
    enqueue(&queue, create_job(1, 5));
    enqueue(&queue, create_job(2, 3));
    enqueue(&queue, create_job(3, 2));
    printf("Executing jobs using FCFS scheduling:\n");
    execute_jobs(&queue);
    return 0;
}
