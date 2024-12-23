import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n_str = sys.stdin.readline().strip()
    while n_str == '':
        n_str = sys.stdin.readline().strip()
    n, d, l = map(int, n_str.split())
    n = int(n)
    d = int(d)
    l = int(l)

    if d >= n or l < 2 or l > n - d + 1:
        print(-1)
        continue

    max_leaves = n - d + 1
    if l > max_leaves:
        print(-1)
        continue

    edges = []
    if d == 1:
        for i in range(2, n + 1):
            edges.append((1, i))
    elif d == 2:
        for i in range(2, n + 1):
            edges.append((1, i))
    else:
        for i in range(1, d + 1):
            edges.append((i, i + 1))
        node_counter = d + 2

        s = n - l - d + 1

        extra_nodes = n - (d + 1)
        if s >= 1 and node_counter <= n:
            edges.append((1, node_counter))
            node_counter += 1
            extra_nodes -= 1
        if s == 2 and node_counter <= n:
            edges.append((d + 1, node_counter))
            node_counter += 1
            extra_nodes -= 1

        internal_nodes = [i for i in range(2, d + 1)]
        num_internal_nodes = len(internal_nodes)
        if num_internal_nodes == 0:
            num_internal_nodes = 1

        extra_nodes_per_node = extra_nodes // num_internal_nodes
        remaining_extra_nodes = extra_nodes % num_internal_nodes

        node_idx = 0
        while node_idx < num_internal_nodes and node_counter <= n:
            current_node = internal_nodes[node_idx]
            for _ in range(extra_nodes_per_node):
                if node_counter <= n:
                    edges.append((current_node, node_counter))
                    node_counter += 1
            if remaining_extra_nodes > 0 and node_counter <= n:
                edges.append((current_node, node_counter))
                node_counter += 1
                remaining_extra_nodes -= 1
            node_idx += 1
    for u, v in edges:
        print(f"{u} {v}")