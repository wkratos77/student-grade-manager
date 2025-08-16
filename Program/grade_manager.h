#ifndef GRADE_MANAGER_H
# define GRADE_MANAGER_H

# include <unistd.h>  
# include <stdlib.h>  

int   ft_strlen(const char *s);
void  ft_putstr(const char *s);
void  ft_putendl(const char *s);
void  ft_putnbr(int n);
int   ft_readline(char *dst, int cap);

# define MAX_STUDENTS 100
# define MAX_NAME     50
# define MAX_GRADES   20

typedef struct {
    char  name[MAX_NAME];
    int grades[MAX_GRADES];
    int   gcount;
} Student;

typedef struct {
    Student arr[MAX_STUDENTS];
    int     count;
} Class;

void init_class(Class *c);
int  add_student(Class *c, const char *name);
int  find_student_index(const Class *c, const char *name);
void list_students(const Class *c);

int  add_grade(Class *c, const char *name, int grade);
void show_average(const Class *c, const char *name);
#endif
