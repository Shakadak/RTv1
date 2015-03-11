UTIL	:=	mtx_determinant.c \
			mtx_identity.c \
			mtx_mult.c \
			mtx_rotate.c \
			mtx_scale.c \
			mtx_translate.c \
			mtx_transpose.c \
			mtx_vec_mult.c \
			mtx_vtx_mult.c \
			solve_quadratic.c \
			transform_pipeline.c \
			vec_add.c \
			vec_cross.c \
			vec_dot.c \
			vec_from_vtx.c \
			vec_homogenize.c \
			vec_magnitude.c \
			vec_normalize.c \
			vec_sub.c \
			vtx_new.c \
			vtx_homogenize.c

OBJ := $(OBJ) $(UTIL:.c=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.c $(HEAD)
	$(COMPIL)
