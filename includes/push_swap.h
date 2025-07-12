/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:18:00 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/12 13:42:07 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf.h"

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
	// struct s_node	*prev;
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
void			ft_lstadd_back(t_node **lst, t_node *new);
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

void			sa(t_node **lst, bool print);
void			sb(t_node **lst, bool print);
void			ss(t_node **a, t_node **b, bool print);
void			pa(t_node **a, t_node **b, bool print);
void			pb(t_node **b, t_node **a, bool print);
void			ra(t_node **lst, bool print);
void			rb(t_node **lst, bool print);
void			rr(t_node **a, t_node **b, bool print);
void			double_rotate(t_node **a, t_node **b, t_node *cheapest_node);
void			rra(t_node **lst, bool print);
void			rrb(t_node **lst, bool print);
void			rrr(t_node **a, t_node **b, bool print);
void			double_rrotate(t_node **a, t_node **b, t_node *cheapest_node);

void			ft_bzero(void *s, size_t n);
int				pars(int ac, char **av, t_stack stack[2]);

int				ft_size_list(t_node *lst);
int				*set_idx_tab(t_node *lst, int size);
int				*sort_idx_tab(int *tab, int size);
void			set_idx(t_node *lst, int *tab, int size);
void			indexation(t_node *lst, int size);

int				is_sorted(t_node *lst);
void			sort_three_nodes(t_node **lst);
t_node			*find_node_max(t_node *lst);
t_node			*find_node_min(t_node *lst);
void			sort_stack(t_node **a, t_node **b);
void			set_position(t_node *lst);
void			best_target_a(t_node *a, t_node *b);
void			best_target_b(t_node *a, t_node *b);
void			cost_analyser(t_node *a, t_node *b);
void			set_cheapest(t_node *lst);
void			init_nodes_a(t_node *a, t_node *b);
void			init_nodes_b(t_node *a, t_node *b);
void			min_on_top(t_node **a);
t_node			*get_cheapest(t_node *lst);
void			move_b_to_a(t_node **a, t_node **b);
void			prep_for_push(t_node **lst,
					t_node *to_top_node, char stack_name);

void			ft_putnbr(int n, int *ret_val);
void			ft_putnbru(unsigned int n, int *ret_val);
void			ft_putnbr_base(unsigned long nbr, char *base, int *ret_val);
void			ft_putptr(unsigned long p, int *ret_val);
void			ft_putstr(char *s, int *ret_val);
void			ft_write(char c, int *ret_val);
void			ft_switch(const char format, va_list args, int *ret_val);
int				ft_printf(const char *format, ...);

#endif
