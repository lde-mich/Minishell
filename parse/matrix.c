/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	compact_fnd_qts(char *s, int *i, char c, char *s2)
{
	int	j;

	j = 1;
	while (s[*i] && s[*i] != c)
	{
		s2[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	s2[j] = s[*i];
	s2[j + 1] = 0;
	if (!s[*i])
		*i = *i - 1;
}

char	*fnd_qts(char *s, int *i)
{	
	int		k;
	int		j;
	char	*s2;
	char	c;

	j = 1;
	k = *i;
	c = s[k];
	k++;
	while (s[k] && s[k] != c)
	{
		j++;
		k++;
	}
	s2 = malloc(j + 2);
	*i = *i + 1;
	s2[0] = c;
	compact_fnd_qts(s, i, c, s2);
	return (s2);
}

char	**create_matrix(char	*s)
{
	int		i;
	char	**mat;
	char	*wrd;

	i = -1;
	mat = malloc(sizeof(char *) * 1);
	mat[0] = 0;
	while (s[++i])
	{
		if (s[i] == ' ')
			continue ;
		else if (s[i] == '<' || s[i] == '>' || s[i] == '|')
		{
			mat = add_chr(mat, s[i]);
			continue ;
		}
		else if (s[i] == '\'' || s[i] == '"')
			wrd = fnd_qts(s, &i);
		else
			wrd = fnd_wrd(s, &i);
		mat = add_wrd(mat, wrd);
	}
	return (mat);
}
