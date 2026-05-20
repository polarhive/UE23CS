# Unit 2: Perception

---

# 2.1 Introduction to Perception

## What is Perception?

**Perception** is the ability of a robot to sense, interpret, and understand its environment. It converts raw sensor data into meaningful information and acts as the **foundation for decision-making and autonomy**.

> Perception enables a robot to answer: **"What is happening around me?"**

## The Perception Pipeline

```
Sensors → Raw Data → Data Processing → Environment Understanding → Situation Assessment → Decision Making
```

## Components of a Robotic Perceptual System

1. **Sensory Inputs** — raw data from sensors
2. **Data Processing** — filtering, transformation
3. **Environment Understanding** — objects, obstacles, terrain
4. **Situation Assessment** — context and state interpretation
5. **Decision Making** — action selection

---

# 2.2 Sensors: Fundamentals

## What is a Sensor?

A sensor is a device that extracts **measurable quantities** from surroundings. Sensors can measure:

- Internal robot state (motor speed, joint angle, voltage)
- External environment (distance to obstacles, light, sound)

## Sensor Classification (Two Axes)

### Axis 1: Proprioceptive vs. Exteroceptive

| Type | Measures | Examples |
|------|---------|---------|
| **Proprioceptive** | Internal robot state | Motor speed, wheel load, joint angles, battery voltage |
| **Exteroceptive** | External environment | Light intensity, sound, distance to obstacles |

### Axis 2: Passive vs. Active

| Type | How it Works | Examples | Risk |
|------|-------------|---------|------|
| **Passive** | Measures ambient energy entering the sensor | Cameras (CCD/CMOS), temperature probes, microphones | — |
| **Active** | Emits energy into environment, measures reaction | Ultrasonic, laser range finders, wheel encoders | May interfere with environment or other sensors |

> Active sensors generally achieve superior performance due to controlled interactions, but may cause interference between multiple sensors on the same robot.

---

# 2.3 Sensor Characteristics

## Key Performance Metrics

### 1. Resolution

**Minimum detectable difference** between two values.

*Example:* An 8-bit ADC sensor measuring 0–5V has:

- 2⁸ − 1 = 255 output levels
- Resolution = 5V / 255 ≈ **20 mV**

### 2. Dynamic Range

The ratio of maximum to minimum measurable input, expressed in **decibels (dB)**.

- `Dynamic Range (dB) = 10 × log₁₀(max/min)` for power-like quantities
- `Dynamic Range (dB) = 20 × log₁₀(max/min)` for voltage/amplitude

*Example:* Current sensor: 1 mA to 20 A → `20 × log₁₀(20000/1) = ~86 dB`

### 3. Sensitivity

Ratio of output change to input change.

- High sensitivity = large output fluctuation per unit input change
- **Cross-sensitivity:** Sensitivity to parameters *other* than the target (e.g., compass sensitive to ferrous building materials)

### 4. Linearity

A linear sensor satisfies: `f(ax + by) = af(x) + bf(y)`

Linear sensors are easier to model and calibrate.

### 5. Bandwidth / Frequency

Number of measurements per second (Hz).

- Critical for mobile robots — maximum speed may be limited by obstacle sensor bandwidth
- High-bandwidth ranging/vision sensors are a major research priority

### 6. Error

`error = measured_value − true_value`

| Type | Description | Example |
|------|-------------|---------|
| **Systematic Error** | Deterministic, modelable | Poor calibration, bent sensor head |
| **Random Error** | Stochastic, probabilistic | Hue instability in cameras, shot noise |

### 7. Precision vs. Accuracy

- **Precision:** Reproducibility — same result repeatedly (may be wrong)
- **Accuracy:** Closeness to true value

> A sensor can be precise (consistent) but inaccurate (consistently wrong), or accurate but imprecise (correct on average but noisy).

### 8. Cost and Weight

- Cost must balance with reliability, accuracy, and life
- Weight is critical for mobile/aerial robots (heavy sensor reduces payload)

---

# 2.4 Non-Perception Sensors (Proprioceptive)

## Optical Encoders

**Purpose:** Measure angular speed and position (odometry)

- **Type:** Proprioceptive, Active
- Work by counting pulses as a disk with holes/lines rotates past an LED-photodiode pair
- **Incremental encoders:** Count pulses relative to a reference
- **Absolute encoders:** Directly report position

**Use in robots:** Wheel encoders feed into odometry — estimating robot position from wheel motion.

## Gyroscope

**Purpose:** Measure angular velocity (rate of rotation)

- Measures rotation about one or more axes
- Used to detect turning/rotation
- Drift accumulates over time — needs correction

## Accelerometer

**Purpose:** Measure linear acceleration

- Measures forces due to acceleration (including gravity)
- Used to detect motion changes, tilt, vibration
- Inexpensive MEMS-based versions widely used

## IMU (Inertial Measurement Unit)

**Purpose:** Combine gyroscope + accelerometer (+ sometimes magnetometer)

- Provides 6-DOF measurement: 3-axis acceleration + 3-axis angular velocity
- **9-DOF IMU** adds 3-axis magnetometer
- Used for dead reckoning, orientation estimation
- Error accumulates — requires external correction (GPS, visual odometry)

## GPS / GNSS

**Purpose:** Absolute global position

| Variant | Accuracy | Notes |
|---------|---------|-------|
| Standard GPS | ~3–5 m | Adequate for coarse localization |
| Differential GPS (DGPS) | ~1–3 m | Uses correction signals |
| RTK-GPS | ~1–2 cm | Real-time kinematics; sub-centimeter |

- **GNSS** (Global Navigation Satellite System) — umbrella term (GPS, GLONASS, Galileo, BeiDou)
- Works outdoors only; degrades in urban canyons and indoors

---

# 2.5 Perception Sensors (Exteroceptive)

## Range Sensors

### Ultrasonic Sensors

- Emit ultrasonic pulses, measure time-of-flight
- Range: ~2 cm to 4 m
- Low cost, simple
- Limited accuracy; susceptible to multi-path and reflective surfaces
- Cannot detect thin objects reliably

### Infrared (IR) Sensors

- Measure reflected infrared light
- Short range (~few cm to ~1.5 m)
- Cheap and fast
- Highly sensitive to ambient light and surface color/reflectivity

### Laser Range Finders (LiDAR)

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

# 2.6 Vision Sensors (Cameras)

## Standard Cameras (RGB Cameras)

- Most common sensor in robotics
- Provide color or grayscale images
- Require image processing for depth estimation
- Types: USB cameras, GigE, MIPI (on embedded systems)

## Depth Cameras

- Capture depth information along with the image → 3D perception
- Structured light (e.g., Intel RealSense, Kinect)
- Time-of-Flight (ToF)

## Stereo Cameras

- Two cameras separated by a baseline
- Compute depth via **disparity** between left and right images
- Foundation of stereo vision (covered below)

## Thermal Cameras

- Detect infrared radiation (heat)
- Useful in low-light conditions
- Detect humans, animals; used in search and rescue

## Time-of-Flight (ToF) Sensors

- Similar to LiDAR but uses modulated light
- High-resolution depth data at short ranges
- Suited for indoor applications

## Event Cameras

- Novel vision sensor
- Detects changes in brightness (events) asynchronously per pixel
- Very low latency (~1 µs); ideal for high-speed motion

---

# 2.7 Vision-Based Perception

## Fundamentals of Computer Vision in Robotics

### Image Processing Basics

- **Filtering:** Remove noise (Gaussian blur, median filter)
- **Edge Detection:** Sobel, Canny operators
- **Thresholding:** Binary segmentation
- **Morphological operations:** Dilation, erosion for shape analysis

## Feature Extraction

### What is a Feature?

A distinctive, repeatable pattern in an image used for matching and recognition.

### Properties of an Ideal Feature Detector

1. **Repeatability:** Rediscovered in different views of the same scene
2. **Distinctiveness:** Distinguishable from other features
3. **Localization accuracy:** Precise in position and scale
4. **Quantity:** Enough features for the task
5. **Invariance:** Stable under rotation, scale, illumination changes
6. **Computational efficiency:** Fast, especially for real-time robotics
7. **Robustness:** Tolerant of noise, blur, compression artifacts

---

# 2.8 Corner Detectors

## Why Corners?

A corner is the **intersection of two or more edges**. Corners have high repeatability — they're distinctive in all directions.

## Moravec Corner Detector

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

## Harris Corner Detector

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

## Scale-Invariant Detection

**Problem:** Harris fails when image scale changes.

**Solution:** Multiscale Harris using **scale-space pyramid** — apply detector at multiple resolutions (downsampled versions of the image).

## Affine Invariant Detection

**Harris-Affine detector** (Mikolajczyk & Schmid):

1. Detect features with scale-invariant Harris-Laplacian
2. Use second moment matrix to find dominant directions
3. Compute elliptical region; normalize to circle
4. Achieves invariance to affine transformations

## Other Corner Detectors

- **Shi-Tomasi:** Closely based on Harris; uses `min(λ₁, λ₂)` as score
- **SUSAN:** Smallest Univalue Segment Assimilating Nucleus; also does edge detection and noise suppression
- **FAST:** Features from Accelerated Segment Test — very fast, used in real-time robotics

---

# 2.9 Stereo Vision and 3D Perception

## What is Stereo Vision?

Stereo vision computes **depth from a pair of images** captured by two cameras at different positions (mimicking human binocular vision).

**Stereopsis:** The perception of depth from slightly different projections in two eyes. The difference between left/right images is called **disparity**.

## Basic Stereo Model

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

## Key Observations

1. **Depth ∝ 1/disparity** — near objects measured more accurately than distant
2. **Disparity ∝ baseline** — larger baseline → more accurate depth for same disparity error
3. Increasing baseline causes **occlusion** — some objects visible in only one camera
4. Unknown baseline → scene reconstructed only **up to scale** (structure-from-motion case)

## The Correspondence Problem

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

# 2.10 Feature Extraction from Range Data

## Laser Range Data Features

LiDAR provides precise distance measurements; useful features include:

- Lines (walls, edges)
- Corners (room corners, furniture)
- Planes (floors, walls in 3D LiDAR)

## Feature Extraction Process

1. Raw LiDAR scan → set of distance measurements
2. Segment scan into groups of nearby points
3. Fit geometric primitives (lines, circles) to each segment
4. Extract endpoints, corners, or center points as features

---

# 2.11 AI-Based Perception

## Deep Learning in Perception

| Technique | Application |
|-----------|------------|
| **CNN (Convolutional Neural Network)** | Object detection, classification, segmentation |
| **RNN / LSTM** | Sequential decision-making, video understanding |
| **Sensor Fusion with ML** | Combining camera + LiDAR + radar |

## Sensor Fusion

AI combines data from multiple sensors (e.g., cameras, LiDAR, radar) to:

- Improve robustness
- Handle sensor failures
- Get complementary information

**Example:** Camera provides color/texture; LiDAR provides accurate depth → fused for robust 3D understanding.

## Object Detection and Place Recognition

### Object Detection

- Identify and localize objects in camera images
- Methods: YOLO, Faster R-CNN, SSD
- Output: Bounding boxes + class labels

### Place Recognition

- Determine if a current camera view matches a previously seen location
- Critical for **loop closure detection** in SLAM
- Methods: Bag-of-Words (BoW), NetVLAD, deep embeddings

---

# 2.12 Choosing the Right Sensor

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

# 2.13 Summary

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
