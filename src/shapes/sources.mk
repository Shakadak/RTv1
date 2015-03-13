SHAPE	:=	new_sphere.c \
			new_cone.c \
			new_cylinder.c \
			new_plane.c \
			new_camera.c \
			intersec_sphere.c \
			intersec_cone.c \
			intersec_cylinder.c \
			intersec_plane.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
