PARSER	:=	atom_fill.c \
			atom_new.c

OBJ := $(OBJ) $(PARSER:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
