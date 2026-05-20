# Unit 1: Introduction to Robotics and Locomotion

---

## 1.1 Introduction to Autonomous Robots

### What is an Autonomous Robot?

An autonomous robot is a robotic system capable of performing tasks and making decisions **without continuous human intervention**. It combines hardware and software to perceive, interpret, and act in its environment.

**Key components:**

- **Sensors** — perceive the environment (cameras, LiDAR, radar)
- **Actuators** — interact physically with the environment (motors, grippers)
- **Control Algorithms** — govern behavior, decision-making, navigation
- **Computational Systems** — integrate AI/ML for autonomy

### Four Key Questions in Autonomous Robotics

| Question | Corresponding Capability |
|---|---|
| What is around me? | Sensor Interpretation / Perception |
| Where am I? | Localization |
| Where am I going? | Map building |
| How do I get there? | Path Planning |

### Historical Timeline

| Year | Milestone |
|---|---|
| 1912 | El Ajedrecista — first autonomous chess-playing machine |
| 1948–49 | Elmer & Elsie (W. Grey Walter) — first true autonomous robots |
| 1950s | Unimate — first industrial robot (George Devol) |
| 1960s | SHAKEY — cameras, tactile sensors, rudimentary planning (Stanford) |
| 1970s | Rise of "pick-and-place" industrial robots |
| 1980s–90s | AI enters robotics; learning algorithms and improved sensing |
| 2000s | Sociable robots (Aibo, Paro); Roomba autonomous vacuum |
| 2010s–present | Self-driving cars, delivery drones, warehouse robots |

### Characteristics of Autonomous Robots

1. **Perception** — sensing via cameras, LiDAR, radar
2. **Decision-Making** — processing sensor data to choose actions
3. **Actuation** — physically interacting using motors and mechanisms

### Applications

- Manufacturing (assembly, welding, painting)
- Logistics & warehousing
- Healthcare (surgery, patient care)
- Agriculture (planting, harvesting, monitoring)
- Search & rescue
- Space exploration
- Assistive/rehabilitation

### Challenges

**Technical:**

- Perception accuracy in dynamic lighting, weather, unpredictable obstacles
- Robustness and reliability (fail-safe mechanisms)
- Data security and privacy

**Ethical:**

- Moral dilemmas (trolley-problem scenarios)
- Job displacement
- Algorithmic bias and discrimination

**Social:**

- Public acceptance and trust
- Regulatory frameworks
- Infrastructure adaptation

---

## 1.2 Basic Concepts and Terminology

| Term | Definition |
|---|---|
| **Sensors** | Devices gathering environmental information |
| **Actuators** | Mechanisms enabling physical interaction |
| **Navigation** | Moving from one location to another (includes path planning + obstacle avoidance) |
| **Localization** | Determining the robot's position within its environment |
| **Mapping** | Creating a representation of the environment |
| **Path Planning** | Calculating optimal collision-free routes |
| **SLAM** | Simultaneous Localization and Mapping |
| **HRI** | Human-Robot Interaction |
| **Swarm Robotics** | Coordinated collaboration of multiple robots |
| **Teleoperation** | Remote control of a robot |
| **End-Effector** | Tool at the end of a robot's arm |
| **Task Planning** | Sequence of actions to achieve a goal |
| **Feedback Control** | Using sensor feedback to maintain desired state |

---

## 1.3 Sensors and Actuators

### Sensor Classification

**Axis 1: Proprioceptive vs. Exteroceptive**

- **Proprioceptive** — measures internal state (motor speed, joint angles, battery voltage)
- **Exteroceptive** — acquires information from environment (distance, light intensity, sound)

**Axis 2: Passive vs. Active**

- **Passive** — measures ambient energy (temperature probes, microphones, CCD cameras)
- **Active** — emits energy and measures reaction (ultrasonic sensors, laser range finders)
  - *Risk:* emitted energy may affect what the sensor is measuring

### Common Sensor Types

| Sensor | Type | Key Applications |
|---|---|---|
| IMU (Gyroscope + Accelerometer) | Proprioceptive | Navigation, balancing, motion control |
| LiDAR | Active/Exteroceptive | 3D mapping, obstacle detection, localization |
| Radar | Active/Exteroceptive | Long-range detection, adverse weather |
| Ultrasonic | Active/Exteroceptive | Proximity sensing, close-range obstacle detection |
| Camera (RGB/Depth/Thermal) | Passive/Exteroceptive | Object recognition, navigation, mapping |
| GPS | Passive/Exteroceptive | Outdoor localization, waypoint navigation |
| Wheel Encoders | Proprioceptive | Odometry, speed control, position estimation |
| Force/Torque Sensors | Proprioceptive | Object manipulation, force feedback |
| Touch/Tactile Sensors | Proprioceptive | Contact/pressure detection |

### Actuator Types

| Actuator | Principle | Applications |
|---|---|---|
| DC / AC Motors | Electromagnetic | Wheel propulsion, joint movement |
| Servo Motors | Built-in feedback | Precise angular positioning (robot arms) |
| Stepper Motors | Discrete steps | Precise joint control, navigation |
| Pneumatic Actuators | Compressed air | Automation, manufacturing |
| Hydraulic Actuators | Pressurized fluid | Heavy machinery, construction |
| Electromagnetic (Solenoids) | Magnetic field | Valves, relays, robotics |
| Shape Memory Alloy (SMA) | Temperature response | Biomedical, aerospace |
| Thermal Actuators | Heat expansion | MEMS, microvalves |

### Motors in Autonomous Robotics

- **DC Motors** — brushed/brushless; commonly used for wheel propulsion
- **Servo Motors** — precise angular control; used in robot arms
- **Stepper Motors** — discrete steps; used for accurate joint movements

### Controllers

Controllers manage and regulate robot behavior by processing sensor data and commanding actuators.

**Types:**

- **Microcontrollers/Microprocessors** — execute control algorithms (e.g., Arduino, Raspberry Pi)
- **Motor Controllers** — regulate motor speed and direction
- **Feedback Systems** — encoders, gyroscopes for closed-loop control
- **Motion Planning Algorithms** — software for autonomous navigation and obstacle avoidance

**Examples:** Siemens SIMATIC S7, Allen-Bradley PLCs, ABB IRC5, Fanuc R-30iB

### Power Sources

| Type | Examples | Best For |
|---|---|---|
| Batteries (Li-ion, LiPo) | Most mobile robots | Portability, high energy density |
| Fuel Cells | Hydrogen fuel cells | Extended endurance (UAVs, underwater) |
| Solar Power | Photovoltaic panels | Outdoor/environmental robots |
| Tethered Power | Cable-connected | Industrial inspection |

### Power Management Techniques

- **Voltage Regulation** — stable voltage for electronics
- **Current Limiting** — prevent component damage
- **Battery Management Systems (BMS)** — monitor charge/discharge
- **Energy Harvesting** — capture ambient vibration, heat, light
- **Sleep Modes** — low-power states during inactivity
- **Emergency Shutdown** — safety kill-switch

---

## 1.4 Range Finders, Encoders, and Vision Sensors

### Range Finders

Provide continuous distance measurements to objects in the robot's vicinity.

| Type | Method | Range/Use |
|---|---|---|
| LiDAR | Laser pulses (time-of-flight) | Long range, 3D mapping |
| Ultrasonic | Sound waves | Short range, proximity sensing |
| Radar | Radio waves | Long range, adverse weather |
| Vision-based | Triangulation / depth cameras | Variable |

**Key Applications:**

- Obstacle avoidance (self-driving cars, drones)
- Precision manipulation (robot arms)
- 3D terrain mapping (Mars rovers)
- Search and rescue

### Encoders

Translate motion into digital signals for feedback and control.

**Types:**

*Rotary Encoders:*

- **Incremental Encoders** — generate pulses indicating relative position changes
  - Optical (light source + photodetector)
  - Magnetic (magnetic fields + sensors)
- **Absolute Encoders** — unique digital code for each distinct position

*Linear Encoders:*

- Optical (linear scale + light sensor)
- Magnetic (linear path)

**Applications:**

- Measuring joint angles and wheel rotations
- Closed-loop motor control
- Odometry

**Choosing an Encoder:** consider resolution, accuracy, operating speed, environmental conditions, and cost.

### Vision Sensors

**Types:**

- **Standard RGB Cameras** — object recognition, navigation, tracking
- **Depth Cameras** — 3D perception, obstacle avoidance
- **Thermal Cameras** — heat-based detection, low-light use
- **Time-of-Flight (ToF) Sensors** — high-resolution depth at shorter ranges
- **Event Cameras** — capture changes in light intensity; excellent for fast-moving objects

**Applications:**

- Navigation and obstacle avoidance
- Object recognition and manipulation
- Human-robot interaction
- Autonomous vehicles

---

## 1.5 AI in Robotics

### AI Perception Systems

- **Computer Vision** — object/scene recognition, facial recognition, gesture interpretation
- **Object Detection and Tracking** — locating and following objects
- **Sensor Fusion** — combining data from cameras, LiDAR, radar for robust understanding
- **SLAM** — building maps while localizing simultaneously

### Machine Learning in Robotics

| Paradigm | Use |
|---|---|
| **Supervised Learning** | Object recognition, path planning (labeled data) |
| **Unsupervised Learning** | Pattern discovery, anomaly detection, clustering sensor data |
| **Reinforcement Learning** | Autonomous decision-making through trial and error |

### Deep Learning Models

- **CNNs** — visual processing: object recognition, obstacle detection
- **RNNs** — sequential decision-making, predicting future states
- **Transformers** — complex reasoning, natural language interaction

### Edge AI (On-Robot Processing)

- **Reduced latency** — real-time local inference
- **Enhanced privacy** — no external data transmission
- **Cloud independence** — works in offline/remote environments
- **Hardware:** NVIDIA Jetson series (GPU), Google Coral (TPU), Qualcomm Snapdragon (NPU)

### AI-Optimized Control

- **Traditional:** PID, LQR, MPC
- **AI enhancements:** automatic gain tuning, adaptive control, reinforcement learning for optimization

---

## 1.6 Robot Motion and Kinematics

### Locomotion Overview

A mobile robot needs locomotion enabling **unbounded movement** throughout its environment.

**Key issues for locomotion:**

1. **Stability**
   - Number and geometry of contact points
   - Center of gravity
   - Static vs. dynamic stability
   - Terrain inclination

2. **Contact Characteristics**
   - Size and shape of contact patch
   - Angle of contact
   - Friction

3. **Type of Environment**
   - Structure
   - Medium (water, air, soft/hard ground)

**Efficiency Comparison:**

- On flat surfaces: wheeled locomotion is **1–2 orders of magnitude more efficient** than legged
- On soft surfaces: wheels accumulate rolling friction; legs (point contacts) suffer much less
- Railway wheels dominate efficiency on hard surfaces; wheels lose efficiency on soft ground

### Types of Locomotion

1. **Terrestrial** — walking, galloping, running, hopping, crawling, rolling
2. **Flight** — flapping wing, gliding
3. **Aquatic** — swimming (undulatory, flagellar, ciliar), jet propulsion

---

## 1.7 Legged Robots

### Advantages

- Highly adaptable to rough and irregular terrain
- Can traverse gaps larger than stride length
- Can manipulate objects with legs
- Only requires point contacts with ground

### Disadvantages

- High power consumption
- Mechanical complexity
- Requires sufficient DOF for maneuverability

### Stability

**Static Stability:** Balance maintained without motion; center of mass must be within the *support polygon* (convex hull of ground contacts).

- Three-legged stool: stable as long as CoM is within the triangle
- Requires at least 3 contact points
- Static walking requires minimum **4 legs**

**Dynamic Stability:** Requires constant motion; robot actively balances itself.

- Inverted pendulum robots — purely dynamically stable
- Bipedal robots — dynamic due to small support polygon

### Leg Configurations

- **1 leg** — simplest, requires dynamic balance; Raibert's Hopper
- **2 legs (Biped)** — anthropomorphic; ZMP approach for balance; reduced total weight
- **4 legs (Quadruped)** — dynamic stable walking; e.g., AIBO (Sony)
- **6 legs (Hexapod)** — *tripod gait* (2 exterior + 1 inner on each side); static stability possible

**Formula for number of events/gaits with k legs:**

```
N = (2k - 1)!
```

- k=2 legs → 6 events
- k=6 legs → 11! = 39,916,800 events

### Degrees of Freedom in Legs

- Minimum 2 DOF to lift and swing a leg forward
- 3 DOF for more complex maneuvers
- Bipedal robots often add 4th DOF at ankle
- Human leg: 7+ major DOF, 15+ muscle groups, 8 complex joints

---

## 1.8 Wheeled Robots

### Advantages

- Simple mechanical implementation
- Excellent efficiency, especially on flat surfaces
- No active balancing required (3+ wheels = stable)

### Wheel Types

| Type | DOF | Description |
|---|---|---|
| **Standard Wheel** | 2 | Rotation around axle and contact point; directional |
| **Castor Wheel** | 2 | Rotates around offset axis; used in office chairs |
| **Swedish/Omni Wheel** | 3 | Rollers allow lateral motion; omnidirectional |
| **Spherical Wheel** | Omnidirectional | True omnidirectionality; technically difficult |

### Key Design Factors

**Maneuverability:** Ability to move in any direction.

- Omnidirectional robots use Swedish or spherical wheels
- Four-castor configuration solves omnidirectional + ground clearance problem

**Controllability:** Degree to which behavior can be precisely directed.

- **Inverse relationship with maneuverability**: more maneuverable = harder to control
- Ackermann steering is easier to control; omnidirectional harder

**Stability:** Minimum 3 wheels for static stability; suspension needed for 4+ wheels.

### Common Configurations

| Config | Maneuverability | Controllability | Notes |
|---|---|---|---|
| Differential Drive (2 wheels) | Moderate | Good | Most popular; rotate around center |
| Ackermann (car) | Moderate | Excellent | Standard car steering |
| Omnidirectional (Swedish wheels) | Excellent | Complex | All-direction movement |
| Synchro Drive | Good | Moderate | 3 wheels, 2 motors; chassis can drift |
| Tricycle | Moderate | Good | 1 steerable front wheel |

### Synchro Drive

- 3 wheels driven by a **single translation motor**
- All wheels steered by **single steering motor**
- **Advantage:** Omnidirectional movement
- **Disadvantage:** No direct chassis orientation control; drift over time due to belt slop and backlash

---

## 1.9 Aerial Mobile Robots (UAVs)

**Definition:** Unmanned aerial vehicles (UAVs) or drones; operate without onboard human presence in three-dimensional space.

### Aircraft Configurations

- **Lighter Than Air (LTA):** blimps — autolift; simple control; key for surveillance
- **Heavier Than Air (HTA):** multirotors, fixed wing, helicopters
- **VTOL (Vertical Take-Off and Landing):** helicopters, multirotors — most promising for miniaturization

### Key Features

- Autonomous flight with navigation systems and sensors
- Multisensor integration (cameras, LiDAR, GPS, IMU)
- Communication systems for remote control or real-time data
- Energy efficiency critical for flight duration

### Applications

- Surveillance and monitoring
- Mapping and surveying (high-resolution 3D models)
- Search and rescue
- Delivery services
- Precision agriculture

---

## 1.10 Degrees of Freedom (DOF)

**Definition:** The number of independent parameters describing a robot's configuration.

An object in 3D space can have up to **6 DOF:**

- Translations: forward/backward, sideways, up/down
- Rotations: Roll, Pitch, Yaw

**Mobility formula:**

```
M = Σ fi (for all n joints)
```

where fi = 1 for revolute/prismatic/helical joints, fi = 3 for spherical joints.

| DOF | Example | Description |
|---|---|---|
| 2-DOF | Planar robot arm | Move in x, y and rotate |
| 3-DOF | Spherical robot | Any direction within a sphere |
| 5-DOF | Serial manipulator | 3 translations + 2 rotations |
| 6-DOF | Industrial robot arm | Full 3D positioning and orientation |

**Key note:** Only robots with 3-DOF wheels (omnidirectional) can freely move on a plane at any orientation.

---

## 1.11 Robot Kinematics

**Kinematics:** Study of motion without considering its causes (forces).

### Forward Kinematics (FK)

- **Given:** Joint angles and link lengths
- **Find:** Position and orientation of the end-effector
- Uses transformation matrices and vector rotations
- `(joint angles) → (end-effector pose)`

### Inverse Kinematics (IK)

- **Given:** Desired position and orientation of end-effector
- **Find:** Required joint angles
- Uses complex optimization algorithms (computationally expensive)
- `(end-effector pose) → (joint angles)`

### Key Math: Homogeneous Transformation Matrix

A 4×4 matrix combining rotation and translation:

```
H = | R  P |
    | 0  1 |
```

where R is the 3×3 rotation matrix and P is the 3×1 translation vector.

**Rotation matrices:**

- Around Z-axis: `Rz`
- Around Y-axis: `Ry`
- Around X-axis: `Rx`

### Robot Dynamics

**Forward Dynamics:** Given forces → find accelerations (used for simulation)

**Inverse Dynamics:** Given accelerations → find forces (used for control, trajectory design)

**Key Algorithms:**

- **RNEA** (Recursive Newton-Euler) — inverse dynamics, O(n) complexity
- **ABA** (Articulated-Body Algorithm) — forward dynamics, O(n) complexity
- **CRBA** (Composite-Rigid-Body Algorithm) — efficiently computes mass matrix

---

## 1.12 ROS2 Overview

### What is ROS?

**Robot Operating System (ROS)** is an open-source framework for robot software development. Despite its name, it is NOT an OS — it provides:

- **Communication System** (Publish-Subscribe and RPC)
- **Framework & Tools** (build system, visualization — RViz, simulation — Gazebo)
- **Ecosystem** (language bindings, drivers, libraries)

ROS 2 introduced **DDS (Data Distribution Service)** middleware, replacing the centralized Roscore with a decentralized architecture.

### ROS2 Graph Structure

**Nodes:** Independent units representing components (sensors, motion controllers, algorithms).

- Multiple nodes can run within a single process
- Nodes communicate via **Topics**, **Services**, and **Actions**

**Communication Patterns:**

| Pattern | Type | Use |
|---|---|---|
| **Topics** | Publish-Subscribe | Continuous data streams (sensor readings) |
| **Services** | Request-Response | Discrete operations with immediate result |
| **Actions** | Long-running | Tasks with intermediate feedback and final result |

**Messages:** Defined data structures for topic communication (match DDS data types).

**Quality of Service (QoS) Profiles:**

- `Best Effort` — sensor data (no delivery guarantee)
- `Reliable` — commands and parameters (guaranteed delivery)

### ROS2 Filesystem

- **Workspace** — folder for modifying, building, and installing packages (built with Colcon)
- **Packages** — smallest build unit; two types: binary (apt) and build-from-source

### Discovery

ROS2 uses **DDS decentralized discovery** — no central Roscore broker needed. Nodes dynamically discover each other through DDS topics.
