# UE23CS342AA3: IoT

# Intro to IoT

A network of physical devices, vehicles, appliances, and other physical objects that are embedded with **sensors**, software, and network connectivity, allowing them to collect and share data.

1.  **Connectivity**: The IoT relies on the ability of physical objects to connect to the internet. This is made possible by the use of low-power, wide-area networks (LPWANs) such as Sigfox, LoRaWAN, and NB-IoT.
2.  **Sensing**: IoT devices are typically equipped with sensors that collect data about the environment. This data can be used to monitor conditions, track movement, and detect events.
3. **Communication**: IoT devices need to be able to communicate with each other and with the cloud. This is typically done using standard protocols such as MQTT, CoAP, and HTTP.
4. **Analytics**: The data collected by IoT devices can be analyzed to gain insights into the physical world. This data can be used to improve efficiency, optimize processes, and make better decisions.

## Connectivity

Connectivity refers to the various communication technologies and protocols that enable devices to connect, communicate, and exchange data with other devices, networks, or cloud platforms.

![[Screenshot 2025-08-29 at 12.21.12.png]]

### What Is an IoT Gateway?

An IoT Gateway is a hardware or software interface that sits between IoT devices (like sensors, wearables, or home appliances) and the cloud or data center. It collects, processes, and transmits data from these local devices to the internet.

### Benefits of IoT-Driven Digitization

Operational Efficiency: Less manual intervention, real-time insights - Cost Reduction: Predictive maintenance reduces downtime and repair costs - Data-Driven Decision Making: Enables AI/ML to optimize workflows - Enhanced Customer Experience: Personalized, responsive services - New Business Models: Subscription-based services, remote diagnostic

---

# IoT Verticals

1. Industrial IoT (IIoT)
2. Smart Cities
3. Smart Healthcare / IoMT
4. Smart Agriculture
5. Connected Vehicles
6. Smart Homes & Buildings
7. Retail & Supply Chain / Logistics
8. Smart Energy & Utilities

## IIoT

Predictive maintenance (using vibration and thermal sensors) - Asset tracking and uptime monitoring - Digital twin modeling of factory processes Impact: - Reduces downtime and maintenance costs - Enhances safety in hazardous environments - Enables remote monitoring of complex systems

## What is a smart city?

A smart city is an urban area where technology and data collection help improve quality of life as well as the sustainability and efficiency of city operations. - Smart city technologies used by local governments include information and communication technologies (ICT) and the Internet of Things (IoT)

- Smart **Governance**: Gati Shakti is India’s National Master Plan for multimodal connectivity and integrated infrastructure planning. It creates a central digital platform to bring together planning data from multiple ministries and states so projects are planned and executed in a coordinated way (roads, rail, ports, airports, waterways, power, telecom, etc.). IoT- backed decision-making for urban planning
- Smart **Mobility** & Traffic Management: Adaptive traffic signals based on real-time congestion data - Smart parking systems guiding drivers to available slots - GPS-enabled public transport tracking Smart Environment - Air and noise pollution sensors - Real-time water and waste management monitoring - Weather and climate sensors for disaster forecasting

> Examples: Barcelona (Spain): Smart parking, waste management, adaptive lighting Singapore: National Smart Nation project – citizen dashboards, predictive healthcare Bhopal (India): Smart poles, integrated command control center (ICCC) - Amsterdam (Netherlands): IoT-driven environmental monitoring and transport systems

## IoMT (Internet of Medical Things)

refers to the integration of IoT devices and systems into healthcare services to enable real-time patient monitoring, predictive diagnostics, equipment maintenance, and enhanced operational efficiency. - Remote Patient Monitoring (RPM) is a subdomain where wearable and in-home IoT devices track a patient’s health continuously, allowing for early intervention without hospitalization.

### What is a Smart Farm?

- Smart farming refers to managing farms using modern Information and communication technologies to increase the quantity and quality of products while optimizing the human labor required. - Among the technologies available for present-day farmers are: - Sensors: soil, water, light, humidity, temperature management - Software: specialized software solutions that target specific farm types or applications agnostic IoT platforms - Connectivity: cellular, LoRa - Location: GPS, Satellite - Robotics: Autonomous tractors, processing facilities - Data analytics: standalone analytics solutions, data pipelines for downstream solutions

---

# Security & Privacy Risks

IoT devices often lack robust security features, making them vulnerable entry points in a network. Examples of Threats: - Default credentials left unchanged by users - Insecure communication (unencrypted data transfer) - Firmware vulnerabilities left unpatched - Botnets (e.g., Mirai attack) using IoT devices for DDoS Impact: - Compromised personal data - Unauthorized control of devices (e.g., smart locks, health monitors) - Loss of trust in IoT solutions

## Lack of Interoperability & Standards

- There is no universally accepted protocol or standard for IoT. - Devices from different vendors often cannot communicate with each other. Examples: - One device uses MQTT, another uses CoAP, a third uses proprietary APIs - Compatibility issues with cloud platforms (AWS, Azure, Google Cloud) Impact: - Increased integration complexity - Vendor lock-in and increased system fragmentation - Difficulty scaling IoT solutions across ecosystems

## Connectivity & Network Reliability

IoT devices rely heavily on continuous, stable internet or wireless connectivity, which isn’t always available—especially in rural or remote environments. Issues: - Packet loss and latency - Power outages or signal interference - Choice of protocol (Wi-Fi vs. LoRa vs. Zigbee vs. NB-IoT) Impact: - Loss of real-time capabilities - Missed alerts or incorrect data readings - Poor user experience and system unreliability

## Power Management

- Most IoT devices (especially sensors) are battery-operated and deployed in hard-to-reach places. Challenges: - Frequent recharging/replacement is impractical - Always-on connectivity drains battery - Trade-off between data transmission frequency and battery life Impact: - Shortened device lifetime - Maintenance overhead and increased costs - Reduced efficiency in long-term deployments

### Data Overload & Management

- IoT ecosystems generate massive volumes of data continuously, much of which is redundant or noisy. Challenges: - Real-time processing vs. long-term storage - Data filtering, deduplication, and compression - Ensuring data integrity and time synchronization Impact: - Cloud and network resource strain - Decision-making delays - Increased need for edge computing and AI analytics

### Scalability Bottlenecks

- Expanding from a few devices to thousands requires rethinking system architecture, data pipelines, and compute power. Challenges: - Load balancing and throughput handling - Device provisioning and lifecycle management - Ensuring performance doesn’t degrade at scale Impact: - Increased cloud and infrastructure costs - Complexity in system orchestration and updates - Need for robust device management platforms

---

# IoT Architecture

- IoT architecture is the structure enabling internet-connected devices to communicate with other devices.
- IoT architecture refers to the many ways that IoT devices are structured to meet user needs. - Most IoT architecture models include 3 to 7 sets of functional components, or “layers”, such as perception (e.g., sensors), transport (e.g., Wi-Fi), and application (e.g., software) layers.
- Notably, IoT architecture lacks standardized protocols, raising compatibility, security, and other challenges.

IoT Architectural Drivers: A driver is a core influencing factor or requirement that shapes the way an IoT system is designed and built. These are not physical components but rather forces, goals, or constraints technical, economic, or user-based—that push the architecture in a specific direction. For example, if low latency is important, the architecture must include edge computing

## Scalability

- Scalability is the ability of an IoT system to handle increasing loads—such as more devices, more users, more data, or more concurrent operations—without a drop in performance, reliability, or manageability. - IoT systems often begin small (e.g., 10 sensors) but can scale to thousands or even millions. A rigid architecture collapses under this expansion

![[Screenshot 2025-08-29 at 12.31.54.png]]

### Architectural Impact of Scalability

To achieve scalability, IoT architectures must include:

1. Cloud-Native Infrastructure
	1. Leverage platforms like AWS IoT, Azure IoT Hub, or GCP IoT Core.
	2. Elastic scaling (auto-scaling compute/storage resources).
2. Microservices Architecture
	1. Break down functionality into independent, reusable services.
	2. Each service (e.g., device registry, data ingestion, alerting) can scale on demand.
3. Message Queuing and Streaming
	1. Use brokers like MQTT, Apache Kafka, or RabbitMQ.
	2. Decouples data producers (devices) from consumers (apps/services), allowing independent scaling.
4. Horizontal Scaling
	1. Add more machines/nodes to handle load, instead of upgrading a single machine (vertical scaling).
	2. Used in load-balanced gateways, API servers, databases.
5. Data Lake or Distributed Databases
	1. Use scalable storage systems like Amazon S3, HDFS, or NoSQL databases like MongoDB, Cassandra.
	2. Handles massive data growth across time

## Latency Sensitivity

Latency sensitivity refers to how critically a system or application is affected by delays in data transmission, processing, or response time. In IoT, latency-sensitive applications require near-instantaneous reactions to sensor inputs or events. In simpler terms, latency is the time taken for data to travel from a device to the server and back. If a delay causes functional failure, it’s latency-sensitive

Latency sensitivity shapes architecture significantly:

1. Edge Computing - Data is processed near the source (e.g., at the gateway or sensor). - Reduces dependency on distant cloud servers. Enables real-time response even if cloud is unreachable.
2. Low-Latency Protocols - Prefer lightweight, fast protocols like MQTT, CoAP, or UDP over HTTP. Minimize handshake overhead and data payload size.
3. Local Decision-Making - Use onboard ML models (TinyML) for immediate inference. - Example: A drone avoids obstacles using onboard logic, not cloud ML.

## Types of Intelligence in IoT

![[Screenshot 2025-08-29 at 12.38.10.png]]

### Architectural Components for Intelligence & Analytics

Data Ingestion Layer Collects data from devices in real time - Tools: MQTT, Kafka, Azure IoT Hub, AWS IoT Core - Edge Analytics - Processing at the gateway or device level to reduce latency and data transmission - Tools: TensorFlow Lite, TinyML, NVIDIA Jetson - Data Lake / Storage Layer - Central repository for raw and processed data - Tools: AWS S3, Azure Data Lake, InfluxDB, Hadoop HDFS

Analytics Engine - Processes data to derive trends, alerts, predictions - Tools: Apache Spark, AWS Glue, Google BigQuery, Grafana, Power BI - AI/ML Engine - Runs models for predictive maintenance, anomaly detection, forecasting - Tools: Amazon SageMaker, Azure ML Studio, TensorFlow, PyTorch - Visualization & Dashboard Layer - Presents insights to users in charts, alerts, and reports - Tools: Grafana, Power BI, Kibana, Tableau.

## Security & Privacy

Security in IoT refers to protecting devices, networks, and data from unauthorized access, attacks, tampering, and data breaches. Privacy in IoT refers to protecting personal, sensitive, or identifiable information collected from devices against misuse, leakage, or unauthorized processing.

IoT environments are: - Highly distributed (millions of endpoints) - Resource-constrained (limited memory, compute, battery) - Often unattended (deployed in open/public spaces) - Always online (exposed to remote attacks) - One vulnerable device can compromise an entire system. - A hacked smart thermostat, for example, can be used to breach a home Wi-Fi network or take part in a DDoS attack (like the Mirai botnet incident in 2016)

![[Screenshot 2025-08-29 at 12.41.15.png]]

## Interoperability & Standards in IoT Architecture

Interoperability in IoT refers to the ability of devices, platforms, applications, and systems from different vendors to work together seamlessly, exchange data, and operate as a unified system. - Standards are the agreed-upon technical rules, formats, and protocols that enable interoperability by ensuring consistency across devices and systems

![[Screenshot 2025-08-29 at 12.41.51.png]]

---

# IoT Network Constraints

Bandwidth, latency, reliability or connectivity quality in the communication network used by IoT devices. The networks are slow, intermittent and power hungry.

## Realtime Response

> The ability of the system to sense, process, and act on data immediately or within a guaranteed timeframe, often milliseconds to seconds.

## Power & Cost Constraints

- Battery-powered, deployed in large quantities, or installed in hard-to-reach places making energy efficiency and low cost essential.
- Devices must run for months or years unattended and must be affordable to scale to thousands of units.

## Modularity

Add, replace or upgrade components (without redesigning) the entire system. Ensures agility, maintainability. IoT Systems evolve quickly.

---

# IoT Architectures

| Type                  | Desc                                                                                                                                                                                         |
| --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [[#3-layer\|3-layer]] | Perception, Network, Application                                                                                                                                                             |
| 5-layer               | +Data processing, Service layers to manage analytics and middleware                                                                                                                          |
| Cloud Centric         | Push to the cloud, where all processing occurs.  Ideal for scalable, centralized control.                                                                                                    |
| Edge/Fog              | Pushes processing closer to the device to reduce latency and bandwidth.                                                                                                                      |
| AIoT                  | ML on the edge / cloud                                                                                                                                                                       |
| Middleware based arch | Standardized device communication, abstract hardware, ensure cross platform interop.                                                                                                         |
| Service (SoA)         | Builds the IoT system using modular, independent services connected via APIs. Supports scalability and maintainability.                                                                      |
| Digital Twin          | Real-time digital replicas of physical assets or systems for simulation, monitoring, and predictive maintenance.                                                                             |
| IoTWF (Cisco)         | 7-layer reference model including device, network, transport, data management, application, plus cross-cutting security and management layers. Designed for industrial-grade IoT deployments |

## 3-layer

- The **Perception** Layer – This is the physical layer. It has sensors for finding and gathering information about an environment, including the ability to identify other smart objects.
- The **Network** Layer – This layer connects to other smart objects, including servers, network devices, and more. It can also transmit and process sensor data.
- The **Application** Layer – This layer is responsible for actually providing application-specific services to the user. It does so by defining ways to deploy the IoT, such as in smart homes or smart cars.

![[Screenshot 2025-08-29 at 11.08.25.png]]

## 5-layer

The Five-Layer IoT Architecture is an extension of the basic three-layer model, offering better clarity and separation of concerns across the IoT system.

It introduces layers for data processing and services, making it more applicable to real-world deployments.

### Perception Layer

This is the bottom-most layer of the architecture and serves as the interface between the physical world and the digital system.

> [!Example]
> Sensors, RFID tags, Actuators: These components are responsible for detecting and collecting real-world data such as temperature, light, sound, humidity, motion, etc. It also includes basic data preprocessing like signal conversion.

### Network Layer

Responsible for transmitting it to other parts of the IoT system, such as the cloud or middleware layer.

> [!Example]
> - Wi-Fi
> - Zigbee
> - Bluetooth
> - LTE/5G
> - LoRaWAN

> This layer ensures that data is reliably and securely routed, and it may also handle encryption and data integrity during transmission.

### Middleware Layer

Often referred to as the "cognition layer", this is the brain of the system. It performs:

> [!Example]
> - Data filtering and aggregation
> - Temporary storage
> - Context-aware processing
> - Decision making (e.g., triggering alerts or actions)

> It acts as a bridge between the network and application layers, and can include edge or fog computing nodes to perform processing closer to the data source.

### Application Layer

This layer defines how users interact with the IoT system and what services are provided. It presents data in a meaningful way through:

> [!Example]
> - Mobile apps
> - Web dashboards
> - Alerts or notifications
> - Automation routines (like turning on lights or adjusting a thermostat)

>  It is domain-specific, tailored to different verticals such as smart homes, healthcare, agriculture, transportation, etc.

### Business Layer

The top-most layer focuses on business logic and strategic decision-making. It deals with:

> [!Example]
> - ROI analysis
> - Compliance and governance
> - Workflow integration (e.g., with ERP or CRM systems)
> - High-level analytics and reporting

 > It ensures that the IoT deployment is aligned with organizational goals and delivers measurable value.

---

## OneM2M IoT Standardization Architecture

A global IoT standardization initiative that defines a common service layer architecture to ensure interoperability among machine-to-machine (M2M) and Internet of Things (IoT) systems.

 - Enable cross-industry communication (e.g., smart city talking to smart grid).
 - Avoid vendor lock-in by offering a platform-neutral service layer.
 - Provide a common language and API for all IoT devices, apps, and platforms.

> [!Important]
> 1. **Application Entity (AE)**
> 	- Resides on either the device side or server/cloud side
> 	- Implements business/application logic.
> 	- Examples: Smart home app, energy monitoring app.
> 2. **Common Services Entity (CSE)**
> 	1. The core of the architecture.
> 	2. Offers standardized services like:
> 	3. Device registration , Security, Data management , Subscription and notification, Grouping and discovery
> 	4. Deployed on:
> 		1. **Infrastructure node (IN-CSE)** – Cloud/data center
> 		2. **Middle node (MN-CSE)** – Gateway/fog/edge
> 		3. **Application node (AE-CSE)** – Device itself
> 3. **Network Services Entity (NSE)**
> 	1. Interfaces with telecom networks (e.g., 3GPP, 5G, LTE).
> 	2. Provides communication functions like authentication, mobility, QoS, billing

> Horizontal, layered architecture that sits between devices and applications.
![[Screenshot 2025-08-29 at 11.23.54.png]]

> **Benefits of oneM2M**: Interoperability across vendors and platforms - Reusable common services (e.g., device mgmt, notifications) - Scalable architecture (device to cloud) - Built-in security (authentication, access control) - Modular and flexible design - Supports multiple industries - Globally standardized (backed by ETSI, TSDSI, etc.)

>  **Cons of oneM2M**: Complex to implement for small projects - Overhead for simple applications - Steep learning curve for developers - Limited open-source tools/community - Difficult integration with legacy or non-standard systems

## IoTWF Architecture

It standardizes the structure of IoT systems by defining a clear set of layers from devices to business processes, with security and management applied throughout.

![[Screenshot 2025-08-29 at 11.26.06.png]]

### Perception Layer (Physical Devices & Controllers)

- What it is:
	- Physical hardware components that sense or control the environment
	- Interface with the physical world.
- Includes:
	- Sensors (temperature, pressure, humidity, motion)
	- Actuators (valves, motors)
	- Smart meters, wearables, embedded controllers
- Function:
	- Collect real-world data
	- Perform basic local processing
	- Generate control signals to actuators

### Network Layer (Connectivity Layer)

- Purpose: Provide secure and efficient communication between devices and upstream systems.
- Includes: Wired: Ethernet, fiber optics - Wireless: Wi-Fi, 5G, LoRa, Zigbee, Bluetooth, NB-IoT
- Function: Transmit data from sensors/devices to data centers, cloud, or edge nodes - Maintain reliability, bandwidth, and QoS

### Data Transport Layer

- Purpose: Enable protocol-level communication between system components (devices, gateways, cloud).
- Includes: MQTT (publish/subscribe) - CoAP (lightweight HTTP) - HTTP/REST, AMQP, DDS
- Function: Standardize data exchange - Ensure message routing, delivery, and interoperability

### Data Management Layer

- Purpose: Store, clean, and process data; make it usable for decision-making.
- Includes: Databases (SQL/NoSQL), Stream processors (Apache Kafka, AWS Lambda), Rule engines, edge analytics
- Function: Data filtering, deduplication, enrichment, Temporary or long-term storage Event detection and triggering

> Example: An edge gateway that filters raw machine vibration data and only uploads anomalies.

### Application Layer

- Purpose: Provide user-facing services based on processed data.
- Includes: Mobile apps - Web dashboards - Notifications/alerts - Voice interfaces (Alexa, Google Assistant)
- Function: Visualize data - Allow user interaction and control - Integrate with business logic - Example: A smart irrigation app that shows real-time soil data and allows remote control of water valves

### Security Layer (Cross-cutting)

- Purpose: Protect data, devices, users, and systems across all other layers.
- Includes: Encryption (TLS, DTLS) - Authentication and authorization (OAuth, certificates) - Secure boot, firmware integrity - Access control and logging
- Function: Ensure confidentiality, integrity, and availability - Prevent unauthorized access and cyber threats - Example: Devices that verify firmware signatures before booting.

### Management Layer (Cross-cutting)

- Purpose: Enable lifecycle management, provisioning, monitoring, and updates.
- Includes: - Device registration and provisioning tools - OTA (Over-the-Air) update systems - Configuration management platforms - Network monitoring tools
- Function: - Track device status and health - Push firmware/software updates securely - Alert on failures or anomalies - Example: A fleet of smart meters receives security patches remotely.
 

![[Screenshot 2025-08-29 at 11.34.16.png]]

### Key Benefits of IoTWF Architecture

**Standardized**, layered approach for complex systems - Cross-industry applicability (smart cities, manufacturing, energy, healthcare) - Separation of concerns improves security, maintainability, and scalability - Cross-cutting security and management ensures trustworthiness and robustness

 IoTWF architecture is ideal for: Large-scale industrial IoT systems, Smart infrastructure and smart cities. Multi-vendor deployments needing interoperability. Systems requiring centralized and distributed processing

 ![[Screenshot 2025-08-29 at 11.35.02.png]]

---

# Simplified IoT Architecture & Core IoT Functional Stack

The Core IoT Functional Stack is presented in three layers, allowing for better visibility into the functions of each layer.

- **Things** (Sensors and Actuators): Physical devices that collect data (sensors) or interact with the environment (actuators).
- **Communications** Network: Transfers data between devices, gateways, and cloud systems using technologies like LoRa, FAN, PLC, and IP-based transport.
- **Applications**: End-user services and business logic that make use of IoT data (e.g., smart home apps, SCADA, MDM systems).

## Things Layer

At this level, the physical devices must conform to the limitations of the environment in which they are deployed, while also being capable of delivering the required information. - There are numerous ways to classify smart objects.

## Communications Network Layer

The cases where smart devices lack self-sufficiency, they must establish communication with an external system. Typically, this communication employs wireless technology. There are four sublayers in this layer.

### Access network sublayer

The access network is the final segment of the IoT network. This is commonly composed of wireless technologies such as 802.11ah, 802.15.4g, and LoRa. The sensors linked to the access network may also be connected via physical cables.

### Gateways and Backhaul network sublayer

It refers to the specific layer inside a network that handles the transmission of data between other networks and the main network infrastructure. A typical communication system arranges numerous intelligent things inside a specific region, all connected to a central gateway.

### The network transport sublayer

Is responsible for ensuring successful communication by implementing network and transport layer protocols, such as IP and UDP. These protocols facilitate the connection of various devices and the use of different media. The IoT network management sublayer: It requires the implementation of additional protocols to enable the transmission of data between the headend apps and the sensors. Some examples of communication protocols are CoAP and MQTT.

## Application and Analytics Layer

At the higher layer, an application is responsible for processing the gathered data.

Its role is not only to control the smart objects as needed, but also to make intelligent decisions based on the collected information. These decisions are then used to instruct the "things" or other systems to adapt to the analyzed conditions and modify their behaviors or parameters. The subsequent sections analyze these components and assist you in designing an IoT communication network.

# IoT Data Management and Compute Stack

- The IoT Data Management and Compute Stack refers to the layered system of technologies and processes used to collect, store, process, analyze, and act upon data generated by IoT devices. - It defines where and how data is handled — from the moment it's sensed by a device to the moment it's used in decision-making or automation.

This stack handles where and how data is processed and stored across the system:

- **Edge**: Data is processed locally at or near the device to enable fast response (e.g., traffic control, industrial robots).
- **Fog**: Acts as an intermediate layer (between edge and cloud), supporting localized storage and analytics closer to the source.
- **Cloud**: Centralized computing and storage, suitable for complex analytics, dashboards, and long-term data management

## Edge Computing Layer

Location: Closest to the IoT devices (sensors & actuators). Examples: Embedded processors, smart cameras, industrial controllers.

- Ultra-low latency: Enables real-time or near-real-time decision-making.
- Local processing: Data is processed at the source (e.g., machine or sensor node).
- Bandwidth efficiency: Only relevant/aggregated data is sent upstream (to fog/cloud).
- Device autonomy: Edge nodes can continue operating even with network disruptions.

## Fog Computing Layer Location

Between edge and cloud, usually at the LAN level. Examples: Edge gateways, micro data centers, routers with compute

- Intermediate analytics: Aggregates and pre-processes data from multiple edge devices.
- Contextual decision-making: Supports site-level intelligence.
- Reduced latency vs cloud: Faster than cloud, though slower than edge.
- Orchestration point: Manages devices and ensures security, reliability, and failover.

## Cloud Computing Layer

Location: Remote data centers or public/private clouds. Examples: AWS IoT Core, Microsoft Azure IoT Hub, Google Cloud IoT.

- Massive scalability: Stores petabytes of data from global IoT devices.
- Advanced analytics: Enables AI/ML, deep learning, and predictive maintenance
- Centralized dashboards: For visualization, reporting, control. - Data fusion and integration: Integrates with ERP, CRM, and external systems

---

# Things

Physical devices that sense, process and communicate.

- Sensors: Measure physical parameters
- Actuators: Act on the env
- Smart Objects

## Sensor

A sensor is a device that detects a change in the environment and responds to some output on some other system. To analog voltage.

Sensors can be active/passive.

- Temperature
- Proximity
- Pressure

## Actuators

### Response Time

### Control Methods

- open loop
- closed loop

| Sensor         | Actuators   |
| -------------- | ----------- |
| Input          | Output      |
| Detects Change | Changes Env |

---

# MEMS

> Micro-Electro-Mechnaical Systems

Miniaturized mechanical and electro-mechanical elements (sensors, actuators, structures) fabricated using microfabrication. Combines mechanical, electrical, and sometimes fluidic components on a chip.

## Smart Objects – Sensor + Actuator Smart Object

A device that both senses and acts autonomously. They are what transform everyday objects into a network of intelligent objects that are able to learn from and interact with their environment in a meaningful way.

A smart object integrates sensors, a microprocessor, wireless communication interfaces (e.g., WiFi, Bluetooth, RFID), and embedded applications. - It analyses its environment through sensors that measure parameters like temperature, motion, speed, light, and humidity. The collected data is transmitted to servers via wireless networks.

![[Screenshot 2025-09-12 at 11.02.56.png]]

### Core Capabilities of a Smart Object

- Unique identity (identifier/name/address)
- Sensing: perceives ambient conditions (temperature, pressure, etc.)
- Processing: microcontroller or CPU + memory
- Communication: wired/wireless interface; network addressability
- Actuation & logic: executes pre‑programmed application logic to act/respond

### Classification by Behavior — Two Categories

1. Mobility
	1. Static objects: fixed installation (e.g. structural sensor, thermostat)
	2. Mobile objects: attached to moving entities or portable devices (e.g. wearables, asset tracker)
2. Reporting Frequency
	1. Low reporting: infrequent transmissions (e.g. a rust sensor sending monthly data)
	2. High reporting: rapid, frequent updates (e.g. motion/machine vibration sensors at hundreds Hz)

### Advantages

Greater deployment flexibility (especially in extreme environments or hard-to-reach places) - Simpler scaling to a large number of nodes - Lower implementation costs - Easier long-term maintenance - Effortless introduction of new sensor/actuator nodes - Better equipped to handle dynamic/rapid topology changes

### Disadvantages

Potentially less secure (for example, hijacked access points) - Typically, lower transmission speeds - Greater level of impact/influence by environment

---

# Wireless Sensor Networks (WSNs)

A Wireless Sensor Network (WSN) is a collection of small, autonomous, low-power sensor nodes that monitor physical or environmental conditions and wirelessly transmit data to a base station (also called a gateway or sink).

These networks are a critical component of the IoT ecosystem for applications like smart cities, industrial automation, agriculture, and environmental monitoring. Each sensor node typically includes:

- Sensor(s): To collect data (e.g., temperature, humidity, motion).
- Microcontroller: For data processing and control logic.
- Radio transceiver: To send and receive data.
- Battery or energy harvester: For power supply

## Communication patterns

- Event-driven: Transmission of sensory information is triggered only when a smart object detects a particular event or predetermined threshold.
- Periodic: Transmission of sensory information occurs only at periodic intervals

## Characteristics

- Low power and compute constraints – designed for long battery life.
- Self-organizing – nodes can form ad hoc mesh or tree topologies.
- Unattended operation – once deployed, nodes often work independently for long periods.

## Challenges

- Power management – nodes must optimize energy use for longevity.
- Reliability & coverage – ensuring consistent data transmission in dynamic environments.
- Scalability – supporting thousands of sensor nodes without congestion.
 - Security – lightweight encryption and authentication are critical due to limited resources.
 ![[Screenshot 2025-09-12 at 11.09.59.png]]

---

# Embedded Programming STM32

Embedded programming involves writing software that runs on microcontrollers: small, dedicated computers inside everyday devices (e.g. washing machines, drones, cars).

Unlike general-purpose computers, embedded systems are:

- Designed for specific tasks
- Run in real-time
- Have limited memory and compute power
- Often lack an operating system or use a real-time OS (RTOS)

> [!Example]
>
> STM32 is a family of 32-bit ARM Cortex-M based microcontrollers by STMicroelectronics. They are: Low-power, high-performance, Have a wide range of built-in peripherals (ADC, UART, SPI, I2C). Supported by a rich development ecosystem
>
> ![[Screenshot 2025-09-12 at 11.11.20.png]]

## Core Hardware Components of STM32

- Cortex-M CPU Core – processes instructions
- Flash Memory – stores firmware
- SRAM – runtime memory (variables, stack)
- GPIO – controls LEDs, buttons, etc.
- Timers – for precise time-based tasks
- ADC – reads analog voltages
- USART/I2C/SPI – for communication with external devices

> Core HW Features Hardware FPU & DSP based Instructions. Advanced Timer System (with Quadrature Encoder Interface). CAN, CAN-FD, USB OTG , Ethernet etc. Mixed-Signal Integration with built in OP - AMPS

## Toolchain

![[Screenshot 2025-09-12 at 11.13.59.png]]

## GPIO

GPIO stands for General Purpose Input Output

- Control LEDs, buttons, sensors
- Pin modes: Input, Output, Alternate Function, Analog

```c
HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle LED 
HAL_Delay(500); // 500ms delay
```

Configure the LED pin as Output in `CubeMX`. In main.c, toggle pin with:

- `HAL_GPIO_TogglePin()`
- Add delay using `HAL_Delay()`

## UART = Universal Asynchronous Receiver/Transmitter

- Used for: Debugging via serial console (e.g., USB/COM)
- Communicating with modules (GPS, Bluetooth, etc.)

```c
char msg[] = "Hello \r\n";
HAL_UART_Transmit(&huart2, (uint8_t*)msg,  strlen(msg), HAL_MAX_DELAY);
```

## Communication Criteria in IoT

When designing or selecting connectivity options (wired or wireless) in an IoT system, engineers must assess various communication criteria to choose the most appropriate technology.

- Range
- Frequency Bands
- Power Consumption
- Topology
- Constrained Devices
- Constrained-Node Networks

Bandwidth refers to the amount of data that can be transmitted over a communication channel per unit of time, typically measured in bits per second (bps).

### Relevance

High-bandwidth networks are needed for transmitting rich data (e.g., images, video, firmware)

> Low-bandwidth networks are sufficient for small data like sensor readings. Example: Ethernet: High bandwidth. Zigbee: Low bandwidth.

### Latency

The delay between sending a signal and receiving the response or result. Measured in milliseconds (ms).

Importance: Real-time systems (e.g., autonomous cars, robotic arms) need very low latency. For non-critical updates (e.g., weekly reports), higher latency is acceptable. Example: Industrial motion controllers: require latency <10 ms. Smart agriculture soil data: tolerates 2–5 seconds delay

### Range

The maximum physical distance over which a communication signal can be transmitted while maintaining signal integrity.

Importance: Determines the physical layout of devices. Affects the cost and topology of deployment (e.g., mesh vs star).

> Example: **Zigbee**: ~10–100 meters indoors. **LoRaWAN**: Up to 10–15 km in rural areas.

### Power Consumption

The amount of electrical power a communication module uses during operation. Measured in milliwatts (mW) or joules per bit. Importance: Critical for battery-powered and energy-harvesting IoT nodes. • High power usage = frequent charging or larger batteries. ☞ Example: • BLE: Low power for fitness bands. • Wi-Fi: High power, suited for plugged-in devices

### Scalability

Scalability refers to the system’s ability to handle increasing numbers of connected devices or nodes without performance degradation. ☞ Importance: • Smart homes may have 20–50 devices. • Smart cities may connect thousands of sensors. ☞ Example: • Zigbee: Supports large mesh networks. • RS-232: Point-to-point, not scalable.

### Reliability

The consistency and dependability of a communication channel to deliver messages without data loss or corruption. ☞ Importance: • Critical in safety-critical and industrial automation systems. ☞ Example: • Ethernet and RS-485 offer highly reliable communication. • Wi-Fi may drop packets in congested areas.

### Security

Security includes confidentiality, integrity, and authentication of data and devices in communication. ☞ Importance: • IoT systems often handle sensitive data (e.g., medical, financial). • Wireless channels are more vulnerable to eavesdropping and attacks. ☞ Example: • HTTPS over Wi-Fi. • AES encryption in Zigbee/LoRaWAN.

---

> [[iot-short-esa]]