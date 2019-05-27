#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {

private:
    vector<vector<int>> a;
public:

    // Конструктор графа, где принимаем название файла
    Graph(string file) {
        this->scan(file);
    }

    // Пустой граф с N вершинами
    Graph(int N = 0) {
        a.resize(N);
        for (int i = 0; i < N; ++i){
            a[i].resize(N);
            fill(a[i].begin(),a[i].end(),0);
        }
    }

    vector<int> operator[](int index) {
        return getRow(index);
    }

    // Получить строку
    vector<int> getRow(int index) {
        if (index >= 0 && index < a.size())
            return a[index];
        return {0};
    }

    // Прочитать граф с файла
    void scan(string file){
        ifstream fin(file);
        int N;
        fin >> N;
        a.resize(N);
        for (int i = 0; i < N; ++i){
            a[i].resize(N);
            for (int j = 0; j < N; ++j) {
                fin >> a[i][j];
            }
        }
        fin.close();
    };

    // Вывести граф на консоль
    void print() {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    /*
     * Модернизоранный поиск в глубину, в котором при прохождении вершин мы их считаем и выводим количество,
     * но если попадаем в вершину в которой были, то значит граф цикличный и выводим 0, т.к. нам нужен ацикличный граф.
    */
    int dfs(int u, vector<bool> &visited){
        int visitedVertices = 1;
        visited[u] = true;                    // помечаем вершину как пройденную
        for (int v = 0; v < a.size(); v++) {
            if (a[u][v]) { // Проверяем есть ли путь к вершине
                if (not visited[v]) {                       // проверяем, не находились ли мы ранее в выбранной вершине
                    visitedVertices += this->dfs(v, visited); // Если не находились, считаем количество пройденных вершин
                } else {                                   // Если находились, значит граф цикличный
                    return 0;
                }
            }
        }
        return visitedVertices;
    }

    /* Проверяем является ли граф деревом,
     * Дерево — это связный ациклический граф.
     * Если у нас количество пройденных вершин равно всем существующим, значит мы прошли все вершины единожды и это дерево.
    */
    bool isTree(){
        vector<bool> visited(a.size(), false);
        return (this->dfs(0, visited) == a.size());
    }

    // Удаление одной вершины
    void removeVertice(int vertice){
        if(vertice >= a.size())
            return;

        for (int i = 0; i < a.size() - 1; ++i) {
            int shiftI = ((i < vertice) ? 0 : 1); // При удалении у нас происходит сдвиг матрицы, до удаляемой вершины мы не сдвигаем, после сдвигаем
            for (int j = 0; j < a.size() - 1; ++j) {
                int shiftJ = ((j < vertice) ? 0 : 1);
                a[i][j] = a[i + shiftI][j + shiftJ];
            }
        }

        for(int i = 0; i < a.size(); ++i) {
            a[i].pop_back();
        }
        a.pop_back();

    }

    // Количество вершин
    int size(){
        return a.size();
    }

};