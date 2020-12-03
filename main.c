
#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <stddef.h>

int main(void){
	int q = 123;
	printf("%xi\n", q);
	ft_printf("%xi", q);
	return 0;
}
