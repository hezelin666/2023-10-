#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

struct student
{
    long num;
    int score;
    struct student* next;
};

struct student* create(int n)
{
    struct student* head = NULL, * p1 = NULL, * p2 = NULL;
    int i;
    for (i = 1; i <= n; i++)
    {
        p1 = (struct student*)malloc(LEN);
        scanf("%ld", &p1->num);
        scanf("%d", &p1->score);
        p1->next = NULL;
        if (i == 1) head = p1;
        else p2->next = p1;
        p2 = p1;
    }
    return(head);
}

void print(struct student* head)
{
    struct student* p;
    p = head;
    while (p != NULL)
    {
        printf("%8ld%8d", p->num, p->score);
        p = p->next;
        printf("\n");
    }
}

struct student* insert(struct student* head, struct student* stud)
{
    struct student *p1, *p2, *p3;
    p1 = head;
    p2 = stud;
    if (p1 == NULL)head = p2;
    else
    {
        while ((p2->num > p1->num) && (p1->next != NULL))
        {
            p3 = p1;
            p1 = p1->next;
        }
        if (p2->num < p1->num)
        {
            if (head == p1)head = p2;
            else
            {
                p3->next = p2;
                p2->next = p1;
            }
        }
        else {
            p1->next = p2;
        }
    }
        return (head);
    }


}

main()
{
    struct student* head, * stu;
    int n;
    scanf("%d", &n);
    head = create(n);
    print(head);
    stu = (struct student*)malloc(LEN);
    scanf("%ld", &stu->num);
    scanf("%d", &stu->score);
    stu->next = NULL;
    head = insert(head, stu);
    print(head);
}