# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 12:57:00 by npineau           #+#    #+#              #
#    Updated: 2015/05/12 15:54:44 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	rtv1

### DIRECTORIES ###

DIRSRC	:=	src
DIROBJ	:=	obj
DIRINC	:=	inc
DIRFT	:=	libft
DIRMLX	:=	libumlx
DIRMTX	:=	libmtx

DIRMAIN		:=	$(DIRSRC)/main
DIRSHAPE	:=	$(DIRSRC)/shapes
DIRRAY		:=	$(DIRSRC)/ray
DIRUTIL		:=	$(DIRSRC)/util

### FILES ###

HEAD := $(DIRINC)/$(NAME).h

include $(DIRMAIN)/sources.mk
include $(DIRSHAPE)/sources.mk
include $(DIRRAY)/sources.mk
include $(DIRUTIL)/sources.mk

POBJ	:=	$(addprefix $(DIROBJ)/, $(OBJ))

PFT		:= $(DIRFT)/libft.a
PMLX	:= $(DIRMLX)/libumlx.a
PMTX	:= $(DIRMTX)/libmtx.a

### COMPILATION VARIABLES ###

CC		:=	gcc

C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3

C_INC	:=	-I $(DIRINC) \
			-I $(DIRFT)/$(DIRINC) \
			-I $(DIRMLX)/$(DIRINC) \
			-I $(DIRMTX)/$(DIRINC) \
			-I /usr/x11/include

L_FLAG	:=	-L $(DIRMTX) -lmtx \
			-L $(DIRMLX) -lumlx \
			-L $(DIRFT) -lft \
			-lmlx \
			-framework OpenGL -framework AppKit \
			-lm

COMPIL	= $(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	= $(CC) -o $@ $^ $(L_FLAG)


### RULES ###

.PHONY: all clean fclean re

all: $(PFT) $(PMLX) $(PMTX) $(NAME)

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	$(LINK)

### LIBS ###

$(PFT):
	make -C $(DIRFT)

$(PMLX):
	make -C $(DIRMLX)

$(PMTX):
	make -C $(DIRMTX)

### MISC ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all
