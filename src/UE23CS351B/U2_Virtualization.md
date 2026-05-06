# Unit 2: Virtualization

## 1. Introduction to Virtualization

> **Virtualization** divides the resources of a computer into multiple execution environments using partial or complete machine simulation or emulation, allowing them to be shared among different tenants.

- The typical granularity of compute division is a **Virtual Machine (VM)**
- Achieved via a software layer called the **Virtual Machine Monitor (VMM)** or **Hypervisor**
- The hypervisor provides the **illusion of a "real" machine** to multiple virtual machines

### Why Virtualization?

- **Multi-tenancy:** Multiple users share one physical server
- **Resource utilization:** Better use of hardware resources
- **Isolation:** Applications don't interfere with each other
- **Portability:** VMs can move between physical servers (migration)
- **Rapid provisioning:** Deploy environments in minutes

---

## 2. Hypervisor – Types

### Type 1 Hypervisor (Bare-Metal / Native)

- Runs **directly on the physical hardware**
- Acts as a lightweight OS that manages VMs
- More efficient; lower overhead
- **Examples:** VMware ESXi, Microsoft Hyper-V, Xen, KVM

```
┌─────────┬─────────┐
│   VM1   │   VM2   │
├─────────┴─────────┤
│   Hypervisor (T1) │
├───────────────────┤
│  Physical Hardware│
└───────────────────┘
```

### Type 2 Hypervisor (Hosted)

- Runs **on top of a host operating system**
- Host OS manages hardware; hypervisor runs as an application
- More overhead; simpler to set up
- **Examples:** VMware Workstation, VirtualBox, Parallels Desktop

```
┌─────────┬─────────┐
│   VM1   │   VM2   │
├─────────┴─────────┤
│   Hypervisor (T2) │
├───────────────────┤
│     Host OS       │
├───────────────────┤
│  Physical Hardware│
└───────────────────┘
```

### Comparison

| Feature | Type 1 | Type 2 |
|---|---|---|
| Runs on | Bare metal | Host OS |
| Performance | High | Lower |
| Security | Better isolated | Depends on host OS |
| Use case | Production servers | Dev/test environments |

---

## 3. Virtualization Techniques

### 3.1 Trap and Emulate (Software)

- Guest OS runs in **user mode** (not ring 0)
- Privileged instructions **trap** to the hypervisor
- Hypervisor **emulates** the expected behavior and returns control
- Works when all sensitive instructions are also privileged (see Popek-Goldberg)

### 3.2 Para-Virtualization

- Guest OS is **modified** to be "aware" it's running in a VM
- Instead of executing privileged instructions directly, the guest OS makes **hypercalls** to the hypervisor
- **More performant** than full emulation; less transparent
- **Example:** Xen para-virtualization
- **Disadvantage:** Guest OS must be modified (can't virtualize proprietary OSes like unmodified Windows)

### 3.3 Full Virtualization / Transparent Virtualization

- Guest OS runs **unmodified**
- The hypervisor intercepts and handles all sensitive operations transparently
- Guest OS is unaware it's running in a VM

### 3.4 Software Binary Translation

- Used when trap-and-emulate fails (some instructions don't trap)
- Hypervisor **scans and replaces** problematic instructions in guest binary at runtime with safe equivalents
- **VMware** used this technique for pre-VT x86 systems

---

## 4. Popek and Goldberg Principles for Virtualization

> Gerald Popek and Robert Goldberg (1974) defined the **formal requirements** for a computer architecture to efficiently support virtualization.

### Terminologies

| Term | Definition |
|---|---|
| **Virtual Machine (VM)** | An efficient, isolated duplicate of a physical machine |
| **VMM / Hypervisor** | System software creating and managing VMs |
| **Privileged Instructions** | Trap if processor is NOT in privileged/supervisor mode |
| **Sensitive Instructions** | Access or change hardware/system state (mode, page tables, I/O devices) |
| **Behavior-sensitive** | Behavior depends on the hardware mode or configuration |
| **Control-sensitive** | Attempt to change system resource configuration |
| **Safe Instructions** | Instructions that are NOT sensitive |

### Essential Characteristics of a VMM

1. **Equivalence (Fidelity):** Programs running on a VM behave identically to running on bare hardware
2. **Resource Control:** VMM has total control over virtualized resources; no unauthorized access
3. **Efficiency (Performance):** Majority of instructions execute without VMM intervention (no trap)

### Popek-Goldberg Theorems

**Theorem 1:**

> A VMM **may be constructed** if the set of sensitive instructions is a **subset** of privileged instructions.

- All instructions that could affect VMM correctness must trap to the VMM
- Non-privileged instructions execute natively (efficiently)

**Theorem 2:**

> A machine is **recursively virtualizable** if:
> (a) It is virtualizable, and
> (b) A VMM without timing dependencies can be constructed for it.

- Recursive virtualization = ability to run a VM inside a VM

**Theorem 3:**

> A **hybrid VMM** may be constructed if user-sensitive instructions are a subset of privileged instructions.

### x86 and Popek-Goldberg

- **x86 ISA does NOT meet** Popek-Goldberg requirements
- x86 had **17+ sensitive but non-privileged instructions** (e.g., SGDT, SIDT, SLDT, PUSHF, POPF, PUSH %cs)
- Example problem: `PUSHF` reads EFLAGS register (including interrupt bit) from Ring 3 — returns wrong result instead of trapping
- **Solution:** Hardware virtualization extensions (Intel VT-x / AMD-V) were introduced to fix this

---

## 5. Hardware-Assisted Virtualization

### Intel VT-x / AMD-V

- Added new CPU modes: **VMX root mode** (hypervisor runs here) and **VMX non-root mode** (guest OS runs here)
- Hardware now intercepts sensitive instructions automatically
- Eliminates the need for binary translation or para-virtualization for CPU
- `VMLAUNCH` / `VMRESUME` instructions to enter non-root mode (run guest)
- `VM Exit` triggers when guest executes sensitive instructions → control returns to hypervisor

---

## 6. Memory Virtualization

### Problem

- Guest OS must believe it has access to physical memory
- Hypervisor must actually control all physical (host) memory
- **Three-level address translation** needed: Guest Virtual → Guest Physical → Host Physical

### 6.1 Shadow Page Tables (Software)

- Hypervisor creates a **shadow page table (sPT)** for each guest page table
- sPT maps **guest virtual addresses directly to host physical addresses**
- Hardware MMU uses the sPT; guest page tables are write-protected
- When guest modifies its page table → **page fault trap** → hypervisor updates sPT

```
gVA → [Guest Page Table] → gPA → [Host Page Table] → sPA

VMM creates: Shadow PT: gVA → sPA directly
```

**Challenges:**

- High overhead: page faults on every guest page table modification
- Memory overhead: shadow copies of all guest page tables
- TLB flush on every "world switch" (VM entry/exit)

### 6.2 Extended Page Tables / Nested Page Tables (Hardware)

- **Intel EPT** (Extended Page Tables) / **AMD NPT** (Nested Page Tables)
- Hardware now performs **two-dimensional page walk** automatically
- Guest controls its own page tables (gVA → gPA)
- Hypervisor sets up NPT (gPA → sPA)
- Hardware MMU walks both tables on every TLB miss

```
gVA → [gPT (CR3)] → gPA → [EPT (EPTP)] → sPA
```

**Advantages over Shadow PT:**

- No VM exits for guest page table modifications
- No shadow page table maintenance overhead
- Guest has full control of its own IA-32 page tables
- Significant performance improvement

---

## 7. I/O Virtualization

### Full Device Emulation

- Hypervisor emulates well-known hardware devices in software
- Guest OS uses standard device drivers
- All I/O requests from guest are **trapped** and handled by the hypervisor's virtual device
- **Downside:** High overhead; slowest approach

### Para-I/O Virtualization (Split Driver Model)

- Also known as **hosted or split-driver I/O virtualization**
- **Frontend driver:** Runs in guest OS (Domain U in Xen)
- **Backend driver:** Runs in privileged domain (Domain 0 in Xen)
- They communicate via **shared memory buffers**
- Better performance than full emulation, but higher CPU overhead
- **Used in:** Xen hypervisor

```
Guest OS → [Frontend Driver] → Shared Memory → [Backend Driver] → Real Hardware
```

### Direct I/O / Passthrough (Hardware Assisted)

- VM accesses devices **directly**, bypassing VMM emulation layer
- Uses **Intel VT-d** / **AMD IOMMU** for DMA remapping
- Near-native performance, low CPU overhead
- **Limitation:** One physical device can only be assigned to one VM (limited scalability)

### Xen I/O Virtualization

- Xen does **not emulate hardware**
- Exposes device abstractions via shared memory buffers
- Virtualized interrupts via lightweight event delivery mechanism

---

## 8. VM Migration

> **VM Migration** is the process of moving a virtual machine from one host to another.

### Why Migrate?

- **Hardware Maintenance** – Move VMs to allow server maintenance
- **Load Balancing** – Redistribute VMs to avoid hot spots
- **Scaling** – Move to servers with more resources
- **Server Consolidation** – Better utilization of hardware
- **Energy Efficiency** – Reduce power consumption
- **Performance** – Move to nodes with better resources
- **Availability / Business Continuity** – Migrate away from failing hardware

### Types of Migration

#### Cold Migration (Non-Live)

- VM is **powered off** before migration
- All state transferred; VM resumes at destination
- **Pros:** Simple, predictable migration time
- **Cons:** Service downtime; users experience interruption

#### Live (Hot) Migration

- VM migrates **while running** — no disruption to service
- Includes: memory contents, BIOS, devices, MAC addresses
- Users don't notice; network connections not dropped
- **Example:** VMware vSphere vMotion, Xen live migration

---

### Live Migration Techniques

#### Pre-Copy Migration

**Stages:**

1. Select destination host; reserve resources
2. **Iterative pre-copying:** Transfer all memory pages; re-copy only "dirty" pages (modified since last round)
3. Keep iterating until dirty pages below threshold
4. **Stop and copy:** Suspend VM briefly; copy final dirty pages + CPU state
5. **Commitment:** Activate VM on destination; redirect network connections
6. Remove original VM from source

**Advantages:** Low downtime (only final copy stage)

**Disadvantages:** Can take long if high memory churn (many dirty pages)

**Used in:** KVM, Xen, VMware

#### Post-Copy Migration

- **CPU/processor state transferred first** to destination
- VM resumes immediately at destination
- Memory pages fetched **on-demand** from source (via page faults)
- Techniques to pre-fetch pages: **Active Push, Memory Prepaging, Demand Paging**

**Advantages:** VM resumes almost instantly at destination

**Disadvantages:** Page faults create service interruptions; risk if network fails during transfer

---

### Issues in VM Migration

#### Memory Migration

- Memory sizes: hundreds of MB to several GB
- **Internet Suspend-Resume (ISR):** Exploits temporal locality — only changed pages need to be sent

#### File System Migration

- Options:
  1. Copy virtual disk contents with the VM
  2. Use a **global/shared file system** accessible from all hosts (no copying needed)

#### Network Migration

- Migrated VM must maintain open network connections
- Each VM assigned a **virtual IP address** (separate from host IP)
- Each VM has its own **virtual MAC address**
- VMM maintains mapping of virtual IP/MAC to host location

---

## 9. Lightweight Virtualization – Containers and Namespaces

### What Are Containers?

> **Linux Containers (LXC)** provide operating-system-level virtualization — multiple isolated Linux systems (containers) run on a single Linux host OS using **kernel namespaces** and **cgroups**.

- Containers do **NOT** create a full-fledged VM
- They provide isolation using **Linux kernel features**, not hardware emulation

### Container vs VM Comparison

| Feature | Virtual Machine | Container |
|---|---|---|
| Isolation | Full OS isolation | Process-level isolation |
| OS | Each VM has its own OS | Shares host OS kernel |
| Size | Gigabytes | Megabytes |
| Boot time | Minutes | Seconds |
| Performance | More overhead | Near-native |
| Flexibility | Run different OSes | Same OS (Linux) |
| Use case | Strong isolation needed | Microservices, rapid deployment |

---

### Linux Namespaces

> **Namespaces** partition kernel resources so each set of processes sees an isolated view of system resources.

| Namespace | What It Isolates |
|---|---|
| **PID** | Process IDs – each container has its own PID space |
| **UTS** | Hostname and domain name |
| **MNT** | Mount points – filesystem visibility |
| **IPC** | Inter-process communication (shared memory) |
| **NET** | Network interfaces, routes, IP addresses, ports |
| **USR** | User IDs – user name mapping |
| **chroot** | Root filesystem location |

**Key kernel calls:**

- `clone()` with `CLONE_NEWNS` – create new mount namespace
- `setns()` – join an existing namespace
- `unshare()` – create new namespace for current process

### cgroups (Control Groups)

- Kernel feature to **limit and account for** resource usage per process group
- Controls: CPU, memory, disk I/O, network bandwidth
- Each container gets its own cgroup with defined resource limits
- Prevents one container from monopolizing system resources

---

## 10. Docker

> **Docker** is an open platform for developing, shipping, and running applications in **containers**. It uses OS-level virtualization to deliver software in packages.

### Docker Architecture (Client-Server)

- **Docker Client (`docker`):** CLI that sends commands to daemon
- **Docker Daemon (`dockerd`):** Listens for API requests; manages containers, images, networks, volumes
- **Docker Registry (Docker Hub):** Stores Docker images (public or private)
- Communication: REST API over UNIX sockets or network

### Docker Objects

#### Images

- **Read-only template** for creating containers
- Built from a **Dockerfile** (script describing build steps)
- Each instruction in Dockerfile creates a **layer** in the image
- Layers are cached — only changed layers are rebuilt → fast builds
- Stored in registries (Docker Hub, private registries)

#### Containers

- A **running instance of an image**
- Adds a writable layer on top of the image's read-only layers
- Changes are ephemeral — deleted when container is removed
- Uses Linux **namespaces** for isolation + **cgroups** for resource limits

#### Dockerfile Example

```dockerfile
FROM ubuntu:22.04          # Base image
RUN apt-get install nginx  # Install software (creates a layer)
COPY ./app /var/www/html   # Copy application files
EXPOSE 80                  # Document exposed port
CMD ["nginx", "-g", "daemon off;"]  # Default command
```

### UnionFS (Union File System)

- Docker uses a **layered filesystem** (e.g., OverlayFS, AUFS)
- Multiple read-only layers stacked; one writable layer on top
- **Copy-on-write:** Modified files are copied to the writable layer before editing
- Enables lightweight image sharing — multiple containers share base layers

```
Container writable layer (R/W)
────────────────────────────
App layer (R/O)
────────────────────────────
Runtime layer (R/O)
────────────────────────────
Base OS layer (R/O)
```

---

## 11. Orchestration and Kubernetes

### Why Orchestration?

- Running one container is easy; running **hundreds of microservices** in production requires automation
- Need: scaling, load balancing, health monitoring, rolling updates, service discovery

### Kubernetes (K8s)

> **Kubernetes** is an open-source **container orchestration platform** that automates deployment, scaling, and management of containerized applications.

#### Key Concepts

| Concept | Description |
|---|---|
| **Pod** | Smallest deployable unit; contains one or more containers |
| **Node** | Worker machine (VM or physical) running Pods |
| **Cluster** | Set of Nodes managed by Kubernetes |
| **Control Plane** | Brain of Kubernetes (API Server, Scheduler, Controller Manager, etcd) |
| **Service** | Stable endpoint to expose Pods (load balancing) |
| **Deployment** | Declarative way to manage replica sets of Pods |
| **Namespace** | Virtual cluster within a physical cluster (for isolation) |
| **ConfigMap / Secret** | Externalized configuration / sensitive data |
| **Ingress** | HTTP/HTTPS routing to services |

#### Kubernetes Architecture

```
Control Plane:
  ┌──────────────────────────────────────┐
  │  API Server │ Scheduler │ etcd       │
  │  Controller Manager                  │
  └──────────────────────────────────────┘

Worker Nodes:
  ┌──────────────────────────────────────┐
  │  kubelet │ kube-proxy │ Container    │
  │  Runtime (Docker/containerd)         │
  │  Pods → Containers                   │
  └──────────────────────────────────────┘
```

- **API Server:** Front-end for control plane; all `kubectl` commands hit this
- **Scheduler:** Assigns Pods to Nodes based on resource availability
- **Controller Manager:** Watches cluster state; ensures desired state matches actual state (e.g., Replication Controller)
- **etcd:** Distributed key-value store; stores all cluster state
- **kubelet:** Agent on each Node; ensures containers in Pods are running

---

## 12. DevOps and Jenkins Pipeline

### DevOps

> **DevOps** is a set of practices that combine software development (Dev) and IT operations (Ops) to shorten the development lifecycle while delivering features, fixes, and updates frequently and reliably.

**Key Practices:**

- **Continuous Integration (CI):** Frequently merge code; automatically build and test
- **Continuous Delivery (CD):** Automatically deploy tested code to staging/production
- **Infrastructure as Code (IaC):** Manage infrastructure via code (Terraform, Ansible)
- **Monitoring and Logging:** Continuous feedback from production

### Jenkins Pipeline

> **Jenkins** is an open-source automation server that enables CI/CD pipelines.

**Pipeline Stages (typical):**

```
Code Commit → Build → Unit Tests → Integration Tests → Docker Build → Push to Registry → Deploy to K8s
```

**Jenkinsfile (declarative pipeline):**

```groovy
pipeline {
    agent any
    stages {
        stage('Build') {
            steps { sh 'mvn clean package' }
        }
        stage('Test') {
            steps { sh 'mvn test' }
        }
        stage('Docker Build') {
            steps { sh 'docker build -t myapp:${BUILD_NUMBER} .' }
        }
        stage('Deploy') {
            steps { sh 'kubectl apply -f deployment.yaml' }
        }
    }
}
```

---

## Summary

```
Virtualization Technologies:
│
├── Hypervisors
│   ├── Type 1 (Bare Metal): ESXi, Xen, KVM, Hyper-V
│   └── Type 2 (Hosted): VirtualBox, VMware Workstation
│
├── Virtualization Techniques
│   ├── Trap & Emulate
│   ├── Para-virtualization (Hypercalls)
│   ├── Binary Translation
│   └── Hardware (VT-x/AMD-V)
│
├── Memory Virtualization
│   ├── Shadow Page Tables (software)
│   └── Extended/Nested Page Tables (hardware)
│
├── I/O Virtualization
│   ├── Full Device Emulation
│   ├── Para-I/O (Split Driver)
│   └── Direct I/O / Passthrough (VT-d)
│
├── VM Migration
│   ├── Cold (offline)
│   └── Live: Pre-copy | Post-copy
│
└── Containers
    ├── Namespaces + cgroups
    ├── Docker (build, ship, run)
    └── Kubernetes (orchestrate at scale)
```

---

## Key Terms

| Term | Definition |
|---|---|
| Hypervisor | Software creating and managing VMs |
| Para-virtualization | Guest OS modified to make hypercalls |
| Binary Translation | Runtime replacement of non-virtualizable instructions |
| Shadow Page Table | Software-maintained gVA→sPA mapping |
| EPT/NPT | Hardware-assisted two-level memory translation |
| VM Exit | Guest executes sensitive instruction → control to hypervisor |
| Live Migration | Moving a running VM with minimal/no downtime |
| Pre-copy | Iteratively copy dirty pages; brief stop at end |
| Post-copy | Transfer CPU state first; fetch memory on demand |
| Container | Lightweight process isolation using namespaces + cgroups |
| Namespace | Linux kernel feature isolating specific system resources |
| cgroups | Limit and account for resource usage per process group |
| Docker | Platform to build and run containers |
| UnionFS | Layered filesystem enabling image sharing |
| Pod | Smallest K8s unit (one or more containers) |
| Kubernetes | Container orchestration platform |

---
