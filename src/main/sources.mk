MAIN	:=	main.c \
			key_press.c \
			scene_to_struct.c \
			update_screen.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
