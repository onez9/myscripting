#
#   2--0--6--7   1--9   5 10--11
#   |  |  |               |
#   3--4  8               12 
#
n = 13  # количество вершин
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
s = 0

visited = [False] * n
print(visited)

# все вершины доступные из компанента связности
cs = 1
def dfs(v):  # dfs is an acronym for "depth-first search"
    visited[v] = True
    for w in adj_list[v]:  # переменная w пробегает всех соседей вершины v
        if not visited[w]:
            dfs(w)


dfs(s)

print(visited)
for v in range(n):
    if not visited[v]:
        cs += 1
        dfs(v)



print(cs)
print(visited)
print('Колличество вершин: {0}'.format(visited.count(True)))






























