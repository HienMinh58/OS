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
                return; // Kiểm tra NULL và quá giới hạn
        q->proc[q->size++] = proc;
}

struct pcb_t *dequeue(struct queue_t *q)
{
        /* TODO: return a pcb whose prioprity is the highest in the queue [q] and remember to remove it from q
         * */
        if (q == NULL || q->size == 0)
                return NULL; // Kiểm tra NULL và hàng đợi rỗng

        int highest_prioprity = 0;
        for (int i = 1; i < q->size; i++)
        {
                if (q->proc[i]->priority < q->proc[highest_prioprity]->priority)
                {
                        highest_prioprity = i; // Tìm tiến trình có độ ưu tiên cao nhất
                }
        }

        struct pcb_t *max_proc = q->proc[highest_prioprity];

        // Dịch chuyển các phần tử còn lại lên trên
        for (int i = highest_prioprity; i < q->size - 1; i++)
        {
                q->proc[i] = q->proc[i + 1];
        }

        q->proc[q->size - 1] = NULL; // Xóa phần tử cuối
        q->size--;
        return max_proc;
}
