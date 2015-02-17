MAIN	:=	shapes.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
