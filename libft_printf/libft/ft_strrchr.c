/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:53:17 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/07 16:54:01 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int target)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (target == 0)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == (char)target)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
