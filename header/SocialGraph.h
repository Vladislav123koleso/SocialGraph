#pragma once

#include <iostream>

#define SIZE 10
#define VERYBIGINT 10000

class Graph
{
public:
    Graph();

    void addUser(std::string user); // добавление пользователя-вершины
    void addFriendEdge(std::string user1, std::string user2); // добавления свзяи-ребра между пользователями
    void findMinDistancesFloyd(); // алгоритм Флойда

    void printUsers();
    void printMatrix();
private:
    int getUserIndex(std::string user); // возвращаем индекс пользователя из массива пользователей

    bool friendEdgeExists(std::string user1, std::string user2); // проверка на наличие связи между пользователями
    bool userExists(std::string v); // проверка на существование пользователя

    int matrix[SIZE][SIZE]; // матрица смежности
    std::string users[SIZE]; // хранилище вершин-пользователей
    int userCount; // кол-во добавленных вершин-пользователей

};