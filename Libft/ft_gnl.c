/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:42:59 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/12 20:16:06 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*null_calloc(char **str, unsigned int count, unsigned int size)
// {
// 	void			*p;
// 	unsigned int	index;

// 	index = 0;
// 	p = malloc(count * size);
// 	if (p == ((void *)0))
// 		return (NULL);
// 	while ((count * size) > index)
// 		((char *)p)[index++] = 0;
// 	*str = p;
// 	if (!*str)
// 		return (NULL);
// 	return (*str);
// }

// char	*join(char *s, char c)
// {
// 	char	*out;
// 	int		len;

// 	len = ft_strlen(s) + 2;
// 	if (!null_calloc(&out, sizeof(char), len + 1))
// 	{
// 		ft_putstr_fd(MALLOC_ERROR, 2);
// 		return (NULL);
// 	}
// 	out[--len] = '\0';
// 	out[--len] = c;
// 	if (s)
// 	{
// 		while (len--)
// 			out[len] = s[len];
// 		free(s);
// 	}
// 	return (out);
// }

// char	*get_next_line(int fd)
// {
// 	char		c;
// 	static char	*text;

// 	if (fd < 0)
// 		return (0);
// 	if (text)
// 		free(text);
// 	text = NULL;
// 	while (read(fd, &c, 1) && (c != '\n' || text == NULL))
// 	{
// 		if (text == NULL && c == '\n')
// 			return ("\n");
// 		if (c == '\n')
// 			continue ;
// 		text = join(text, c);
// 	}
// 	return (text);
// }

char	*create_line(char *stack_line)
{
	char	*line;
	int		i;

	if (!stack_line || !*stack_line)
		return (NULL);
	i = 0;
	while (stack_line[i] != '\n' && stack_line[i] != '\0')
		i++;
	if (stack_line[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack_line[i] != '\n' && stack_line[i] != '\0')
	{
		line[i] = stack_line[i];
		i++;
	}
	if (stack_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

	p = ft_strchr(stack, '\n');
	if (!p)
	{
		free(stack);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	i = 0;
	while (*p != '\0')
	{
		aux[i] = *p;
		i++;
		p++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*join_and_free(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = 0;
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	if (!aux)
		return (free(stack), NULL);
	if (stack)
		free(stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*tmp;
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	tmp = (char* )malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return NULL;
	while (!(ft_strchr(stack, '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[readbytes] = '\0';
		stack = join_and_free(stack, tmp);
		if (!stack)
			return (NULL);
	}
	free(tmp);
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	int		fd;
// 	fd = open("file.txt", O_RDONLY);
// 	str = get_next_line(fd);

// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// }