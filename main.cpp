#include <iostream>

#include "Graph.h"

#define L 0
#define R 1


bool dnsBi(Graph * graph, int side, int index){
    if (graph->getBiPart(index) == side) return false;
    else if (graph->getBiPart(index) == 2){
        side = side == L ? R : L;
        graph->setBiPart(side, index);
        for (int i = 0; i < graph->getDegree(index); i++){
            if (!dnsBi(graph, side, graph->getVector(index).getRelation(i)-1)) return false;
        }
        return true;
    }
    else return true;
}

bool allSided(int *index, Graph * graph){
    for (int i = 0; i < graph->getVertices(); i++){
        if (graph->getBiPart(i) == 2) {
            *index = i;
            return false;
        }
    }
    return true;
}

void biPart(Graph *graph){
    int side = L;
    int index = 0;
    bool output = true;

    for (int i = 0; i < graph->getVertices(); i++){
        if (graph->getDegree(i) == 0){
            graph->setBiPart(L, i);
        }
    }

    while (!allSided(&index, graph)){
        if (!dnsBi(graph, side, index)) {
            output = false;
            break;
        }
    }

    if (!output) printf("F\n");
    else printf("T\n");
}

void merge(int l, int m, int r, Graph * graph) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int* left = new int[n1];
    int* right = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        left[i] = graph->getSorted(l + i);
    for (int j = 0; j < n2; j++)
        right[j] = graph->getSorted(m+1+j);

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] >= right[j]) {
            graph->setSorted(left[i], k);
            i++;
        } else {
            graph->setSorted(right[j], k);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        graph->setSorted(left[i], k);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        graph->setSorted(right[j], k);
        j++;
        k++;
    }

    // Free the memory allocated for temp arrays
    delete[] left;
    delete[] right;
}

void sortDegrees(int l, int r, Graph * graph) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2; // Find the middle point to divide the array into two halves

    sortDegrees( l, m, graph); // Sort the first half
    sortDegrees( m + 1, r, graph); // Sort the second half

    merge(l, m, r, graph);

    /*for (int i = 0; i < getVertices() - 1; ++i) {
        for (int j = i + 1; j < getVertices(); ++j) {
            if (sortedDegrees[i] < sortedDegrees[j]) {
                // Swap the elements
                int temp = sortedDegrees[i];
                sortedDegrees[i] = sortedDegrees[j];
                sortedDegrees[j] = temp;
            }
        }
    }
     */
}


//answears
void degreeSeq(Graph *graph) {
    graph->copyDegrees();
    sortDegrees(0, graph->getVertices()-1, graph);


    for (int i = 0; i < graph->getVertices(); i++){
        std::cout << graph->getSorted(i) << " ";
    }
    std::cout << endl;
}

void dnsCompl(int *iterator, int *old, Graph * graph) {
    graph->setReached(true ,*iterator);
    for (int i = 0; i < graph->getDegree(*iterator); i++){
        if (!graph->getReached(graph->getVector(*iterator).getRelation(i) - 1)) {
            //reached[getVector(*iterator)[i]] = true;
            int current = *iterator;
            *iterator = graph->getVector(*iterator).getRelation(i) - 1;
            *old = current;
            dnsCompl(iterator, old, graph);
            *iterator = current;
        }
    }
}

bool allReached(int * iterator, Graph * graph) {
    for (int i = 0; i < graph->getVertices(); i++){
        if (!graph->getReached(i)) {
            *iterator = i;
            return false;
        }
    }
    return true;
}

void numComp(Graph *graph) {
    int iterator =0;
    int complexity = 0, old;

    for (int i = 0; i < graph->getVertices(); i++){
        if (graph->getDegree(i) == 0){
            complexity++;
            graph->setReached(true, i);
        }
    }
    while (!allReached(&iterator, graph)){
        old = iterator;
        dnsCompl(&iterator, &old, graph);
        complexity++;
    }
    printf("%d\n", complexity);
}

void complEdges(Graph *graph) {
    unsigned long long result, ver = 0, sum = 0;
    unsigned long long var = graph->getVertices();
    ver = var*(var-1)/2;

    for (int i = 0 ; i < var; i++){
        sum += graph->getDegree(i);
    }
    sum = sum/2;

    result = ver - sum;

    printf("%llu\n", result);
}



//input
void inputGraph(Graph *graph){
    int inputInt, degree = 0;

    for (int j = 0; j< graph->getVertices(); j++){
        std::cin >> degree;
        Vertex var;
        var.setDegree(degree);

        if (degree != 0) {
            for (int i = 0; i< degree; i++) {
                std::cin >> inputInt;
                var.addRelation(inputInt, i);
            }
        }

        graph->setVector(var, j);
        graph->setDegree(degree, j);
    }
}

int main() {
    int numGraphs, numVertices;

    std::cin >> numGraphs;

    for(int i = 0; i < numGraphs; i++){
        std::cin >> numVertices;

        Graph newGraph(numVertices);

        newGraph.setVertices(numVertices);

        inputGraph(&newGraph);

        degreeSeq(&newGraph);
        numComp(&newGraph);
        biPart(&newGraph);

        for (int j = 0; j < 6; j++){
            printf("?\n");
        }

        complEdges(&newGraph);
    }

    return 0;
}
