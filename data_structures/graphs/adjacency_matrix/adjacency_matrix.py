class Graph:
    def __init__(self, directed=True, vertices=5):
        self.directed = directed
        self.vertices = vertices
        self.edges = [[False] * vertices for _ in range(vertices)]

    def has_vertex(self, vertex):
        return 0 <= vertex < self.vertices

    def has_edge(self, vertex_1, vertex_2):
        if not self.has_vertex(vertex_1) or not self.has_vertex(vertex_2):
            return False

        if self.directed:
            return self.edges[vertex_1][vertex_2]
        return self.edges[vertex_1][vertex_2] and self.edges[vertex_2][vertex_1]

    def add_edge(self, vertex_1, vertex_2):
        if self.has_edge(vertex_1, vertex_2):
            return False

        if self.directed:
            self.edges[vertex_1][vertex_2] = True
            return True
        else:
            self.edges[vertex_1][vertex_2] = True
            self.edges[vertex_2][vertex_1] = True
        return True

    def delete_edge(self, vertex_1, vertex_2):
        if not self.has_edge(vertex_1, vertex_2):
            return False

        if self.directed:
            self.edges[vertex_1][vertex_2] = False
        else:
            self.edges[vertex_1][vertex_2] = False
            self.edges[vertex_2][vertex_1] = False
        return True

    def __str__(self):
        output = ""
        for i in range(0, self.vertices):
            for j in range(0, self.vertices):
                if self.edges[i][j]:
                    if self.directed:
                        output += f"{i} -> {j}\n"
                    else:
                        output += f"{i} -- {j}\n"

        return output


def main():

    # Basic driver code to generate the
    # directed graph 0 -> 1 -> 2

    graph = Graph()
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    print(graph)
    graph.delete_edge(0, 1)
    print(graph)


if __name__ == "__main__":
    main()
