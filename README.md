# graphs_isTree
Написать программу на с++ для университета.
Известно, что граф - не дерево. Проверить, можно ли удалить из него одну вершину (вместе с индидентными ей рёбрами), чтобы в результате получилось дерево
Граф реализовать 2-мя способами (матрицей смежности и матрицей весов)
Все оформить в виде классов. Все данные считывать из файла

# input
В файл input.txt первой цифрой ввести количество вершин, остальные цифры это связи между вершинами.  
Граф считается ориентированным.  
Можно вводить в input.txt, как матрицу смежности, так и матрицу весов. Где нет связи, нужно писать 0.  
## Пример:
8  
0 1 1 0 0 0 0 1  
0 0 0 1 0 0 0 0  
0 0 0 1 0 0 0 0  
0 0 0 0 1 0 0 0  
0 0 0 0 0 1 1 0  
0 0 0 0 0 0 0 0  
0 0 0 0 0 0 0 0  
0 0 0 0 0 0 0 0  
