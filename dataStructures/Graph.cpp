//
// Created by Zuza on 2024-05-23.
//
#include <iostream>

#include "Graph.h"

void Graph::setVertices(int num) {
    numVertices = num;
}

void Graph::setDegree(int degree, int index) {
    degrees[index] = degree;
}

int Graph::getVertices() {
    return  numVertices;
}

int Graph::getDegree(int index) {
    return degrees[index];
}

void Graph::coutDegrees() {
    for (int i = 0; i < getVertices(); i++){
        std::cout << degrees[i] << " ";
    }
}

Graph::Graph(int num) {
    numVertices = num;
    degrees = new int[num];
}

Graph::~Graph() {
    delete degrees;
}

