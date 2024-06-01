//
// Created by Zuza on 2024-05-23.
//

#ifndef AIDS3_GRAPH_H
#define AIDS3_GRAPH_H

#include "Vertex.h"


using namespace std;

class Graph {
private:
    int numVertices;
    int* degrees;
    int* sortedDegrees;
    bool* reached;
    Vertex *relations;
    int* biPart;
public:
    Graph(int num);

    int getVertices();
    Vertex getVector(int index);
    int getDegree(int index);
    int getSorted(int index);
    bool getReached(int index);
    int getBiPart(int index);


    void setVertices(int num);
    void setVector(Vertex vertex, int index);
    void setDegree(int degree, int index);
    void setSorted(int deg, int index);
    void setReached(bool reach, int index);
    void setBiPart(int num, int index);


    void copyDegrees();
    void sortDegrees(int l, int r);

    ~Graph();
};


#endif //AIDS3_GRAPH_H
