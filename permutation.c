#include <unistd.h>
#include <stdio.h>

void ft_swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int ft_strlen(char *str)
{
    if (!str)
        return 0;
    int i = 0;
    while (str[i])
        i++;
    return(i);
}

void sort(char *str)
{
    if (!str)
        return ;
    int i = 0;
    int len = ft_strlen(str);
    int j;
    while (i < len && str[i])
    {
        j = 0;
        while (str[j] && j < len)
        {
            if (str[i] < str[j])
                ft_swap(&str[i], &str[j]);
            j++;
        }
        
        i++;
    }
    
    
}

void premutation(char *str, int start, int end)
{
    if (start == end)
    {
        puts(str);
        return ;
    }
    int i = start;
    while(i <= end)
    {
        ft_swap(&str[start], &str[i]);
        premutation(str, start + 1, end);
        ft_swap(&str[start], &str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str;
        str = argv[1];
        sort(str);
        premutation(str, 0,ft_strlen(str) - 1);
    }
    else
        write(1, "\n", 1);
}