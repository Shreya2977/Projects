# 🚗 **Ride-Sharing Route Optimizer**

## **Graph Algorithms – C++ (Dijkstra, Floyd-Warshall, Multi-Source Dijkstra)**

### A high-performance ride-sharing route optimization system that simulates how apps like Uber/Ola compute shortest routes, handle traffic, and select the best pickup point.
The project uses advanced graph algorithms and models the city map as a weighted graph.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🚀 Features

✔ Shortest Path Computation
Uses Dijkstra’s Algorithm to compute the fastest route from a driver’s location to any destination.

✔ All-Pairs Shortest Path
Implements Floyd-Warshall to generate a distance table between every pair of nodes in the city.

✔ Best Pickup Point Suggestion
Uses Multi-source Dijkstra to determine the nearest passenger when multiple passengers are waiting.

✔ Traffic-Aware Weights
Roads are represented with weighted edges, simulating traffic or travel time.

✔ Modular & Extendable Code
-Easily expandable to include:
-multiple drivers
-real map datasets
-congestion detection
-dynamic re-routing

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🧠 Algorithms Used

🔹 Dijkstra’s Algorithm
- Single-source shortest path
- Uses priority queue (min-heap)
- Time complexity: O(E log V)

🔹 Floyd-Warshall Algorithm
- All-pairs shortest path
- Generates full distance matrix
- Time complexity: O(V³)
- Useful when many distance queries occur repeatedly.

🔹 Multi-Source Dijkstra
- Finds nearest passenger/hotspot/charging station
- Insert all starting sources in priority queue
- Time complexity: O(E log V)
- Used to suggest optimal pickup point in ride-sharing systems.



--------------------------------------------------------------------------------------------------------------------------------------------

📁 Project Structure

RideSharingRouteOptimizer/
│
├── src/
│   ├── main.cpp        # Main program
│   ├── Graph.h         # Graph class & algorithms
│
├── data/
│   └── sample_graph.txt  # Example city map (optional)
│
├── README.md
└── LICENSE (optional)


--------------------------------------------------------------------------------------------------------------------------------------------------------------------

🧪 Sample Output

===== DIJKSTRA: Shortest path from Node 0 =====
0 -> 0 = 0
0 -> 1 = 3
0 -> 2 = 2
0 -> 3 = 5
0 -> 4 = 7
0 -> 5 = 10

===== BEST PICKUP POINT =====
Nearest passenger: Node 3


---

🧰 Requirements

C++17 or higher

VS Code / CLion / CodeBlocks

g++ compiler

(Optional) Git Bash for version control


Compile using:

g++ main.cpp -o route_optimizer
./route_optimizer


---

📚 How It Works

✔ Build graph (adjacency list)
Each node is a location, each edge is a road with weight = travel time.

✔ Run Dijkstra
Find distance from driver → all nodes.

✔ Run Multi-Source Dijkstra
Find which passenger is closest.

✔ (Optional) Use Floyd-Warshall
Answer "distance between any two points" instantly.

🛠 Future Extensions

- GPS coordinate integration
- Real-time traffic APIs
- Multi-driver assignment (Hungarian algorithm)
- Heatmap-based pickup zones
- UI visualization
- Using A* instead of Dijkstra for faster routes



-
