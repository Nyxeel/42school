#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    size = 0;
    
    while (tab[size] != '\0')
        {
            size++;
        }

    int reverse[size];
    int i;

    i = 0;
    while (size != 0)
        {
            reverse[size] = tab[i];
            size--;
            i++;
            
            int h;
            h = 0;
                while (h < size)
                {
                    printf("%d", reverse[h]);
                    h++;
                } 
        }

      
}


int	main(void)
{
    int* tab;
    int value = 123456789;
    int size;

    tab = {1, 2, 5, 6};

   
    size = 0;
   
    
        
    printf("0123456789\n");
    ft_rev_int_tab(tab, size);
}

