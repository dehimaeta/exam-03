#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

int ft_strncmp(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    if (!str1 || !str2)
        return INT_MIN;
    while (str1[i] && str2[j])
    {
        if (str1[i] != str2[j])
            return(str1[i]-str2[j]);
        i++;
        j++;
    }
    return 0;
}

void ft_filter(char *target)
{
    char buffer[10001];
    int r;
    r = read(0, buffer, 10000);
    buffer[10000] = '\0';
    if (r >= 0)
    {
        int i = 0;
        while (buffer[i])
        {
            if (buffer[i] == target[0])
            {
                if (ft_strncmp(buffer + i, target) == 0)
                {
                    int j = 0;
                    while (j < strlen(target))
                    {
                        buffer[i + j] = '*';
                        ++j;
                    }
                }
            }
            ++i;
        }
        printf("%s\n", buffer);
    }
    else
        perror("Error: ");
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_filter(argv[1]);
        return 0;
    }
    else
        return 1;
}