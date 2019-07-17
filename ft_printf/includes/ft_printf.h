/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:17:21 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 17:29:09 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	H & L Flags does not working well, %f need upgrade
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	LIMITS
*/
# include <limits.h>

/*
**	MALLOC & FREE & EXIT
*/
# include <stdlib.h>

/*
**	WRITE
*/
# include <unistd.h>

/*
**	VA_START & VA_ARG & VA_COPY & VA_END
*/
# include <stdarg.h>

/*
**	OTHER INCLUDES
*/
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

/*
**	VARIABLES
*/

# define MAX_UINT 4294967295
# define NB_ATTRIBUTES 20
# define NB_OPTIONS 6
# define D_BASE 10
# define U_BASE 10
# define O_BASE 8
# define X_BASE 16

enum				e_attributes
{
	C,
	S,
	DI,
	U,
	O,
	X,
	BIGX,
	F,
	ARG_NB,
	TYPE,
	ZERO_FILLED,
	LEFT_ALIGNED,
	PLUS,
	SPACE,
	PREFIX,
	WIDTH,
	PRECISION,
	H,
	HH,
	L,
	LL,
	P
};

/*
**	Precision is initially set on 6
*/

typedef struct		s_attributes
{
	struct s_attributes	*next;
	struct s_attributes	*prev;
	va_list				arg_list;
	char				**current_str;
	char				conversion;
	int					type;
	int					width;
	int					prec;
	int					precision;
	int					zero_filled;
	int					left_aligned;
	int					plus;
	int					space;
	int					prefix;
	int					nb_null_param;
}					t_attributes;

/*
**	UTILITIES FUNCTIONS
*/
long double			ft_roundl(long double x);
size_t				ft_longlen(long nb);
char				*ft_add_a_char(char *str, char c, int end);
unsigned long long	ft_ten_pow(int nb);
char				*fill_with_zeros(char *str, int len);

/*
**	FT_PRINTF FUNCTIONS
*/
int					ft_printf(const char *restrict format, ...);
char				*ft_vsprintf(const char *restrict format, va_list list);
char				*replace_by_str(char *format, t_attributes *att_list);
int					alone_percent(const char *format);

/*
**	FIND ATTRIBUTES FUNCTIONS
*/
void				ft_find_options(const char *format, t_attributes *att_list);
void				ft_find_width(const char *format, t_attributes *att_list);
void				ft_find_precis(const char *format, t_attributes *att_list);
void				ft_find_type(const char *format, t_attributes *att_list);

/*
**	DIGIT TO ASCII BASE FUNCTIONS
*/
char				*ft_itoa_base(int l, int base);
char				*ft_ltoa_base(long l, int base);
char				*ft_lltoa_base(long long l, int base);
char				*ft_ulltoa_base(unsigned long long l, int base);

/*
**	OPTION FUNCTIONS
**	called in conv functions
*/
char				*diouxx_precision(char *str, t_attributes *att_list,
		int len);
char				*ft_add_a_prefix(char *str, char conversion);
char				*ft_add_a_plus(char *str);
char				*ft_add_a_minus(char *str);
char				*ft_add_a_space(char *str);
char				*ft_make_str(char *str, int width, int left_aligned);
char				*zero_filler(char *str, t_attributes *att_list);
char				*f_zero_filler(char *str, t_attributes *att_list);
char				*ft_byte_viewer(void *first_byte, int bytes_nb);

/*
**	CONV FUNCTIONS			A faire
*/
char				*ft_c_conv(t_attributes *att_list);
char				*ft_s_conv(t_attributes *att_list);
char				*ft_d_conv(t_attributes *att_list);
char				*ft_u_conv(t_attributes *att_list);
char				*ft_o_conv(t_attributes *att_list);
char				*ft_x_conv(t_attributes *att_list);
char				*ft_bigx_conv(t_attributes *att_list);
char				*ft_p_conv(t_attributes *att_list);
char				*ft_f_conv(t_attributes *att_list);
char				*ft_percent_conv(t_attributes *att_list);

/*
** DEBUG FUNCTIONS
*/
void				print_attributes(t_attributes *arg_att_list);

#endif
