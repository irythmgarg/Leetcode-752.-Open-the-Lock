# Leetcode-752.-Open-the-Lock
# 🚀 Dijkstra Path Edge Checker & Lock Puzzle Solver

This repository includes two C++ solutions:
1. **Dijkstra-based edge validator** to find edges that lie on any shortest path.
2. **Open Lock puzzle solver** using Breadth-First Search (BFS).

---

## 🧩 Problem 1: Dijkstra Path Edge Checker
Given a graph with `n` nodes and weighted edges, determine for each edge if it lies on **any shortest path** from node `0` to node `n-1`.

### ✅ Example:
```cpp
n = 5
edges = {{0,1,1}, {1,2,1}, {0,2,2}, {2,3,1}, {3,4,1}, {2,4,2}}
```
**Output:**
```cpp
[true, true, true, true, true, true]
```

### ⚙️ Approach
- Run **Dijkstra's algorithm** from `0` to all nodes → `distFromStart`
- Run **Dijkstra's algorithm** from `n-1` to all nodes → `distFromEnd`
- For each edge `(u, v, cost)`, check if:
  - `distFromStart[u] + cost + distFromEnd[v] == distFromStart[n-1]`
  - or `distFromStart[v] + cost + distFromEnd[u] == distFromStart[n-1]`

### 💡 Key Concepts
- Dijkstra's Algorithm
- Edge validation through path reconstruction

### ⏱️ Time & Space Complexity
- **Time Complexity:** O(E * log V)
- **Space Complexity:** O(V + E)

---

## 🧩 Problem 2: Open Lock Puzzle Solver

Given a lock represented as a 4-digit string (e.g., `"0000"`), a list of deadends, and a target, determine the **minimum number of moves** to reach the target. Each move involves rotating one wheel up or down.

### ✅ Example:
```cpp
deadends = {"0201","0101","0102","1212","2002"}
target = "0202"
```
**Output:**
```cpp
6
```

### ⚙️ Approach
- Treat the problem as a shortest path problem using **Breadth-First Search (BFS)**
- Start from `"0000"`, and for every digit position (0 to 3):
  - Rotate up (next digit)
  - Rotate down (previous digit)
- Skip already visited states and deadends
- Return number of moves when the target is found

### 💡 Key Concepts
- BFS for shortest path in unweighted graphs
- Avoiding revisits using `unordered_set`

### ⏱️ Time & Space Complexity
- **Time Complexity:** O(10^4) → all combinations of 4-digit lock
- **Space Complexity:** O(10^4) → visited states and queue


```

---

## 👨‍💻 Author
Crafted with clean logic to solve pathfinding and lock problems efficiently 🚀

