#include "vector-buffer/includes/vector.h"
#include <stdio.h>

int	main(void)
{
	t_vector vect;

	vect_init(&vect);
	printf("%s\n",vect_write(&vect, "UwU"));
	printf("%s\n",vect_write(&vect, "U                       wU"));
	printf("%s\n",vect_write(&vect, "                        UwU"));
	printf("%s\n",vect_write(&vect, "OwO               "));
	printf("%s\n",vect_write(&vect, ""));
	return (0);
}
