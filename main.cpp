/*
 *
Написать программу на с++ для университета.
Известно, что граф - не дерево. Проверить, можно ли удалить из него одну вершину (вместе с индидентными ей рёбрами), чтобы в результате получилось дерево
Граф реализовать 2-мя способами (матрицей смежности и матрицей весов)
Все оформить в виде классов. Все данные считывать из файла
 */
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph graph = Graph("input.txt"); // Считываем граф с файла

    cout << "Input: " << endl;
    graph.print(); // Выводим граф, который считали

    bool checkNotTree = true;
    for(int i = 0; i < graph.size(); i++) { // Перебираем все вершины графа
        Graph tempgraph = graph; // Создаём временный граф
        tempgraph.removeVertice(i); // Удаляем вершину из временного графа
        if(tempgraph.isTree()) { // Проверяем временный граф дерево ли
            cout << "True remove vertice: " << i << endl << "Output: " << endl;
            tempgraph.print();
            checkNotTree = false;
            break;
        }
    }

    if(checkNotTree)
        cout << "False" << endl;
    return 0;
}