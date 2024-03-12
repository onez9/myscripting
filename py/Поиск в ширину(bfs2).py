
import collections


# BFS algorithm
def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:
        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        # If not visited, mark it as visited, and
        # enqueue it

        for neighbour in graph[vertex]:

            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    # graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    adj_list = [[2, 4, 6],
            [9],
            [0, 3],
            [2, 4],
            [0, 3],
            [],
            [0, 7, 8],
            [6],
            [6],
            [1],
            [11,12],
            [10],
            [10]
            ]

    print("Following is Breadth First Traversal: ")
    bfs(adj_list, 0)
