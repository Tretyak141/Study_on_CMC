#include "stud.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void input_data(struct student* a)//получение данных о студенте из терминала
{
    printf("Введите номер личного дела ");
    scanf("%d",&((*a).pers_data));
    printf("Введите код кафедры ");
    int i=0;
    scanf("%d",&((*a).cafedra));
}

char priority(char s[])
{
        if (!strcmp("МА1",s))
            return 1;
        if (!strcmp(s,"МА2"))
            return 2;
        if (!strcmp(s,"АиГ1"))
            return 3;
        if (!strcmp(s,"АиГ2"))
            return 4;
        if (!strcmp(s,"ООП"))
            return 5;
        if(!strcmp(s,"ОП"))
            return 6;
        if (!strcmp(s,"АиАЯ"))
            return 7;
        if (!strcmp("АиЯА",s))
            return 8;
        if (!strcmp(s,"ДМ"))
            return 9;
        if (!strcmp(s,"И"))
            return 10;
        if (!strcmp(s,"Р"))
            return 11;
}

void input_marks(struct student* a, char s[20],int mark)
{
    char code = priority(s);
    switch (code)
    {
        case 1:
        {
            (*a).marks.mathan[0] = mark;
            return;
        }
        case 2:
        {
            (*a).marks.mathan[1] = mark;
            return;
        }
        case 3:
        {
            (*a).marks.linal[0] = mark;
            return;
        }
        case 4:
        {
            (*a).marks.linal[1] = mark;
            return;
        }
        case 5:
        {
            (*a).marks.oop = mark;
            return;
        }
        case 6:
        {
            (*a).marks.op = mark;
            return;
        }
        case 7:
        {
            (*a).marks.algo = mark;
            return;
        }
        case 8:
        {
            (*a).marks.arch = mark;
            return;
        }
        case 9:
        {
            (*a).marks.dm = mark;
            return;
        }
        case 10:
        {
            (*a).marks.history = mark;
            return;
        }
        case 11:
        {
            (*a).marks.rus = mark;
            return;
        }
    }
}

double middle(struct student a)
{
    double s;
    s = a.marks.mathan[0] + a.marks.mathan[1] + a.marks.linal[0] + a.marks.linal[1] + a.marks.oop + a.marks.op + a.marks.algo + a.marks.arch + a.marks.dm + a.marks.history + a.marks.rus;
    return s/11.0;  
}



char student_cmp(struct student a,struct student b)
{
    double middle_a = middle(a);
    double middle_b = middle(b);
    if (middle_a>middle_b)
    {
        return 1;
    }
    if (middle_a<middle_b)
    {
        return 0;
    }
    if (a.marks.mathan[0]>b.marks.mathan[0])
        return 1;
    if (a.marks.mathan[0]<b.marks.mathan[0])
        return 0;
    if (a.marks.mathan[1]>b.marks.mathan[1])
        return 1;
    if (a.marks.mathan[1]<b.marks.mathan[1])
        return 0;
    if (a.marks.linal[0]>b.marks.linal[0])
        return 1;
    if (a.marks.linal[0]<b.marks.linal[0])
        return 0;
    if (a.marks.linal[1]>b.marks.linal[1])
        return 1;
    if (a.marks.linal[1]<b.marks.linal[1])
        return 0;
    if (a.marks.oop>b.marks.oop)
        return 1;
    if (a.marks.oop<b.marks.oop)
        return 0;
    if (a.marks.op>b.marks.op)
        return 1;
    if (a.marks.op<b.marks.op)
        return 0;
    if (a.marks.algo>b.marks.algo)
        return 1;
    if (a.marks.algo<b.marks.algo)
        return 0;
    if (a.marks.arch>b.marks.arch)
        return 1;
    if (a.marks.arch<b.marks.arch)
        return 0;
    if (a.marks.dm>b.marks.dm)
        return 1;
    if (a.marks.dm<b.marks.dm)
        return 0;
    if (a.marks.history>b.marks.history)
        return 1;
    if (a.marks.history<b.marks.history)
        return 0;
    if (a.marks.rus>b.marks.rus)
        return 1;
    if (a.marks.rus<b.marks.rus)
        return 0;
    return 0;
}

void sort(struct student cath[],int pointer,int places)
{
    for (int i=0;i<pointer-1;i++)
    {
        struct student max = cath[i];
        int ind = i;
        for (int j=i+1;j<pointer;j++)
        {
            if (student_cmp(cath[j],max))
            {
                max = cath[j];
                ind = j;
            }
        }
        struct student per = cath[i];
        cath[i] = cath[ind];
        cath[ind] = per;
    }
    for (int i=0;i<places;i++)
        cath[i].flag = 1;
}

void append_cath(struct student cath[],int pointer,struct student st)
{
    cath[pointer] = st;
}

void output_cath(struct student cath[],int pointer)
{
    for (int i=0;i<pointer;i++)
    {
        printf("\nСтудент c рейтингом %d\n",i);
        printf("Номер личного дела: %d\n",cath[i].pers_data);
        printf("Средний балл: %f\n", middle(cath[i]));
        printf("Вердикт по поступлению: %d\n\n",cath[i].flag);
    }
}