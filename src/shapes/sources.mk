SHAPE	:=	new_sphere.c \
			new_camera.c \
			new_coordinate.c

OBJ := $(OBJ) $(SHAPE:.c=.o)

$(DIROBJ)/%.o: $(DIRSHAPE)/%.c $(HEAD)
	$(COMPIL)
