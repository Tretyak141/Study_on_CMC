#ifndef _stud_h_
#define _stud_h_


struct student
{
    struct
    {
        int mathan[2];
        int linal[2];
        int history;
        int oop;
        int op;
        int rus;
        int arch;
        int diffs;
        int algo;
        int dm;
    } marks;
    int pers_data;
    char cafedra;
    char flag;
};


char priority(char s[]);
void input_data(struct student*);
void input_marks(struct student*,char s[20],int);
double middle(struct student);
char student_cmp(struct student,struct student);
void append_cath(struct student list[],int pointer,struct student st);
void output_cath(struct student cath[],int pointer);
void sort(struct student cath[],int,int);

#endif