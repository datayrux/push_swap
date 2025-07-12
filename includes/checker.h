/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:18:00 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 15:40:07 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line.h"

enum
{
	a,
	b
};

typedef struct s_node
{
	int				nb;
	int				idx;
	int				position;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
}	t_stack;

int				ft_atol(const char *str, int *p);
t_node			*lst_new(int nb);
int				is_digit(char c);
t_node			*create_list(char **tab);
void			print_list(t_node *list);
void			ft_free_list(t_node **lst);
t_node			*ft_lstlast(t_node *lst);
void			ft_lstadd_back(t_node **lst, t_node *new_node);
int				node_cmp(t_node *list);
void			write_free_exit(t_node *list);
void			ft_free_split(char **tab);
int				ft_count_str(char const *str, char c);
void			*ft_protect(char **tab, size_t j);
char			**ft_fill_tab(char const *s, char **tab, char c, size_t j);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_strlen(const char *s);

void			sa(t_node **lst);
void			sb(t_node **lst);
void			ss(t_node **a, t_node **b);
void			pa(t_node **a, t_node **b);
void			pb(t_node **b, t_node **a);
void			ra(t_node **lst);
void			rb(t_node **lst);
void			rr(t_node **a, t_node **b);
void			double_rotate(t_node **a, t_node **b, t_node *cheapest_node);
void			rra(t_node **lst);
void			rrb(t_node **lst);
void			rrr(t_node **a, t_node **b);
void			double_rrotate(t_node **a, t_node **b, t_node *cheapest_node);

void			ft_bzero(void *s, size_t n);
int				pars(int ac, char **av, t_stack stack[2]);

int				ft_size_list(t_node *lst);
int				*set_idx_tab(t_node *lst, int size);
int				*sort_idx_tab(int *tab, int size);
void			set_idx(t_node *lst, int *tab, int size);
void			indexation(t_node *lst, int size);

int				is_sorted(t_node *lst);
void			set_position(t_node *lst);
void			prep_for_push(t_node **lst, t_node *top_node, char stack_name);

void			ft_putnbr(int n, int *ret_val);
void			ft_putnbru(unsigned int n, int *ret_val);
void			ft_putnbr_base(unsigned long nbr, char *base, int *ret_val);
void			ft_putptr(unsigned long p, int *ret_val);
void			ft_putstr(char *s, int *ret_val);
void			ft_write(char c, int *ret_val);
void			ft_switch(const char format, va_list args, int *ret_val);
int				ft_printf(const char *format, ...);

int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				check(t_node **a, t_node **b);
int				read_and_execute(char *line, t_node **a, t_node **b);
char			*get_next_line(int fd);
char			*update_remaining(char *remaining, char *line);
char			*get_a_line(char *remaining);
char			*ft_jonction(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);

#endif
