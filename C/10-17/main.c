#include <stdio.h>
#include "stud.h"
#include <string.h>
#define N 15
#define places 5

//Структура данных описывает студента второго курса в конце 4 семестра,
//поступающего на кафедры третьего потока
//Функции помогают по среднему баллу отсортировать список студентов, претендующих
//на ту или иную кафедру и определить тех, кто не проходит (flag==0)

//Студента описывают его оценки, выбранная кафедра и flag

int main()
{
    struct student al[N],sp[N],iit[N],ascc[N],ski[N];
    int pointeral = 0,pointersp=0,pointeriit=0,pointerascc=0,pointerski=0;
    int n;
    printf("Введите число студентов ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        struct student st;
        char s[11][20]={"МА1", "МА2", "АиГ1", "АиГ2", "ООП","ОП","АиАЯ","АиЯА","ДМ","И","Р"};
        input_data(&st);
        for (int j=0;j<11;j++)
        {
            short mark;
            printf("Оценка за курс %s: ",s[j]);
            scanf("%d",&mark);
            input_marks(&st,s[j],mark);
        }
        if (st.cafedra==1)
        {
            append_cath(al,pointeral,st);
            pointeral++; 
        }
        if (st.cafedra==2)
        {
            append_cath(sp,pointersp,st); 
            pointersp++;
        }
        if (st.cafedra==3)
        {
            append_cath(iit,pointeriit,st); 
            pointeriit++;
        }
        if (st.cafedra==4)
        {
            append_cath(ascc,pointerascc,st); 
            pointerascc++;
        }
        if (st.cafedra==5)
        {
            append_cath(ski,pointerski,st);
            pointerski++; 
        }
    }

    printf("Кафедра АЯ\n");
    sort(al,pointeral,N);
    output_cath(al,pointeral);
    
    printf("Кафедра СП\n");

    sort(sp,pointersp,N);
    output_cath(sp,pointersp);
    
    printf("Кафедра ИИТ\n");

    sort(iit,pointeriit,N);
    output_cath(iit,pointeriit);

    printf("Кафедра АСВК\n");
    sort(ascc,pointerascc,N);
    output_cath(ascc,pointerascc);

    printf("Кафедра СКИ\n");

    sort(ski,pointerski,N);
    output_cath(ski,pointerski);
}