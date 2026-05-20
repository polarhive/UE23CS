# Unit 4: Planning and Navigation

---

## 4.1 Introduction to Navigation

### What is Navigation?

**Navigation** is the "cognitive" level of a mobile robot — the ability to reliably reach a goal using a mix of prior knowledge (maps) and real-time sensor data.

> Navigation answers: **"How do I get there?"**

Navigation moves beyond simple movement — it involves purposeful decision-making to traverse from A to B while handling real-world uncertainty and obstacles.

### Two Core Competences

| Competence | Type | Description |
|-----------|------|-------------|
| **Path Planning** | Strategic / Long-term | Identify a trajectory based on a map to reach a destination |
| **Obstacle Avoidance** | Tactical / Real-time | Modulate trajectory to prevent immediate collisions |

Balancing these two allows a robot to stay **goal-oriented** while remaining **safe in dynamic environments**.

### Planning vs. Reacting

- **Planning:** Long-term strategy to reach a distant goal
- **Reacting:** Handles unforeseen obstacles and dynamic changes
- The ideal system **merges both**: instantly updates the strategic plan as new sensor data arrives

> "Without a plan, a robot has no direction. Without reaction, it cannot survive the physical journey."

### Belief-Based Navigation

A robot navigates based on a **belief state** — never 100% certain of exact location. A plan is a trajectory moving the robot from its initial belief to a goal belief.

**Completeness:** A navigation system is **complete** if it is guaranteed to find a solution whenever one exists. In practice, completeness is often sacrificed for faster computation.

---

## 4.2 Configuration Space (C-Space)

### What is C-Space?

The **Configuration Space** (C-Space) maps all obstacles in the robot's physical world to a space defined by the robot's degrees of freedom. Path planning is performed in C-space.

- For a point robot in 2D: C-space = 2D map of free vs. occupied cells
- For a car: C-space includes x, y, heading θ (3D)
- **C-free:** The subset of C-space that is collision-free

**Advantage:** Reduces the problem of a robot with size to a point-robot in C-space by **inflating obstacles** by the robot's radius.

---

## 4.3 Graph Search Methods

Graph search path planning has two main steps:

1. **Graph Construction:** Place nodes and connect via edges
2. **Graph Search:** Compute the optimal path

### 4.3.1 Visibility Graphs

**Concept:** Connect all pairs of obstacle vertices that can "see" each other (unobstructed line of sight), plus the start and goal positions.

**Algorithm:**

1. Place nodes at obstacle vertices, start, and goal
2. Connect all mutually visible nodes with edges (straight lines)
3. Find shortest path through this graph

**Properties:**

- Produces the **geometrically shortest** path
- Widely used; simple implementation
- Directly uses polygonal obstacle descriptions

**Limitations:**

- Computationally inefficient in **dense environments** (edges scale with obstacle count)
- Paths **graze obstacles** — mathematically optimal but collision-risk high
- Safety buffers must be added → loses shortest-path optimality

---

### 4.3.2 Voronoi Diagram

**Concept:** For each point in free space, compute its distance to the nearest obstacle. The **Voronoi diagram** consists of edges/ridges formed by points **equidistant from two or more obstacles**.

```
Voronoi edge: set of points equidistant from two nearest obstacles
```

**Properties:**

- **Maximizes distance** from all obstacles → safest paths
- Complete road-map method (guarantees path if one exists)
- When obstacles are polygons → Voronoi = straight lines + parabolic segments

**Limitations:**

- Paths are much **longer** than optimal
- Edges are far from obstacles → poor localization for range-sensor robots
- Despite drawback, Voronoi paths are easy to **execute** with simple control rules

---

### 4.3.3 Exact Cell Decomposition

**Concept:** Divide the environment into **non-overlapping cells** based on geometric criticality. Each cell is either entirely free or entirely occupied.

**Properties:**

- Completeness guaranteed (like road-map methods)
- Computational efficiency depends on density of obstacles
- Path found by traversing sequence of adjacent free cells

**Limitation:**

- Difficult to implement
- Rarely used in practical mobile robotics

---

### 4.3.4 Approximate Cell Decomposition

**Fixed-size (Uniform Grid):**

- Environment divided into uniform cells (e.g., occupancy grid)
- Simple to implement
- May miss narrow passages if cell size too large

**Variable-size (Quadtree):**

- Recursive decomposition of free space into rectangles
- Cells subdivided until entirely free, entirely occupied, or minimum resolution reached
- **White cells** = free, **Black cells** = occupied, **Gray cells** = mixed

**Key advantage:** Low computational complexity → most popular for mobile robotics.

---

### 4.3.5 Lattice Graph Search

- Construct a base set of motion primitives (edges) and replicate across C-space
- Edges are **kinematically feasible** — directly executable by the robot
- Precomputed offline and stored in memory
- Used for: planetary rovers, autonomous cars

---

## 4.4 Deterministic Graph Search Algorithms

### Cost Functions

For a node n in the graph:

| Symbol | Meaning |
|--------|---------|
| g(n) | Accumulated cost from start to n |
| h(n) | Heuristic: estimated cost from n to goal |
| c(n, n') | Edge traversal cost from n to adjacent n' |
| f(n) = g(n) + ε·h(n) | Total expected cost |

### 4.4.1 Breadth-First Search (BFS)

- Explores nodes in order of **proximity to start** (fewest edge transitions)
- **Optimal** if all edges have constant cost
- For non-uniform costs: not optimal
- **Wavefront expansion** in robotics: marks each cell's distance to goal, then traces shortest path

**Complexity:** Linear regardless of environment complexity

---

### 4.4.2 Depth-First Search (DFS)

- Explores as deep as possible before backtracking
- Not optimal
- Useful for exploring unknown spaces

---

### 4.4.3 Dijkstra's Algorithm

- Optimal for **non-uniform cost** graphs
- Explores all nodes in order of accumulated cost from start
- Guarantees **globally optimal path**
- `ε = 0` (no heuristic)
- Higher complexity than BFS: O((V + E) log V)

---

### 4.4.4 A\* Algorithm

- Extends Dijkstra with a **heuristic function h(n)**
- `f(n) = g(n) + h(n)`
- Directs search toward goal → much faster than Dijkstra

**Admissibility condition:**

```
h(n) ≤ h*(n)   for all n
```

If the heuristic never overestimates the true cost, A\* guarantees optimal paths.

**Common heuristics:**

- **Euclidean distance:** `h = √((x_goal − x)² + (y_goal − y)²)`
- **Manhattan distance:** `h = |x_goal − x| + |y_goal − y|` (for grid graphs)

**Inflated A\* (Weighted A\*):**

- `f(n) = g(n) + ε·h(n)` with ε > 1
- Faster but not guaranteed optimal
- Useful for real-time robotics

---

## 4.5 Potential Field Path Planning

### Core Idea

Treat the robot as a **particle in an artificial force field**:

- **Goal** creates an **attractive potential** (like a valley/sink)
- **Obstacles** create **repulsive potentials** (like hills)
- Robot follows the **gradient** of the combined field downhill toward the goal

```
U(q) = U_att(q) + U_rep(q)
```

Robot velocity proportional to negative gradient:

```
F(q) = −∇U(q)
```

### Attractive Potential

```
U_att(q) = ½ k_att · d²(q, q_goal)
```

- d = distance to goal
- k_att = attraction gain
- Force: `F_att = −k_att · (q − q_goal)`

### Repulsive Potential

```
U_rep(q) = ½ k_rep · (1/d(q) − 1/d₀)²   if d(q) ≤ d₀
         = 0                               if d(q) > d₀
```

- d(q) = distance to nearest obstacle
- d₀ = influence radius of obstacle
- Force repels robot away when too close

### Properties

- Originally invented for robot manipulators
- Smooth guidance from start to goal
- Can update field dynamically if new obstacles appear
- Robot treated as a **point** in C-space

### Critical Limitation: Local Minima

A major problem — the robot can get **stuck in a local minimum** where attractive and repulsive forces cancel before reaching the goal.

**Solutions:**

- Random walk to escape local minimum
- Navigation functions (mathematically guaranteed no local minima)
- Combine with global planner

---

## 4.6 Obstacle Avoidance

Obstacle avoidance is the **reactive** component of navigation — modifying trajectory based on real-time sensor data.

### 4.6.1 Bug Algorithms

Simplest obstacle avoidance — uses only current sensor values and approximate goal direction.

**Basic idea:** Follow the contour of each obstacle to circumnavigate it.

#### Bug 1

1. Head toward goal
2. On hitting an obstacle: **completely circle** the obstacle
3. Depart from the point on the obstacle with **shortest distance to goal**
4. Resume heading toward goal

- Guarantees reaching any reachable goal
- Very **inefficient** (full circles)

```
Hit points: H1, H2, ...
Leave points: L1, L2, ...
```

#### Bug 2

1. Head toward goal along the **M-line** (straight line from start to goal)
2. On hitting obstacle: follow contour
3. Depart immediately when the robot can **move directly toward goal** again (returns to M-line closer to goal)

- Significantly shorter paths than Bug 1
- Still not optimal (adversarial cases can be constructed)

#### Tangent Bug

- Adds **range sensing** and a **Local Tangent Graph (LTG)**
- LTG represents locally-visible obstacle boundaries as tangent segments
- Enables more efficient navigation, shortcut discovery
- In simple environments: often yields globally optimal paths

#### Bug 2 Implementation (Two States)

```
State: GOAL-SEEK
  if obstacle detected:
    switch to WALL-FOLLOW

State: WALL-FOLLOW
  if on M-line AND closer to goal than hit point:
    switch to GOAL-SEEK
```

---

### 4.6.2 Vector Field Histogram (VFH)

**Motivation:** Bug algorithms use only instantaneous sensor readings → fragile in noisy environments.

**VFH overcomes this** by maintaining a **local occupancy grid map** around the robot, populated by recent sensor readings.

#### VFH Algorithm

1. **Build local map:** Small occupancy grid around robot
2. **Build polar histogram:**
   - X-axis = direction of obstacle (0°–360°)
   - Y-axis = probability of obstacle in that direction
3. **Find open sectors:** Identify gaps large enough for robot to pass
4. **Apply cost function:**

```
G = α·target_direction + β·wheel_orientation + γ·previous_direction
```

Where:

- `target_direction` = alignment of candidate direction with goal
- `wheel_orientation` = change required from current wheel angle
- `previous_direction` = consistency with previously chosen direction

5. **Choose sector** with lowest cost G

#### VFH+ (Improved VFH)

- Additional **reduction stage** considering robot's kinematic constraints
- Obstacles enlarged to account for all **kinematically blocked trajectories**
- Models robot movement as arcs → more realistic

---

### 4.6.3 Bubble Band Technique

**Concept:** A **bubble** = the maximum local subset of free space around the robot's current configuration that it can safely traverse in any direction.

- Generated using a simplified robot model + range information from map
- A **band (string) of bubbles** is maintained along the entire planned trajectory

```
Start → [Bubble₁] → [Bubble₂] → ... → [BubbleN] → Goal
```

**During motion:**

- If sensor detects unexpected obstacle → band deforms
- Robot deviates from planned path to avoid obstacle
- **Tension minimization** ensures smooth navigation

**Properties:**

- Considers robot's actual dimensions
- Most effective when environment configuration is **well-known in advance**
- Primarily **path optimization** + collision avoidance integration

---

### 4.6.4 Curvature Velocity Method (CVM)

**Concept:** Takes into account **kinematic and dynamic constraints** of the robot during obstacle avoidance.

**Velocity space:** (v, ω) pairs where:

- v = translational velocity
- ω = rotational velocity
- Robot travels along circular arcs with curvature `c = ω/v`

#### Algorithm

1. **Define velocity space** with two types of constraints:
   - Robot limits: `−v_max ≤ v ≤ v_max`, `−ω_max ≤ ω ≤ ω_max`
   - Obstacle constraints: block (v, ω) pairs that lead to collision
2. **Transform obstacles** from Cartesian to velocity space
3. **Simplify:** Obstacles approximated as circles for real-time performance
4. **Objective function:** Choose best (v, ω) in the admissible velocity space

**Limitations:**

- Circular obstacle simplification → issues in some environments
- Susceptible to local minima (no global knowledge)

#### Lane Curvature Method (LCM)

Improvement over CVM:

- Calculate a set of **desired lanes** (trading off lane length vs. width to obstacles)
- Select best lane using objective function
- Better performance than basic CVM

---

### 4.6.5 Dynamic Window Approach (DWA)

**Concept:** Search the **velocity space** for commands that are both achievable within the robot's dynamics and safe from collisions.

**Key insight:** At any instant, only a small **window** of (v, ω) velocities is reachable given current speed and acceleration limits.

#### Local Dynamic Window Approach

1. **Compute dynamic window:** All (v, ω) reachable in next sample period given acceleration limits
2. **Reduce to admissible velocities:** Remove (v, ω) that cannot stop before hitting an obstacle
3. **Apply objective function:**

```
O(v, ω) = α·heading(v, ω) + β·velocity(v, ω) + γ·dist(v, ω)
```

Where:

- `heading` = progress toward goal heading
- `velocity` = forward speed (rewards fast motion)
- `dist` = distance to closest obstacle on trajectory

4. **Select (v, ω) that maximizes O**

**Shape of window:** Rectangular (translational and rotational dynamics assumed independent)

#### Global Dynamic Window Approach

- Integrates **global path planning (NF1/grassfire)** into the objective function
- NF1 assigns labels to occupancy grid cells based on **total distance to goal**
- Combines global planning benefits without requiring complete prior map
- Occupancy grid updated dynamically → real-time global replanning

**Performance:** ~15 Hz cycle with 5 cm resolution grid, sustained >1 m/s average speed

#### Other Obstacle Avoidance Approaches

| Method | Description |
|--------|-------------|
| Schlegel approach | Velocity-based with different constraint modeling |
| Nearness diagram | Uses nearest obstacle direction/distance |
| Gradient method | Obstacle force gradient in velocity space |
| Adding dynamic constraints | Extends CVM/DWA with full dynamics |

---

## 4.7 Navigation Architectures

### What is a Navigation Architecture?

A **principled design** for organizing all software modules in a mobile robot navigation system (path planning + obstacle avoidance + localization + perception).

### Why Architecture Matters

1. **Modularity for code reuse:**
   - Robot hardware and environment change frequently
   - Changing one module should not break others
   - Example: Swap LiDAR for ultrasonic → only sensor driver changes, not planner
   
2. **Control localization:**
   - Isolate software modules to enable targeted testing
   - Obstacle avoidance module testable independently
   - High-level planner testable in simulation

### Types of Decompositions

#### 1. Temporal Decomposition

Distinguishes between processes with varying real-time demands:

```
High-Level (Strategic/Offline)  ← Mission Planning, Map Building
        ↓
Tactical Layer                  ← Path Re-planning
        ↓
Quasi Real-time (~10 Hz)        ← Obstacle Avoidance
        ↓
Real-time (40 Hz+)              ← Motor Control, Sensor Reading
```

Four correlated trends with temporal decomposition:

1. **Sensor response time** — time from sensor event to module output change
2. **Temporal depth** — how far ahead the process plans
3. **Spatial locality** — how local vs. global the process's view is
4. **Context specificity** — how specific vs. general the process is

#### 2. Control Decomposition

Identifies how control outputs combine to produce physical robot actions.

**Hierarchical control:**

- High-level planner produces waypoints
- Mid-level navigator follows waypoints
- Low-level controller executes motor commands

**Behavior-based control:**

- Multiple behaviors run simultaneously (wall-follow, goal-seek, obstacle-avoid)
- Behaviors compete or cooperate to produce final action

### Classic Navigation Architectures

#### Deliberative (Sense-Plan-Act)

```
Sense → Plan → Act
```

- Complete world model built; optimal plan computed
- **Advantage:** Optimal, globally consistent
- **Disadvantage:** Slow, brittle to model errors

#### Reactive (Behavior-Based)

- No internal model; direct sensor-to-action mapping
- Fast response to environment
- **Example:** Subsumption Architecture (Brooks)

#### Hybrid (Deliberative + Reactive)

Most modern robots use hybrid architectures:

- **Deliberative layer:** Long-term planning with global map
- **Reactive layer:** Fast local obstacle avoidance
- **Executive layer:** Coordinates the two

---

## 4.8 Navigation with Reinforcement Learning

### Classical vs. Learning-Based Navigation

| Approach | Method | Pros | Cons |
|----------|--------|------|------|
| Classical | A\*, VFH, DWA | Predictable, well-understood | Brittle to model errors |
| RL-based | Q-learning, PPO, SAC | Adapts to complex scenarios | Hard to train, less interpretable |

### Reinforcement Learning for Navigation

**Framework:**

- **State:** Robot observation (sensor data, goal direction)
- **Action:** Velocity commands (v, ω)
- **Reward:** Positive for reaching goal; negative for collision; small negative for time

**Algorithms used:**

- **Q-learning / DQN:** Discrete action space
- **DDPG / SAC / PPO:** Continuous action space (more common in navigation)

**Advantages:**

- Can learn to navigate in complex, cluttered environments
- Adapts to sensor noise and model errors automatically
- Can discover non-obvious strategies

**Challenges:**

- Sample efficiency (needs millions of simulation steps)
- Sim-to-real transfer (policies trained in simulation may fail in real world)
- Safety guarantees are difficult to provide

### Imitation Learning (IL) for Navigation

**Concept:** Learn navigation policy by **imitating expert demonstrations** (human teleoperation or classical planner output).

**Approaches:**

- **Behavioral Cloning (BC):** Supervised learning on expert state-action pairs
- **DAgger (Dataset Aggregation):** Iteratively collects new data under learned policy guided by expert

**Advantages:**

- Much more sample-efficient than RL
- Leverages expert knowledge

**Limitations:**

- Distribution shift: policy sees states not in training data
- Requires high-quality demonstrations

### Deep Learning in Navigation

- **CNNs** for visual navigation from camera images
- **RNNs/LSTMs** for sequential decision-making with memory
- **End-to-end learning:** Raw sensor → steering/velocity commands directly

---

## 4.9 Social Implications and Applications

### Applications of Navigation Technology

| Domain | Application |
|--------|------------|
| Autonomous Vehicles | Highway/urban driving, parking |
| Warehouse Robots | Amazon Kiva, pick-and-place |
| Delivery Robots | Last-mile delivery (Starship, Nuro) |
| Agricultural Robots | Field navigation, crop monitoring |
| Search and Rescue | Disaster zone exploration |
| Inspection | Pipeline, bridge, infrastructure inspection |
| Space Exploration | Mars rovers (Perseverance, Curiosity) |

### Social Implications

- **Employment:** Automation of logistics, manufacturing, delivery
- **Safety:** Reduced human exposure to dangerous tasks
- **Accessibility:** Assistive robots for elderly and disabled
- **Privacy:** Navigation robots collect environmental data
- **Security:** Autonomous surveillance raises ethical questions
- **Accountability:** Who is responsible when an autonomous robot causes harm?

---

## 4.10 Summary and Comparison

### Path Planning Methods Comparison

| Method | Type | Completeness | Optimal | Complexity | Best For |
|--------|------|-------------|---------|-----------|---------|
| Visibility Graph | Road-map | ✅ | ✅ (shortest) | O(n²) | Polygonal environments |
| Voronoi Diagram | Road-map | ✅ | ❌ (safe) | O(n log n) | Safety-critical nav |
| Exact Cell Decomp. | Cell | ✅ | ✅ | Varies | Theoretical |
| Approx. Cell Decomp. | Cell | Approx. | ❌ | Low | Most practical robots |
| Potential Field | Field | ❌ (local minima) | ❌ | Low | Smooth environments |
| BFS | Graph search | ✅ (uniform cost) | ✅ (uniform) | O(V+E) | Uniform grids |
| Dijkstra | Graph search | ✅ | ✅ | O((V+E)logV) | Non-uniform cost |
| A\* | Graph search | ✅ | ✅ (admissible h) | Better than Dijkstra | Most practical use |

### Obstacle Avoidance Methods Comparison

| Method | Uses Map? | Reactive | Kinematic Constraints | Real-time |
|--------|-----------|----------|-----------------------|-----------|
| Bug 1/2 | ❌ | ✅ | ❌ | ✅ |
| Tangent Bug | Partial | ✅ | ❌ | ✅ |
| VFH / VFH+ | Local | ✅ | VFH+: ✅ | ✅ |
| Bubble Band | ✅ | ✅ | ✅ | ✅ |
| CVM / LCM | ✅ | ✅ | ✅ | ✅ |
| Local DWA | ✅ | ✅ | ✅ | ✅ |
| Global DWA | ✅ | ✅ | ✅ | ✅ |

### Full Navigation Stack Integration

```
Global Map
     ↓
Global Path Planner (A*, Dijkstra)
     ↓
Waypoints
     ↓
Local Planner (DWA, VFH)  ←← Real-time Sensor Data
     ↓
Velocity Commands (v, ω)
     ↓
Motor Controllers
     ↓
Robot Motion
     ↑↑ Localization / SLAM (feeds back updated map)
```
