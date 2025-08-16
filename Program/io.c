#include "grade_manager.h"

int ft_strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void ft_putstr(const char *s)
{
    if (s[0] == '\0') 
        return;
    write(1, &s[0], 1);
    ft_putstr(s + 1);
}

void ft_putendl(const char *s)
{
    ft_putstr(s);
    write(1, "\n", 1);
}

void ft_putnbr(int n)
{
    long nb = n;

    if (nb == 0) 
    {
        write(1, "0", 1); 
        return; 
    }
    if (nb < 0) 
    {
        write(1, "-", 1); 
        nb = -nb; 
    }
    if (nb > 9) 
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else 
    {
        write(1, &"0123456789" [nb], 1);
    }
}

int ft_readline(char *dst, int cap)
{
    int  pos = 0;
    char c;
    int r;

    if (cap <= 0) 
        return 0;
    while ((r = read(0, &c, 1)) == 1)
    {
        if (c == '\n')
            break;
        if (pos < cap - 1)
            dst[pos++] = c;
    }
    dst[pos] = '\0';
    return pos;
}
