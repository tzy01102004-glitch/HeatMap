# Plan

## Goal

Build a wearable 3×3 thermistor-based insole system that measures plantar temperature distribution in real time and outputs structured data for thermal mapping and analysis.

The system aims to provide stable, low-cost, and expandable temperature sensing suitable for prototyping wearable biomedical devices.

---

## Non-goals

* No pressure sensing (FSRs excluded)
* No clinical/medical diagnosis or certification-level accuracy
* No wireless transmission in initial prototype
* No advanced PCB fabrication in early stages
* No high-density array expansion (10×10) in initial build phase

---

## Requirements / Constraints

### Hardware

* Arduino Uno / Nano / Mega
* 9 × NTC thermistors (10k nominal)
* 9 × 10kΩ resistors (voltage divider configuration)
* Optional CD74HC4067 multiplexer (for scaling or pin limitation)
* Ribbon cable or flexible wiring for wearable integration
* Foam insole or soft substrate for mounting sensors

### Electrical Constraints

* 5V USB power supply from Arduino
* Shared ground across all sensors
* Stable analog readings required (low noise environment preferred)

### Performance Constraints

* Sampling rate: 1–5 Hz sufficient (temperature changes slowly)
* Target accuracy: ±0.5°C after calibration

---

## Proposed approach

### Sensor Architecture

Each thermistor is paired with a fixed resistor in a voltage divider circuit, producing an analog voltage proportional to temperature.

Two implementation options:

1. Direct analog reading (preferred for Arduino Mega)
2. Multiplexed reading using CD74HC4067 (for Arduino Uno/Nano)

---

### Data Processing Pipeline

1. Arduino reads analog voltage from each sensor
2. Convert voltage → resistance
3. Convert resistance → temperature using Beta equation
4. Apply per-sensor calibration offsets
5. Output serial data stream for visualization

---

### System Layout

3×3 spatial grid:

Toe region:
[T1] [T2] [T3]

Midfoot:
[T4] [T5] [T6]

Heel:
[T7] [T8] [T9]

---

## Milestones (small steps)

### Milestone 1: Single Sensor Validation

* Connect 1 thermistor voltage divider
* Verify stable temperature readings
* Confirm correct resistance-to-temperature conversion

### Milestone 2: 3-Sensor Prototype

* Expand to 3 thermistors
* Test consistency and noise behaviour

### Milestone 3: Full 3×3 Array

* Complete hardware assembly
* Implement full Arduino data acquisition
* Verify cross-sensor consistency

### Milestone 4: Calibration & Stabilisation

* Perform two-point calibration
* Apply per-sensor offsets in firmware
* Improve noise filtering (moving average)

### Milestone 5: Wearable Integration

* Embed sensors into insole
* Test during standing and walking
* Evaluate durability and signal stability

---

## Test plan

### Unit tests

* Test single thermistor response to heat
* Validate voltage divider operation

### Integration tests

* Test all 9 sensors simultaneously
* Ensure stable readings with no sensor dropout

### Consistency tests

* Place all sensors under same temperature
* Check variance across sensors (target: ±0.5–1.0°C)

### Stability tests

* Record readings over time (1–2 minutes stationary)
* Check for noise and drift

### Wearable tests

* Embed into insole and test during motion
* Ensure readings remain stable under walking conditions

---

## Rollback plan

If system fails at any stage:

* If readings are unstable → revert to single sensor testing
* If multiplexing fails → switch to direct analog reading (if pins available)
* If noise is high → add averaging filter and decoupling capacitors
* If wiring fails → revert to breadboard prototype before wearable integration
* If calibration fails → reset offsets and repeat two-point calibration

---

## Open questions

* Should multiplexing or direct analog reading be used for final architecture?
* What is the optimal sensor spacing for accurate plantar mapping?
* How much does insole material affect thermal response time?
* Is additional filtering needed for walking motion artifacts?
* Should future expansion move toward 5×5 or 10×10 resolution?

