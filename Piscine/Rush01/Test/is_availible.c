recursion.c                                                                                         0000664 0307731 0010201 00000004407 13200662410 013546  0                                                                                                    ustar   pjelinek                        2025_vienna                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:23:51 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:35:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	next_position(int *x, int *y, char tab[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab[i][j] == '.')
			{
				*x = i;
				*y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	recursion(char tab[9][9])
{
	int		x;
	int		y;
	char	c;

	if (next_position(&x, &y, tab) == 0)
		return (1);
	c = '1';
	while (c <= '9')
	{
		if (is_available(c, x, y, tab))
		{
			tab[x][y] = c;
			if (recursion(tab) == 1)
				return (1);
			else
				tab[x][y] = '.';
		}
		c++;
	}
	return (0);
}

int	reverse_next_position(int *x, int *y, char tab[9][9])
{
	int i;
	int j;

	i = 8;
	while (i >= 0)
	{
		j = 8;
		while (j >= 0)
		{
			if (tab[i][j] == '.')
			{
				*x = i;
				*y = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	reverse_recursion(char tab[9][9])
{
	int		x;
	int		y;
	char	c;

	if (reverse_next_position(&x, &y, tab) == 0)
		return (1);
	c = '1';
	while (c <= '9')
	{
		if (is_available(c, x, y, tab))
		{
			tab[x][y] = c;
			if (reverse_recursion(tab) == 1)
				return (1);
			else
				tab[x][y] = '.';
		}
		c++;
	}
	return (0);
}

int	solve(char tab1[9][9], char tab2[9][9])
{
	if (recursion(tab1) != 1)
		return (write(1, "Error\n", 6));
	if (reverse_recursion(tab2) != 1)
		return (write(1, "Error\n", 6));
	if (compare_solutions(tab1, tab2) == 0)
		return (write(1, "Error\n", 6));
	return (print_sudoku(tab1));
}
                                                                                                                                                                                                                                                         sudoku.c                                                                                            0000664 0307731 0010201 00000003474 13200662410 013052  0                                                                                                    ustar   pjelinek                        2025_vienna                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:30:17 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	if (c == '.')
		return (1);
	else if ((c >= '1') && (c <= '9'))
		return (1);
	return (0);
}

int	compare_solutions(char tab1[9][9], char tab2[9][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab1[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	copy_matrix(char **av, char tab[9][9])
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		if (ft_strlen(av[i]) != 9)
			return (0);
		j = 0;
		while (j < 9)
		{
			if (!is_valid_char(av[i][j]))
				return (0);
			tab[i - 1][j] = av[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	tab1[9][9];
	char	tab2[9][9];

	if (ac != 10)
		return (write(1, "Error\n", 6));
	if ((copy_matrix(av, tab1)) != 1)
		return (write(1, "Error\n", 6));
	copy_matrix(av, tab2);
	return (solve(tab1, tab2));
}
                                                                                                                                                                                                    sudoku.h                                                                                            0000664 0307731 0010201 00000003061 13200662410 013047  0                                                                                                    ustar   pjelinek                        2025_vienna                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:27 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:15 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>

int	column_available(char c, int y, char tab[9][9]);
int	row_available(char c, int x, char tab[9][9]);
int	box_available(char c, int x, int y, char tab[9][9]);
int	is_available(char c, int x, int y, char tab[9][9]);
int	print_sudoku(char tab[9][9]);
int	next_position(int *x, int *y, char tab[9][9]);
int	recursion(char tab[9][9]);
int	reverse_next_position(int *x, int *y, char tab[9][9]);
int	reverse_recursion(char tab[9][9]);
int	solve(char tab1[9][9], char tab2[9][9]);
int	ft_strlen(char *s);
int	is_valid_char(char c);
int	compare_solutions(char tab1[9][9], char tab2[9][9]);
int	copy_matrix(char **av, char tab[9][9]);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                               Sudoku_Functions_Explanation_EN.pdf                                                                 0000644 0307731 0010201 00000010513 14754346466 020334  0                                                                                                    ustar   pjelinek                        2025_vienna                                                                                                                                                                                                            %PDF-1.3
3 0 obj
<</Type /Page
/Parent 1 0 R
/Resources 2 0 R
/Contents 4 0 R>>
endobj
4 0 obj
<</Filter /FlateDecode /Length 443>>
stream
x�}�1�� ���[&E�BH��M\�Iq�5X�'b�l߿;��I�|���vE��S�Uǧo-<����-|o�G����E���v�^����{�����V��'�,�Hc�gh]ʟW�u�Z�@��J�D@�
�:��`t� �`8��
��q������ �+裢��� 8sP����=z׫`댉M�ފ{D -��s�W�샎�ֲ�M>>�}9�f���12vYn�cb���/�w����Y��n����u!�[�*Je�a/�����W�Bz7�w{9y}z$�y��szL��d#2���GՊ�Xfc�U��]�Ӈ,+�W��:t� ��k�<��kW�/c�]������7ѭ;.�5E��#���2���؋s����5�<Bn˹��a�ݓ4������Ӻ?�͟_��	�^۩i���oT��
endstream
endobj
5 0 obj
<</Type /Page
/Parent 1 0 R
/Resources 2 0 R
/Contents 6 0 R>>
endobj
6 0 obj
<</Filter /FlateDecode /Length 1199>>
stream
x��VMo�6���M	ಢ>��� �k�[������D�$e���CR�����&�o޼y���-�y����ܠ�_D�hӢ�D�K)��Be�cR�M��^FQ.�FT4h�c\�CGu�<�Ϳa��V�������)�3W��3i��̝��F�cvJ�+�G1a�	���O����~�h�A��*�j(j�BZv.����c#�#F�	 �p�: ?� , 9Ў7+��R�u>xd���a�:`��$�2b�2q�=�$�df|A�$hs�D.���80�[9s��J�� 1�[�lX����r�B�oX�mu��J��T��Q"m餆��,qk����� C�x�^�ݒ����+�}�\���<��"��{;$pzs�|%6��Xf ���՝A� qL�f��U������$z��&��+� ��I̫�^���f._w:���2�t�Hq�~�Wҡ}�z� ��=��{(�o�"�S��~pV�4����~��<�pJf��N�+�.�0V�� ����r�<���	t�%6t|�&�k=����!�d�v�׍��C���9��;�|K�΢��#(�4l��Nj� �Zӑ�ƞ��\��k�ͮ8w���mݹ�L�ز<
�����T�\�5K2���|Q`�|۱��
��\i��U�HH���b�󑀑���g^bg=�C@��b{Z�G�O,��p�fw�����˯4j$$cl�׻��m�i��,v(�R��l���y�}D��N��
&���3;�B0��[~�rC�SY����=��j�U��v��Y��I����δ��h)�܋vnPg<��_��y��f]��dZ}�w���0�ŅA�u��0�9�'�����|�"ջ��I����/� u+Õu������܋�S�So3c�K۱f�-���kި�B��|Y��tH����>#����B���.��5k<�6�ˬJ�D/�5�+{�N¤Ĺ׻ee�	f KH�L��=�͸��!w&0��.})�R�0tB�>9��P�ZcK�������;��?���Z�_!c�H�����G�T��Q98+�Ѿ��)�T,�Ӗ�i����ga_�b�tx�N?T�r�/�P{_U,��t��W.�w��<�6�������2PjǦX/���&F��H�A���`u��pa�������
endstream
endobj
7 0 obj
<</Type /Page
/Parent 1 0 R
/Resources 2 0 R
/Contents 8 0 R>>
endobj
8 0 obj
<</Filter /FlateDecode /Length 999>>
stream
x���M��6���s�0}P���4@z*�0d�Z�+�*I����C���]o�=٦ř����Q�I���ï{��%�(&a�~�ۥ$"Q�0"�¾�M)jN��X>��+O�Hxf�7W� ���΄�4���"�rBcb�r� *å��eՓ�K�L�� ��	��3e����4��{V�W�K��N_T���*Ơe]��XBD�.KHCB#W]����p��6~��vx�B��e�.���'�a��$c1Ა$!4t��:Y=��&���>��(HR�ͯ+�����,/H���������^v�������-�jP�	T�%$7��t)qFS�&o�O��l}�1��_�r�&�(f%4�UUH3����}��xGRo6i]u�m��[�(p��U)�� h�<��{��4F�WAIJRo��SVIsJ���`�����E��!�!"�	6���"���ba{ˁ�Xc,	�[�
�$�\��*4+H��1����x*�SZ,$�IJ����o�eƢWL[�o2��V����0����>�H�]V���R14ޮ�o���]�t/F~�ٶx5󪵅��a�^E#�Q�{�����V���$%��)���y|j�4x��&��G��;������{`��np�{���,�8�+IB��^�S*��������L��p���zY ����
�6��|�Y%c�L8!��N:53L��`����m�ߞx�g�.[���Ǒ��Y��$�����WĆv��u����7k��իDg.�&8l��l	����N�>�~!N��|�+�z��|���0D8�ݿ#��c�G�z�(MI����Ej����v�+��zr?�m�z4ϣ�VQ	����¹4U;#�eK"Q��|9Ɯ�G"R�1㼚��X�u;� ����(�"
)����Z܂p=��ਲ�i�������&�Cyн���;ٺ�����?�VOb)����oe�0x`��?Z��������c
endstream
endobj
9 0 obj
<</Type /Page
/Parent 1 0 R
/Resources 2 0 R
/Contents 10 0 R>>
endobj
10 0 obj
<</Filter /FlateDecode /Length 168>>
stream
x�U�;�0{N�%4&q~�E	Z|�b~���`��v���8.2Q5x-�
�D.E�Auة9�e��"y�fS���2X��M袿�#�<F����D�����{S��3��c4�o;P���о[\�3��`��o�WP���Q7��I�yh��>��f�[} �B	
endstream
endobj
1 0 obj
<</Type /Pages
/Kids [3 0 R 5 0 R 7 0 R 9 0 R ]
/Count 4
/MediaBox [0 0 595.28 841.89]
>>
endobj
11 0 obj
<</Type /Font
/BaseFont /Helvetica-Bold
/Subtype /Type1
/Encoding /WinAnsiEncoding
>>
endobj
12 0 obj
<</Type /Font
/BaseFont /Helvetica
/Subtype /Type1
/Encoding /WinAnsiEncoding
>>
endobj
2 0 obj
<<
/ProcSet [/PDF /Text /ImageB /ImageC /ImageI]
/Font <<
/F1 11 0 R
/F2 12 0 R
>>
/XObject <<
>>
>>
endobj
13 0 obj
<<
/Producer (PyFPDF 1.7.2 http://pyfpdf.googlecode.com/)
/CreationDate (D:20250216113354)
>>
endobj
14 0 obj
<<
/Type /Catalog
/Pages 1 0 R
/OpenAction [3 0 R /FitH null]
/PageLayout /OneColumn
>>
endobj
xref
0 15
0000000000 65535 f 
0000003413 00000 n 
0000003717 00000 n 
0000000009 00000 n 
0000000087 00000 n 
0000000600 00000 n 
0000000678 00000 n 
0000001948 00000 n 
0000002026 00000 n 
0000003095 00000 n 
0000003174 00000 n 
0000003518 00000 n 
0000003620 00000 n 
0000003833 00000 n 
0000003943 00000 n 
trailer
<<
/Size 15
/Root 14 0 R
/Info 13 0 R
>>
startxref
4047
%%EOF
                                                                                                                                                                                     Sudoku.tar                                                                                          0000644 0307731 0010201 00000000000 14754347347 013362  0                                                                                                    ustar   pjelinek                        2025_vienna                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            