# Unit 2: Compute and Lightweight Virtualization

This unit covers the evolution and technical implementation of virtualization, ranging from traditional hardware-level abstraction to modern lightweight containerization and orchestration.

## 1. Virtualization Fundamentals and Types

Virtualization abstracts physical resources into logical views to increase infrastructure utilization and management efficiency.

- **Transparent (Full) Virtualization:** The hypervisor translates CPU instructions of the guest OS on the fly so it can run **unmodified**. This provides an environment identical to the original hardware, allowing the guest OS to be "unaware" it is virtualized. VMWare Workstation is a common example.
- **Paravirtualization:** This involves rewriting the guest OS code to replace non-virtualizable instructions with **hypercalls**. While more efficient than binary translation, it requires a **modified guest OS** that is aware of the hypervisor. **Xen** is a primary example of this architecture.

---

## 2. Software Virtualization Techniques

### Trap and Emulate

This technique relies on CPU privilege levels (Rings). Typically, the OS runs in **Ring 0** (highest privilege) and applications in **Ring 3**.

- **Mechanism:** The VM runs in **User mode** (Ring 3), while the hypervisor runs in **Privileged mode** (Ring 0). When the VM executes a system instruction or accesses system state, it triggers a **trap** (general protection fault) to the hypervisor, which then **emulates** the action.
- **Challenges:** Some x86 instructions are **sensitive but unprivileged** (e.g., `popf`), meaning they execute incorrectly in Ring 3 without triggering a trap. This led to the conclusion that pre-2005 x86 ISAs were not fully virtualizable by "trap and emulate" alone.

### Binary Translation

To support unmodified guest OSes on architectures that do not support classic trap-and-emulate, hypervisors use **binary translation**.

- **Mechanism:** The monitor inspects basic blocks of guest code for **"unsafe or sensitive"** unprivileged instructions. These are translated into **"safe"** privileged equivalents and stored in a **translation cache** for execution.
- **Benefit:** Since instructions are translated before execution, no traps are needed, providing a conceptually simple workaround for x86 limitations.

---

## 3. The Popek and Goldberg Principles (1974)

These principles define the requirements for an architecture to efficiently support virtualization.

- **Essential Characteristics:**
    1. **Equivalence:** The VMM must provide an environment identical to the original machine.
    2. **Efficiency:** All safe instructions should run directly on the hardware.
    3. **Resource Control (Omnipotence):** Only the VMM can manipulate sensitive system states.
- **Theorem:** A VMM can be constructed if every **sensitive instruction** (those accessing low-level machine states) is also a **privileged instruction** (causing a trap in unprivileged mode).

---

## 4. Hardware-Assisted Virtualization

To resolve the "sensitive-but-unprivileged" instruction problem, vendors introduced **Intel VT-x and AMD-v**.

- **Root and Non-root Modes:** These introduce two new operation modes, each with its own set of Ring 0–3 levels. The hypervisor runs in **Root mode**, while VMs run in **Non-root mode**.
- **VMCS:** The hypervisor initializes and modifies a **Virtual Machine Control Structure (VMCS)** and uses instructions like `vmlaunch` to enter a VM. Triggers then cause a **VM Exit** back to the hypervisor, ensuring it retains control.

---

## 5. Memory Virtualization

VMs must not have direct access to physical memory; the VMM must manage host physical memory while making the guest believe it has its own.

### Shadow Page Tables (Software Approach)

The hypervisor creates a **shadow page table** that maps **guest virtual addresses (gVA)** directly to **host physical addresses (hPA)**.

- **Consistency:** The hypervisor marks the guest’s own page tables as **read-only**; any attempts by the guest to modify them trigger a trap, allowing the hypervisor to sync the shadow table.
- **Drawback:** This leads to high overhead due to frequent page faults and the need for a shadow table for every guest process.

### Nested/Extended Page Tables (Hardware Assisted)

**Nested Page Tables (NPT)** or **Extended Page Tables (EPT)** reduce software overhead.

- **Mechanism:** The hardware is made aware of two levels of translation: the guest page table (gPT) and the nested table (nPT). On a TLB miss, the **hardware page walker** performs a **two-dimensional walk** to translate gVA to hPA.
- **Benefits:** The guest has full control over its page tables without VM exits, reducing the memory footprint and improving performance by up to 20% depending on the workload.

---

## 6. I/O Virtualization and VM Migration

### I/O Virtualization Techniques

1. **Full Device Emulation:** Replicates device functions in software.
2. **Para-I/O (Virtualized Abstractions):** Used in **Xen**, this method uses **shared-memory buffers** and light-weight event delivery (virtualized interrupts) instead of emulating hardware.
3. **Direct I/O (Passthrough):** Allows the VM to access physical devices directly, enabling **DMA** to/from host memory and achieving close-to-native performance.

### VM Migration

Migration is the process of moving a running VM between physical hosts to improve availability or energy efficiency.

- **Cold Migration:** Moving a **powered-off** VM.
- **Live (Hot) Migration:** Moving a powered-on VM with **no service disruption**.
    - **Pre-copy Technique:** Memory pages are copied while the VM continues running. Dirty pages (modified during copying) are tracked using shadow paging and sent in iterative rounds until the remaining portion is small enough for a short **"stop and copy"** phase.
    - **Post-copy Technique:** The processor state is transferred **before** memory content. The VM resumes instantly on the target, and memory pages are fetched as needed via **demand paging** or proactively via **active push**.

---

## 7. Lightweight Virtualization: Containers

**Linux Containers (LXC)** are an OS-level virtualization method for running multiple isolated systems on a single host. They are "lighter" than VMs because they share the **host OS kernel** and binaries, starting in seconds rather than minutes.

### Key Enabling Technologies

- **Namespaces:** Partition kernel resources so processes in one namespace see a distinct set of resources.
    - **MNT:** Isolates mount points (using `chroot` or `pivot_root` to change the root directory).
    - **UTS:** Isolates hostnames and domain names.
    - **NET:** Provides isolated network interfaces, routing tables, and IP addresses.
    - **PID:** Isolates process identifiers.
- **Cgroups (Control Groups):** Used to **limit, account, and prioritize** resource usage (CPU, memory, disk I/O) for groups of processes.
- **UnionFS:** Overlays files from separate branches to form a single coherent filesystem. It uses a **Copy-on-Write (CoW)** pattern, where changes are recorded in a temporary layer without modifying the original read-only image.

---

## 8. Deployment and Orchestration

### Docker Fundamentals

Docker uses containers to separate applications from infrastructure.

- **Images:** Read-only collections of files and metadata.
- **Registries:** (e.g., Docker Hub) Stores and distributes images.
- **Volumes:** Used for persistent storage, as container filesystems are deleted when destroyed.

### Orchestration and Kubernetes (K8s)

As systems scale, **orchestration** is needed to coordinate activities and **scheduling** is required to assign workloads to available resources.

- **Kubernetes Basics:** A platform that orchestrates workloads across infrastructure to maintain **immutable infrastructure**.
- **Pod:** The smallest unit, consisting of co-located containers that share namespaces, Cgroups, and IP addresses.
- **Service:** A policy-driven coupling that exposes a set of Pods to external access, providing stable endpoints despite Pods being destroyed and recreated.

### DevOps and Continuous Delivery

**DevOps** combines software development (Dev) and IT operations (Ops) to shorten the **System Development Life Cycle (SDLC)**.

- **Continuous Integration (CI):** The automatic merging of code, requiring modules to compile and pass sanity testing against the mainline branch.
- **Continuous Delivery:** The principle that every build is a potential release and manual bottlenecks should be eliminated.
