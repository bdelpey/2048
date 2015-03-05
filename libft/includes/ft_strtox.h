/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtox.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 12:24:47 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:59:27 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOX_H
# define FT_STRTOX_H

# define ARG_PREFIX (0)
# define ARG_CHARSET (1)

# define T_HEX (16)

# define T_BINARY_PREFIX "0b"
# define T_DECIMAL_PREFIX ""
# define T_OCTAL_PREFIX "0"
# define T_HEX_PREFIX "0x"

typedef struct s_strtol_m	t_strtol_m;

struct						s_strtol_m
{
	char					*prefix;
	unsigned char			charmap[256];
};

extern const t_strtol_m		g_hex_map;
extern const t_strtol_m		g_bin_map;
extern const t_strtol_m		g_dec_map;
extern const t_strtol_m		g_oct_map;

const t_strtol_m			*g_conv_map[] =
{
	[0] = NULL,
	[2] = &g_bin_map,
	[8] = &g_oct_map,
	[10] = &g_dec_map,
	[16] = &g_hex_map
};

const t_strtol_m			g_hex_map =
{
	T_HEX_PREFIX,
	{
		['0'] = 0x0 + 1,
		['1'] = 0x1 + 1,
		['2'] = 0x2 + 1,
		['3'] = 0x3 + 1,
		['4'] = 0x4 + 1,
		['5'] = 0x5 + 1,
		['6'] = 0x6 + 1,
		['7'] = 0x7 + 1,
		['8'] = 0x8 + 1,
		['9'] = 0x9 + 1,
		['A'] = 0xA + 1,
		['B'] = 0xB + 1,
		['C'] = 0xC + 1,
		['D'] = 0xD + 1,
		['E'] = 0xE + 1,
		['F'] = 0xF + 1,
		['a'] = 0xa + 1,
		['b'] = 0xb + 1,
		['c'] = 0xc + 1,
		['d'] = 0xd + 1,
		['e'] = 0xe + 1,
		['f'] = 0xf + 1,
	}
};

const t_strtol_m			g_dec_map =
{
	T_DECIMAL_PREFIX,
	{
		['0'] = 0 + 1,
		['1'] = 1 + 1,
		['2'] = 2 + 1,
		['3'] = 3 + 1,
		['4'] = 4 + 1,
		['5'] = 5 + 1,
		['6'] = 6 + 1,
		['7'] = 7 + 1,
		['8'] = 8 + 1,
		['9'] = 9 + 1,
	}
};

const t_strtol_m			g_oct_map =
{
	T_OCTAL_PREFIX,
	{
		['0'] = 00 + 1,
		['1'] = 01 + 1,
		['2'] = 02 + 1,
		['3'] = 03 + 1,
		['4'] = 04 + 1,
		['5'] = 05 + 1,
		['6'] = 06 + 1,
		['7'] = 07 + 1,
	}
};

const t_strtol_m			g_bin_map =
{
	T_BINARY_PREFIX,
	{
		['0'] = 0 + 1,
		['1'] = 1 + 1,
	}
};

#endif
