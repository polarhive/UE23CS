# Unit 1: Locomotion

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

---

# Unit 2: Perception

## 2.1 Introduction to Perception

### What is Perception?

**Perception** is the ability of a robot to sense, interpret, and understand its environment. It converts raw sensor data into meaningful information and acts as the **foundation for decision-making and autonomy**.

> Perception enables a robot to answer: **"What is happening around me?"**

### The Perception Pipeline

```
Sensors → Raw Data → Data Processing → Environment Understanding → Situation Assessment → Decision Making
```

### Components of a Robotic Perceptual System

1. **Sensory Inputs** — raw data from sensors
2. **Data Processing** — filtering, transformation
3. **Environment Understanding** — objects, obstacles, terrain
4. **Situation Assessment** — context and state interpretation
5. **Decision Making** — action selection

---

## 2.2 Sensors: Fundamentals

### What is a Sensor?

A sensor is a device that extracts **measurable quantities** from surroundings. Sensors can measure:

- Internal robot state (motor speed, joint angle, voltage)
- External environment (distance to obstacles, light, sound)

### Sensor Classification (Two Axes)

#### Axis 1: Proprioceptive vs. Exteroceptive

| Type | Measures | Examples |
|------|---------|---------|
| **Proprioceptive** | Internal robot state | Motor speed, wheel load, joint angles, battery voltage |
| **Exteroceptive** | External environment | Light intensity, sound, distance to obstacles |

#### Axis 2: Passive vs. Active

| Type | How it Works | Examples | Risk |
|------|-------------|---------|------|
| **Passive** | Measures ambient energy entering the sensor | Cameras (CCD/CMOS), temperature probes, microphones | — |
| **Active** | Emits energy into environment, measures reaction | Ultrasonic, laser range finders, wheel encoders | May interfere with environment or other sensors |

> Active sensors generally achieve superior performance due to controlled interactions, but may cause interference between multiple sensors on the same robot.

---

## 2.3 Sensor Characteristics

### Key Performance Metrics

#### 1. Resolution

**Minimum detectable difference** between two values.

*Example:* An 8-bit ADC sensor measuring 0–5V has:

- 2⁸ − 1 = 255 output levels
- Resolution = 5V / 255 ≈ **20 mV**

#### 2. Dynamic Range

The ratio of maximum to minimum measurable input, expressed in **decibels (dB)**.

- `Dynamic Range (dB) = 10 × log₁₀(max/min)` for power-like quantities
- `Dynamic Range (dB) = 20 × log₁₀(max/min)` for voltage/amplitude

*Example:* Current sensor: 1 mA to 20 A → `20 × log₁₀(20000/1) = ~86 dB`

#### 3. Sensitivity

Ratio of output change to input change.

- High sensitivity = large output fluctuation per unit input change
- **Cross-sensitivity:** Sensitivity to parameters *other* than the target (e.g., compass sensitive to ferrous building materials)

#### 4. Linearity

A linear sensor satisfies: `f(ax + by) = af(x) + bf(y)`

Linear sensors are easier to model and calibrate.

#### 5. Bandwidth / Frequency

Number of measurements per second (Hz).

- Critical for mobile robots — maximum speed may be limited by obstacle sensor bandwidth
- High-bandwidth ranging/vision sensors are a major research priority

#### 6. Error

`error = measured_value − true_value`

| Type | Description | Example |
|------|-------------|---------|
| **Systematic Error** | Deterministic, modelable | Poor calibration, bent sensor head |
| **Random Error** | Stochastic, probabilistic | Hue instability in cameras, shot noise |

#### 7. Precision vs. Accuracy

- **Precision:** Reproducibility — same result repeatedly (may be wrong)
- **Accuracy:** Closeness to true value

> A sensor can be precise (consistent) but inaccurate (consistently wrong), or accurate but imprecise (correct on average but noisy).

#### 8. Cost and Weight

- Cost must balance with reliability, accuracy, and life
- Weight is critical for mobile/aerial robots (heavy sensor reduces payload)

---

## 2.4 Non-Perception Sensors (Proprioceptive)

### Optical Encoders

**Purpose:** Measure angular speed and position (odometry)

- **Type:** Proprioceptive, Active
- Work by counting pulses as a disk with holes/lines rotates past an LED-photodiode pair
- **Incremental encoders:** Count pulses relative to a reference
- **Absolute encoders:** Directly report position

**Use in robots:** Wheel encoders feed into odometry — estimating robot position from wheel motion.

### Gyroscope

**Purpose:** Measure angular velocity (rate of rotation)

- Measures rotation about one or more axes
- Used to detect turning/rotation
- Drift accumulates over time — needs correction

### Accelerometer

**Purpose:** Measure linear acceleration

- Measures forces due to acceleration (including gravity)
- Used to detect motion changes, tilt, vibration
- Inexpensive MEMS-based versions widely used

### IMU (Inertial Measurement Unit)

**Purpose:** Combine gyroscope + accelerometer (+ sometimes magnetometer)

- Provides 6-DOF measurement: 3-axis acceleration + 3-axis angular velocity
- **9-DOF IMU** adds 3-axis magnetometer
- Used for dead reckoning, orientation estimation
- Error accumulates — requires external correction (GPS, visual odometry)

### GPS / GNSS

**Purpose:** Absolute global position

| Variant | Accuracy | Notes |
|---------|---------|-------|
| Standard GPS | ~3–5 m | Adequate for coarse localization |
| Differential GPS (DGPS) | ~1–3 m | Uses correction signals |
| RTK-GPS | ~1–2 cm | Real-time kinematics; sub-centimeter |

- **GNSS** (Global Navigation Satellite System) — umbrella term (GPS, GLONASS, Galileo, BeiDou)
- Works outdoors only; degrades in urban canyons and indoors

---

## 2.5 Perception Sensors (Exteroceptive)

### Range Sensors

#### Ultrasonic Sensors

- Emit ultrasonic pulses, measure time-of-flight
- Range: ~2 cm to 4 m
- Low cost, simple
- Limited accuracy; susceptible to multi-path and reflective surfaces
- Cannot detect thin objects reliably

#### Infrared (IR) Sensors

- Measure reflected infrared light
- Short range (~few cm to ~1.5 m)
- Cheap and fast
- Highly sensitive to ambient light and surface color/reflectivity

#### Laser Range Finders (LiDAR)

**LiDAR = Light Detection and Ranging**

- Emits laser pulses and measures time-of-flight for each
- Provides highly accurate distance measurements
- **2D LiDAR:** Rotates to build 360° planar scan (e.g., SICK, Hokuyo)
- **3D LiDAR:** Multiple beams or rotating mechanism for 3D point cloud (e.g., Velodyne)

| Feature | Value |
|---------|-------|
| Range | Up to 100m+ |
| Accuracy | ±1–3 cm |
| Output | Point cloud |
| Cost | Medium to high |

**Applications:**

- Obstacle detection and avoidance
- SLAM
- Autonomous vehicle navigation

---

## 2.6 Vision Sensors (Cameras)

### Standard Cameras (RGB Cameras)

- Most common sensor in robotics
- Provide color or grayscale images
- Require image processing for depth estimation
- Types: USB cameras, GigE, MIPI (on embedded systems)

### Depth Cameras

- Capture depth information along with the image → 3D perception
- Structured light (e.g., Intel RealSense, Kinect)
- Time-of-Flight (ToF)

### Stereo Cameras

- Two cameras separated by a baseline
- Compute depth via **disparity** between left and right images
- Foundation of stereo vision (covered below)

### Thermal Cameras

- Detect infrared radiation (heat)
- Useful in low-light conditions
- Detect humans, animals; used in search and rescue

### Time-of-Flight (ToF) Sensors

- Similar to LiDAR but uses modulated light
- High-resolution depth data at short ranges
- Suited for indoor applications

### Event Cameras

- Novel vision sensor
- Detects changes in brightness (events) asynchronously per pixel
- Very low latency (~1 µs); ideal for high-speed motion

---

## 2.7 Vision-Based Perception

### Fundamentals of Computer Vision in Robotics

#### Image Processing Basics

- **Filtering:** Remove noise (Gaussian blur, median filter)
- **Edge Detection:** Sobel, Canny operators
- **Thresholding:** Binary segmentation
- **Morphological operations:** Dilation, erosion for shape analysis

### Feature Extraction

#### What is a Feature?

A distinctive, repeatable pattern in an image used for matching and recognition.

#### Properties of an Ideal Feature Detector

1. **Repeatability:** Rediscovered in different views of the same scene
2. **Distinctiveness:** Distinguishable from other features
3. **Localization accuracy:** Precise in position and scale
4. **Quantity:** Enough features for the task
5. **Invariance:** Stable under rotation, scale, illumination changes
6. **Computational efficiency:** Fast, especially for real-time robotics
7. **Robustness:** Tolerant of noise, blur, compression artifacts

---

## 2.8 Corner Detectors

### Why Corners?

A corner is the **intersection of two or more edges**. Corners have high repeatability — they're distinctive in all directions.

### Moravec Corner Detector

**Principle:** A corner is a point where all neighboring windows look different.

- **Flat region:** All windows look similar
- **Edge:** Windows perpendicular to edge differ; parallel ones don't
- **Corner:** ALL adjacent windows are different

**Algorithm:**

1. Select target pixel
2. Define 3×3 reference matrix around pixel
3. Shift matrix in 8 directions (up, down, left, right, 4 diagonals)
4. Compute **SSD (Sum of Squared Differences)** for each shift:
   `SSD = Σ(Reference − Shifted)²`
5. Select **minimum SSD** across all shifts
6. Compare with threshold:
   - If `min_SSD > threshold` → **CORNER**
   - If `min_SSD ≤ threshold` → not a corner

**Example:**

- SSD values in 8 directions: [395, 451, 422, 576, 227, 764, 493, 702]
- Minimum SSD = 227 (SSD5 = diagonal shift)
- Threshold = 220 → Since 227 > 220 → **CORNER detected**

### Harris Corner Detector

Improvement over Moravec using **partial derivatives of the SSD** instead of shifted windows.

**Second Moment Matrix M:**

```
M = Σ w(x,y) [ Ix²   IxIy ]
              [ IxIy  Iy²  ]
```

Where Ix, Iy are image gradients.

**Corner Detection via Eigenvalues of M:**

| Eigenvalue Magnitudes | Classification |
|----------------------|---------------|
| Both λ₁, λ₂ small | Flat region |
| One large, one small | Edge |
| Both λ₁, λ₂ large | **Corner** |

**Harris Response Function (avoids expensive eigenvalue computation):**

```
R = det(M) − k × trace(M)²
  = λ₁λ₂ − k(λ₁+λ₂)²
```

Where k ≈ 0.04–0.15 (empirically tuned)

**Process:** Extract local maxima of R above a threshold using non-maxima suppression.

**Invariance Properties:**

- ✅ Invariant to 2D rotation
- ✅ Invariant to affine intensity changes
- ❌ NOT invariant to scale changes
- ❌ NOT invariant to geometric affine transformations

> After rescaling by 2×, only ~20% of Harris corners are re-detected. Despite this, Harris remains widely used (available in OpenCV).

### Scale-Invariant Detection

**Problem:** Harris fails when image scale changes.

**Solution:** Multiscale Harris using **scale-space pyramid** — apply detector at multiple resolutions (downsampled versions of the image).

### Affine Invariant Detection

**Harris-Affine detector** (Mikolajczyk & Schmid):

1. Detect features with scale-invariant Harris-Laplacian
2. Use second moment matrix to find dominant directions
3. Compute elliptical region; normalize to circle
4. Achieves invariance to affine transformations

### Other Corner Detectors

- **Shi-Tomasi:** Closely based on Harris; uses `min(λ₁, λ₂)` as score
- **SUSAN:** Smallest Univalue Segment Assimilating Nucleus; also does edge detection and noise suppression
- **FAST:** Features from Accelerated Segment Test — very fast, used in real-time robotics

---

## 2.9 Stereo Vision and 3D Perception

### What is Stereo Vision?

Stereo vision computes **depth from a pair of images** captured by two cameras at different positions (mimicking human binocular vision).

**Stereopsis:** The perception of depth from slightly different projections in two eyes. The difference between left/right images is called **disparity**.

### Basic Stereo Model

Two cameras with:

- Parallel optical axes
- Separation of **b** (baseline)

**Depth formula:**

```
Z = (f × b) / d
```

Where:

- Z = depth of point
- f = focal length
- b = baseline (camera separation)
- d = disparity (difference in x-coordinates in left vs. right image)

### Key Observations

1. **Depth ∝ 1/disparity** — near objects measured more accurately than distant
2. **Disparity ∝ baseline** — larger baseline → more accurate depth for same disparity error
3. Increasing baseline causes **occlusion** — some objects visible in only one camera
4. Unknown baseline → scene reconstructed only **up to scale** (structure-from-motion case)

### The Correspondence Problem

**Core challenge:** Finding which pixel in the left image matches which pixel in the right image.

**Difficulties:**

- **Occlusions** — object visible in one camera, hidden in other
- **Photometric distortion** — illumination differences between cameras
- **Projective distortion** — geometric differences

**Helpful Constraints:**

1. **Similarity constraint** — matched points should look similar
2. **Continuity constraint** — depth changes smoothly
3. **Uniqueness** — each point in one image maps to at most one in other
4. **Monotonic order** — order of points along epipolar line is preserved
5. **Epipolar constraint** — corresponding point in right image must lie on **epipolar line**
6. **Area-based matching** — compare patches (windows) around points
7. **Feature-based matching** — compare feature descriptors

---

## 2.10 Feature Extraction from Range Data

### Laser Range Data Features

LiDAR provides precise distance measurements; useful features include:

- Lines (walls, edges)
- Corners (room corners, furniture)
- Planes (floors, walls in 3D LiDAR)

### Feature Extraction Process

1. Raw LiDAR scan → set of distance measurements
2. Segment scan into groups of nearby points
3. Fit geometric primitives (lines, circles) to each segment
4. Extract endpoints, corners, or center points as features

---

## 2.11 AI-Based Perception

### Deep Learning in Perception

| Technique | Application |
|-----------|------------|
| **CNN (Convolutional Neural Network)** | Object detection, classification, segmentation |
| **RNN / LSTM** | Sequential decision-making, video understanding |
| **Sensor Fusion with ML** | Combining camera + LiDAR + radar |

### Sensor Fusion

AI combines data from multiple sensors (e.g., cameras, LiDAR, radar) to:

- Improve robustness
- Handle sensor failures
- Get complementary information

**Example:** Camera provides color/texture; LiDAR provides accurate depth → fused for robust 3D understanding.

### Object Detection and Place Recognition

#### Object Detection

- Identify and localize objects in camera images
- Methods: YOLO, Faster R-CNN, SSD
- Output: Bounding boxes + class labels

#### Place Recognition

- Determine if a current camera view matches a previously seen location
- Critical for **loop closure detection** in SLAM
- Methods: Bag-of-Words (BoW), NetVLAD, deep embeddings

---

## 2.12 Choosing the Right Sensor

| Application | Recommended Sensor |
|-------------|-------------------|
| Precise distance (outdoors/indoors) | 2D/3D LiDAR |
| Short-range proximity | Ultrasonic / IR |
| Vision, object detection | Camera (RGB/Depth) |
| Global position (outdoors) | GPS / RTK-GPS |
| Orientation, motion | IMU (Gyro + Accel) |
| High-speed motion | Event camera |
| Night/heat detection | Thermal camera |
| Self-localization via wheels | Optical encoders |

---

## 2.13 Summary

| Concept | Key Points |
|---------|-----------|
| Perception | Converting raw sensor data to meaningful info |
| Passive sensors | Measure ambient energy (camera, microphone) |
| Active sensors | Emit + measure (LiDAR, ultrasonic) |
| Proprioceptive | Internal state (encoders, IMU) |
| Exteroceptive | External world (camera, LiDAR, GPS) |
| Harris corner | R = det(M) − k·trace(M)²; eigenvalue-based |
| Stereo vision | Depth = f·b/d; correspondence problem is key |
| Sensor fusion | Multiple sensors → more robust perception |

---

# Unit 3: Localization

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

---

# Unit 4: Navigation

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
