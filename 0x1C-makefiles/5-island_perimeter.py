#!/usr/bin/python3
"""
    Function that returns the perimeter\
    of the island described in grid
"""


def island_perimeter(grid):
    """" Returns the perimeter of the\
    island described in grid"""
    if not len(grid):
        return 0

    perimeter = 0
    for i, g_cell in enumerate(grid):
        for j, cell in enumerate(g_cell):
            if cell:
                perimeter += 4
                if i != 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j + 1 != len(g_cell) and g_cell[j + 1] == 1:
                    perimeter -= 2

    return perimeter
