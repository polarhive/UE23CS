# IoT ESA Notes

## Unit 1: Introduction, Concepts, and Industry Verticals

### 1.1 Introduction and History of IoT

| Aspect            | Details                                                                                                                                                                                                    | Source |
| :---------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----- |
| **Definition**    | The Internet of Things (IoT) is a network of physical objects (devices, vehicles, appliances, and machines) embedded with sensors, software, and connectivity, enabling them to collect and exchange data. |        |
| **Smart Objects** | IoT devices, also known as "smart objects," range from consumer items (smart thermostats, wearables) to complex systems (industrial machinery, transportation).                                            |        |
| **Genesis**       | The concept began with early experiments in the **1980s–1990s** (e.g., the internet-connected Coke machine).                                                                                               |        |
| **Term Coined**   | The term "Internet of Things" was introduced in **1999** by **Kevin Ashton** at the MIT Auto-ID Lab.                                                                                                       |        |
| **Mass Adoption** | Widespread consumer and industrial adoption surged post-2010 with the rise of affordable sensors, reliable wireless tech (Wi-Fi, BLE), microcontrollers, and cloud services.                               |        |
| **Market Value**  | The global IoT market is projected to surpass **$300+ billion by 2023**.                                                                                                                                   |        |

### 1.2 Core Concepts and Building Blocks

IoT relies on the ability of physical objects to perform four core functions:

1. **Sensing:** Devices use embedded sensors to collect real-time data about the environment (e.g., temperature, pressure, motion).
2. **Connectivity:** Physical objects must connect to the internet, often facilitated by low-power, wide-area networks (LPWANs) such as Sigfox, LoRaWAN, and NB-IoT.
3. **Communication:** Data exchange occurs using standardized protocols like **MQTT, CoAP, and HTTP**.
4. **Analytics:** Collected data is analyzed to gain insights for improving efficiency, optimizing processes, and making better decisions.

### 1.3 IoT Traffic Model

IoT traffic patterns fundamentally differ from human-generated internet traffic:

|Aspect|Human-Generated Traffic|IoT-Generated Traffic|Source|
|:--|:--|:--|:--|
|**Event Dependency**|Not event-based (often random)|**Event-based** (e.g., triggered by an alarm or change in state)||
|**Traffic Pattern**|Peaks during the day|**Periodic** throughout the day||
|**Traffic Direction**|High downlink (downloading content)|**High uplink** (devices sending sensor data)||
|**Mobility**|Application-dependent|Mostly **stationary** (exceptions exist, e.g., wearables)||

**Traffic Examples by Device:**

- **Smoke Detector:** Event-based, low latency, requires acknowledgment (ACK).
- **Surveillance Camera:** Event-based, but transfers large data volumes.
- **Smart Meters:** Mix of periodic updates and event-based transmissions (e.g., power outage notification).

### 1.4 IoT Industry Verticals

IoT verticals are industry-specific domains that apply IoT technologies to solve unique problems, generating value through tailored solutions.

1. **Industrial IoT (IIoT) / Industry 4.0**
    - **Focus:** Integrating sensors and analytics into manufacturing, energy, and logistics.
    - **Use Cases:** **Predictive maintenance** (using vibration/thermal sensors to anticipate failure), asset tracking/uptime monitoring, and digital twin modeling.
    - **Benefits:** Increases efficiency and productivity, enhances worker safety, and reduces asset lifecycle costs.
2. **Smart Cities**
    - **Definition:** Urban areas using IoT and ICT to improve quality of life, sustainability, and efficiency of operations.
    - **Components:**
        - **Smart Governance:** Centralized planning and coordinated infrastructure development (e.g., India's Gati Shakti platform).
        - **Smart Mobility:** Adaptive traffic signals based on real-time congestion, smart parking systems, and GPS-enabled public transport tracking.
        - **Smart Environment:** Air/noise pollution sensors, real-time waste management monitoring, and weather sensors for disaster forecasting.
3. **Smart Healthcare / IoMT (Internet of Medical Things)**
    - **Focus:** Integrating devices for real-time patient monitoring and enhanced operational efficiency.
    - **Key Applications:**
        - **Remote Patient Monitoring (RPM):** Wearables track vital signs (heart rate, SpO₂, glucose) for chronic illness management.
        - **Predictive Maintenance:** Sensors on MRI/ventilators predict faults, ensuring continuity of care.
        - **Asset Tracking:** Locating critical equipment (wheelchairs, pumps) within hospitals.
        - **Medication Adherence:** Smart pill dispensers track intake and send reminders.
    - **Patient Benefits:** Personalized care, greater accessibility (reduced hospital visits), better chronic disease management, and faster emergency response.
4. **Smart Agriculture (Smart Farming)**
    - **Focus:** Managing farms using technology to increase quantity/quality of products while optimizing labor and resources.
    - **Technology:** Sensors (soil, water, temp, light), robotics (autonomous tractors), GPS, and cellular/LoRa connectivity.
    - **Applications:** Precision crop monitoring (soil pH/moisture tracking), automated irrigation systems, drone surveillance for pest detection, and livestock monitoring (health/location tracking).
    - **Operational Cycle:** Data Collection → Diagnostics (problems identified) → Decision Making (optimal actions decided) → Actions (automated response).
5. **Connected Vehicles**
    - **Focus:** Vehicles establishing wireless connections (WLAN) to exchange data bi-directionally with other vehicles (V2V), mobile devices, and infrastructure.
    - **Applications:** Adaptive cruise control, real-time route planning, dynamic road signage updates (weather/traffic/hazards), automatic collision avoidance, and autonomous driving.

---

## Unit 2: IoT Hardware and Performance Metrics

### 2.1 The "Things": Sensors, Actuators, and Smart Objects

|Component|Role|Function in IoT|Examples|Source|
|:--|:--|:--|:--|:--|
|**Sensor**|Input Device (Eyes/Ears)|Detects changes in the physical environment and converts phenomena (heat, motion, sound) into measurable electrical signals.|Thermometer, LDR, Accelerometer, Pressure sensors.||
|**Actuator**|Output Device (Hands)|Converts an electrical signal (command) from the controller into a physical action (motion, flow, light, sound).|Electric motors, Solenoid valves, Relays, LEDs.||
|**Smart Object**|Autonomous Entity|Combines **Sensing, Processing, Communication, and Actuation/Logic** to interact intelligently with the environment.|Smart Thermostat (senses temp, processes data, controls AC/heat relay).||

**Sensor Classification**

|Classification Type|Subcategory|Mechanism/Definition|Examples|Source|
|:--|:--|:--|:--|:--|
|**By Energy Source**|**Active**|Emits energy (light, radio waves, sound) and measures the reflected response signal. Requires continuous power.|Radar, LiDAR, Ultrasonic sensor.||
||**Passive**|Detects natural energy (heat, light, radiation) coming from the object/environment without emitting its own energy.|Thermocouple, PIR sensor, Photodiode.||
|**By Interaction**|**Invasive**|Inserted into or becomes part of the measured system (direct, internal measurement).|pH probe, blood glucose needle sensor.||
||**Non-Invasive**|Operates externally without disturbing the system (indirect, external observation).|Infrared thermometer, wearable fitness tracker.||

**Actuator Control Methods**

1. **Open-loop control:** The actuator executes a command for a fixed time/intensity without utilizing feedback from sensors. This method is simple but inefficient.
2. **Closed-loop control:** The system uses feedback from sensors to continuously adjust actuator behavior to meet desired output (e.g., thermostat adjusting based on live temperature readings). This method is accurate and adaptive.

### 2.2 Sensor Performance Metrics

Metrics assess the quality, reliability, and suitability of a sensor for an application.

#### Static Performance Metrics (Steady Conditions)

|Metric|Definition|Importance / Example|Source|
|:--|:--|:--|:--|
|**Accuracy**|How close the measured value is to the true or standard value.|Critical for medical and scientific systems where precision error is unacceptable.||
|**Precision** (Repeatability)|The consistency or reproducibility of repeated measurements under identical conditions.|Essential for trend analysis; ensures consistency even if slightly off the true value.||
|**Sensitivity**|The ratio of output change relative to a unit change in input quantity.|Higher sensitivity allows detection of smaller changes (e.g., minor pressure shifts).||
|**Resolution**|The smallest increment of the measured quantity that the device can detect and report.|Crucial for high-precision applications like ECGs or detailed position sensing.||
|**Linearity**|How well the sensor’s output follows a directly proportional straight line over its measurement range.|Poor linearity introduces errors that calibration alone cannot fix.||
|**Range**|The minimum and maximum values within which the sensor can accurately measure.|Must encompass the expected measurement extremes to prevent saturation or loss of accuracy.||
|**Offset**|The non-zero output when the measured quantity is zero.|Must be corrected during sensor calibration.||
|**Drift**|The gradual change in a sensor’s reading over time when the actual input value remains constant.|Impacts the reliability of long-term deployments.||

#### Dynamic Performance Metrics (Changing Conditions)

|Metric|Definition|Importance|Source|
|:--|:--|:--|:--|
|**Response Time**|The speed at which a sensor reacts to a step change in input and settles to a stable output (typically 90–95% of the final value).|Crucial for real-time safety-critical systems (e.g., gas detection, industrial control).||
|**Signal-to-Noise Ratio (SNR)**|The level of the desired signal relative to the background noise.|High SNR ensures clear, usable data even in noisy environments (e.g., industrial settings).||
|**Bandwidth**|The range of frequencies over which the sensor can reliably operate and track the input signal without distortion.|Needed for dynamic applications like vibration monitoring or audio processing.||

---

## Unit 3: IoT Architectures and Protocols

### 3.1 IoT Architecture Models

IoT architecture is the structure that enables device communication. The lack of standardized protocols creates compatibility and security challenges.

|Model|Layers|Key Role of Added Layers (vs 3-Layer)|Source|
|:--|:--|:--|:--|
|**Three-Layer (Basic)**|1. Perception, 2. Network, 3. Application|Conceptual model emphasizing sensing, transmission, and end-user services.||
|**Five-Layer**|1. Perception, 2. Network, **3. Data Processing**, **4. Service**, 5. Application|Separates processing (filtering/aggregation/edge analytics) and service orchestration (middleware/APIs) for real-world deployments.||
|**IoTWF Architecture (Cisco)**|7 Layers (Physical, Connectivity, Edge Computing, Data Accumulation, Data Abstraction, Application, Collaboration)|Industrial-grade reference model emphasizing cross-cutting **Security** and **Management** layers.||
|**oneM2M**|Horizontal Service Layer (CSE, AE, NSE)|A global standard that provides a **Common Service Entity (CSE)** for device registration, security, and data management, ensuring cross-industry interoperability and avoiding vendor lock-in.||

### 3.2 Architectural Drivers

These are core requirements and constraints that influence system design.

1. **Scalability:** The ability to handle increasing loads (millions of devices, petabytes of data, many users) without performance degradation.
    - _Types:_ Device, Data, User/Application, and Functional Scalability.
    - _Architectural Requirements:_ Cloud-Native Infrastructure (elastic scaling, e.g., AWS/Azure), Microservices Architecture (independent scaling of functions), Message Queuing (decouples producers/consumers using MQTT/Kafka), and Horizontal Scaling (adding nodes instead of upgrading one).
2. **Latency Sensitivity:** The degree to which an application is affected by delays in data transmission or response time.
    - _Architectural Solutions:_ **Edge Computing** (processing data near the source for ultra-low latency), Low-Latency Protocols (MQTT, CoAP over UDP), Local Decision-Making (TinyML onboard).
3. **Data Intelligence & Analytics:** The ability to derive actionable insights from raw data streams.
    - _Architectural Components:_ Data Ingestion (MQTT, Kafka), Edge Analytics (TensorFlow Lite, TinyML), Data Lake/Storage (S3, HDFS), and AI/ML Engine (SageMaker, TensorFlow).
4. **Security & Privacy:** Protecting devices/data and controlling personal information dissemination.
5. **Interoperability:** The seamless integration and data exchange between devices/platforms from different vendors. _Types:_ Device, Network, Data, Application, and Semantic levels.
6. **Power & Cost Constraints:** Ensuring devices are affordable and energy-efficient for long-term, battery-powered deployment.

### 3.3 The IoT Gateway

An IoT Gateway is a bridge (hardware or software interface) between local IoT devices (which often use short-range, non-IP protocols) and the cloud or data center.

|Function|Description|Source|
|:--|:--|:--|
|**Protocol Translation**|Converts local protocols (e.g., Bluetooth, ZigBee, Wi-Fi) into internet-compatible formats (e.g., HTTP, MQTT, CoAP).||
|**Data Aggregation**|Collects data from multiple devices and combines it for efficient transmission to the cloud.||
|**Edge Processing**|Filters, preprocesses, or analyzes data locally to reduce latency and bandwidth usage before sending it upstream.||
|**Security Enforcement**|Adds layers like encryption, authentication, and firewalling to protect device communication.||
|**Device Management**|Enables firmware updates (OTA), diagnostics, and provisioning of local devices.||

### 3.4 IoT Connectivity Options

#### A. Wired Connectivity (High Reliability/Speed)

|Technology|Characteristics|Key Applications / IoT Use|Source|
|:--|:--|:--|:--|
|**Ethernet** (IEEE 802.3)|High data rates (up to 100 Gbps); highly reliable and stable LAN standard. Typically uses star topology.|Industrial IoT, critical systems, core network backhaul.||
|**PoE** (Power over Ethernet)|Carries both data and electrical power simultaneously over one Ethernet cable. _Standards:_ 802.3af (15.4 W), 802.3bt (90 W).|Powering remote sensors, IP cameras, wireless access points without separate power wiring.||
|**TSN** (Time-Sensitive Networking)|Enhances Ethernet for **deterministic real-time** communication; guarantees low latency and minimal jitter.|Industrial automation (robotics), autonomous vehicles, smart grid control.||
|**PLC** (Power Line Comm.)|Uses existing AC electrical wiring to transmit data signals; avoids need for new cabling.|Smart grids, utility meters, smart home control, remote area connectivity.||

#### B. Wireless Protocols (Low Power/Flexible)

|Protocol|Range / Power|Data Rate|Key Architectural Feature|Use Case Fit|Source|
|:--|:--|:--|:--|:--|:--|
|**BLE** (Bluetooth Low Energy)|Short range, **Very Low Power** (mostly in sleep mode).|Low–Medium (optimized for small, intermittent bursts).|**GATT** (Generic Attribute Profile) data structure; uses AES-128 encryption.|Wearables, health monitors, smart locks, proximity detection.||
|**Zigbee** (IEEE 802.15.4)|Short–Medium range, Low Power.|Low (20–250 kbps).|**Mesh topology** (Routers extend range); AES-128 security.|Smart homes (lighting/HVAC), industrial control.||
|**LoRaWAN** (LPWAN)|**Long Range** (up to 15 km rural), **Ultra Low Power** (years on battery).|Very Low (small data packets).|**Star-of-Stars topology**; Network/Application Servers handle logic; Geolocation via TDOA.|Smart cities, agriculture (soil sensors), utility metering.||

### 3.5 Application Layer Protocols

These protocols handle data formatting, reliability, and routing logic above the network layer.

|Protocol|Transport|Messaging Model|Overhead|Reliability|Security|Source|
|:--|:--|:--|:--|:--|:--|:--|
|**MQTT**|TCP|**Publish/Subscribe** (via central Broker).|Very Low (2 bytes minimum header).|**QoS Levels** (0, 1, 2).|TLS/SSL (over port 8883), Broker ACLs.||
|**CoAP**|UDP.|**Request/Response** (RESTful, Client/Server) + Observe.|Very Low (compact binary header).|Optional (via Confirmable messages/ACK).|**DTLS** (Datagram TLS).||

---

## Unit 4: Data Analytics, Machine Learning, and Security

### 4.1 IoT Data Analytics and Categorization

IoT analytics extracts actionable insights from vast, continuous streams of data.

#### A. Data Types

|Categorization|Type|Description / Characteristics|Source|
|:--|:--|:--|:--|
|**Structure**|**Structured**|Follows a fixed schema (tabular, time-series, numerical values); easily queried.||
||**Unstructured**|Lacks a fixed schema (video, images, text, speech); accounts for ~80% of business data. Requires ML/cognitive tools.||
|**State**|**Data in Motion**|Data actively streaming through the network (e.g., live sensor readings, GPS). Requires real-time processing (stream analytics).||
||**Data at Rest**|Data stored persistently (e.g., cloud data lakes, databases) for long-term, batch analysis, and model training.||

#### B. Types of Analytics (Increasing Value and Complexity)

1. **Descriptive Analytics:** Summarizes current or historical data to answer **"What is happening?"**. (e.g., providing dashboards/reports).
2. **Diagnostic Analytics:** Investigates past events to answer **"Why did it happen?"**. (e.g., correlating sensor readings to find a root cause).
3. **Predictive Analytics:** Uses ML/statistical models to forecast future events or trends to answer **"What is likely to happen?"**. (e.g., predicting RUL or time-to-failure).
4. **Prescriptive Analytics:** Recommends optimal actions or decisions based on predictions to answer **"What should we do about it?"**. (e.g., scheduling maintenance immediately).

### 4.2 Machine Learning (ML) in IoT

ML enables systems to learn patterns from data and make decisions without explicit programming.

#### A. Learning Paradigms

|Paradigm|Data Requirement|Objective in IoT|Application Examples|Source|
|:--|:--|:--|:--|:--|
|**Supervised Learning**|**Labeled** input-output pairs.|**Prediction** (Regression: RUL, energy forecast) or **Classification** (Faulty/Healthy state).|Predictive maintenance, crop yield forecasting, activity recognition.||
|**Unsupervised Learning**|**Unlabeled** data.|**Pattern Discovery** (Clustering) and **Anomaly Detection**.|Identifying abnormal network behavior, grouping energy consumption profiles.||
|**Reinforcement Learning**|**Interaction** (Reward/Penalty feedback loop).|Optimal **Sequential Decision-Making** in dynamic environments.|Autonomous robotics navigation, smart grid optimization.||

#### B. Classification using Decision Trees

- **Definition:** A model that maps choices and outcomes using a hierarchical, flowchart-like structure. They are favored for their interpretability.
- **Key Components:**
    - **Root Node:** The starting decision point, representing the entire dataset.
    - **Decision Nodes:** Internal points evaluating specific conditions (e.g., "temperature > X?").
    - **Branches:** Represent outcomes of a decision.
    - **Leaf Nodes:** The final node representing the resulting classification (e.g., "Faulty Device" or "Healthy").

### 4.3 IoT Cloud and Edge Computing

Cloud platforms manage massive scale, ingestion, and centralized analytics, while edge/fog computing pushes processing closer to the data source.

| Layer     | Location/Role                                                    | Key Characteristics                                                                                                                                  | Examples                                                                 | Source |
| :-------- | :--------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------- | :----- |
| **Edge**  | Closest to the devices (embedded processors, local controllers). | **Ultra-low latency** (real-time decisions), **Local processing**, **Bandwidth efficiency** (only relevant data sent upstream).                      | Traffic control systems, industrial robots, local ML inference (TinyML). |        |
| **Fog**   | Intermediate layer (gateways, micro data centers).               | **Intermediate analytics** (aggregates data from multiple edges), **Contextual decision-making** (site-level intelligence), **Orchestration point**. | IoT gateways with compute capability.                                    |        |
| **Cloud** | Remote data centers.                                             | **Massive scalability** and storage (petabytes), **Advanced analytics** (AI/ML, deep learning), Centralized dashboards and data fusion.              | AWS IoT Core, Azure IoT Hub, Google Cloud IoT.                           |        |

### 4.4 IoT Security and Privacy

IoT security protects devices/data; privacy protects personal/sensitive information.

#### A. Fundamental Security Pillars (CIAAN)

| Pillar              | Objective                                                               | Threat Examples                                                                                                  | Primary Protection Mechanism                                |
| :------------------ | :---------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------- |
| **Confidentiality** | Protecting data content from unauthorized reading.                      | Eavesdropping, sniffing, information disclosure.                                                                 | **Encryption** (data at rest, in motion, in use).           |
| **Integrity**       | Protecting data from unauthorized modification.                         | Data tampering (e.g., modifying financial data, vehicle control data).                                           | **Hash Algorithms**, digital signatures, data validation.   |
| **Authentication**  | Verifying the identity of users or devices.                             | Identity spoofing (impersonation, MITM, password attacks).                                                       | Usernames/passwords, certificates, multi-factor mechanisms. |
| **Non-Repudiation** | Preventing a sender from denying the validity of a transaction/message. | Repudiation of origin or emission (denying a transfer amount).                                                   | **Digital signatures**.                                     |
| **Availability**    | Ensuring the system remains operational and accessible.                 | **DoS/DDoS attacks** (saturating the network/system); **Denial of Sleep Attack (DoSA)** (draining battery life). | Network resilience, filtering, cloud scalability.           |

#### B. Key Vulnerabilities and Threats

- **Weak Credentials:** Devices often use default or hard-coded credentials.
- **Insecure Firmware/Updates:** Unpatched firmware vulnerabilities or bugs in the update process (e.g., LockState smart locks, Jeep vehicle systems).
- **Insecure Communication:** Data transferred without encryption (plain text) makes data vulnerable to eavesdropping (e.g., TRENDnet Webcam data leak).
- **Network Attacks:** Routing attacks like the **Black hole attack** attempt to spoof the shortest path to drop or redirect packets.
- **Hardware/Physical Attacks:** Manipulating environmental parameters (voltage, temperature) to force the chip into an insecure state, known as **glitch injection**.
- **Botnets:** Compromised IoT devices (e.g., cameras, gateways) are enlisted into a massive network (botnet) and commanded to launch large-scale DDoS attacks (e.g., **Mirai botnet** attack in 2016).

#### C. Risk Management and Privacy

- **Threat Modeling:** A systematic process to identify assets, analyze message flow, classify threats (e.g., spoofing, tampering, DoS), and rate risks based on their impact and probability.
- **DREAD Model:** A specific risk assessment model used to score threats based on five factors: **Damage**, **Reproducibility**, **Exploitability**, **Affected users**, and **Discoverability**.
- **Privacy Concerns:** Arise when sensitive personal information (location, health, identity) is collected, stored, or shared without user consent. Privacy risks can increase substantially when integrated with other seemingly harmless data sets.
- **Privacy Impact Assessment (PIA):** A formal review process performed before deployment to identify, evaluate, and control privacy risks associated with collecting and handling personal information.