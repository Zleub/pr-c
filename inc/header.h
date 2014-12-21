/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 04:02:20 by adebray           #+#    #+#             */
/*   Updated: 2014/12/21 04:27:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <test.h>

typedef struct	s_hugo
{
	char		*name;
	int			height;
	int			weight;
	WINDOW		*pointofview;
}				t_hugo;

struct				s_t1
{
	unsigned int	id;
	int				x;
	int				y;

	color			c;
	shape			*s;

	struct s_t1		*neibourghs[10];
};

#endif
