# communication systems

```
input -> input transducer Tx <== channel ==> Rx -> output transducer -> output
```

> Communication systems involve the conversion of information from one form to another. In the context of electrical signals, this process involves several key components:

1. **Input Transducer (Tx)**: This is the first step in the communication process. It converts the input signal into an electrical signal that can be transmitted over the channel.
2. **Channel**: This is the medium through which the electrical signal is transmitted. It can be a wire, air, or any other medium that allows the signal to travel from the transmitter to the receiver.
3. **Output Transducer (Rx)**: Upon receiving the signal from the channel, the output transducer converts the electrical signal back into the original form of the information.
4. **Output**: This is the final step where the information is presented in its original form to the user.

## Transducers

Transducers play a crucial role in communication systems by converting signals between different forms. There are two main types of transducers:

- **Active Transducers**: These do not require an external power source to operate. They are capable of converting signals on their own.
- **Passive Transducers**: These require an external power source to operate. They are used when the signal needs to be amplified or otherwise processed before it can be transmitted or received.

Transducers operate on the principle of energy conversion, transforming the signal from one form to another.

## Modulation

Modulation is a technique used in communication systems to encode information onto a carrier signal. This process allows for the efficient transmission of information over a channel. There are several types of modulation:

### Continuous Modulation

- **Amplitude Modulation (AM)**: The amplitude of the carrier signal is varied in proportion to the message signal.
- **Frequency Modulation (FM)**: The frequency of the carrier signal is varied in proportion to the message signal.

### Digital Modulation

Information will be in binary form i.e. 1s and 0s where as carrier will be continuous. The amplitude or phase of the carrier will be varied according to binary data.

- **Amplitude Shift Keying (ASK)**: The amplitude of the carrier signal is varied to represent binary data.
- **Phase Shift Keying (PSK)**: The phase of the carrier signal is varied to represent binary data.
- **Frequency Shift Keying (FSK)**: The frequency of the carrier signal is varied to represent binary data.

## Demodulation

The process of recovering the message from the modulated signal is called demodulation.

### Types of demodulation

- **In Coherent**: Local oscillator is tuned to the frequency of the carrier to get back the message.
- **Non-Coherent**: Does not use any Local oscillator.

---

### Need for Modulation

- Modulation increases the distance over which the signal can be transmitted faithfully.
- Modulation reduces the height of the antenna.
- Modulation avoids mixing of signals.
- Modulation reduces noise and interference.
- Modulation is used for multiplexing.
- Modulation helps to adjust bandwidth.

---

## Important Bands

| Application  | Frequency Band |
| ------------ | -------------- |
| AM Radio     | 0.54-1.6 MHz   |
| TV           | 54-8 MHz       |
| FM Radio     | 8-108 MHz      |
| Mobile Radio | 806-901 MHz    |

---

### The Objectives of a Cellular System Include

- Ensuring high **capacity**
- Achieving extensive **coverage**
- Making the best use of a limited spectrum

However, for achieving a large coverage area, a single transmission necessitates high power and the use of tall towers. This approach limits the service to a small number of users and results in efficient spectrum utilization.

### Cellular Concept and Frequency Reuse Pattern

- Each cellular base station is allocated a group of radio channels within a small geographic area known as a cell.
- **Neighbouring Cells** are assigned different channel groups.
- **Frequency Reuse**: By limiting the coverage area to within the boundary of the cell, the channel groups may be reused to cover different cells.
- Keep interference levels within tolerable limits.
- Frequency reuse or frequency planning: seven groups of channels from A to G, footprint of a cell is the actual radio coverage.
 - Each cell uses an omni-directional antenna. (360 degrees)

#### Use of Cellular Concept

- Solves the problem of spectral congestion and user capacity.
- Offers very high capacity in a limited spectrum without major technological changes.
- Helps in the reuse of radio channels in different cells.
- Enables a fixed number of channels to serve an arbitrarily large number of users by reusing the channel throughout the coverage region.

### Cells

- Base station antennas designed to cover specific cell area.
- Hexagonal cell shape assumed for planning.
- Simple model for easy analysis → circles leave gaps.
- Actual cell “footprint” is amorphous (no specific shape) where Tx successfully serves mobile unit.
- Base station location:
  - Cell centre → omni-directional antenna (360° coverage).
    - Not necessarily in the exact center (can be up to R/4 from the ideal location).
  - Cell corners → sectored or directional antennas on 3 corners with 120° coverage.
    - Very common.
- Note that what is defined as a “corner” is somewhat flexible → a sectored antenna covers 120° of a hexagonal cell.
- So one can define a cell as having three antennas in the centre or antennas at 3 corners.

## Handoff Strategies

- **Handoff**: This occurs when a mobile unit moves from one cell to another while a call is in progress. The Mobile Switching Centre (MSC) must transfer (handoff) the call to a new channel belonging to a new base station.
  This involves changing to new voice and control channel frequencies.
- **Importance**: It is crucial to ensure that the handoff process is smooth and efficient, as it is often given higher priority than new calls. It is worse to drop an in-progress call than to deny a new one.
- **Handoff Threshold**: A handoff threshold is chosen that is greater than the minimum usable signal level. This ensures there is time to switch channels before the signal level becomes too low, as the mobile moves away from one base station and towards another.

### **Roaming**

- A mobile device may move into a different system controlled by a different Mobile Switching Centre (MSC). This is known as an inter-system hand off.

1. **Prioritising Handoffs**:
   - Issue: Perceived Grade of Service (GOS) – the quality of service as viewed by users.
   - Quality Consideration: "Quality" in terms of dropped or blocked calls (not voice quality).
   - Prioritization: Handoffs are assigned higher priority over new call requests.
   - Impact of Dropped Calls: A dropped call is more aggravating than an occasional blocked call.

2. **Guard Channels**:

   - Percentage of total available cell channels exclusively set aside for hand off requests
   - Makes fewer channels available for new call requests
   - A good strategy is dynamic channel allocation (not fixed)
   - adjust number of guard channels as needed by demand

3. **Queuing** Handoff Requests

   - Use time delay between handoff threshold and minimum usable signal level to place a blocked handoff request in queue.
   - A handoff request can "keep trying" during that time period, instead of having a single block/no block decision.
   - Prioritise requests (based on mobile speed) and handoff as needed.
	- Calls will still be dropped if time period expires.

### Practical Handoff Considerations

Problems occur because of a large range of mobile velocities

- Pedestrian vs. vehicle user
- Small cell sizes and/or micro-cells lead to larger number of handoffs
Mobile Switching Centre load is heavy when high speed users are passed between very small cells

### Umbrella Cells

- Use different antenna heights and Tx power levels to provide large and small cell coverage
- Multiple antennas & Tx can be co-located at single location if necessary (save on obtaining new tower licenses)
- Large cell →high speed traffic →fewer handoffs
- Small cell →low speed traffic

Example areas: interstate highway passing through urban centre, office park, or nearby shopping mall.

---

#### Typical handoff parameters

- Analog cellular (1st generation): threshold margin Δ≈ 6 to 12 dB, total time to complete handoff ≈ 8 to 10 sec
- Digital cellular (2nd generation): total time to complete handoff ≈ 1 to 2 sec, lower necessary threshold margin Δ≈ 0 to 6 dB, enabled by mobile assisted handoff

#### Benefits of small handoff time

- Greater flexibility in handling high/low speed users
- **Queuing** handoffs & prioritizing
- More time to “rescue” calls needing urgent handoff
- Fewer dropped calls → GOS increased
- Can make decisions based on a wide range of metrics other than signal strength
  - Such as measure interference levels
  - Can have a multidimensional algorithm for making decisions
MSC dynamically decides which signal is best and then listens to that one
- Soft Handoff: Passes data from that base station on to the PSTN(Public switched telephone Network)
This choice of best signal can keep changing
- Mobile user does nothing for handoffs except just transmit, MSC does all the work
- Advantage is unique to CDMA (Code-division Multiple access) systems: as long as there are enough codes available.

---

## Co-Channel Interference

During Frequency reuse there are several cells that use the same set of frequencies which leads to co-channel interference.

- To reduce co-channel interference (CCI), co-channel cell must be separated by a minimum distance.
- co-channel interference is independent of the transmitted
power

### co-channel interference is a function of

- **R**: Radius of the cell
- **D**: distance to the centre of the nearest co-channel cell
- Increasing the ratio *==Q=D/R==* the interference is reduced.
- **Q** is called the co-channel reuse ratio

---

next: [[embedded]]
