SHAPE	:=	new_sphere.c \
			new_cylinder.c \
			new_camera.c \
			new_coordinate.c \
			intersec_sphere.c \
			intersec_cylinder.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
