RAY	:=	ray_cast.c \
		ray_new.c \
		ray_normal.c \
		ray_shade.c \
		ray_transform.c

OBJ := $(OBJ) $(RAY:.c=.o)

$(DIROBJ)/%.o: $(DIRRAY)/%.c $(HEAD)
	$(COMPIL)
