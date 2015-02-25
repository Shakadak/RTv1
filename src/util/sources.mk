UTIL	:=	vtx_from_coordinates.c \
			vec_from_vtx.c \
			solve_quadratic.c

OBJ := $(OBJ) $(UTIL:.c=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.c $(HEAD)
	$(COMPIL)
