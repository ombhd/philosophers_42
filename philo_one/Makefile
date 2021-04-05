# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 19:25:29 by obouykou          #+#    #+#              #
#    Updated: 2021/04/05 19:01:31 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

LIB = lib_philo.a

MAIN = philo_one.c

FILES = sources/ft_atoi.c sources/init.c sources/utils.c
		
HEADER = includes/philo_one.h

OBJECT = $(FILES:.c=.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)
	@echo "\n\033[32m◊◊◊ ------- $(NAME) has been created successfully ------- ◊◊◊\033[0m\n"

$(NAME): $(OBJECT) $(HEADER) $(FILES) $(MAIN)
	@ar -rcs $(LIB) $(OBJECT)
	@echo "\n\033[36m◊◊◊ Producin' object files done! ◊◊◊\033[0m\n"
	@gcc $(FLAGS) $(MAIN) $(LIB) -o $(NAME)

%.o:%.c $(HEADER)								
	@gcc -c $< $(FLAGS) -o $@

clean:
	@rm -rf $(OBJECT) $(LIB)
	@echo "\n\033[36m◊◊◊ Cleanin' object files done! ◊◊◊\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re : fclean all