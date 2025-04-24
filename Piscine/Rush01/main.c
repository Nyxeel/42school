#include <unistd.h>

#define GRID_SIZE 4


/////////////////////////////////// CHECK INPUT VALUES

char	ft_number_check(char c)
{
	int	i;
	char	grid;
	int	count;
	
	count = 0;
	grid = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == ' ')
			i++;
			continue;
		if (c[i] >= '1' <= 'GRID_SIZE')
			
			grid[count] = c[i];
			count++;
			i++;
	}
	if (count == GRID_SIZE * GRID_SIZE)
		return (grid);
	else
		ft_error();
		return (1);
}

///////////////////////////////////////////////////////////// 	FUNCTION TO CREATE GRID

char create_grid(char *grid, char up, char bottom, char left, char right) 
{
	
	int i;
	i = 1;
	while (i <= GRID_SIZE)
	{
		*grid[0][i] = up[i-1];
		i++;
	]
	
	
	i = 1;
	while (i <= GRID_SIZE)
	{
		*grid[5][i] = bot[i-1];
		i++;
	]
	
	
	i = 1;
	while (i <= GRID_SIZE)
	{
		*grid[i][0] = left[i-1];
		i++;
	]
	
	i = 1;
	while (i <= GRID_SIZE)
	{
		*grid[i][5] = right[i-1];
		i++;
	]
	
	return (grid);
}
	
	
char	ft_checking_rules(char *up, char *bot, char *left, char *right, char *al_up, 
		char solution_up, char *solution_bot, char *solution_left, char *solution_right)
{

	
	call solution_grid[i] from database
	
	int i;
	
	i = 1;
	
	
	while ((*solution_up == *up && *solution_bot == *bot) &&
		(*solution_left == *left && *solution_right == *right))
	{
		if (!(*solution_up || *solution_bot || *solution_left || *solution_right))
		
			ft_ call solution_grid[i] from database
		if((*solution_up != *up && *solution_bot != *bot) &&
		(*solution_left != *left && *solution_right != *right))
			ft_alvaro
	}
	
	
	
		
	
	
	
	
	while (grid[0][i] == solution[0][i])
	{
		if(grid[0][i] != solution[0][i])
			ft_alvaro;		
		i++
	}	
			j = 0;
			while (j <= GRID_SIZE)		
			{
				if (grid[5][j] == solution[5][j])  //check bottom row
				{
					h = 0;
					while (h <= GRID_SIZE)
					{
						if (grid[0][h] == solution[0][h]) 	//check left column
						{
							k = 0;
							while (k <= GRID_SIZE)
							{
								if (grid[0][h] == solution_grid[0][h])  //check right column
								{
									
								}
							
								k++;
							}
							
						}
					
						h++;	
					}
					
				
				}
				j++;
			}
			
		}	
		i++;
	}
	
	
	
	

	
	grid[i][j][h] = {(av[0][1],  av[0][2], av[0][3], av[0][4]) ,  //upper row
		(av[0][1],  av[0][2], av[0][3], av[0][4]), 	// bottom row
		(av[0][1],  av[0][2], av[0][3], av[0][4]),	// left row
		(av[0][1],  av[0][2], av[0][3], av[0][4])}	// right row
	
	
	

}	
 	
	
	
	
	
	
	
	
	
	
	
/*
	
	
	int i = 0;
	char board;
	while (i < GRID_SIZE) 
	{
		int j = 0;
		while (j < GRID_SIZE) 
		{
			board[i][j] = grid[i + 1][j + 1]; 
			j++;
        	}
        	i++;
    	}
}


////////////////////////////////////////////////////////////	FUNCTION TO CHECK LATIN AQUARE RULES

void	ft_check_square_rules(char *grid[GRID_SIZE][GRID_SIZE])
{
	int i = 0;
	while (i < GRID_SIZE) 
	{
		int j = 0;
		while (j < GRID_SIZE) 
		{
			board[i][j] = grid[i + 1][j + 1]; 
			j++;
        	}
        	i++;
    	}
}	
*/




int	main(int argc, char **argv)
{
	int *grid;
	
	if (argc != 2)
	{
		ft_error();
		return(1);
	}
	
	//grid = (int*)malloc(GRID_SIZE * GRID_SIZE); /// while ( solution_grid == up && solution == bot &&
	
	grid = ft_number_check(argv[1]);
	
	up[GRID_SIZE] = {grid[0], grid[1], grid[2], grid[3]};
	bot[GRID_SIZE] = {grid[4], grid[5], grid[6], grid[7]};
	left[GRID_SIZE] = {grid[8], grid[9], grid[10], grid[11]};
	right[GRID_SIZE] = {grid[12], grid[13], grid[14], grid[15]};
	
	grid[GRID_SIZE + 2][GRID_SIZE + 2];			/////////	MAIN GRID
	
	
	
	////////////////////////////////////////////////// 	TAKE CHORDS TO CREATE INNER BOARD

	char *board[GRID_SIZE + 2][GRID_SIZE + 2];
	
	
	ft_create_grid(board, up, bot, left, right);
	
	
	up[GRID_SIZE] = {grid[0], grid[1], grid[2], grid[3]};
	bot[GRID_SIZE] = {grid[4], grid[5], grid[6], grid[7]};
	left[GRID_SIZE] = {grid[8], grid[9], grid[10], grid[11]};
	right[GRID_SIZE] = {grid[12], grid[13], grid[14], grid[15]};
	
	alvaro_grid[][] = { {grid[0], grid[1], grid[2], grid[3]}, 
			{grid[4], grid[5], grid[6], grid[7]}, 
			{grid[8], grid[9], grid[10], grid[11]} }
	
	ft_checking_rules(up, bot, left, right,

	
	/////////////////////////////////////////////////	CALL LATIN SQUARE CHECK
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
