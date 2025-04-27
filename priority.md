

# Priority-Based Scheduling Algorithm

This program implements a **Priority-Based Scheduling** algorithm, which is a CPU scheduling technique where each job is assigned a priority. The jobs are executed in ascending order of their priorities (lower priority value indicates higher priority). 

## Algorithm

The following steps outline the algorithm:

1. **Input Jobs**: 
   - Input the number of jobs (`n`), their IDs, burst times, and priorities.
2. **Sort Jobs by Priority**: 
   - Sort the jobs in ascending order of their priority values using nested loops.
3. **Enqueue Jobs**: 
   - Create a queue and enqueue the sorted jobs.
4. **Process Jobs**:
   - Dequeue and execute jobs one by one.
   - Calculate and display the waiting time for each job.
```markdown
### Code Implementation
```cpp
// Input number of jobs and their details (ID, burst time, priority)
cin >> n;
for (int i = 0; i < n; i++) {
    cin >> id[i] >> burst_time[i] >> priority[i];
}

// Sort jobs by ascending priority
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (priority[i] > priority[j]) {
            swap(burst_time[i], burst_time[j]);
            swap(id[i], id[j]);
            swap(priority[i], priority[j]);
        }
    }
}

// Enqueue sorted jobs into the queue
for (int i = 0; i < n; i++) {
    enqueue(&queue, create_job(id[i], burst_time[i], priority[i]));
}

// Process jobs and calculate waiting time
execute_job(&queue);
```

## Time Complexity

Let `n` be the number of jobs.

1. **Sorting Jobs**: Sorting is performed using a nested loop, which results in:
   - **Best Case**: `O(n^2)` (No swaps required but still iterates)
   - **Average Case**: `O(n^2)`
   - **Worst Case**: `O(n^2)` (All jobs need to be swapped)
2. **Enqueue Operations**: Each enqueue operation is `O(1)`, so for `n` jobs: `O(n)`.
3. **Dequeue & Execution**: Each dequeue operation is `O(1)`, so for `n` jobs: `O(n)`.

**Overall Time Complexity**:  
`O(n^2)` (Dominated by the sorting operation).

## Space Complexity

1. **Queue Storage**: Requires memory for `n` jobs stored in a linked list format: `O(n)`.
2. **Auxiliary Storage for Sorting**: No additional storage used as sorting is performed in-place: `O(1)`.

**Overall Space Complexity**:  
`O(n)`.

## Example Execution

Input:
```
No. of jobs: 3
Job ID: 1, Burst Time: 5, Priority: 3
Job ID: 2, Burst Time: 2, Priority: 1
Job ID: 3, Burst Time: 3, Priority: 2
```

Output:
```
Processing job 2 with burst time 2 waiting time: 0
Processing job 3 with burst time 3 waiting time: 2
Processing job 1 with burst time 5 waiting time: 5
```

## Features

- Implements custom `Queue` operations (enqueue, dequeue).
- Calculates and displays waiting time for each job.
- Handles dynamic job input and priority-based execution.

---

This program demonstrates the functionality and implementation of the **Priority-Based Scheduling** algorithm efficiently.
``` 
