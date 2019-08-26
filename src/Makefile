# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 21:16:45 by yquaro            #+#    #+#              #
#    Updated: 2019/08/26 20:38:15 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/filler.mk

DIR_O = ../lib
SOURCES = main.c input_parsing.c init.c make_a_move.c central_square.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling filler

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
