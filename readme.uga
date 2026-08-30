# Random Undirected Graph Analysis in C

A C program that generates random undirected graphs of different sizes and analyzes their **number of edges, vertex degrees, degree sum, and computational time**. The program also verifies the **Handshaking Theorem** for each generated graph.

## 📌 Project Overview

This project demonstrates how an undirected graph can be represented using an **adjacency matrix** and how basic graph properties can be calculated using C.

The program generates random graphs for the following numbers of vertices:

* 1000
* 2000
* 3000
* 4000
* 5000

For each graph, it calculates:

* Number of edges
* Degree of every vertex
* Sum of all vertex degrees
* `2E` (twice the number of edges)
* Computational time
* Verification of the Handshaking Theorem

## ⚙️ How the Program Works

### 1. Graph Sizes

The program stores different graph sizes in an array:

```c
int sizes[] = {1000, 2000, 3000, 4000, 5000};
```

The program processes each graph size one by one.

### 2. Random Graph Generation

A random undirected graph is generated using an **adjacency matrix**.

For every pair of different vertices, a random value (`0` or `1`) is generated:

* `1` → an edge exists
* `0` → no edge

Only the upper triangular part of the matrix is generated, and the same value is assigned symmetrically:

```text
adj[i][j] = adj[j][i]
```

This ensures that the graph is **undirected**.

### 3. Degree Calculation

The degree of each vertex is calculated by summing the values in its corresponding row of the adjacency matrix.

The program also calculates the total degree sum:

```text
Sum of Degrees = degree(0) + degree(1) + ... + degree(n-1)
```

### 4. Edge Counting

The program counts edges by checking only the upper triangular portion of the adjacency matrix.

This prevents counting the same undirected edge twice.

### 5. Handshaking Theorem Verification

The program verifies the fundamental property of an undirected graph:

```text
Sum of Degrees = 2 × Number of Edges
```

Therefore:

```text
degreeSum == 2 * edges
```

If the equality holds, the program prints:

```text
Handshaking Logic = TRUE
```

Otherwise:

```text
Handshaking Logic = FALSE
```

### 6. Computational Time

The program measures the time required for **degree calculation and edge counting** using the C `clock()` function.

The elapsed time is converted into milliseconds:

```text
time_ms = (end - start) × 1000 / CLOCKS_PER_SEC
```

## 🧠 Concepts Used

* C Programming
* Undirected Graph
* Adjacency Matrix
* Random Number Generation
* Vertex Degree
* Edge Counting
* Handshaking Theorem
* Nested Loops
* Dynamic Memory Allocation
* `calloc()`
* `free()`
* `rand()`
* `srand()`
* `time()`
* `clock()`
* Computational Time Analysis

## 💾 Dynamic Memory Allocation

The adjacency matrix and degree array are dynamically allocated using `calloc()`:

```c
int *adj = (int *)calloc(n * n, sizeof(int));
int *degree = (int *)calloc(n, sizeof(int));
```

After each graph is analyzed, the allocated memory is released using:

```c
free(adj);
free(degree);
```

## 📊 Output

For every value of `n`, the program displays:

```text
===== n = 1000 =====
Number of Edges = ...
Sum of Degrees = ...
2E = ...
Handshaking Logic = TRUE
Computational Time = ... ms
```

The exact edge count and execution time can vary because the graph is generated randomly.

## ⏱️ Complexity

For a graph with `n` vertices:

### Graph Generation

The program checks every pair of vertices:

```text
O(n²)
```

### Degree Calculation

For every vertex, the program scans all vertices:

```text
O(n²)
```

### Edge Counting

The upper triangular part of the adjacency matrix is scanned:

```text
O(n²)
```

Therefore, the overall computational complexity is:

```text
O(n²)
```

The adjacency matrix requires:

```text
O(n²)
```

memory.

## 🛠️ Requirements

* C compiler such as GCC
* Any C-supported development environment

## ▶️ How to Run

### Compile

```bash
gcc undirected_graph_analysis.c -o graph_analysis
```

### Run

**Linux / macOS:**

```bash
./graph_analysis
```

**Windows:**

```bash
graph_analysis.exe
```

## 🎯 Learning Objectives

This project was created to practice:

* Implementing graph concepts using C
* Working with adjacency matrices
* Using dynamic memory allocation
* Generating random data
* Calculating graph properties
* Verifying the Handshaking Theorem programmatically
* Measuring computational performance

## 👩‍💻 Author

**Humayra Binte Islam**

CSE Student

---

⭐ This project is part of my **C Programming Practice** repository.
