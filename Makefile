# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 19:10:39 by ale-coss          #+#    #+#              #
#    Updated: 2025/07/10 17:21:39 by ale-coss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la librairie
NAME = push_swap
BONUS_NAME = checker

# Fichiers source
D_SRCS = ./srcs/
S_SRCS = main.c pars.c utils_pars.c utils_lists.c swap.c push.c rotate.c rrotate.c utils_sort.c\
	utils_sort_2.c utils_sort_3.c utils_sort_4.c utils_main.c sort_stack.c utils_ft_printf.c\
	utils_ft_printf_2.c ft_printf.c ft_split.c ft_substr.c set_index.c
SRCS = $(addprefix $(D_SRCS), $(S_SRCS))

# Fichiers includes
D_INC = ./includes/

# Fichiers bonus
D_BONUS = ./bonus/
S_BONUS = checker_bonus.c get_next_line_bonus.c utils_bonus.c ft_printf_bonus.c ft_split_bonus.c ft_substr_bonus.c\
pars_bonus.c push_bonus.c rotate_bonus.c rrotate_bonus.c swap_bonus.c utils_ft_printf_bonus.c utils_ft_printf_2_bonus.c\
utils_lists_bonus.c utils_pars_bonus.c utils_main_bonus.c utils_sort_bonus.c

BONUS_C = $(addprefix $(D_BONUS), $(S_BONUS))

# Couleurs
DEFAULT = \033[0m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
UNDERLINE = \033[4m
BOLD = \033[1m

# Fichiers objets
D_OBJS = .build/
OBJS = $(addprefix $(D_OBJS), $(S_SRCS:.c=.o))

BONUS_OBJS = $(addprefix $(D_OBJS), $(S_BONUS:.c=.o))

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Règle par défaut
all: $(NAME)

# Création de la librairie avec les fichiers SRCS uniquement
$(NAME): $(OBJS)
	@${CC} ${CFLAGS} -o $(NAME) $(OBJS)

# Règle pour compiler uniquement les fichiers BONUS_C
bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@${CC} ${CFLAGS} $^ -o $@

# Compilation des .c en .o
$(D_OBJS)%.o: $(D_SRCS)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(D_INC) -c $< -o $@
	@echo "$(YELLOW)$(BOLD) Compiling: $< $(DEFAULT)"

$(D_OBJS)%.o: $(D_BONUS)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(D_INC) -c $< -o $@
	@echo "$(YELLOW)$(BOLD) Compiling: $< $(DEFAULT)"


# Supprimer les fichiers objets
clean:
	@${RM} -R $(D_OBJS) $(BONUS_O)
	@echo "$(CYAN)$(BOLD) remove object files succesfully !$(DEFAULT)"

# Supprimer les fichiers objets et la librairie
fclean: clean
	@${RM} $(NAME) $(BONUS_NAME)
	@echo "$(CYAN)$(BOLD) remove executable file succesfully !$(DEFAULT)"

# Recompiler proprement
re: fclean
	@make --silent all

# Précise que ces cibles ne sont pas des fichiers
.PHONY: all clean fclean re go gov bonus
