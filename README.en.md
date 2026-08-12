# 🚀 8-Week Algorithm & Coding-Test Study

[한국어](Readme.md) · [日本語](README.ja.md) · **English**

> **"Build the ability to solve Baekjoon Gold-level problems on your own, without AI help."**
>
> This study group was designed to develop the problem-solving skills that underpin web-development ability.

---

## 👥 Members
- **Member A (me):** studying frontend/backend (comfortable with C++ pointers and classes)
- **Member B (senior):** a university senior (comfortable with C++ pointers, currently taking Data Structures)

## 🎯 Goals
1. **No AI Policy:** solve every problem by hand, without help from generative AI.
2. **Master the C++ STL:** get fluent with `vector`, `sort`, `stack`, `queue`, and friends.
3. **Synergy with coursework:** run in parallel with the C-language Data Structures class to build theory and practice together.

---

## 📅 8-week curriculum roadmap

| Week | Topic | Prerequisites | Required problems (BOJ) |
| :--- | :--- | :--- | :--- |
| **1** | **C++ basics & time complexity** | Fast I/O, `vector`, the $O(N)$ notion | 2557, 15552, 10818, 2750 |
| **2** | **Basic data structures** | Stack, queue, deque (understanding the mechanics) | 10828, 10845, 10866 |
| **3** | **Brute force** | Recursion, setting base cases | 2798, 2231, 1018 |
| **4** | **Graph traversal (BFS/DFS)** | Adjacency lists, visited arrays | 1260, 2606, 2178 |
| **5** | **Binary search** | Binary search, parametric search | 1920, 2805, 1654 |
| **6** | **Greedy** | Sorting and optimal choice, proofs | 11047, 1931, 1541 |
| **7** | **Dynamic programming** | Designing recurrences, memoization | 1463, 9095, 2579 |
| **8** | **Shortest path (Dijkstra)** | Priority-queue-based shortest-path algorithms | 1753, 1916, 1504 |

---

## ⏰ Daily routine (120 min)

1. **[00:00 – 00:40] Concepts**
   - Study the week's keyword theory (blogs / YouTube)
   - Compare and contrast with the school's C-language Data Structures material
2. **[00:40 – 01:40] Solving on your own**
   - Implement the required problems on Baekjoon
   - **Tip:** if stuck for more than 30 minutes, look at a hint only and try again
3. **[01:40 – 02:00] Code review**
   - Share each other's code and discuss complexity improvements

---

## 🛠 Required C++ template (Fast I/O)
When solving in C++, always include the following so that I/O speed doesn't cause a TLE.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // I/O speed-up
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // algorithm here

    return 0;
}
```

---

## 📁 Repository layout (actual implementations)

Each weekly folder holds the Baekjoon (BOJ) solutions (`.cpp`). Below is what each folder actually contains.

> Note: because of the order things were actually implemented, the **greedy and DP weeks are swapped** relative to the roadmap above — `week6` holds DP and `week7` holds greedy.

| Folder | Topic | Representative files (problems) |
| :--- | :--- | :--- |
| `week1/` | **Sorting & time complexity** | `timeComplex` (15552 Fast I/O), `sortWithVector` (2750), `minMax` (10818), `ageSort` (10814), `coorSort` (11650) |
| `week2/` | **Basic data structures (stack, queue)** | `stack`, `queue`, `stackseq` (stack sequence), `yosefus` (Josephus) |
| `week3/` | **Brute force & backtracking** | `blackjack` (2798 — three implementations compared: permutations / combinations / triple loop), `lotto`, `nm` (N and M), `nqueen` (N-Queens) |
| `week4/` | **Graph traversal (BFS, DFS)** | `dfsbfs` (1260), `mindist` (maze), `tomato`, `cabbage` (organic cabbage), `worm_bfs` / `worm_dfs` (virus) |
| `week5/` | **Binary & parametric search** | `binary_Search` (1920), `wood` (cutting trees), `lan` (cutting LAN cables), `router` (installing routers) |
| `week6/` | **Dynamic programming** | `fibo` (Fibonacci), `make1` (make it 1), `123sum` (1·2·3 addition), `2ntile` (2×n tiling), `rgb` (RGB street), `baggage` (knapsack) |
| `week7/` | **Greedy & heaps** | `coin_zero` (coin 0), `meeting` (meeting rooms), `cards` (sorting cards, min-heap), `maxheap` |
| `week8/` | **Shortest path (Dijkstra, Floyd)** | `mindist` (1753), `mindist_bus` (1916), `mindist_spec` (1504, specific shortest path), `floyd` (Floyd–Warshall) |

Every solution was written by hand under the study's **No AI Policy**, and some — such as the blackjack problem in the brute-force week — implement the same problem several ways (permutations, combinations, plain loops) to compare their time complexity.

---

## 👤 Contribution & development environment

| Item | Detail |
|---|---|
| **Contribution share** | **100%** (solo development) |
| **Commits** | 15 / 15 (mine / all human commits) |
| **Contributors** | 1 |

<sub>Counting basis (snapshot as of 2026-08-12): commits reachable from **every branch** on origin (merge commits and empty commits excluded), counted by commit author email with one person’s multiple addresses merged; bot and automation commits are excluded.</sub>
