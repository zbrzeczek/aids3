//
// Created by Zuza on 2024-05-23.
//

#ifndef AIDS3_GRAPH_H
#define AIDS3_GRAPH_H


class Graph {
private:
    int numVertices;
    int* degrees;
public:
    Graph(int num);

    int getVertices();
    int getDegree(int index);

    void setVertices(int num);
    void setDegree(int degree, int index);

    void coutDegrees();

    ~Graph();
};


#endif //AIDS3_GRAPH_H
