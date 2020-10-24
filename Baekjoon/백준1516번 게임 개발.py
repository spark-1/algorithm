from queue import Queue

N = int(input())
structure = [0 for _ in range(N + 1)]
result = [0 for _ in range(N + 1)]
adj = [[] for _ in range(N + 1)]
indegree = [0 for _ in range(N + 1)]
Q = Queue()

for i in range(1, N + 1):
    t = input().split()
    structure[i] = int(t[0])
    for j in range(1, len(t) - 1):
        adj[int(t[j])].append(i)
        indegree[i] += 1

for i in range(1, N + 1):
    if indegree[i] == 0:
        Q.put(i)
        result[i] = structure[i]

while not Q.empty():
    now = Q.get()
    for next in adj[now]:
        result[next] = max(result[next], result[now] + structure[next])
        indegree[next] -= 1
        if indegree[next] == 0 :
            Q.put(next)

for i in range(1, N + 1):
    print(result[i])
