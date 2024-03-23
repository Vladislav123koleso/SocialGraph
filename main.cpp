#include "cpp/SocialGraph.cpp"

int main()
{
    Graph graph;

    graph.addUser("Stan");
    graph.addUser("Terra");
    graph.addUser("Lui");
    graph.addUser("Daniel");
    graph.addUser("Fly");
    graph.addUser("Cate");

    graph.addFriendEdge("Terra", "Stan");
    graph.addFriendEdge("Terra", "Lui");
    graph.addFriendEdge("Stan", "Fly");
    graph.addFriendEdge("Fly", "Cate");
    graph.addFriendEdge("Cate", "Daniel");

    graph.printUsers();
    graph.printMatrix();
    
    std::cout << std::endl;

    graph.findMinDistancesFloyd();


    return 0;   
}