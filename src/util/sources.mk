UTIL	:=	vtx_from_coordinates.c \
			vec_from_vtx.c \
			solve_quadratic.c \
			vec_dot.c \
			vec_cross.c \
			vec_sub.c \
			vec_add.c \
			vec_normalize.c \
			vec_magnitude.c

OBJ := $(OBJ) $(UTIL:.c=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.c $(HEAD)
	$(COMPIL)
