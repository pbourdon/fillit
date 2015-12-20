#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishafie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 13:57:48 by ishafie           #+#    #+#              #
#    Updated: 2015/12/19 22:37:52 by ishafie          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit # Binary name
DIRSRC		=	. # ./path/to/sources/directorie/
DIROBJ		=	. # ./path/to/object/directorie/
INCLUDE		=	. # ./path/to/include/directorie/
SUB_MAKE	=	# ./path/to/sub/makefile/directorie/ (Put nothing if isn't)
INC_LIB		=	# -L./path/to/lib/directorie -lname
SRC			=	ft_main.c\
				ft_str.c\
				ft_strd.c\
				ft_strt.c\
				ft_strq.c\
				ft_get_tetriminos.c\
				ft_check.c\
				ft_map.c\
				ft_add_tetriminos.c\
				ft_change.c\
				ft_verif_test.c\
				ft_memcpy.c\
				ft_strcmp.c\


OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e


$(NAME)	:		$(OBJ)
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE))
endif
				$(CC) -o $(NAME) $(SRC)
				@$(ECHO) '> Compiled'

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) clean)
endif
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

%.o		:		$(DIRSRC)/%.c
				$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
