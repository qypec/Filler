# Base variables for filler

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
FILLER_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(FILLER_H)
EXECUTABLE = yquaro.filler
LIBNAME = libft.a
