#include "grade_manager.h"

int  ft_strcmp(const char *a, const char *b)
{
    int i = 0;
    while (a[i] && a[i] == b[i])
        i++;
    return ((unsigned char)a[i] - (unsigned char)b[i]);
}

void ft_strcpy(char *dst, const char *src)
{
    int i = 0;
    while (src[i]) 
    {
        dst[i] = src[i]; i++; 
    }
    dst[i] = '\0';
}

void init_class(Class *c)
{
    c->count = 0;
}

int find_student_index(const Class *c, const char *name)
{
    int i = 0;
    while (i < c->count) {
        if (ft_strcmp(c->arr[i].name, name) == 0)
            return i;
        i++;
    }
    return -1;
}

int add_student(Class *c, const char *name)
{
    if (c->count >= MAX_STUDENTS) {
        ft_putendl("Class full.");
        return 0;
    }
    if (name[0] == '\0') {
        ft_putendl("Empty name.");
        return 0;
    }
    if (find_student_index(c, name) != -1) {
        ft_putendl("Student already exists.");
        return 0;
    }
    Student *s = &c->arr[c->count++];
    ft_strcpy(s->name, name);
    s->gcount = 0;
    return 1;
}

void list_students(const Class *c)
{
    if (c->count == 0) {
        ft_putendl("No students yet.");
        return;
    }
    int i = 0;
    while (i < c->count) {
        ft_putstr(" - ");
        ft_putendl(c->arr[i].name);
        i++;
    }
}
int add_grade(Class *c, const char *name, int grade)
{
    int idx;

    if (grade < 0 || grade > 100) {
        ft_putendl("Grade must be between 0 and 100.");
        return 0;
    }
    idx = find_student_index(c, name);
    if (idx == -1) {
        ft_putendl("Student not found.");
        return 0;
    }
    if (c->arr[idx].gcount >= MAX_GRADES) {
        ft_putendl("This student has the maximum number of grades.");
        return 0;
    }
    c->arr[idx].grades[c->arr[idx].gcount++] = grade;
    return 1;
}

void show_average(const Class *c, const char *name)
{
    int idx = find_student_index(c, name);
    if (idx == -1) 
    {
        ft_putendl("Student not found.");
        return;
    }
    if (c->arr[idx].gcount == 0) 
    {
        ft_putendl("No grades for this student.");
        return;
    }
    int sum = 0;
    int i = 0;
    while (i < c->arr[idx].gcount) 
    {
        sum += c->arr[idx].grades[i];
        i++;
    }
    int avg = sum / c->arr[idx].gcount;

    ft_putstr("Average of ");
    ft_putstr(c->arr[idx].name);
    ft_putstr(": ");
    ft_putnbr(avg);
    ft_putendl("");
}

