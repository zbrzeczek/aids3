//
// Created by Zuzanna Brzęczek on 30/05/2024.
//

#include "Vertex.h"

Vertex::Vertex() {
    degree = 0;
    relations = nullptr;
}

int Vertex::getDegree() {
    return degree;
}

int Vertex::getRelation(int index) {
    return relations[index];
}

void Vertex::addRelation(int value, int index) {
    relations[index] = value;
}

void Vertex::setDegree(int deg) {
    degree = deg;
    relations = new int[deg];
}


Vertex::~Vertex() {

}
