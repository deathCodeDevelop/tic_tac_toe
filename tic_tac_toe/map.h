#pragma once

char** CreateNewMap(int rows, int cols);
void CopyMap(char** map, char** newMap, size_t size);
void DeleteMap(char** map, size_t size);