/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxiang <qxiang@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:35:09 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/06 21:43:51 by qxiang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	s_len(char *src)
{
	int	j;

	j = 0;
	while (src[j])
		++j;
	return (j);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l_dest;

	i = 0;
	l_dest = s_len(dest);
	while (src[i])
	{
		dest[l_dest + i] = src[i];
		++i;
	}
	dest[l_dest + i] = '\0';
	return (dest);
}
