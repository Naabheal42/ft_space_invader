# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/20 10:23:44 by bbecker           #+#    #+#              #
#    Updated: 2016/10/15 17:46:56 by nbrizini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_space_invader

CPP =		AEntity.cpp		\
			Enemy.cpp		\
			Projectile.cpp	\
			Screen.cpp		\
			Ship.cpp		\
			main.cpp

O =			AEntity.o		\
			Enemy.o			\
			Projectile.o	\
			Screen.o		\
			Ship.o			\
			main.o

all: $(NAME)

$(NAME):
	clang++  -c $(CPP)
	clang++  -lncurses -o $(NAME) $(O)

clean :
	/bin/rm -rf $(O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all
