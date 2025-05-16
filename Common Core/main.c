#include <stdio.h>
#include <limits.h>
#include "printf/libftprintf.h"

int main(void)
{
	int ret1, ret2;

	printf("\n--- CHAR TEST ---\n");
	ret1 = ft_printf("MY Char: [%c]\n", 'A');
	ret2 = printf("Char: [%c]\n", 'A');
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- STRING TEST ---\n");
	ret1 = ft_printf("MY String: [%s]\n", "Hello, World!");
	ret2 = printf("String: [%s]\n", "Hello, World!");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- POINTER TEST ---\n");
	int x = 42;
	ret1 = ft_printf("MYPointer: [%p]\n", &x);
	ret2 = printf("Pointer: [%p]\n", &x);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	ret1 = ft_printf("Null pointer: [%p]\n", (void *)0);
	ret2 = printf("Null pointer: [%p]\n", (void *)0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- DECIMAL & INTEGER TEST ---\n");
	ret1 = ft_printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	ret2 = printf("INT_MAX: [%d] INT_MIN: [%i]\n", INT_MAX, INT_MIN);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- UNSIGNED TEST ---\n");
	ret1 = ft_printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	ret2 = printf("UINT_MAX: [%u] ZERO: [%u]\n", UINT_MAX, 0);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- HEXADECIMAL TEST ---\n");
	ret1 = ft_printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	ret2 = printf("Hex lower: [%x] upper: [%X]\n", 305441741, 305441741);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- PERCENT SIGN TEST ---\n");
	ret1 = ft_printf("100%% sure!\n");
	ret2 = printf("100%% sure!\n");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);



	printf("\n--- DOUBLE SPECIFIERS ---\n");
	ret1 = ft_printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	ret2 = printf("Mix: [%c][%s][%d][%x]\n", 'X', "Test", -42, 48879);
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- INVALID SPECIFIER ---\n");
	ret1 = ft_printf("What happens with %%r?\n");
	ret2 = printf("What happens with %%r?\n");
	printf("Return values: ft: %d | original: %d\n", ret1, ret2);

	printf("\n--- NO ARGUMENTS ---\n");
	ret1 = ft_printf("char: %c, int: %d, string: %s\n"); // <- No Arguments!
	printf("Return values: ft: %d\n", ret1);

	printf("\n--- TOO MANY ARGUMENTS ---\n");
	ret1 = ft_printf("only one: %%d = %d\n", 42, 1337, "oops", NULL);
	printf("Return values: ft: %d\n", ret1);


/* 	printf("\n--- TYPE WRONG ---\n");
	ret1 = ft_printf("unsigned: %s\n", -1);
	printf("Return values: ft: %d\n", ret1); */

	char *ptr = NULL;
	printf("\n--- NULL POINTER IN STRING ---\n");
	ret1 = ft_printf("null string: %s\n", ptr);
	printf("Return values: ft: %d\n", ret1);


	printf("\n--- NULL CHAR ---\n");
	ret1 = ft_printf("null char: %c$\n", '\0');
	printf("Return values: ft: %d\n", ret1);

	printf("\n--- ONLY %% 4 TIMES ---\n");
	ret1 = ft_printf("%%%%%%%%\n");
	printf("Return values: ft: %d\n", ret1);

	printf("\n--- STRING ENDS WITH %% ---\n");
	ret1 = ft_printf("invalid: %");
	printf("Return values: ft: %d\n", ret1);

	printf("\n---UNKNOWN FORMATSIGN---\n");
	ret1 = ft_printf("unknown: %q\n", 42);
	printf("Return values: ft: %d\n", ret1);

	printf("\n---CHAINED---\n");
	ret1 = ft_printf("int: %d, hex: %x, char: %c, str: %s, percent: %%\n", 42, 255, 'A', "Hallo");
	printf("Return values: ft: %d\n", ret1);

	return (0);
}
