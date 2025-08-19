import os
import io
import sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


class SegmentTree:
    def __init__(self, arr):
        n = len(arr)
        self.tree = [0] * (4 * n)
        self.build(arr, 0, 0, n - 1)

    def merge(self, a, b):
        return a + b

    def build(self, arr, node, low, high):
        mid = ((high - low) >> 1) + low
        if low == high:
            self.tree[node] = arr[mid]
        else:
            leftNode, rightNode = (node << 1) + 1, (node << 1) + 2
            self.build(arr, leftNode, low, mid)
            self.build(arr, rightNode, mid + 1, high)
            self.tree[node] = self.merge(
                self.tree[leftNode], self.tree[rightNode])

    def query(self, node, low, high, left, right):
        if high < left or right < low:
            return 0
        if (left <= low and high <= right):
            return self.tree[node]
        mid = ((high - low) >> 1) + low
        leftNode, rightNode = (node << 1) + 1, (node << 1) + 2
        leftSubtree = self.query(leftNode, low, mid, left, right)
        rightSubtree = self.query(rightNode, mid + 1, high, left, right)
        return self.merge(leftSubtree, rightSubtree)

    def update(self, node, low, high, pos, value):
        mid = ((high - low) >> 1) + low
        leftNode, rightNode = (node << 1) + 1, (node << 1) + 2
        if low == high and mid == pos:
            self.tree[node] = value
        elif pos <= mid:
            self.update(leftNode, low, mid, pos, value)
        else:
            self.update(rightNode, mid + 1, high, pos, value)
        self.tree[node] = self.merge(
            self.tree[leftNode], self.tree[rightNode])


def solve():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    # print(n, q, arr)

    segTree = SegmentTree(arr)

    output = []
    for _ in range(q):
        ty, x, y = map(int, input().split())
        if ty == 1:
            pos, value = x, y
            segTree.update(0, 0, n - 1, pos, value)
        else:
            left, right = x, y
            res = segTree.query(0, 0, n - 1, left - 1, right - 1)
            output.append(str(res))
        # sys.stdout.write(str(res) + '\n')

    sys.stdout.write("\n".join(map(str, output)) + "\n")


solve()
