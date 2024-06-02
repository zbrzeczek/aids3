//
// Created by Zuza on 2024-05-23.
//
#include <iostream>

#include "Graph.h"

//settery
void Graph::setVertices(int num) {
    numVertices = num;
}

void Graph::setDegree(int degree, int index) {
    degrees[index] = degree;
}

void Graph::setSorted(int deg, int index) {
    sortedDegrees[index] = deg;
}

void Graph::setVector(Vertex vertex, int index) {
    relations[index] = vertex;
}

void Graph::setReached(bool reach, int index) {
    reached[index] = reach;
}

void Graph::setBiPart(int num, int index) {
    biPart[index] = num;
}

void Graph::setColors(int col, int index) {
    colors[index] = col;
}



//gettery
int Graph::getVertices() {
    return  numVertices;
}

int Graph::getDegree(int index) {
    return degrees[index];
}

int Graph::getSorted(int index) {
    return sortedDegrees[index];
}

Vertex Graph::getVector(int index) {
    return relations[index];
}

bool Graph::getReached(int index) {
    return  reached[index];
}

int Graph::getBiPart(int index) {
    return biPart[index];
}

int Graph::getColor(int index) {
    return colors[index];
}



//other

void Graph::copyDegrees() {
    for (int i = 0; i < getVertices(); ++i) {
        sortedDegrees[i] = degrees[i];
    }
}



Graph::Graph(int num) {
    numVertices = num;
    degrees = new int[num];
    sortedDegrees = new int[num];
    reached = new bool[num];
    relations = new Vertex[num];
    biPart = new int[num];
    colors = new int[num];

    for(int i =0; i < num; i++){
        reached[i] = false;
    }
    for(int i =0; i < num; i++){
        biPart[i] = 2;
    }
    for(int i =0; i < num; i++){
        colors[i] = 0;
    }
}

Graph::~Graph() {
    delete[] degrees;
    delete[] sortedDegrees;
    delete[] reached;
    delete[] relations;
    delete[] biPart;
}

