// Graphs
// Graphs are represented by an ordered pair of a set of nodes(vertices) V and a set of edges E, something like G = (V,E)
// Edges can weighted/unweighted and undirected/directed
// Examples of graphs in real life are Social Media Networks, World Wide Web, Intercity Road Network, etc...

// Properties of Graphs
// Edges can be also be self-loop(an edge directing to itself) and multi-edge/parallel(2 edges from 1 vertice pointing to same vertice)
// A simple graph is a graph where there are no self-loof/parallel edges
// In a simple graph, the max number of edges is n(n-1) if it is a Digraph or (n(n-1))/2 if it is a Undirected Graph
// A walk is a sequence of vertices where each adjacent pair is connected by an edge
// A path is a walk in which no vertices(and thus no edges) are repeated
// A trail is a walk in which no edges are repeated
// A closed walk is a walk where we start and end at the same vertex
// A simple cycle is a closed walk where no repetition occurs except at start and end
// A acyclic graph is a graph with no cycle

// Strongly Connected Graphs are graphs are graphs where there is a path from any vertex to any other vertex