#include <stdio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

// ENQUEUE operation
void enqueue(int x)
{
    // Queue full condition
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is FULL!\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;

    printf("%d inserted into queue.\n", x);
}

// DEQUEUE operation
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    // Only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// FRONT operation
void showFront()
{
    if (front == -1)
    {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

// DISPLAY operation
void display()
{
    if (front == -1)
    {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            showFront();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}