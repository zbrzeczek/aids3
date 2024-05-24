#include <iostream>

#include "dataStructures/Graph.h"

void inputGraph(Graph *graph){
    char input;
    int inputInt, degree = 0;

    std::cin.get(input);
    std::cout << input;
    for (int j = 0; j< graph->getVertices(); j++){
        std::cin >> inputInt;
        degree++;
        std::cin.get(input);
        while (input != '\n') {
            //std::cout << inputInt << " ";
            std::cin >> inputInt;
            degree++;
            std::cin.get(input);
        }
        graph->setDegree(degree, j);
        degree = 0;
        //std::cout << inputInt << " ";
        //std::cout << std::endl;
    }
    graph->coutDegrees();
}

int main() {
    int numGraphs, numVertices;
    char input;

    std::cin >> numGraphs;

    for(int i = 0; i < numGraphs; i++){
        std::cin >> numVertices;

        Graph newGraph(numVertices);

        newGraph.setVertices(numVertices);

        inputGraph(&newGraph);

    }

    return 0;
}
