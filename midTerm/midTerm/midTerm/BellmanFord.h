#ifndef BellmanFord_h
#define BellmanFord_h

#include "List.h"
#include "Node.h"

#define INFINITE_DISTANCE INT_MAX

void DEBUG_printAllNode_And_SetInfiniteValue(List* sListPtr, int sizeOfVertex);

int* getMinDistanceUsingBellmanFord(List* weightListPtr, int sizeOfVertex, int numOftestVertex);

#endif /* BellmanFord_h */
