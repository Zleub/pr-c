/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 04:02:20 by adebray           #+#    #+#             */
/*   Updated: 2014/07/26 15:22:15 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <test.h>

/*
 *PUSH_BACK
 *next=huguette
 */

typedef struct		s_hugo
{
	char			*name;
	struct s_hugo	*huguette;
	int				height;
	int				weight;
	WINDOW			*pointofview;
	char			state;
}					t_hugo;

#endif
