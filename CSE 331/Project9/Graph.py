import random

# Custom Graph error
class GraphError(Exception): pass


class Graph:
    """
    Graph Class ADT
    """

    class Edge:
        """
        Class representing an Edge in the Graph
        """
        __slots__ = ['source', 'destination']

        def __init__(self, source, destination):
            """
            DO NOT EDIT THIS METHOD!
            Class representing an Edge in a graph
            :param source: Vertex where this edge originates
            :param destination: ID of Vertex where this edge ends
            """
            self.source = source
            self.destination = destination

        def __eq__(self, other):
            return self.source == other.source and self.destination == other.destination

        def __repr__(self):
            return f"Source: {self.source} Destination: {self.destination}"

        __str__ = __repr__

    class Path:
        """
        Class representing a Path through the Graph
        """
        __slots__ = ['vertices']

        def __init__(self, vertices=[]):
            """
            DO NOT EDIT THIS METHOD!
            Class representing a path in a graph
            :param vertices: Ordered list of vertices that compose the path
            """
            self.vertices = vertices

        def __eq__(self, other):
            return self.vertices == other.vertices

        def __repr__(self):
            return f"Path: {' -> '.join([str(v) for v in self.vertices])}\n"

        __str__ = __repr__

        def add_vertex(self, vertex):
            """
            Add a Vertex id to the path
            :param vertex: vertex ID
            :return: None
            """
            self.vertices.append(vertex)

        def remove_vertex(self):
            """
            Remove the most recently added Vertex id from the path
            :return: None
            """
            if len(self.vertices) > 0:
                self.vertices.pop()

        def last_vertex(self):
            """
            Return the last Vertex id added to the path
            :return: last vertex ID of Path
            """
            if len(self.vertices) > 0:
                return self.vertices[-1]

        def is_empty(self):
            """
            Check if the path is empty
            :return: True if empty, False otherwise
            """
            return len(self.vertices) == 0

    class Vertex:
        """
        Class representing a Vertex in the Graph
        """
        __slots__ = ['ID', 'edges', 'visited', 'fake']

        def __init__(self, ID):
            """
            Class representing a vertex in the graph
            :param ID : Unique ID of this vertex
            """
            self.edges = []
            self.ID = ID
            self.visited = False
            self.fake = False

        def __repr__(self):
            return f"Vertex: {self.ID}"

        __str__ = __repr__

        def __eq__(self, other):
            """
            DO NOT EDIT THIS METHOD
            :param other: Vertex to compare
            :return: Bool, True if same, otherwise False
            """
            if self.ID == other.ID and self.visited == other.visited:
                if self.fake == other.fake and len(self.edges) == len(other.edges):
                    edges = set((edge.source.ID, edge.destination) for edge in self.edges)
                    difference = [e for e in other.edges if (e.source.ID, e.destination) not in edges]
                    if len(difference) > 0:
                        return False
                    return True

        def add_edge(self, destination):
            """
            Add an edge to the Vertex given the id of the destination Vertex
            :param destination: ID of destination vertex
            :return:
            """
            self.edges.append(Graph.Edge(self, destination))

        def degree(self):
            """
            Return the number of outgoing edges (degree) of the Vertex
            :return: Degree of vertex
            """
            return len(self.edges)

        def get_edge(self, destination):
            """
            Returns the Edge that goes to a specified destination node
            :param destination: ID of destination node
            :return: Edge the goes to destination node
            """
            for edge in self.edges:
                if edge.destination == destination:
                    return edge
            return None

        def get_edges(self):
            """
            Returns a list of all of the edges
            :return: list of all edges of vertex
            """
            return self.edges

        def set_fake(self):
            """
            Set the vertex as a fake vertex
            :return: None
            """
            self.fake = True

        def visit(self):
            """
            Set the vertex as a visited vertex
            :return: None
            """
            self.visited = True

    def __init__(self, size=0, connectedness=1, filename=None):
        """
        DO NOT EDIT THIS METHOD
        Construct a random DAG
        :param size: Number of vertices
        :param connectedness: Value from 0 - 1 with 1 being a fully connected graph
        :param: filename: The name of a file to use to construct the graph.
        """
        assert connectedness <= 1
        self.adj_list = {}
        self.size = size
        self.connectedness = connectedness
        self.filename = filename
        self.construct_graph()

    def __eq__(self, other):
        """
        DO NOT EDIT THIS METHOD
        Determines if 2 graphs are IDentical
        :param other: Graph Object
        :return: Bool, True if Graph objects are equal
        """
        if len(self.adj_list) == len(other.adj_list):
            for key, value in self.adj_list.items():
                if key in other.adj_list:
                    if not self.adj_list[key] == other.adj_list[key]:
                        return False
                else:
                    return False
            return True
        return False

    def generate_edges(self):
        """
        DO NOT EDIT THIS METHOD
        Generates directed edges between vertices to form a DAG
        :return: A generator object that returns a tuple of the form (source ID, destination ID)
        used to construct an edge
        """
        random.seed(10)
        for i in range(self.size):
            for j in range(i + 1, self.size):
                if random.randrange(0, 100) <= self.connectedness * 100:
                    yield [i, j]

    def get_vertex(self, ID):
        """
        Returns the vertex with the specified id
        :param ID: Id of vertex to be found
        :return: vertex with specified ID
        """
        return self.adj_list.get(ID)

    def construct_graph(self):
        """
        Adds all edges to a Graph from file or generator
        :return: None
        """
        if self.filename is not None:
            try:
                file = open(self.filename, 'r')
            except OSError:
                raise GraphError()
            for line in file:
                [i, j] = line.split()
                i = int(i)
                j = int(j)
                if self.adj_list.get(i) is None:
                    self.adj_list[i] = Graph.Vertex(i)
                if self.adj_list.get(j) is None:
                    self.adj_list[j] = Graph.Vertex(j)
                if self.get_vertex(i).get_edge(j) is None:
                    self.get_vertex(i).add_edge(j)
        else:
            if 1 < self.connectedness <= 0 or self.size < 1:
                raise GraphError()
            for [i, j] in self.generate_edges():
                if self.adj_list.get(i) is None:
                    self.adj_list[i] = Graph.Vertex(i)
                if self.adj_list.get(j) is None:
                    self.adj_list[j] = Graph.Vertex(j)
                if self.get_vertex(i).get_edge(j) is None:
                    self.get_vertex(i).add_edge(j)

    def BFS(self, start, target):
        """
        Breadth First Search given a start ID, find a path to the target ID
        :param start: Id of vertex to start from
        :param target: Id of vertex to find
        :return: Path from start to target
        """
        for (ID, vertex) in self.adj_list.items():
            vertex.visited = False
        previous = {start : None}
        level = [start]

        while len(level) > 0:
            next_level = []
            for current in level:
                if current == target:
                    return self.backtrack(start, target, previous)
                vertex = self.get_vertex(current)
                vertex.visited = True
                for edge in vertex.get_edges():
                    if not self.get_vertex(edge.destination).visited and edge.destination not in next_level:
                        previous[edge.destination] = current
                        next_level.append(edge.destination)
            level = next_level
        path = Graph.Path()
        return path

    def DFS(self, start, target, path=Path()):
        """
        Depth First Search with the same return specifications as BFS
        :param start: Id of vertex to start from
        :param target: Id of vertex to find
        :param path: Path to add to
        :return: Path from start to target
        """
        vertex = self.get_vertex(start)
        if not vertex.visited:
            path.add_vertex(start)
            if path.last_vertex() == target:
                return path
            vertex.visited = True
            for edge in vertex.get_edges():
                if self.DFS(edge.destination, target, path) is None \
                        and path.last_vertex() != start and path.last_vertex() != target:
                    path.remove_vertex()
                if path.last_vertex() == target:
                    return path

    def backtrack(self, start, end, previous_map):
        """
        Creates a path from map of previous adjacency's
        :param start: Id of start vertex
        :param end: Id of target vertex
        :param previous_map: Map containing previous adjacency's
        :return: Path from start to target
        """
        if start == end:
            path = Graph.Path()
            return path
        current = end
        result = []
        path = Graph.Path()
        while current is not None:
            result.append(current)
            current = previous_map.get(current)
        for _ in range(len(result)):
            path.add_vertex(result.pop())
        return path


def fake_emails(graph, mark_fake=False):
    """
    Finds all fake vertices in the Graph, sets them to be fake, and adds their IDs to a list
    :param graph: Graph to search from
    :param mark_fake: Sets vertexes to fake if True
    :return: List of fake ID's
    """
    result = []
    for (ID, vertex) in graph.adj_list.items():
        if vertex.degree == 0:
            result.append(ID)
            if mark_fake:
                vertex.set_fake()

    def check_fake_emails(start, emails=list()):
        """
        Given a start Vertex ID, find all fake email addressses that can be reached from that ID and remove the edge
        connecting to the fake address.
        :param start: Vertex ID to start from
        :param emails: List of email addresses
        :return: None
        """
        print(start, emails)
        print(check_fake_emails)

