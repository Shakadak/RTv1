UTIL	:=	vtx_from_coordinates.c

OBJ := $(OBJ) $(UTIL:.c=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.c $(HEAD)
	$(COMPIL)
