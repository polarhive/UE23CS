# Mobile and Autonomous Robotics — PYQ Master

## TOPIC 1: Autonomous Robots — Definition, Characteristics & Challenges

---

### Q1 — Define Autonomous Robots, and what are their characteristics?

**[ESA Jul-2024 Set-1 · Q1.a · 5 Marks]**

**Answer:**

**Definition:**

An autonomous robot is a robotic system capable of performing tasks and making decisions **without continuous human intervention**. It integrates sensors, actuators, and onboard computational systems — often with AI/ML algorithms — to perceive, interpret, and act in its environment independently.

**Characteristics:**

1. **Perception**
   The robot senses its environment using cameras, LiDAR, radar, sonar, GPS, and IMUs. It converts raw sensor data into meaningful environmental representations.

2. **Decision-Making**
   The robot processes sensory information to choose appropriate actions. This may involve following a pre-programmed plan, adapting to changing conditions, or learning from experience (via ML/RL).

3. **Actuation**
   The robot physically interacts with the environment using motors, servos, and actuators. This enables locomotion, manipulation, and task execution.

4. **Autonomy & Adaptability**
   The robot operates without step-by-step human commands. It adapts to unforeseen situations, dynamic obstacles, and changing environments.

5. **Self-Localization**
   The robot can estimate its own position and orientation within an environment using odometry, SLAM, or GPS.

6. **Integration of Hardware and Software**
   High autonomy requires tight coupling of sensors, processing units (CPU/GPU/NPU), control algorithms, and communication systems.

**Examples:** Self-driving cars, Roomba vacuum cleaners, Mars rovers (Perseverance), warehouse robots (Amazon Kiva).

---

### Q2 — Discuss the importance of technical, social, and ethical challenges in the development of autonomous robots, with specific examples for each

**[ESA Jan–May 2024 · Q1.a · 7 Marks]**

**Answer:**

#### Technical Challenges

| Challenge | Example |
|-----------|---------|
| Sensor noise & aliasing | LiDAR returns spurious readings in rain/fog |
| Real-time computation | Processing 3D point clouds at 10 Hz on embedded hardware |
| Localization drift | Odometry error accumulates over long runs — requires periodic correction |
| Sim-to-real gap | RL policies trained in simulation fail in real-world dynamics |
| Power constraints | Aerial robots limited by battery capacity vs. payload |

#### Social Challenges

| Challenge | Example |
|-----------|---------|
| Unemployment | Autonomous warehouse robots displacing logistics workers |
| Accessibility | Assistive robots for elderly/disabled are expensive and not widely available |
| Public trust | People fear self-driving cars after high-profile accidents |
| Skill gap | Workforce needs retraining for robot-assisted industries |

#### Ethical Challenges

| Challenge | Example |
|-----------|---------|
| Accountability | Who is liable when a self-driving car kills a pedestrian — manufacturer, owner, or software? |
| Privacy | Service robots with cameras continuously collect personal data |
| Autonomous weapons | Military drones that select and engage targets without human approval |
| Algorithmic bias | Face-recognition systems in robots performing worse for certain demographics |

---

# TOPIC 2: Sensors — Types, Classification, and Applications

---

## Q3 — How do proprioceptive and exteroceptive sensors differ? What are the key distinctions between passive and active sensors? What are the applications of LiDAR, Radar, Ultrasonic sensors, and Wheel Encoders?

**[ESA Jul-2024 Set-1 · Q1.b · 10 Marks]**

**Answer:**

### Proprioceptive vs. Exteroceptive

| Feature | Proprioceptive | Exteroceptive |
|---------|---------------|--------------|
| What it measures | **Internal** robot state | **External** environment |
| Examples | Motor speed, wheel encoders, IMU, joint angles, battery voltage | Camera, LiDAR, ultrasonic, GPS |
| Use | Odometry, joint control, pose estimation | Obstacle detection, mapping, localization |

### Passive vs. Active

| Feature | Passive | Active |
|---------|---------|--------|
| Operation | Measures ambient energy entering the sensor | **Emits** energy into the environment, measures the reaction |
| Examples | CCD/CMOS cameras, microphones, temperature probes | LiDAR, ultrasonic sensors, wheel encoders, radar |
| Advantage | No interference, low power | Higher accuracy, more controlled measurements |
| Risk | Affected by ambient conditions | May interfere with other sensors or environment |

### Sensor Applications

**LiDAR (Light Detection and Ranging)**

- Emits laser pulses and measures time-of-flight
- Applications: 3D environment mapping, obstacle detection for autonomous vehicles, SLAM, terrain mapping for UAVs
- Used in: Waymo self-driving cars, Boston Dynamics robots

**Radar (Radio Detection and Ranging)**

- Emits radio waves; measures reflection
- Applications: Adaptive cruise control, collision warning, detection in fog/rain/darkness (works where LiDAR/cameras fail)
- Used in: Automotive ADAS systems, drone collision avoidance

**Ultrasonic Sensors**

- Emits ultrasonic pulses (20 kHz+); measures time-of-flight
- Applications: Short-range proximity detection, parking sensors, object detection in industrial robots, liquid level sensing
- Range: ~2 cm to 4 m; low cost

**Wheel Encoders**

- Measures angular displacement of wheels via optical or magnetic pulses
- Applications: Odometry (estimating position from wheel motion), speed control, dead reckoning, differential drive control

---

## Q4 — Distinguish between active and passive sensors, and give examples

**[ESA Jan–May 2024 · Q1.d · 4 Marks]**

**Answer:**

| Aspect | Active Sensors | Passive Sensors |
|--------|---------------|----------------|
| Principle | Emit energy; measure reflected/returned signal | Measure naturally available ambient energy |
| Energy | Self-powered energy emission | No self-emission |
| Examples | LiDAR, ultrasonic, radar, structured-light cameras, wheel encoders | CCD/CMOS cameras, microphones, temperature sensors, GPS receivers |
| Advantage | Work in dark/featureless environments; controlled conditions | Non-intrusive; no interference |
| Disadvantage | Interference between sensors; power usage | Dependent on ambient conditions |

---

## Q5 — Explain the role and functionality of encoders in robotics. What factors should be considered when selecting an encoder?

**[ESA Jan–May 2024 · Q1.c · 7 Marks]**

**Answer:**

### What Encoders Do

Encoders are sensors that measure **angular position and/or speed** of a rotating shaft or wheel. In robotics they are primarily used for:

- **Odometry:** Computing how far each wheel has turned → estimating robot displacement
- **Speed feedback:** Closed-loop motor control
- **Joint position sensing:** In robot arms, each joint's angle

### How They Work

**Optical Encoder:**

1. A disk with evenly-spaced holes/slots (or reflective patterns) is mounted on the rotating shaft
2. An LED emits light; a photodetector on the other side detects pulses as holes pass
3. Pulses are counted → angular displacement and velocity calculated

**Incremental Encoder:** Counts pulses relative to a reference (start) position

**Absolute Encoder:** Directly outputs absolute angle — never loses position even after power-off

### Factors for Encoder Selection

| Factor | Consideration |
|--------|--------------|
| **Resolution** | Pulses per revolution (PPR) — higher = more precise position measurement |
| **Speed range** | Maximum RPM the encoder can handle without missing pulses |
| **Output type** | Digital (quadrature A/B) or analog; single-ended or differential |
| **Environmental conditions** | Dust, vibration, temperature — industrial robots need IP-rated encoders |
| **Size and weight** | Critical for aerial robots and small mobile platforms |
| **Absolute vs. incremental** | Absolute needed if homing on startup is unacceptable |
| **Cost** | High-resolution absolute encoders are significantly more expensive |

---

## Q6 — What do optical encoders measure? How do they work? How does the sensor react when the encoder disk blocks the light beam?

**[ESA Jan–May 2024 · Q3.a · 7 Marks]**

**Answer:**

**What They Measure:** Optical encoders measure **angular position, angular velocity, and direction of rotation** of a rotating shaft.

**How They Work:**

1. A transparent disk with **evenly-spaced opaque slots** is mounted on the rotating shaft
2. An **infrared LED** emits light toward the disk
3. A **photodetector** sits on the opposite side
4. As the disk rotates, light alternately passes through slots and is blocked by opaque sections

**When the disk blocks the light beam:**

- The photodetector receives **no light** → outputs a **LOW (0) signal**
- When the slot aligns → light passes → photodetector outputs **HIGH (1) signal**
- The resulting pulse train is counted to determine angular displacement

**Quadrature Encoding (A + B channels, 90° offset):**

- Two sensors positioned 90° apart generate signals A and B
- If A leads B → **clockwise** rotation
- If B leads A → **counter-clockwise** rotation
- This gives both position AND direction

**Resolution:** Determined by the number of slots on the disk (e.g., 1024 CPR = 1024 pulses per revolution = 0.35° resolution)

---

## Q7 — Define the IMU and specify the number of DOF it typically estimates. Provide a schematic of its block diagram

**[ESA Jan–May 2024 · Q3.c · 7 Marks]**

**Answer:**

**Definition:**

An **IMU (Inertial Measurement Unit)** is an electronic device that measures and reports a body's specific force, angular rate, and sometimes magnetic field. It is a combination of:

- **Accelerometers** (measure linear acceleration along 3 axes)
- **Gyroscopes** (measure angular velocity about 3 axes)
- Optionally: **Magnetometer** (measures magnetic field along 3 axes)

**DOF Estimates:**

- 6-DOF IMU: 3-axis acceleration + 3-axis angular velocity
- 9-DOF IMU: 6-DOF + 3-axis magnetic field (absolute heading)

**IMU Block Diagram:**

```
┌─────────────────────────────────────────────────────┐
│                    IMU                              │
│                                                     │
│  ┌─────────────┐    ┌─────────────┐                 │
│  │ Accelerometer│    │  Gyroscope  │                 │
│  │  (3-axis)   │    │  (3-axis)   │                 │
│  │  ax, ay, az │    │  ωx, ωy, ωz │                 │
│  └──────┬──────┘    └──────┬──────┘                 │
│         │                  │                        │
│         └────────┬─────────┘                        │
│                  ▼                                   │
│         ┌────────────────┐                          │
│         │  Signal Cond.  │ (Amplify, Filter)        │
│         └────────┬───────┘                          │
│                  ▼                                   │
│         ┌────────────────┐                          │
│         │  ADC           │ (Analog → Digital)       │
│         └────────┬───────┘                          │
│                  ▼                                   │
│         ┌────────────────┐                          │
│         │  Processor     │ (Sensor Fusion / Filter) │
│         └────────┬───────┘                          │
│                  ▼                                   │
│         ┌────────────────┐                          │
│         │  Output Bus    │ (I²C / SPI / UART)       │
│         └────────────────┘                          │
└─────────────────────────────────────────────────────┘
```

**Applications:** Drone attitude control, robot dead reckoning, AR/VR headsets, smartphone orientation, autonomous vehicle navigation.

---

## Q8 — What is dead reckoning? Which sensor is used for dead reckoning?

**[ESA Jan–May 2024 · Q3.d · 4 Marks]**

**Answer:**

**Dead Reckoning** is a method of estimating a robot's current position by starting from a **known position** and integrating velocity/displacement over time using motion data — without any external reference (no GPS, no landmarks).

**Process:**

```
x_t = x_{t-1} + Δx(v, ω, Δt)
y_t = y_{t-1} + Δy(v, ω, Δt)
θ_t = θ_{t-1} + ω·Δt
```

**Primary Sensor:** **Wheel Encoders (Odometry)**

- Count wheel rotations → compute linear and angular displacement
- Two encoders (left + right wheel) on a differential-drive robot give full 2D pose estimate

**Supporting Sensors:**

- **IMU (Gyroscope):** Measures heading changes; compensates for wheel slip
- **Accelerometer:** Detects sudden movements

**Critical Limitation:** Errors are **cumulative** — small errors in each step accumulate over time (unbounded drift). Periodic correction using GPS or landmarks is required.

---

# TOPIC 3: Actuators

---

## Q9 — Provide a detailed explanation of actuators. What are the different types of actuators and their applications?

**[ESA Jul-2024 Set-1 · Q1.c · 10 Marks]**

**Answer:**

**Definition:**

An **actuator** is a device that converts energy (electrical, pneumatic, hydraulic) into **physical motion** or force. It is the output mechanism of a robot — the component that makes things move.

### Types of Actuators

**1. Electric Actuators**

**(a) DC Motors:**

- Converts DC electrical energy to rotational mechanical energy
- Speed controlled via PWM; direction via H-bridge
- Applications: Wheeled robot drive, conveyor belts
- Types: Brushed (simple, cheaper), Brushless (efficient, longer life)

**(b) Servo Motors:**

- DC motor + position feedback (encoder) + controller in one unit
- Provides precise angular position control
- Applications: Robot arm joints, pan-tilt camera mounts, RC vehicles
- Types: Standard servo (limited rotation), Continuous rotation servo

**(c) Stepper Motors:**

- Rotates in discrete steps (e.g., 1.8° per step = 200 steps/revolution)
- Open-loop position control — no encoder needed for basic use
- Applications: 3D printer axes, CNC machines, camera focus mechanisms

**(d) Linear Actuators:**

- Produces linear (straight-line) motion
- Types: Lead-screw driven, belt-driven, linear motor
- Applications: Height-adjustable platforms, gripper linear motion

**2. Pneumatic Actuators**

- Use compressed air to create motion
- Applications: Industrial grippers, surgical robots, high-speed assembly lines
- Advantage: High power-to-weight ratio, fast response
- Disadvantage: Requires air compressor, noisy, position control is difficult

**3. Hydraulic Actuators**

- Use pressurized fluid (oil) to generate large forces
- Applications: Heavy industrial robots, construction machinery, exoskeletons
- Advantage: Enormous force output
- Disadvantage: Heavy, risk of leaks, not precise

**4. Shape Memory Alloy (SMA) Actuators**

- Material contracts/expands with temperature change
- Applications: Micro-robots, minimally invasive surgical instruments
- Advantage: Very small, silent
- Disadvantage: Slow, low force

**5. Piezoelectric Actuators**

- Vibrate/expand at nanometer scale when voltage is applied
- Applications: High-precision positioning (atomic force microscopes), micro-robots
- Advantage: Sub-micron precision

### Comparison Table

| Type | Power Source | Motion | Force | Precision | Typical Use |
|------|-------------|--------|-------|-----------|-------------|
| DC Motor | Electrical | Rotary | Medium | Medium | Drive wheels |
| Servo | Electrical | Rotary | Medium | High | Joint control |
| Stepper | Electrical | Rotary (steps) | Medium | High | 3D printers |
| Pneumatic | Compressed air | Linear/Rotary | High | Low | Industrial grippers |
| Hydraulic | Pressurized fluid | Linear/Rotary | Very High | Medium | Heavy machinery |
| SMA | Thermal | Linear | Low | Medium | Micro-robots |

---

# TOPIC 4: Kinematics and Robot Motion

---

## Q10 — What are rotational matrices in robot kinematics? Give an example and explain how it is used

**[ESA Jul-2024 Set-1 · Q2.a · 5 Marks]**

**Answer:**

**Rotational Matrix Definition:**

A **rotation matrix** R is a 3×3 orthogonal matrix that represents a rotation in 3D space. It transforms a vector from one coordinate frame to another (rotated) frame.

Properties:

- R^T = R^{-1} (transpose = inverse)
- det(R) = +1
- Columns are orthonormal unit vectors

**Rotation about the Z-axis by angle θ:**

```
Rz(θ) = | cos θ  -sin θ   0 |
         | sin θ   cos θ   0 |
         |   0       0     1 |
```

**Rotation about X-axis by angle α:**

```
Rx(α) = | 1     0       0   |
         | 0   cos α  -sin α |
         | 0   sin α   cos α |
```

**Rotation about Y-axis by angle β:**

```
Ry(β) = | cos β   0   sin β |
         |   0     1     0   |
         |-sin β   0   cos β |
```

**Example:**

Rotate point P = (1, 0, 0) by 90° about Z-axis:

```
P' = Rz(90°) × P
   = | 0  -1  0 |   | 1 |   |  0 |
     | 1   0  0 | × | 0 | = |  1 |
     | 0   0  1 |   | 0 |   |  0 |
```

The point moved from (1, 0, 0) to (0, 1, 0) — a 90° rotation as expected.

**Use in Robotics:**

- Computing end-effector orientation given joint angles (forward kinematics)
- Transforming sensor data from sensor frame to robot/world frame
- Composing multiple rotations: R_total = R1 × R2 × R3

---

## Q11 — Differentiate forward kinematics from inverse kinematics with an example

**[ESA Jul-2024 Set-1 · Q2.c · 10 Marks] · [ESA Jan–May 2024 · Q1.b · 7 Marks]**

**Answer:**

### Forward Kinematics (FK)

**Definition:** Given **joint angles/positions**, compute the **position and orientation of the end effector**.

- Direction: Joint space → Task space
- Unique solution (one set of joint angles → one pose)
- Computationally straightforward
- Uses transformation matrices chained together

**Mathematical form (2-link planar arm):**

```
x = L1·cos(θ1) + L2·cos(θ1 + θ2)
y = L1·sin(θ1) + L2·sin(θ1 + θ2)
```

**Example:**

2-link arm, L1 = L2 = 1 m, θ1 = 45°, θ2 = 45°:

```
x = cos(45°) + cos(90°) = 0.707 + 0 = 0.707 m
y = sin(45°) + sin(90°) = 0.707 + 1.0 = 1.707 m
```

### Inverse Kinematics (IK)

**Definition:** Given the **desired end-effector position and orientation**, compute the required **joint angles**.

- Direction: Task space → Joint space
- May have **multiple solutions**, **one solution**, or **no solution**
- Computationally harder — requires solving non-linear equations
- Uses optimization algorithms (Jacobian inverse, gradient descent, CCD)

**Example (same 2-link arm):**

Desired position: (0.707, 1.707)

```
cos(θ2) = (x² + y² − L1² − L2²) / (2·L1·L2)
         = (0.5 + 2.91 − 1 − 1) / 2 = 0.707
θ2 = ±45°

θ1 = atan2(y, x) − atan2(L2·sin(θ2), L1 + L2·cos(θ2))
   = 90° − 45° = 45°
```

→ θ1 = 45°, θ2 = 45° (matches the FK example)

### Comparison

| Aspect | Forward Kinematics | Inverse Kinematics |
|--------|-------------------|-------------------|
| Input | Joint angles (θ1, θ2, ...) | End-effector pose (x, y, θ) |
| Output | End-effector pose | Joint angles |
| Solutions | Always unique | Multiple / none possible |
| Complexity | Low | High (non-linear) |
| Computation | Closed-form | Iterative/numerical |
| Use | Simulation, visualization | Motion planning, control |

**Importance of IK:**

- Without IK, you cannot tell a robot arm to "pick up this object at position (x, y, z)"
- Essential for robot arm manipulators, humanoid locomotion, camera pointing, surgical robots

---

## Q12 — Explain the configuration of Ackermann Steering and Synchro Drive with diagrams and equations

**[ESA Jul-2024 Set-1 · Q2.b · 10 Marks]**

**Answer:**

### Ackermann Steering

Used in car-like robots. The key constraint is that all wheels rotate about a **common instantaneous center** (ICC), so inner wheels turn at a sharper angle than outer wheels.

```
        ┌───────┐
        │       │
   [FL] │       │ [FR]
   /    │   R   │    \
  /     │       │     \
 /      └───────┘      \
[RL]                  [RR]
         ↑ ICC
```

**Ackermann Condition:**

```
cot(δ_outer) − cot(δ_inner) = W / L
```

Where:

- δ_outer = steering angle of outer front wheel
- δ_inner = steering angle of inner front wheel
- W = track width (distance between left and right wheels)
- L = wheelbase (distance between front and rear axles)

**Turn radius** (to center of rear axle):

```
R = L / tan(δ)
```

**Properties:**

- No tire slipping during turning (unlike differential drive)
- Non-holonomic — cannot move sideways
- Minimum turning radius limited by maximum steering angle
- Used in: cars, autonomous vehicles (Apollo, Waymo)

---

### Synchro Drive

All wheels **steer and drive simultaneously** — all wheels always point in the same direction.

```
         ↑   ↑   ↑    (all wheels parallel)
        ┌─────────┐
        │         │
   [W1] │    R    │ [W2]
        │         │
        └─────────┘
              │
             [W3]
```

**Mechanism:**

- Two independent motors:
  - **Drive motor:** Controls speed of all three wheels (synchronized via belt/chain)
  - **Steering motor:** Rotates all wheels simultaneously (same angle)
- Robot body does not rotate when changing direction — orientation is fixed

**Equations:**

```
v_robot = v_wheel            (translational speed)
ω_robot = 0                  (body does not rotate)
Heading changed by steering motor directly
```

**Properties:**

- Holonomic-like behavior — can move in any direction without turning body
- Body orientation decoupled from motion direction
- Simple control
- Disadvantage: Mechanical complexity; belt wear; odometry is simpler

---

## Q13 — What is the difference between locomotion and manipulation? Discuss key issues and limitations affecting locomotion in robotic systems

**[ESA Jan–May 2024 · Q2.a · 7 Marks]**

**Answer:**

### Locomotion vs. Manipulation

| Aspect | Locomotion | Manipulation |
|--------|-----------|-------------|
| Definition | Moving the **entire robot** through the environment | Moving **objects** in the environment using the robot |
| Goal | Reach a location | Grasp, move, assemble objects |
| Examples | Wheeled/legged motion, flying | Robot arm pick-and-place, welding |
| DOF concern | Position/orientation of robot body | Position/orientation of end effector |

**Note:** Locomotion and manipulation share the same core challenges of stability, contact, and force control. A legged robot's leg simultaneously provides locomotion (support + swing) — the distinction blurs.

### Key Issues and Limitations of Locomotion

1. **Stability**
   - Must maintain balance throughout motion
   - Static stability: CoG must remain within support polygon
   - Dynamic stability: Balance maintained through motion (bipeds, running)

2. **Contact Characteristics**
   - Friction at contact points determines traction
   - Wheel–ground contact type (point, line, area)
   - Slip reduces odometry accuracy

3. **Environment Type**
   - Hard flat ground → wheels are optimal
   - Soft ground (mud, sand) → wheels sink; legs suffer less
   - Rough/broken terrain → legs adapt better than wheels
   - Air → propellers/wings

4. **Mechanical Complexity**
   - More DOF = more complex control
   - Legged robots require real-time balance computation
   - More joints = more possible failures

5. **Energy Efficiency**
   - Wheels on hard surface: most efficient
   - Legged locomotion: moderate efficiency
   - Flying: high power consumption

6. **Minimum Turning Radius**
   - Non-holonomic systems (Ackermann, tricycle) cannot turn in place
   - Limits maneuverability in tight spaces

---

## Q14 — What is static and dynamic stability? Explain support polygon with example

**[ESA Jan–May 2024 · Q2.b · 7 Marks]**

**Answer:**

### Static Stability

A robot is **statically stable** when it can remain balanced without any motion. Condition: the **center of gravity (CoG)** must lie **within the support polygon** formed by the ground contact points.

No active control is needed — the robot can stop at any instant and remain upright.

**Example:** A tripod (3-legged stool) — always statically stable as long as CoG is in the triangle.

### Dynamic Stability

A robot is **dynamically stable** when balance is maintained **only through motion** — the CoG may temporarily leave the support polygon but the robot doesn't fall because it uses inertial forces and active control to correct.

**Example:** A bicycle — falls if stationary but stays balanced while moving due to gyroscopic effects and active steering.

### Support Polygon

The **support polygon** is the convex hull of all ground contact points of a robot.

**4-Legged Robot Example:**

```
Contact points: FL(0,1), FR(1,1), RL(0,0), RR(1,0)

Support Polygon:
  FL ─────── FR
   │           │
   │    CoG    │  ← CoG at (0.5, 0.5) = inside = STABLE
   │     ×     │
  RL ─────── RR
```

If the robot lifts one leg (e.g., FL):

```
Support Triangle: FR(1,1), RL(0,0), RR(1,0)
```

CoG must now remain within this triangle to maintain static stability.

**Rules:**

- **3 legs minimum** for static stability
- **6-legged robot (hexapod):** Can maintain a stable tripod always in contact while the other 3 swing forward → always statically stable

---

## Q15 — Explain Degrees of Freedom (DOF) in robotics and describe capabilities for 2-DOF, 3-DOF, 5-DOF, and 6-DOF robots

**[ESA Jan–May 2024 · Q2.c · 7 Marks]**

**Answer:**

**Degrees of Freedom (DOF):** The number of independent parameters that completely define the configuration (position + orientation) of a robotic system. Each joint typically contributes 1 DOF.

| DOF | Capabilities | Example Robot | Applications |
|-----|-------------|--------------|-------------|
| **2-DOF** | Move in a plane (x, y) OR 2 rotations | SCARA robot arm (simplified), pan-tilt camera | Pick and place on flat surface, camera tracking |
| **3-DOF** | Full 3D position (x, y, z) or 2 translations + 1 rotation | Basic robotic arm, Delta robot | 3D printing head, simple assembly |
| **5-DOF** | 3D position + 2 orientations (pitch + yaw, no roll) | 5-axis CNC machine, some welding robots | Welding, milling curved surfaces |
| **6-DOF** | Full 3D position + full 3D orientation (roll, pitch, yaw) | Industrial robot arm (KUKA, ABB), human arm | Assembly, painting, surgery, pick-and-place of arbitrarily oriented objects |

**Why 6-DOF is special:**

A rigid body in 3D space has exactly 6 DOF (3 translation + 3 rotation). A 6-DOF robot can therefore reach **any position and orientation** in its reachable workspace (subject to joint limits). This matches human arm capability.

**Redundant robots (7+ DOF):** Like the human arm (7 major DOF) — can reach the same pose in multiple configurations, allowing obstacle avoidance while keeping the end-effector fixed.

---

## Q16 — Write four differences between legged and wheeled robots

**[ESA Jan–May 2024 · Q2.d · 4 Marks]**

**Answer:**

| Aspect | Legged Robots | Wheeled Robots |
|--------|--------------|----------------|
| **Terrain** | Excellent on rough, uneven, or broken terrain | Best on smooth, flat surfaces |
| **Mechanical complexity** | High — many joints, complex gait control | Low — simple drive mechanisms |
| **Energy efficiency** | Moderate — energy lost in lifting legs | Very high on hard surfaces (rolling friction) |
| **Stability** | Must actively manage balance (especially bipeds) | Inherently stable with 3+ wheels on flat ground |
| *(Bonus)* **Speed** | Generally slower; limited by gait dynamics | Higher speeds achievable with wheels |
| *(Bonus)* **Payload** | Limited by leg strength and CoG constraints | Can carry heavy loads with large wheels/suspension |

---

# TOPIC 5: Computer Vision and Feature Detection

---

## Q17 — Write the advantages and disadvantages of visible spectrum cameras, infrared cameras, and sonar

**[ESA Jul-2024 Set-1 · Q3.a · 5 Marks]**

**Answer:**

### Visible Spectrum Camera

| Advantages | Disadvantages |
|-----------|--------------|
| Rich color and texture information | Fails in darkness or very low light |
| High resolution; detailed images | Affected by glare, shadows, weather |
| Passive — no energy emission | Requires good illumination |
| Low cost; widely available | Depth perception requires stereo or additional processing |
| Basis for object detection (YOLO, R-CNN) | Computationally expensive for real-time 3D |

### Infrared (IR) Camera

| Advantages | Disadvantages |
|-----------|--------------|
| Works in complete darkness (detects heat) | Cannot read text or fine visual details |
| Detects living beings (search & rescue) | Low spatial resolution compared to visible cameras |
| Not affected by visible light conditions | Expensive (thermal cameras especially) |
| Useful for night vision in autonomous vehicles | Background temperature changes affect readings |

### Sonar (Ultrasonic)

| Advantages | Disadvantages |
|-----------|--------------|
| Works in total darkness | Poor angular resolution (wide beam) |
| Cheap and simple | Cannot detect thin objects (wires, glass) |
| Unaffected by lighting conditions | Affected by soft/angled surfaces (absorb/deflect sound) |
| Good for proximity detection | Crosstalk between multiple sonar sensors |
| Works in water (marine robots) | Maximum range ~4 m; slow update rate |

---

## Q18 — Compare CCD and CMOS sensors. Explain the working of a CCD camera with a neat diagram

**[ESA Jul-2024 Set-1 · Q3.b · 10 Marks]**

**Answer:**

### CCD vs. CMOS Comparison

| Feature | CCD | CMOS |
|---------|-----|------|
| Full form | Charge-Coupled Device | Complementary Metal-Oxide Semiconductor |
| Image quality | Higher uniformity; lower noise | Slightly more noise per pixel historically |
| Power consumption | High (~100× CMOS) | Very low |
| Read speed | Slow (serial read) | Fast (parallel read per pixel) |
| Cost | Higher | Lower (standard semiconductor fab) |
| On-chip processing | Minimal | ADC, amp, logic per pixel (system-on-chip) |
| Rolling shutter | No — global shutter | Yes (can cause jello effect in fast motion) |
| Use in robotics | Scientific/precision cameras | Most consumer cameras, phones, robot cameras |

### CCD Camera Working Principle

**Step-by-step:**

1. **Light → Electron conversion:** Photons strike each pixel's photodiode, generating a proportional number of electrons (photoelectric effect). Brighter light = more electrons.
2. **Charge accumulation:** Electrons are collected in a potential well for the duration of the exposure time.
3. **Charge transfer (the "coupled" part):** At readout, a sequence of voltage pulses shifts each row of charge packets horizontally along the CCD shift register to a read column, then vertically to an output node.
4. **Charge → Voltage:** An output amplifier converts the accumulated charge to a voltage proportional to the number of electrons.
5. **Analog → Digital:** An ADC converts the voltage to a digital pixel value (e.g., 8-bit = 0–255 gray levels).

**CCD Diagram:**

```
   Photons
   ↓  ↓  ↓  ↓  ↓  ↓

  ┌─┬─┬─┬─┬─┬─┐   ← Row of pixels (each stores charge)
  │e│e│e│e│e│e│   Row N
  └─┴─┴─┴─┴─┴─┘
        ↓ (shift)
  ┌─┬─┬─┬─┬─┬─┐
  │e│e│e│e│e│e│   Row N-1
  └─┴─┴─┴─┴─┴─┘
        ↓ (shift)
  ┌─┬─┬─┬─┬─┬─┐
  │e│e│e│e│e│e│   Horizontal Shift Register
  └─┬─┴─┴─┴─┴─┘
    ↓ (serial shift →)
  [Amplifier] → [ADC] → Digital Pixel Values
```

---

## Q19 — What is corner detection? Explain Moravec's algorithm with a diagram. What improvement does Harris introduce?

**[ESA Jan–May 2024 · Q3.b · 7 Marks] · [ESA Jul-2024 Set-1 · Q3.c · 10 Marks]**

**Answer:**

### Corner Detection

**Corner detection** identifies pixels that are the intersection of two or more edges — points with high gradient change in **multiple directions**. Corners are ideal image features because they are repeatable, distinctive, and stable across viewpoints.

---

### Moravec's Corner Detection Algorithm

**Key Insight:**

- **Flat region:** Shifting a window in any direction → similar appearance (low SSD)
- **Edge:** Shifting perpendicular to edge → large SSD; parallel → small SSD
- **Corner:** Shifting in **any** direction → large SSD

**SSD (Sum of Squared Differences):**

```
SSD(Δx, Δy) = Σ [I(x+Δx, y+Δy) − I(x, y)]²
```

**Algorithm Steps:**

1. For each pixel, define a 3×3 reference window
2. Shift the window in 8 directions (up, down, left, right, 4 diagonals)
3. Compute SSD for each shift
4. Take the **minimum SSD** across all 8 shifts (worst-case similarity)
5. If `min(SSD) > threshold` → **CORNER**

**Worked Example:**

```
Reference 3×3 patch around pixel:
[ 6  6  6]
[15 14  0]   ← target pixel = 14
[15  0  0]

SSD values for 8 shifts:
SSD1(up)  = 395,  SSD2(down)  = 451
SSD3(left)= 422,  SSD4(right) = 576
SSD5(↖)  = 227,  SSD6(↗)    = 764
SSD7(↙)  = 493,  SSD8(↘)    = 702

min(SSD) = 227
Threshold = 220
227 > 220 → CORNER DETECTED ✓
```

**Diagram:**

```
         Image
    ┌─────────────┐
    │  flat  edge │
    │       ┌──┐  │
    │       │  │  │
    │ flat  └──┘  │ ← corners at rectangle corners
    └─────────────┘

   Flat: SSD all low
   Edge: SSD high only ⊥ edge
   Corner: SSD high in ALL directions → detected
```

---

### Harris Corner Detector — Improvement Over Moravec

**Problems with Moravec:**

1. Uses only **8 discrete shift directions** (not all directions)
2. **Binary threshold** — sensitive to noise
3. Not rotation-invariant (diagonal shifts weighted differently)

**Harris's Improvement:**

Uses **partial derivatives** (continuous gradient) of the image instead of discrete shifts.

**Second Moment Matrix M:**

```
M = Σ w(x,y) [ Ix²    IxIy ]
              [ IxIy   Iy²  ]
```

(w = Gaussian weighting window; Ix, Iy = image gradient components)

**Harris Response:**

```
R = det(M) − k · [trace(M)]²
  = λ1·λ2 − k·(λ1+λ2)²
```

Where k ≈ 0.04–0.15 (empirically chosen)

**Decision:**

- R >> 0 → **Corner**
- R << 0 → **Edge**
- |R| ≈ 0 → **Flat region**

**Improvements over Moravec:**

- Considers **all directions** (not just 8)
- Smooth response (not binary)
- More noise-tolerant via Gaussian weighting
- Rotation invariant (eigenvalues don't change with rotation)

---

### Affine Invariant Detection (Harris-Affine)

Steps:

1. Detect candidate features using **scale-invariant Harris-Laplacian**
2. Compute the **second moment matrix M** to identify slowest/fastest change directions
3. Fit an **ellipse** from M to represent the anisotropic region around the feature
4. **Normalize** the elliptical region to a circle
5. Extract descriptor from the normalized circular region

This makes the detector invariant to **affine transformations** (non-uniform scaling, shear), not just rotation.

---

# TOPIC 6: Localization

---

## Q20 — Explain prediction update and perception update in the localization process

**[ESA Jul-2024 Set-1 · Q4.a · 5 Marks]**

**Answer:**

Robot localization uses a **Bayes Filter** framework with two alternating steps:

### Prediction Update (Motion Update)

Occurs when the robot executes a motion command u_t.

```
bel̄(x_t) = ∫ p(x_t | u_t, x_{t-1}) · bel(x_{t-1}) dx_{t-1}
```

- **p(x_t | u_t, x_{t-1})** = motion model — probability of being at x_t given you were at x_{t-1} and executed u_t
- Since motion is imperfect (wheel slip, noise), uncertainty **increases**
- The belief distribution spreads/blurs

**Example:** Robot moves forward 1 m. The true displacement has noise → the position estimate becomes a wider Gaussian (more uncertain).

### Perception Update (Sensor/Measurement Update)

Occurs when the robot takes a sensor reading z_t.

```
bel(x_t) = η · p(z_t | x_t) · bel̄(x_t)
```

- **p(z_t | x_t)** = sensor/observation model — how likely is observation z_t given the robot is at x_t
- η = normalizing constant
- New observation sharpens the estimate → uncertainty **decreases**

**Example:** Robot's LiDAR sees a wall at 2 m to the right. Only positions in the map where a wall is 2 m to the right are plausible → belief concentrates around those positions.

### Combined Cycle

```
Initial belief  →  [PREDICT: move]  →  blurred belief
                →  [UPDATE: observe] →  sharp belief
                →  [PREDICT: move]  →  blurred again ...
```

In **Kalman Filter:**

- Predict: μ̄ = A·μ + B·u; Σ̄ = A·Σ·A^T + R
- Update: K = Σ̄·C^T(C·Σ̄·C^T+Q)^{-1}; μ = μ̄ + K(z − C·μ̄); Σ = (I−K·C)·Σ̄

---

# TOPIC 7: SLAM

---

## Q21 — What are the key points in Particle Filter SLAM?

**[ESA Jul-2024 Set-1 · Q4.b · 10 Marks] · [ESA Jan–May 2024 · Q4.c · 7 Marks]**

**Answer:**

### 1. Particle Representation

Belief is represented as a set of **N weighted particles** (not a Gaussian):

```
{(x^(i), w^(i))} for i = 1 to N
```

Each particle is a complete hypothesis: the robot's pose + a full map consistent with that pose. This can represent **any distribution** — multi-modal, skewed, non-Gaussian.

### 2. Bayesian Filter Foundation

Particle Filter SLAM is a **Bayesian filtering** approach. It maintains a probability distribution over all possible poses and maps, updated with every motion and observation.

### 3. Motion Update (Sampling)

For each particle, a new pose is sampled from the **motion model**:

```
x^(i)_t ~ p(x_t | u_t, x^(i)_{t-1})
```

This propagates each particle according to the robot's action, adding motion uncertainty.

### 4. Observation Update (Weighting)

Each particle is assigned a **weight** based on how well the current sensor observation matches the expected observation at that particle's pose:

```
w^(i)_t = p(z_t | x^(i)_t, map^(i))
```

High-weight particles represent more likely positions.

### 5. Resampling (Importance Sampling)

Draw N new particles from the weighted set, with probability proportional to weight:

- High-weight particles **survive and multiply**
- Low-weight particles are **discarded**
- Focuses computation on high-probability regions

### 6. Map Management

Each particle maintains its **own map**. In FastSLAM, each particle holds a separate EKF per landmark — complexity is O(N log M) instead of O(M²) for standard EKF-SLAM.

### 7. Data Association

Match current observations to previously seen features in each particle's map. Correct data association is critical — wrong matches cause map inconsistencies.

### 8. Loop Closure Handling

When the robot revisits a location, particles on the correct trajectory receive much higher weights and dominate after resampling — uncertainty collapses, improving the overall map.

### 9. Challenges

- **Curse of dimensionality:** Number of particles grows exponentially with state space size
- **Particle depletion:** Diversity decreases after many resamplings
- **Computational cost:** Large N needed for accuracy

### 10. Applications

Autonomous vehicles, indoor robot navigation, augmented reality, underwater mapping.

---

# TOPIC 8: Path Planning and Navigation

---

## Q22 — Explain the two types of Bug algorithm and how a robot navigates around obstacles using them

**[ESA Jan–May 2024 · Q4.a · 7 Marks]**

**Answer:**

The Bug algorithms are simple reactive navigation methods that use only **current sensor readings** and **approximate goal direction**. The core strategy is: head toward goal; if an obstacle is hit, follow its boundary to get around it.

### Bug 1

**Algorithm:**

1. Move straight toward the goal
2. On encountering an obstacle: record the **hit point H**
3. Completely circumnavigate the obstacle (full circle)
4. During the circumnavigation, record the point with **shortest distance to goal** → **leave point L**
5. Return to L and depart toward goal

**Diagram:**

```
  Start ─────────────→ H1 ─ circle ──→ L1 ──────────────→ Goal
                         ↘            ↗
                          (full loop around obstacle)
```

- **Guarantee:** Always reaches goal if reachable
- **Drawback:** Extremely inefficient (full circles even for small deviations)

---

### Bug 2

**Algorithm:**

1. Define the **M-line**: straight line from Start to Goal
2. Move along M-line toward goal
3. On encountering an obstacle: record hit point H, follow the obstacle boundary
4. **Depart from the boundary** as soon as the robot reaches any point **on the M-line that is closer to the goal** than H

**Diagram:**

```
  Start ─── H1 ─ wall-follow ─ L1 ─── H2 ─ wall-follow ─ L2 ──→ Goal
              ↗ (short boundary arc)    ↗
```

- **More efficient** than Bug 1 in most cases
- Departs contour early when M-line is reached again
- Still not optimal (adversarial layouts can make Bug 2 worse than Bug 1)

### Bug 2 State Machine

```
State GOAL_SEEK:
  move toward goal
  if obstacle detected:
    record hit point H
    switch to WALL_FOLLOW

State WALL_FOLLOW:
  follow obstacle boundary (keep obstacle on one side)
  if on M-line AND closer to goal than H:
    switch to GOAL_SEEK
  if current position == H:
    goal is unreachable; STOP
```

### Tangent Bug (Extension)

Uses **range sensing** and a **Local Tangent Graph (LTG)** to detect visible obstacle endpoints and navigate toward the most promising gap — yields near-optimal paths in simple environments.

---

## Q23 — How are temporal decomposition and control decomposition useful in robotics? What are the four interrelated trends that correlate with temporal decomposition?

**[ESA Jul-2024 Set-1 · Q4.c · 10 Marks] · [ESA Jan–May 2024 · Q4.b · 7 Marks]**

**Answer:**

### Why Decompositions Are Useful

Navigation architectures use decompositions to organize complex robot software into **manageable, modular, testable components**.

**Benefits:**

- **Modularity:** Change one module without breaking others (e.g., swap sensor driver without modifying planner)
- **Code reuse:** Same obstacle avoidance module works on different hardware platforms
- **Targeted testing:** Test high-level planner in simulation; test low-level motor controller on hardware independently
- **Targeted learning:** Apply a learning algorithm to just one module of the system

---

### 1. Temporal Decomposition

Distinguishes software processes by their **real-time requirements** — how fast they must respond.

```
┌─────────────────────────────────────────────┐
│  STRATEGIC / OFFLINE       No real-time     │  ← Mission planning
│  (minutes to hours)                         │
├─────────────────────────────────────────────┤
│  TACTICAL                  ~1 sec           │  ← Path re-planning
├─────────────────────────────────────────────┤
│  QUASI REAL-TIME           ~0.1 sec         │  ← Obstacle avoidance (VFH, DWA)
├─────────────────────────────────────────────┤
│  REAL-TIME                 ~25 ms (40 Hz)   │  ← Motor PID, sensor read
└─────────────────────────────────────────────┘
```

**Usefulness:**

- Safety-critical modules (motor control) get the most CPU time and priority
- Slow modules (map building, mission planning) run at lower frequency
- Allows mixing fast reactive behavior with slow deliberative planning

---

### 2. Control Decomposition

Identifies how **different control outputs combine** to produce physical robot actions. Two major paradigms:

| Paradigm | Description |
|----------|-------------|
| **Hierarchical** | High-level planner → mid-level navigator → low-level motor controller |
| **Behavior-based** | Multiple behaviors run in parallel; compete or cooperate for final output |

**Usefulness:**

- Localizes where decisions are made
- Behavior-based: obstacle avoidance behavior can override path-following behavior safely
- Hierarchical: clear responsibility chain

---

### Four Interrelated Trends Correlated with Temporal Decomposition

| Trend | Description |
|-------|-------------|
| **1. Sensor Response Time** | Time between a sensor event occurring and the module changing its output. Real-time modules have response times of milliseconds; strategic modules may respond in seconds. |
| **2. Temporal Depth** | How far into the future a module plans. Real-time modules plan for the next milliseconds (avoid immediate collision); strategic modules plan for minutes/hours (route to destination). |
| **3. Spatial Locality** | How local vs. global the process's view of the environment is. Real-time modules focus on nearby obstacles; strategic modules consider the entire map. |
| **4. Context Specificity** | How specific vs. general the module's behavior is. Real-time obstacle avoidance is highly specific (react to this obstacle now); mission planning is general (get to the hospital). |

**Key insight:** As you move up the temporal decomposition stack (from real-time to strategic), response time increases, temporal depth increases, spatial scope broadens, and context becomes more general.

---

## Q24 — What are the advantages of using reinforcement learning in legged robots and autonomous vehicles?

**[ESA Jan–May 2024 · Q4.d · 4 Marks]**

**Answer:**

### In Legged Robots

1. **Complex gait learning:** RL can discover efficient gaits (trot, gallop, bound) without manually programming each motion pattern — the robot learns what works via trial and error
2. **Terrain adaptation:** RL policies adapt to unexpected terrain (rocks, slopes, gaps) by learning recovery behaviors from simulated falls
3. **Energy efficiency:** RL can optimize for energy consumption — learns to minimize leg forces while maintaining stability
4. **Robustness to damage:** RL can discover compensatory gaits when a leg is damaged (shown in Cully et al. 2015 "Intelligent Trial and Error")

### In Autonomous Vehicles

1. **Handles edge cases:** Classical rule-based systems struggle with unusual scenarios; RL learns from millions of simulated scenarios including rare events
2. **End-to-end learning:** RL can learn directly from raw sensor inputs (camera → steering/throttle) without hand-crafted intermediate representations
3. **Complex interaction modeling:** RL can learn social behavior — how to merge into traffic, negotiate intersections, yield to pedestrians — through multi-agent simulation
4. **Continuous improvement:** As the vehicle collects more real-world data, the policy can be fine-tuned to improve performance in specific environments

---

# TOPIC 9: Combined / Cross-Topic Questions

---

## Q25 — Define temporal decomposition in robotic navigation and illustrate with a generic architecture diagram

**[ESA Jan–May 2024 · Q4.b · 7 Marks]**

*(See Q23 above for full answer — this is the same question. Below is the diagram specifically requested.)*

**Generic Navigation Architecture with Temporal Decomposition:**

```
┌──────────────────────────────────────────────────────────────┐
│ MISSION PLANNER (Offline)                                    │
│ • Task sequencing  • Goal selection  • Map updates           │
│ Cycle: minutes                                               │
└────────────────────────┬─────────────────────────────────────┘
                         ▼
┌──────────────────────────────────────────────────────────────┐
│ PATH PLANNER (Strategic)                                     │
│ • A* / Dijkstra / RRT  • Global path to goal                 │
│ Cycle: seconds                                               │
└────────────────────────┬─────────────────────────────────────┘
                         ▼
┌──────────────────────────────────────────────────────────────┐
│ LOCAL NAVIGATOR (Quasi Real-Time)                            │
│ • DWA / VFH  • Obstacle avoidance  • Waypoint following      │
│ Cycle: ~0.1 s (10 Hz)                                        │
└────────────────────────┬─────────────────────────────────────┘
                         ▼
┌──────────────────────────────────────────────────────────────┐
│ MOTOR CONTROLLER (Real-Time)                                 │
│ • PID control  • Encoder feedback  • Velocity commands       │
│ Cycle: ~25 ms (40 Hz)                                        │
└────────────────────────┬─────────────────────────────────────┘
                         ▼
                    ROBOT MOTION

    ↑──── Sensor Data (LiDAR, Camera, Odometry) ────↑
    feeds back to all layers asynchronously
```

---

# Quick Reference: Questions by Paper

## ESA July 2024 — Set 1 (100 Marks)

| Q | Topic | Marks | Answered In |
|---|-------|-------|-------------|
| 1.a | Autonomous robots: definition & characteristics | 5 | Q1 |
| 1.b | Proprioceptive/exteroceptive; passive/active; LiDAR/Radar/Ultrasonic/Encoders | 10 | Q3 |
| 1.c | Actuators: types and applications | 10 | Q9 |
| 2.a | Rotational matrices in kinematics | 5 | Q10 |
| 2.b | Ackermann steering & Synchro Drive | 10 | Q12 |
| 2.c | Forward vs. Inverse Kinematics | 10 | Q11 |
| 3.a | Visible camera / IR camera / Sonar: pros & cons | 5 | Q17 |
| 3.b | CCD vs. CMOS; working of CCD camera | 10 | Q18 |
| 3.c | Harris corner detector & Affine invariant detection | 10 | Q19 |
| 4.a | Prediction update & perception update in localization | 5 | Q20 |
| 4.b | Particle Filter SLAM key points | 10 | Q21 |
| 4.c | Temporal & control decomposition; four trends | 10 | Q23 |

## ESA Jan–May 2024 (100 Marks)

| Q   | Topic                                                      | Marks | Answered In |
| --- | ---------------------------------------------------------- | ----- | ----------- |
| 1.a | Technical, social, ethical challenges in autonomous robots | 7     | Q2          |
| 1.b | Forward & inverse kinematics; robot arm importance         | 7     | Q11         |
| 1.c | Encoders: role, working, selection factors                 | 7     | Q5          |
| 1.d | Active vs. passive sensors with examples                   | 4     | Q4          |
| 2.a | Locomotion vs. manipulation; key issues                    | 7     | Q13         |
| 2.b | Static & dynamic stability; support polygon                | 7     | Q14         |
| 2.c | DOF: 2, 3, 5, 6-DOF robots — capabilities & examples       | 7     | Q15         |
| 2.d | 4 differences: legged vs. wheeled robots                   | 4     | Q16         |
| 3.a | Optical encoders: measure, work, light-blocking reaction   | 7     | Q6          |
| 3.b | Corner detection; Moravec; Harris improvement              | 7     | Q19         |
| 3.c | IMU: definition, DOF, block diagram                        | 7     | Q7          |
| 3.d | Dead reckoning; which sensor                               | 4     | Q8          |
| 4.a | Bug 1 & Bug 2 algorithms with diagram                      | 7     | Q22         |
| 4.b | Temporal decomposition; generic architecture; four trends  | 7     | Q23/Q25     |
| 4.c | Particle Filter SLAM — 5 key points                        | 7     | Q21         |
| 4.d | RL advantages in legged robots & autonomous vehicles       | 4     | Q24         |