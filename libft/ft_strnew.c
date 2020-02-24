/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 22:26:51 by bhugo             #+#    #+#             */
/*   Updated: 2019/11/18 14:17:28 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (p == NULL)
		return (NULL);
	ft_memset(p, '\0', size + 1);
	return (p);
}
