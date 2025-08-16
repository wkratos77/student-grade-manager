#include "grade_manager.h"

int ft_atoi(const char *s)
{
    int i = 0, sign = 1, num = 0;
    while (s[i] == ' ' || s[i] == '\t')
        i++;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return sign * num;
}

void show_menu(void)
{
    ft_putendl("\n=== Student Grade Manager ===");
    ft_putendl("1) Add student");
    ft_putendl("2) List students");
    ft_putendl("3) Add grade");
    ft_putendl("4) Show student average");
    ft_putendl("0) Quit");
    ft_putstr("> ");
}

int main(void)
{
    Class cls;
    char  op[128];

    init_class(&cls);

    while (1)
    {
        show_menu();
        if (ft_readline(op, sizeof op) == 0)
            break;

        if (op[0] == '0')
            break;

        else if (op[0] == '1')
        {
            ft_putstr("Student name: ");
            if (ft_readline(op, sizeof op) > 0)
            {
                if (add_student(&cls, op))
                    ft_putendl("Added.");
            }
            else
                ft_putendl("Empty name.");
        }

        else if (op[0] == '2')
        {
            list_students(&cls);
        }

        else if (op[0] == '3')
        {
            char name[128];
            char gbuf[32];
            ft_putstr("Student name: ");
            if (ft_readline(name, sizeof name) == 0) 
            { 
                ft_putendl("Empty name."); 
                continue; 
            }
            ft_putstr("Grade (0-100): ");
            if (ft_readline(gbuf, sizeof gbuf) == 0) 
            {
                ft_putendl("Empty grade."); 
                continue; 
                }
            int g = ft_atoi(gbuf);
            if (add_grade(&cls, name, g))
                ft_putendl("Grade added.");
        }
        else if (op[0] == '4')
        {
            char name[128];
            ft_putstr("Student name: ");
            if (ft_readline(name, sizeof name) == 0) 
            { 
                ft_putendl("Empty name."); 
                continue; 
            }
            show_average(&cls, name);
        }

        else
        {
            ft_putendl("Please choose one of the available options.");
        }
    }

    ft_putendl("y3awnrebi");
    return 0;
}