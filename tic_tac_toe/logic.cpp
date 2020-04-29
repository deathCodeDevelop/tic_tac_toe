#include "logic.h"

int Logic(char** map, bool crossColorTurn)
{
	char symbol;
	int count = 0;
	const int SIZE = 3;

	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++)
			if (map[i][j] == 'x' || map[i][j] == 'o')
				count++;
	
	if (crossColorTurn) 
		symbol = 'x';
	else
		symbol = 'o';	
	
	if (GorizontalCheck(map, symbol))
	{
		return WIN;
	}
	else if (VerticalCheck(map, symbol))
	{
		return WIN;
	}
	else if (DiagonalsCheck(map, symbol))
	{
		return WIN;
	}

	if (count == SIZE * SIZE)
		return NOBODY_WON;

	return NONE;
}

bool GorizontalCheck(char** map, char symbol)
{
	for (size_t temp = 0; temp < 3; temp++)
	{
		int count = 0;

		for (size_t i = 0; i < 3; i++)
		{
			if (map[temp][i] == symbol)
			{
				count++;
			}
		}

		if (count == 3)
		{
			return true;
		}
	}
	return false;
}

bool VerticalCheck(char** map, char symbol)
{
	for (size_t temp = 0; temp < 3; temp++)
	{
		int count = 0;

		for (size_t i = 0; i < 3; i++)
		{
			if (map[i][temp] == symbol)
			{
				count++;
			}
		}

		if (count == 3)
		{
			return true;
		}
	}

	return false;
}

bool DiagonalsCheck(char** map, char symbol)
{
	int count = 0;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (map[i][j] == symbol)
				{
					count++;
				}
			}
		}
	}

	if (count == 3)
	{
		return true;
	}
	
	count = 0;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i + j == 2)
			{
				if (map[i][j] == symbol)
				{
					count++;
				}
			}
		}
	}

	if (count == 3)
	{
		return true;
	}

	return false;
}