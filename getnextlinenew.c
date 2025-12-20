#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 100

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return 0;
	while (str[i])
		i++;
	return(i);
}

char *ft_strdup(char *str)
{
	int i = 0;
	if (!str)
		return NULL;
	char *res = (char *)malloc(ft_strlen(str) + 1);
	if (!res)
		return NULL;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_strchr(char *str, char c)
{
	int i = 0;
	if (!str)
		return(NULL);
	while (str[i])
	{
		if (str[i] == c)
			return(str + i);
		i++;
	}
	if (c == '\0')
		return(str + i);
	return NULL;
}

char *ft_strjoin(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	char *res = NULL;

	if (!str1 && !str2)
		return NULL;
	else if (!str1 && str2)
		return(ft_strdup(str2));
	else if (str1 && !str2)
		return(ft_strdup(str1));
	res = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
		return(NULL);
	while (str1[i])
	{
		res[i] = str1[i];
		++i;
	}
	while (str2[j])
	{
		res[i + j] = str2[j];
		++j;
	}
	res[i + j] = '\0';
	return(res);
}

char *readline(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	char *res = NULL;
	char *temp = NULL;
	int r = 0;

	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		temp = ft_strjoin(res, buffer);
		free(res);
		res = temp;
		if (ft_strchr(res, '\n'))
			return(res);
	}
	return(res);
}

char *trim_result(char *line)
{
	int i = 0;
	int len;
	if (!line)
		return NULL;
	char *newline = NULL;
	char *result;

	newline = ft_strchr(line, '\n');
	if (!newline)
		return (ft_strdup(line));
	len = (newline - line) + 1;
	result = (char *)malloc(len + 1);
	if (!result)
		return NULL;
	while (line[i] && i < len)
	{
		result[i] = line[i];
		i++;
	}
	result[i] = '\0';
	return(result);
}

char *trim_temp(char *line)
{
	int i = 0;
	int j;
	char *res;
	char *newline;
	if (!line)
		return NULL;
	newline = ft_strchr(line, '\n');
	if (!newline)
		return(NULL);
	j = ft_strlen(line) - ft_strlen(newline + 1);
	if (j == 0)
		return NULL;
	res = (char *)malloc(ft_strlen(newline + 1) + 1);
	if (!res)
		return(NULL);
	while (line[j])
	{
		res[i] = line[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return(res);
}

char *get_next_line(int fd)
{
	char *line = NULL;
	char *result = NULL;
	char *temp = NULL;
	static char *buffer = NULL;

	if (fd < 0)
		return(NULL);
	temp = readline(fd);
	line = ft_strjoin(buffer, temp);
	free(temp);
	result = trim_result(line);
	free(buffer);
	buffer = trim_temp(line);
	free(line);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			char *line;
			while ((line = get_next_line(fd)))
			{
				printf("line: %s", line);
				free(line);
			}
		}
	}
	return 0;
}
