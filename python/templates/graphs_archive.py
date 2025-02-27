### CLASS NOTATION
class Solution:
    def dfs(self,node,vis,graph):
        vis[node]=True
        for neigh in graph[node]:
            if vis[neigh]:continue
            self.dfs(neigh,vis,graph)
    def someFunction(self, adj):
        n=len(adj)
        vis=[False]*n
        self.dfs(0,vis,adj)

### CYCLE DETECTION
## UNDIRECTED
# simple detection
def detect_cycle_undirected(graph):
    n=len(graph)
    vis=[False]*n
    
    def dfs(node,par=-1):
        vis[node]=True
        for neigh in graph[node]:
            if neigh==par:continue
            if vis[neigh] or dfs(neigh,node):return True
        return False
        
    for i in range(n):
        if not vis[i] and dfs(i):return True
    
    return False

# 1 vis for all dfs
def detect_cycle_undirected(graph): # returns a list
    n=len(graph)
    isCycleNode=[-1]*n
    
    def dfs(node,par=-1):
        if isCycleNode[node]!=-1:return isCycleNode[node]
        isCycleNode[node]=0
        for neigh in graph[node]:
            if neigh==par:continue
            if isCycleNode[neigh]==0 or dfs(neigh,node):
                isCycleNode[node]=1
                break
        return isCycleNode[node]
        
    for i in range(n):
        if isCycleNode[i]!=-1:continue
        dfs(i)
    
    return isCycleNode

# first code
def detect_cycle_undirected(graph): # returns a list ...
    n=len(graph)
    isCycleNode=[-1]*n
    
    def dfs(node,par=-1):
        if isCycleNode[node]!=-1:return isCycleNode[node]
        isCycleNode[node]=0
        for neigh in graph[node]:
            if neigh==par:continue
            if isCycleNode[neigh]==0 or dfs(neigh,node):
                isCycleNode[node]=1
                break
        return isCycleNode[node]
        
    for i in range(n):
        if isCycleNode[i]!=-1:continue
        dfs(i)
    
    return isCycleNode


# simple detection
def detect_cycle_directed(graph): # returns existence of cycle
    n=len(graph)
    vis=[False]*n
    
    def dfs(node):
        vis[node]=True
        for neigh in graph[node]:
            if neigh==node or vis[neigh] or dfs(neigh):
                return True
        vis[node]=False
        return False
        
    for i in range(n):
        if dfs(i):return True
    return False

# memoisation
def detect_cycle_directed(graph): # returns a list
    n=len(graph)
    isCycleNode=[-1]*n
    vis=[False]*n
    
    def dfs(node):
        if vis[node]:return True
        if isCycleNode[node]!=-1:return isCycleNode[node]
        vis[node]=True
        hasCycle=0
        for neigh in graph[node]:
            if neigh==node or vis[neigh] or dfs(neigh):
                hasCycle=1
                break
        vis[node]=False
        isCycleNode[node]=hasCycle
        return hasCycle
        
    for i in range(n):
        dfs(i)

    return isCycleNode

# no vis 
def detect_cycle_directed(graph):
    n=len(graph)
    # -1->not vis, 0->vis and no cycle, 1->cycle and in recursion stack
    isCycleNode=[-1]*n
    
    def dfs(node):
        if isCycleNode[node]==1:return True
        if isCycleNode[node]==0:return False
        isCycleNode[node]=1
        for neigh in graph[node]:
            if neigh==node or dfs(neigh):return True
        isCycleNode[node]=0
        return False
        
    for i in range(n):
        if isCycleNode[i]==-1:dfs(i)
    return isCycleNode


# long bipartite dfs
def isBipartite(n,graph): # returns true for all even length cycles else false
    colors=[-1]*n
    def dfs(node,color=0):
        if colors[node]!=-1:return False
        colors[node]=color
        for neigh in graph[node]:
            if colors[neigh]==color or dfs(neigh,color^1):return True
        return False
    for i in range(n):
        if dfs(i):return False
    return True