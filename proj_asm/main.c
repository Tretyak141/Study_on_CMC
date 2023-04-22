#include <stdio.h>
#include "string.h"

#define N 201

int check(int a[],int n)//Проверка выполнения условия номер 6
{
    int i=0;
    while ((a[i]!=0)&&(i<n))
    {
        if ((a[i]>='0' && a[i]<='9')||(a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')) i+=1;
        else return 2;//если символ не цифра и не буква латинского алфавита - возвращаем 2
    }
    return 1;
}

void input_string(int s[],int *n)//ввод строки
{
    int c;
    int i=0;
    while (((c=getchar())!=' ')&&(c!=EOF)&&(c!='\n')&&(c!='\0'))
    {
        s[i] = c;
        i++;
    }
    (*n) = i;
}

void output_string(int s[],int n)//вывод строки
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
    int s[N];
    printf("Введите входную строку\n");
    input_string(s,&a);
    printf("Входная строка имеет следующий вид: ");
    output_string(s,a);
    printf("Правило обработки: %d\n",check(s,a));
    if (check(s,a)==1) firstrule(s,a);//если строка требуемого формата - выполняется первое правило (правило 1.5)
    else secondrule(s,a);//иначе - второе (правило 1.4)
    printf("\n\nПреобразованная строка: ");
    output_string(s,a);
    return 0;
}