#include "../header/SocialGraph.h"

Graph :: Graph()
{
    for(int i = 0;i < SIZE; i++)
    {
        for(int j = 0;j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
    userCount = 0;
}

bool Graph :: userExists(std::string user)
{
    for(int i = 0;i < SIZE;i++)
    {
        if(user == users[i])
        {
            return true;
        }
    }
    return false;
}

bool Graph :: friendEdgeExists(std::string user1, std::string user2)
{
    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0; j < SIZE;j++)
        {
            if(matrix[i][j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}

int Graph :: getUserIndex(std::string user)
{
    for(int i = 0;i < SIZE;i++)
    {
        if(users[i] == user)
        {
            return i;
        }
    }
    return -1;
}

void Graph :: addUser(std::string user)
{
    users[userCount++] = user;
}

void Graph :: addFriendEdge(std::string user1, std::string user2)
{
    if(userExists(user1) && userExists(user1))
    {
        int index1 = getUserIndex(user1);
        int index2 = getUserIndex(user2);

        matrix[index1][index2] = 1;
        matrix[index2][index1] = 1;
    }
}


void Graph :: findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей

    // инициализация матрицы
    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0; j < SIZE;j++)
        {
            if(i == j)
            {
                weights[i][j] = 0;
            }
            else
            {
                if(matrix[i][j] == 0)
                {
                    weights[i][j] = VERYBIGINT;    
                }
                else
                {
                    weights[i][j] = matrix[i][j];
                }

            }
        }
    }

    for(int k = 0;k < SIZE;k++)
    {
        int ck = getUserIndex(users[k]);

        for(int i = 0; i < SIZE; i++)
        {
            if(i == k)
            {
                continue;
            }
            int ci = getUserIndex(users[i]);
        
            for(int j = 0; j < SIZE; j++)
            {
                if(j == k)
                {
                    continue;
                }
                int cj = getUserIndex(users[j]);

                if(weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
                {
                    // пересчет матрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for(int i = 0; i < userCount;i++)
    {
        for(int j = 0; j < userCount; j++)
        {
            std::cout << weights[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < userCount;i++)
    {
        for(int j = 0; j < userCount;j++)
        {
            if(weights[i][j] == 3)
            {
                std::cout << users[i] << " и " << users[j] << "  знакомы через 3 рукопожатия" << std::endl;
            }
        }
    }
}

void Graph :: printUsers()
{
    for(int i = 0;i < SIZE;i++)
    {
        std::cout << users[i] << " "; 
    }
    std::cout << std::endl;
}

void Graph :: printMatrix()
{
    // for(int i = 0; i < SIZE;i++)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl; 
    for(int j = 0;j < SIZE;j++)
    {
        // std::cout << j << " ";
        for(int i = 0;i < SIZE;i++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}