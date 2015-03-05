/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_backends.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 18:53:52 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:00:41 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIADIC_BACKENDS_H
# define FT_VARIADIC_BACKENDS_H

# include <stdarg.h>
# include "libft.h"

ssize_t			private_putnstr_fd(int fd, int argc, va_list ls);

#endif
