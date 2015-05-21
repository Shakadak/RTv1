PARSER	:=	atom_fill.c \
			atom_new.c \
			fill_color.c \
			fill_transformation.c

OBJ := $(OBJ) $(PARSER:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
