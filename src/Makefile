# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 21:16:45 by yquaro            #+#    #+#              #
#    Updated: 2019/09/03 11:40:01 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/filler.mk

DIR_O = ../lib
SOURCES = main.c input_parsing.c init.c make_a_move.c central_rectangle.c \
			optimum_way.c heat_map.c temperature_value_tools.c put_piece.c \
			init_score.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling filler

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
