RAY	:=	new_ray.c \
		transform_ray.c

OBJ := $(OBJ) $(RAY:.c=.o)

$(DIROBJ)/%.o: $(DIRRAY)/%.c $(HEAD)
	$(COMPIL)
