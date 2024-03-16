/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:06:42 by welee             #+#    #+#             */
/*   Updated: 2024/03/16 17:40:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

/// @brief check if the dictionary file exists
/// @param dict dictionary file
/// @return 1 if the file exists, 0 otherwise
int	check_dict_file(char *dict)
{
	int	fd;
	char *buf;
	long bytes_read;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read == -1)
	{
		close(fd);
		return (0);
	}

	close(fd);
	return (1);
}
