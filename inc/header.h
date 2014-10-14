/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 04:02:20 by adebray           #+#    #+#             */
/*   Updated: 2014/08/04 01:32:20 by adebray          ###   ########.fr       */
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
	char		state;
}				t_hugo;

typedef struct			s_hugo_list
{
	t_hugo				*ptr;
	struct s_hugo_list	*next;
}						t_hugo_list;

#endif
