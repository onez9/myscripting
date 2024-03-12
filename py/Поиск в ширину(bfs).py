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



arr = int(input())
def show_key():
    print('Anime')
s = 0
start_node = 0
visited = [False] * n
queue = []
def bfs(adj_list, start_node):
    # добавляем в очередь корень
    queue.append(start_node)
    # помечаем как пройденный узел
    visited[start_node] = True

    # пока очередь не пустая
    while queue:
        # вырезаем первый элемент из очереди и записываем в node
        node = queue.pop(0)

        print(node)

        # пробегаемся по всем соседям node
        for element in adj_list[node]:
            # если сосед помечен как не пройденный то добавляем его в очередь и помечаем, как пройденный
            if visited[element] == False:
                queue.append(element)
                visited[element] = True


if __name__ == '__main__':
    bfs(adj_list, start_node)
# lst = []
# lst.append(False)
# lst.append('hello')
# lst.append(123)
# lst.append('12hello3')
# lst.append(True)
# print(lst)
# a = lst.pop()
# 
# print(lst)
# print(a)
# a = lst.pop()
# print(lst)
# print(a)
# bfs(s)
# 
# print(cs)
# print(visited)
# print('Колличество вершин: {0}'.format(visited.count(True)))







# 
# print(visited)
# class aaa:
#     def __init__(self):
#         self.data = []
# oo = []
# # все вершины доступные из компанента связности
# cs = 1
# visited = [False] * n
# def bfs(v):  # dfs is an acronym for "depth-first search"
#     while 
# 
# bfs(star)
# 










