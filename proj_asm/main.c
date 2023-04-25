#include <stdio.h>
#include "string.h"

#define N 101

void psevdo_graph()
{
    for (int i=0;i<100;i++)
    {
        putchar('*');
    }
    printf("\n");
}

int check(char a[],int n)//Проверка выполнения условия номер 6
{
    int i=0;
    while ((a[i]!=0)&&(i<n))
    {
        if ((a[i]>='0' && a[i]<='9')||(a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')) i+=1;
        else return 2;//если символ не цифра и не буква латинского алфавита - возвращаем 2
    }
    return 1;
}

void input_string(char s[],int *n)//ввод строки
{
    char c;
    int i=0;
    while (((c=getchar())!=' ')&&(c!=EOF)&&(c!='\n')&&(c!='\0'))
    {
        s[i] = c;
        i++;
    }
    (*n) = i;
}

void output_string(char s[],int n)//вывод строки
{
    int i = 0;
    while ((i<n)&&(s[i]!=0))
    {
        printf("%c",s[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int a = 0;
    char s[N];
    psevdo_graph();
    printf("Ввод и обработка текста\n\n");
    printf("Введите входную строку\n");
    input_string(s,&a);
    printf("Входная строка имеет следующий вид: \n");
    output_string(s,a);
    printf("Правило обработки: %d\n",check(s,a));
    psevdo_graph();
    if (check(s,a)==1) firstrule(s,a);//если строка требуемого формата - выполняется первое правило (правило 1.5)
    else secondrule(s,a);//иначе - второе (правило 1.4)
    printf("Итоговый результат\n\n");
    printf("Преобразованная строка: \n");
    output_string(s,a);
    psevdo_graph();
    return 0;
}