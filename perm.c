#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    if (!str)
        return 0;
    int i = 0;
    while (str[i])
        i++;
    return(i);
}

void ft_swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(char *str)
{
    if (!str)
        return ;
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

void sort(char *str)
{
    int i = 0;
    int len;
    int j = 0;
    len = ft_strlen(str);
    while (i < len && str[i])
    {
        j = 0;
        while (j < len)
        {
            if (str[i] < str[j])
                ft_swap(&str[i], &str[j]);
                j++;
        }
        i++;
    }
    
}

void generate(char *str, int start, int end)
{
    int i = start;
    if (start ==  end)
    {
        print(str);
        return;
    }
    while (i <= end)
    {
        ft_swap(&str[start], &str[i]);
        generate(str, start + 1, end);
        ft_swap(&str[start], &str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    int i = 0;
    char *str = argv[1];
    sort(str);
    generate(str, 0, ft_strlen(str) - 1);
}

