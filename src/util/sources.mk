UTIL	:=	mtx_rotate.c \
			mtx_scale.c \
			mtx_translate.c \
			solve_quadratic.c \
			transform_pipeline.c \
			vec_from_vtx.c \
			vec_magnitude.c \
			vec_new.c \
			vec_normalize.c \
			vtx_homogenize.c \
			vtx_new.c

OBJ := $(OBJ) $(UTIL:.c=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.c $(HEAD)
	$(COMPIL)
