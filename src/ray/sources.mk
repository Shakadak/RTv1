RAY	:=	new_ray.c \
		ray_transform.c

OBJ := $(OBJ) $(RAY:.c=.o)

$(DIROBJ)/%.o: $(DIRRAY)/%.c $(HEAD)
	$(COMPIL)
