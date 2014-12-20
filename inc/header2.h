/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 16:38:32 by adebray           #+#    #+#             */
/*   Updated: 2014/12/20 16:41:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER2_H
# define HEADER2_H

struct				s_t1
{
	unsigned int	id;
	int				x;
	int				y;

	color			c;
	shape			s;

	struct s_t1		*neibourghs[10];
};

#endif
