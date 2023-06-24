#include <libc.h>

int	main(void)
{
	char *str = "あ";

	write(1, &str[0], 1);
	write(2, &str[1], 1);
	write(1, &str[2], 1);
}
