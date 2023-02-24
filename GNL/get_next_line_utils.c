/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:53:31 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/19 19:19:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	list_len_check_nl(t_list *node, int check)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (node)
	{
		i = 0;
		while ((node->content)[i])
		{
			if ((node->content)[i] == '\n')
				return (len);
			len++;
			i++;
		}
		node = node->next;
	}
	if (!check)
		return (len);
	return (0);
}

int	create_and_append_node(char *buffer, t_list *header)
{
	t_list	*node;

	if (!buffer || !header)
		return (0);
	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = ft_strdup((const char*)buffer);
	if (!node->content)
		return (0);
	node->next = NULL;

	while (header->next)
		header = header->next;
	header->next = node;
	return (1);
}

void	free_list(t_list *node)
{
	if (!node)
		return ;
	free_list(node->next);
	if (*(node->content))
		free(node->content);
	free(node);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	char	*start_ptr;

	len = 0;
	while (*str && str[len])
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	start_ptr = ptr;
	while (*str)
		*ptr++ = *(char *)str++;
	*ptr = '\0';
	return (start_ptr);
}
