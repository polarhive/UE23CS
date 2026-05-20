# Unit 3: Localization and SLAM

---

## 3.1 Introduction to Localization

### What is Localization?

**Localization** is the ability of a robot to determine its own **position and orientation (pose)** within an environment so it can navigate and perform tasks effectively.

> Localization answers: **"Where am I?"**

Formally, localization means:

1. Building or using a map of the environment
2. Identifying the robot's position **relative to that map**

Localization methods use sensors like cameras, LiDAR, and wheel odometry, combined with algorithms such as **SLAM**, Kalman Filters, and Particle Filters.

---

## 3.2 Challenges of Localization

### Sources of Error

#### 1. Sensor Noise

Random variations in sensor readings even when the environment hasn't changed.

| Impact | Sources |
|--------|---------|
| Reduces accuracy | Environmental changes |
| Reduces information reliability | Sensor hardware limitations |
| Makes perception difficult | Electronic interference |

**Example — CCD Camera Indoor Navigation:**

- Robot uses color info to detect objects
- Lighting changes (sunlight through clouds, indoor lamps) affect color readings
- **Result:** Camera output appears noisy even though nothing moved

Common vision noise types:

- Picture jitter
- Signal gain variations
- Blooming
- Blurring

**Solutions to Sensor Noise:**

1. **Temporal Fusion** — combine readings over time
2. **Multi-sensor Fusion** — Camera + LiDAR, Sonar + IMU, GPS + Vision → higher reliability

---

#### 2. Sensor Aliasing

Occurs when **different environments produce identical sensor readings**, creating ambiguity.

**Human analogy:**

- Walking in complete darkness → everything looks the same
- Maze of tall identical hedges → many locations look identical

**Robot example:**

- A range sensor detects an obstacle at 0.5 m
- It cannot distinguish whether the obstacle is:
  - A human
  - A cardboard box
  - A wall section
- All produce identical sensor readings → aliasing

**Solutions:**

1. Multiple sensor readings **over time**
2. **Motion-based observations** — move and re-observe
3. **Environmental mapping** with SLAM
4. **Particle filters** and **Kalman filters**

---

#### 3. Effector Noise (Odometry Errors)

Robot actions are not perfectly executed. The robot's actual motion differs from intended motion.

**Causes:**

- Wheel slip on slippery surfaces
- Uneven terrain causing unexpected tilts
- External disturbances (bumps, pushes)

**Result:** Errors **accumulate over time** (dead reckoning drift)

#### Sources of Odometry Errors

1. Limited encoder resolution
2. Wheel misalignment
3. Unequal wheel diameters
4. Changing wheel contact points (tire wear, surface deformation)
5. Floor irregularities

---

## 3.3 To Localize or Not to Localize

### Localization-Based Navigation vs. Programmed Solutions

| Approach | Description | Pros | Cons |
|----------|-------------|------|------|
| **Programmed (Dead Reckoning)** | Execute fixed motion sequences | Simple, no sensors needed | Errors accumulate, no correction |
| **Localization-Based** | Use sensors + map to determine pose | Handles uncertainty, corrects drift | Requires sensors and algorithms |

### Types of Localization Problems

| Problem | Description |
|---------|-------------|
| **Position Tracking** | Initial pose is known; track it as robot moves |
| **Global Localization** | Initial pose unknown; determine it from scratch |
| **Kidnapped Robot** | Robot teleported to unknown location mid-operation (hardest case) |

---

## 3.4 Belief Representation

### What is a Belief?

A **belief** is a probability distribution over all possible robot positions. Since the robot cannot know its exact position with certainty, it maintains a distribution.

```
bel(x_t) = P(x_t | z_{1:t}, u_{1:t})
```

Where x_t = pose, z = sensor observations, u = control inputs

### Single Hypothesis Belief

- Robot maintains **one estimate** of its position (a single point/Gaussian)
- Updated to a new single position as robot moves
- **Efficient** but cannot represent ambiguity
- Used by: **Kalman Filter Localization**

### Multiple Hypothesis Belief

- Robot maintains **several possible positions** simultaneously
- Can represent ambiguity (e.g., robot is in one of three similar corridors)
- More computationally expensive
- Used by: **Markov Localization**, **Particle Filters**

### Continuous vs. Discrete Belief

- **Continuous:** Gaussian (Kalman Filter), mixture of Gaussians
- **Discrete:** Grid/histogram over quantized positions (Markov Localization)

---

## 3.5 Map Representation

Maps provide the spatial context for localization. Different map types suit different algorithms.

### Types of Maps

#### 1. Metric Maps

Represent precise geometric positions and shapes.

| Sub-type | Description | Example Use |
|----------|-------------|------------|
| **Occupancy Grid** | 2D/3D grid; each cell = free/occupied/unknown | Laser-based SLAM |
| **Feature Map** | Set of landmark positions (points, lines) | EKF SLAM |
| **Point Cloud** | 3D set of points from LiDAR | 3D SLAM |

#### 2. Topological Maps

- Graph-based representation
- **Nodes** = places/locations
- **Edges** = traversable paths between places
- Compact; good for high-level planning
- Less precise than metric maps

#### 3. Hybrid Maps

Combine metric and topological representations.

---

## 3.6 Probabilistic Localization Framework

### Bayes Filter — The Foundation

Both Markov and Kalman filter localization are based on **Bayes' rule**:

```
P(x | z) = P(z | x) · P(x) / P(z)
```

The recursive belief update has two steps:

**1. Prediction Step (motion update):**

```
bel̄(x_t) = ∫ p(x_t | u_t, x_{t-1}) · bel(x_{t-1}) dx_{t-1}
```

*The robot moved; uncertainty grows*

**2. Correction Step (sensor update):**

```
bel(x_t) = η · p(z_t | x_t) · bel̄(x_t)
```

*New observation; uncertainty shrinks*

---

## 3.7 Markov Localization

### Core Idea

Markov localization tracks the robot's belief state using an **arbitrary probability density function** — not restricted to Gaussians.

In practice, all Markov implementations use a **discrete representation** of the probability distribution (histogram/grid over position space).

### Assumptions

- **Markov assumption:** Current belief depends only on the previous belief and latest action/observation (no need for full history)
- Sensor measurements are **conditionally independent** given the robot's true position

### What Problems it Solves

- **Global localization** — from an unknown starting position
- **Position tracking** — maintaining pose estimate over time
- **Kidnapped robot** — can recover from sudden displacement

### Markov Localization Algorithm

```
Algorithm Markov_Localization(bel(x_{t-1}), u_t, z_t, map):
  for each x_t:
    bel̄(x_t) = Σ p(x_t | u_t, x_{t-1}) · bel(x_{t-1})   ← Prediction
    bel(x_t) = η · p(z_t | x_t, map) · bel̄(x_t)           ← Correction
  return bel(x_t)
```

**Critical challenge:** Computing `p(z_t | x_t, map)` — the sensor model. Requires modeling how sensors behave at different positions in the map.

### Advantages

- Can represent **any arbitrary distribution** (multi-modal, skewed)
- Handles global localization
- Robust to large uncertainties and ambiguous environments

### Disadvantages

- **Computationally expensive** — must update belief over all grid cells
- Memory-intensive for high-resolution grids
- Slow convergence in large environments

---

## 3.8 Kalman Filter Localization

### Core Idea

The Kalman Filter provides a **mathematically optimal** estimate for linear systems with Gaussian noise. It assumes:

1. Robot motion model is **linear**
2. Sensor model is **linear**
3. Noise is **Gaussian** (unimodal)

Under these assumptions, the belief is always a **Gaussian distribution**, characterized by:

- Mean **μ** (best estimate of position)
- Covariance **Σ** (uncertainty)

### Kalman Filter Steps

**1. Predict (Motion Update):**

```
μ̄_t = A_t · μ_{t-1} + B_t · u_t
Σ̄_t = A_t · Σ_{t-1} · A_t^T + R_t
```

- A_t = state transition matrix
- B_t = control input matrix
- R_t = process noise covariance
- Uncertainty **increases** with motion

**2. Update (Sensor Correction):**

```
K_t = Σ̄_t · C_t^T · (C_t · Σ̄_t · C_t^T + Q_t)^{-1}   ← Kalman Gain
μ_t = μ̄_t + K_t · (z_t − C_t · μ̄_t)
Σ_t = (I − K_t · C_t) · Σ̄_t
```

- K_t = Kalman Gain (how much to trust new measurement)
- C_t = observation matrix
- Q_t = measurement noise covariance
- Uncertainty **decreases** with observation

### Intuition of Kalman Gain

- If **measurement noise Q is small** → trust sensor → K is large → pull estimate toward sensor reading
- If **process noise R is small** → trust model → K is small → rely on prediction

### Concrete Example — 1D Robot Position

| State | Position (μ) | Uncertainty (σ) |
|-------|-------------|----------------|
| Initial | 5.0 m | 2.0 m |
| After moving 1 m (with noise) | 6.0 m | 2.2 m (grew) |
| After sensor reads 6.2 m (low noise) | 6.14 m | 1.1 m (shrank) |

**Kalman Filter blends odometry and sensor optimally** → best of both worlds.

### Limitations of Kalman Filter

- Requires **linear** motion and observation models
- Assumes **unimodal (Gaussian)** distribution — cannot handle multi-modal uncertainty
- Cannot localize globally (needs initial estimate close to true position)
- If robot is kidnapped, the distribution is no longer unimodal → Kalman Filter fails

### Extended Kalman Filter (EKF)

Extends KF to **non-linear** systems by linearizing via **Jacobians**:

```
F_t = ∂f/∂x |_{μ_{t-1}, u_t}   ← Jacobian of motion model
H_t = ∂h/∂x |_{μ̄_t}           ← Jacobian of observation model
```

EKF uses these Jacobians in place of the linear matrices A_t, C_t.

**Limitations of EKF:**

- Linearization errors in highly non-linear scenarios
- May diverge if Jacobian approximation is poor

### Markov vs. Kalman Comparison

| Feature | Markov Localization | Kalman Filter |
|---------|--------------------|-|
| Belief type | Any distribution (grid) | Gaussian (parametric) |
| Global localization | ✅ Yes | ❌ No (needs initial estimate) |
| Multi-modal | ✅ Yes | ❌ No |
| Computation | High | Low |
| Handles kidnapping | ✅ Yes | ❌ Poor |
| Accuracy (tracking) | Moderate | High (optimal) |

---

## 3.9 SLAM — Simultaneous Localization and Mapping

### The Core Problem

Traditional localization requires a **pre-built map**. Traditional mapping requires **known robot pose**.

> **SLAM solves both simultaneously** — the robot builds a map while localizing itself within that map.

This is the classic **chicken-and-egg problem:**

- For localization, you need to know where features are (map)
- For map building, you need to know where you are (pose)

### Formal Definition

Given:

- Odometry data (robot displacements)
- Sensor observations (landmark positions from LiDAR/camera)

**Find:**

- The robot's full path: x₁, x₂, ..., x_t
- The map of landmarks: m₁, m₂, ..., m_k

### Why SLAM is Hard

1. Both estimated path and extracted features are **corrupted by noise**
2. Errors in pose estimate affect landmark placement
3. Errors in landmark estimates affect pose correction
4. All estimates become **correlated** over time

### SLAM Process (Conceptual)

1. **Initial:** Robot starts at known position, zero uncertainty
2. **Observe:** Robot sees landmark — maps it with uncertainty = sensor noise
3. **Move:** Robot moves — pose uncertainty grows via odometry error
4. **Re-observe:** Robot sees previous landmark → **Loop Closure**
5. **Update:** Loop closure detected → pose uncertainty **shrinks dramatically**
6. **Propagate:** Entire map corrects itself — correlated landmarks all improve

### Loop Closure

When a robot returns to a previously visited location and **recognizes it**, this is called **loop closure**. It is the most powerful uncertainty-reducing event in SLAM.

### SLAM Variants

| Variant | Description |
|---------|-------------|
| **Online SLAM** | Estimates pose at each step in real-time |
| **Offline (Full) SLAM** | Post-processes all data for a globally consistent map |

---

## 3.10 EKF SLAM

### Overview

**EKF-SLAM (Extended Kalman Filter SLAM)** is the classical SLAM algorithm, combining EKF with landmark-based mapping.

**State vector:**

```
X = [x_robot, y_robot, θ_robot, x_l1, y_l1, x_l2, y_l2, ...]^T
```

All robot pose variables AND all landmark positions in a single state.

**Covariance matrix:**

```
Σ = | Σ_robot     Σ_robot,landmarks |
    | Σ_landmarks,robot  Σ_landmarks |
```

Captures correlations between robot pose and all landmark estimates.

### Algorithm Steps

1. **Predict:** Move robot using odometry → update robot pose + grow uncertainty
2. **Update:** Observe landmarks → compute Kalman gain → update robot + landmark positions
3. **Data Association:** Match current observation to known landmark (or add new)
4. **Loop Closure:** Recognize revisited landmark → large uncertainty reduction

### Complexity

- O(n²) where n = number of landmarks
- **Computationally expensive** for large environments
- Solution: Divide map into **submaps**, update covariances locally

### Advantages

- Real-time localization + continuous map updates
- Handles sensor uncertainty explicitly

### Challenges

| Challenge | Details |
|-----------|---------|
| Quadratic complexity | Scales badly with number of landmarks |
| Linearization errors | Jacobian approximation can cause divergence |
| Data association | Incorrect matching especially at loop closure |
| Sensor limitations | 2D laser rangefinders lack distinctive features vs cameras |

---

## 3.11 Particle Filter SLAM

### Core Concept

Instead of representing belief as a Gaussian (EKF), Particle Filter SLAM represents it as a **set of particles** — random samples from the probability distribution.

Each **particle** = one hypothesis:

- Robot's full pose (x, y, θ)
- A complete map consistent with that pose

```
Belief = { (x^(i), w^(i)) }  for i = 1..N
```

Where x^(i) is a particle and w^(i) is its weight (likelihood).

### Why Particles?

- Can represent **any distribution** — Gaussian, multi-modal, skewed
- Can handle **non-linear** transformations
- Power: flexibility of representation

**For a Gaussian:** More particles cluster near the center; fewer toward the edges (density matches distribution).

### Particle Filter Algorithm

```
Algorithm Particle_Filter(X_{t-1}, u_t, z_t):
  X̄_t = ∅
  for i = 1 to N:
    x^(i)_t ~ p(x_t | u_t, x^(i)_{t-1})   ← Sample from motion model
    w^(i)_t = p(z_t | x^(i)_t)              ← Weight by observation likelihood
    X̄_t += (x^(i)_t, w^(i)_t)
  X_t = resample(X̄_t)                       ← Draw N particles with prob ∝ weight
  return X_t
```

### Key Steps

1. **Sampling:** Draw new particle poses using motion model
2. **Weighting:** Assign importance weight based on how well observation matches
3. **Resampling:** Draw N particles from weighted set — high-weight particles survive and multiply; low-weight particles die

### Resampling (Importance Sampling)

- Particles with higher likelihood → more likely to be resampled
- Particles with lower likelihood → likely discarded
- Focuses computation on **high-probability regions**

### Challenges

| Challenge | Details |
|-----------|---------|
| Curse of dimensionality | Particles needed grows exponentially with state space dimension |
| Depletion | After many resamplings, diversity can decrease |
| Computation | Large N needed for accuracy; expensive |
| Data association | Must match observations to map features |

### FastSLAM

An efficient particle filter SLAM variant:

- Each particle maintains its own **map estimate** (set of EKFs per landmark)
- Complexity: O(N log M) where N = particles, M = landmarks
- Much more scalable than standard EKF-SLAM

### Applications of Particle Filter SLAM

- Indoor robot navigation
- Autonomous vehicles
- Augmented/Virtual reality
- Underwater robotics

---

## 3.12 GraphSLAM

### Concept

GraphSLAM represents the SLAM problem as a **graph optimization** problem:

- **Nodes** = robot poses at different times + landmark positions
- **Edges** = constraints from odometry (between poses) and observations (pose ↔ landmark)

### Formulation

Each edge adds a constraint with an **information matrix** (inverse of covariance).

**Objective:** Find the configuration of nodes that **maximizes likelihood** of all constraints:

```
x* = argmin_x Σ_ij (x_i − x_j)^T Ω_ij (x_i − x_j)
```

This is a **non-linear least-squares problem**, solved by iterative methods (Gauss-Newton, Levenberg-Marquardt).

### Loop Closure in GraphSLAM

When loop closure is detected, a new edge is added connecting current pose to old pose. This strongly constrains the graph and causes **global map correction**.

### Advantages

- Can process entire trajectory at once (batch optimization)
- Very accurate maps
- Well-suited for offline SLAM

---

## 3.13 Open Challenges in SLAM

| Challenge | Description |
|-----------|-------------|
| **Dynamic Environments** | Moving objects (people, cars) violate the static map assumption. Must treat as outliers or predict motion. |
| **Multi-Robot SLAM** | Combining maps from multiple robots into one global consistent map. Data association between robots is hard. |
| **Data Association & Loop Closure** | Matching current observations to map features can fail, causing catastrophic map errors |
| **Sensor Feature Limitations** | 2D laser rangefinders produce sparse, undistinctive features vs. cameras' rich information |
| **Monocular Scale Ambiguity** | Single cameras only give bearing info; absolute scale requires GPS, IMU, or known object sizes |
| **Long-term Autonomy** | Maps degrade as environments change over hours/days/months |
| **Large-scale Environments** | Computational complexity scales with environment size |

---

## 3.14 Summary

| Concept | Key Points |
|---------|-----------|
| Localization | Determining robot pose in known/unknown environment |
| Sensor noise | Random sensor errors → temporal/multi-sensor fusion |
| Sensor aliasing | Different places look the same → use multiple readings |
| Effector noise | Wheel slip etc. → odometry drift → needs correction |
| Belief | Probability distribution over possible poses |
| Markov Localization | Any distribution; grid-based; handles global localization |
| Kalman Filter | Gaussian belief; optimal for linear systems; tracking only |
| EKF | Extended KF for non-linear systems via Jacobians |
| SLAM | Simultaneous localization AND mapping |
| EKF-SLAM | State vector includes robot + landmarks; O(n²) complexity |
| Particle Filter SLAM | Set of weighted particles; any distribution; flexible |
| GraphSLAM | Graph optimization; best for offline/batch processing |
| Loop closure | Recognizing revisited location → biggest uncertainty reducer |
