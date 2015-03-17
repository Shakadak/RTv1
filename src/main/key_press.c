#include <X11/keysym.h>
#include <stdlib.h>

int	key_press(int key)
{
	if (key == XK_Escape)
		exit(0);
	return (0);
}
