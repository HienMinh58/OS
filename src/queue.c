#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
        if (q == NULL)
                return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: put a new process to queue [q] */
        if (q == NULL || q->size >= MAX_QUEUE_SIZE)
                return;
        q->proc[q->size++] = proc;
}

struct pcb_t *dequeue(struct queue_t *q)
{
        /* TODO: return a pcb whose prioprity is the highest in the queue [q] and remember to remove it from q
         * */
        if (q == NULL || q->size == 0) return NULL;
        int highest_prioprity = 0;
        for (int i = 1; i < q->size; i++)
        {
                if (q->proc[i]->priority < q->proc[highest_prioprity]->priority)
                {
                        highest_prioprity = i;
                }
        }

        struct pcb_t *max_proc = q->proc[highest_prioprity];
        for (int i = highest_prioprity; i < q->size - 1; i++)
        {
                q->proc[i] = q->proc[i + 1];
        }

        q->proc[q->size - 1] = NULL;
        q->size--;
        return max_proc;
}
