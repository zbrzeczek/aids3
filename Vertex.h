//
// Created by Zuzanna Brzęczek on 30/05/2024.
//

#ifndef AIDS3_VERTEX_H
#define AIDS3_VERTEX_H


class Vertex {
private:
    int *relations;
    int degree;
public:
    Vertex();

    int getRelation(int index);
    int getDegree();

    void addRelation(int value, int index);
    void setDegree(int deg);

    ~Vertex();
};


#endif //AIDS3_VERTEX_H
