SHAPE	:=	new_sphere.c \
			new_cone.c \
			new_cylinder.c \
			new_plane.c \
			new_camera.c \
			intersec_quadric.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
