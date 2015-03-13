SHAPE	:=	new_sphere.c \
			new_cone.c \
			new_cylinder.c \
			new_camera.c \
			intersec_sphere.c \
			intersec_cone.c \
			intersec_cylinder.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
