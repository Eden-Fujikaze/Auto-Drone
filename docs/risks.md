# Project Risks

## 1. Risk Assessment Methodology

Risks are assessed using a 1–5 scale for probability and impact.

| Score | Probability | Impact |
|---:|---|---|
| 1 | Very unlikely | Negligible |
| 2 | Unlikely | Minor |
| 3 | Possible | Moderate |
| 4 | Likely | Major |
| 5 | Very likely | Critical |

**Risk score = Probability × Impact**

| Score | Priority |
|---:|---|
| 1–5 | Low |
| 6–11 | Medium |
| 12–19 | High |
| 20–25 | Critical |

## 2. Risk Register

| ID | Risk | Probability | Impact | Score | Priority |
|---|---|---:|---:|---:|---|
| R1 | Unreliable UWB ranging or angle estimation | 4 | 5 | 20 | Critical |
| R2 | Drone instability, crash, or injury | 3 | 5 | 15 | High |
| R3 | Battery endurance below 30 minutes | 4 | 5 | 20 | Critical |
| R4 | Hardware exceeds the 500 PLN budget | 4 | 4 | 16 | High |
| R5 | Delayed UWB module delivery | 4 | 4 | 16 | High |
| R6 | Integration problems between ESP32-C6 and flight controller | 3 | 4 | 12 | High |
| R7 | Autonomous following or deadzone logic fails | 3 | 5 | 15 | High |
| R8 | Project schedule slips before the March deadline | 4 | 5 | 20 | Critical |
| R9 | Excessive weight or weak 3D-printed parts | 3 | 4 | 12 | High |
| R10 | Communication loss or interference | 3 | 5 | 15 | High |
| R11 | GPS or compass limitations | 3 | 3 | 9 | Medium |
| R12 | Components damaged during development and testing | 4 | 3 | 12 | High |
| R13 | Flight controller or ESC incompatibility | 3 | 4 | 12 | High |
| R14 | Certification or legal restrictions delay testing | 3 | 5 | 15 | High |

## 3. Risk Prevention and Contingency Plans

### R1 — Unreliable UWB Ranging or Angle Estimation

**Risk:** The BU03 and BU04 modules may not provide sufficiently reliable distance and direction measurements during flight. Multipath reflections, antenna orientation, obstructions, and interference may introduce errors.

**Preventive measures:**
- Test both modules on a bench before installing them on the drone.
- Measure distance accuracy at several known distances and orientations.
- Verify the BU04's angle-estimation capabilities and supported interfaces.
- Test with a moving lure and different antenna orientations.
- Filter noisy measurements and reject stale or implausible readings.

**Contingency plan:**
- Begin with distance-only tracking or a restricted demonstration if angle estimation is unreliable.
- Continue development using the existing Wi-Fi-based lure demonstration.
- If the BU04 cannot provide sufficient direction data, investigate alternative positioning methods or additional hardware.

### R2 — Drone Instability, Crash, or Injury

**Risk:** Incorrect motor configuration, control errors, or unexpected movements may cause a crash, component damage, or injury.

**Preventive measures:**
- Use an established flight controller and proven flight-control firmware.
- Configure arming checks, low-battery warnings, failsafe behavior, and emergency disarming.
- Test software and motor outputs with propellers removed.
- Conduct initial flights in a controlled, unoccupied area.
- Keep autonomous following disabled until manual flight and failsafe behavior are verified.

**Contingency plan:**
- Stop testing after an uncontrolled movement or crash.
- Inspect the frame, motors, propellers, battery, wiring, and electronics before further testing.
- Replace damaged components and restore the last verified firmware configuration.
- If safe autonomous flight cannot be achieved, demonstrate positioning without autonomous propulsion.

### R3 — Battery Endurance Below 30 Minutes

**Risk:** The estimated final mass of approximately 850 g may require more power than expected. The 30-minute endurance target may not be achievable with the selected frame, motors, and battery.

**Preventive measures:**
- Measure the completed aircraft's actual weight.
- Select motors, propellers, ESCs, and battery as a compatible propulsion system.
- Estimate endurance using measured average current and usable battery capacity.
- Test hover power consumption before finalizing the body.
- Minimize unnecessary structural weight.

**Contingency plan:**
- Reassess the airframe, propulsion system, and battery capacity.
- Reduce payload and body weight where structurally safe.
- If 30 minutes proves impractical within the available budget and dimensions, document the achievable endurance and revise the target.

### R4 — Hardware Exceeds the 500 PLN Budget

**Risk:** The flight controller may consume most or more than the available budget, while ESCs, motors, the frame, battery, and UWB modules still require funding.

**Preventive measures:**
- Maintain a complete bill of materials with component prices, shipping, and taxes.
- Compare complete system costs rather than individual component prices.
- Prioritize hardware essential for safe flight and the UWB demonstration.
- Compare separate flight controllers and ESCs against an AIO solution.
- Reserve funds for replacement parts where possible.

**Contingency plan:**
- Remove nonessential features and cosmetic components.
- Reuse compatible parts already available.
- Purchase equivalent components from alternative suppliers.
- If the full specification remains unaffordable, reduce the scope to a safe proof of concept.

### R5 — Delayed UWB Module Delivery

**Risk:** Late delivery of the BU03 or BU04 may leave insufficient time for integration and testing before the deadline.

**Preventive measures:**
- Verify stock availability and shipping estimates before ordering.
- Order critical modules early.
- Continue developing the lure using the existing Wi-Fi implementation.
- Develop communication interfaces independently of the physical UWB hardware.

**Contingency plan:**
- Test the drone, flight controller, and lure interface using simulated positioning data.
- Investigate alternative suppliers or compatible modules.
- If the modules arrive too late, demonstrate the existing Wi-Fi implementation and document the remaining UWB integration work.

### R6 — ESP32-C6 and Flight Controller Integration Problems

**Risk:** Communication may fail because of incompatible interfaces, message formats, electrical levels, timing, or firmware configuration.

**Preventive measures:**
- Select the communication protocol early, such as UART using a supported flight-controller protocol.
- Verify voltage levels, pin assignments, baud rates, and interface availability.
- Build a minimal communication prototype before integrating UWB.
- Separate positioning code from the flight-control interface.
- Test delayed, invalid, and missing messages.

**Contingency plan:**
- Replace the communication layer without rewriting the positioning system.
- Use another supported protocol or available flight-controller interface.
- Demonstrate positioning output independently while resolving integration problems.

### R7 — Autonomous Following or Deadzone Logic Fails

**Risk:** The drone may approach too close to the lure, oscillate around the desired following distance, move in the wrong direction, or continue moving when positioning data becomes unreliable.

**Preventive measures:**
- Define the following distance, maximum speed, stopping conditions, and target-loss behavior.
- Keep the following controller separate from the flight controller's stabilization system.
- Implement a deadzone with hysteresis to prevent repeated starting and stopping near its boundary.
- Limit commanded speed and acceleration.
- Test the algorithm with simulated or recorded positioning data before flight.

**Contingency plan:**
- Disable autonomous movement and return to manual control.
- Use a tested safe mode that stops following and performs a controlled landing when required.
- Reduce operating distance and movement speed.
- Demonstrate tracking and deadzone behavior in simulation if flight tests remain unreliable.

### R8 — Project Schedule Slips Before the March Deadline

**Risk:** Hardware selection, procurement, software development, and flight testing overlap. Delays in one activity may prevent the complete system from being tested before the deadline.

**Preventive measures:**
- Define a minimum viable demonstration and prioritize it over optional features.
- Establish milestones for hardware selection, bench testing, manual flight, UWB integration, and autonomous flight.
- Track task dependencies in the Gantt chart and review progress regularly.
- Develop the lure and flight-control interfaces in parallel.
- Reserve time for debugging and final testing.

**Contingency plan:**
- Reduce the scope to the core functionality that can be demonstrated safely.
- Defer optional flight modes and cosmetic improvements.
- Use simulation and bench testing to validate unfinished subsystems.
- Deliver a documented prototype with clearly stated limitations if full implementation is not possible by the deadline.

### R9 — Excessive Weight or Weak 3D-Printed Parts

**Risk:** The printed body may add unnecessary weight or fail under vibration or impact. The current weight estimate may omit additional components and mounting hardware.

**Preventive measures:**
- Weigh components as they are acquired and maintain an updated mass estimate.
- Include wiring, connectors, fasteners, and mounts in the weight calculation.
- Use lightweight designs with sufficient reinforcement at mounting points.
- Test printed components for fit, vibration, and mechanical strength.
- Secure the battery and other heavy components properly.

**Contingency plan:**
- Redesign or remove nonstructural printed parts.
- Use a conventional frame for the primary load-bearing structure.
- Replace damaged mounts and repeat the relevant tests before flight.

### R10 — Communication Loss or Interference

**Risk:** The lure may lose communication with the drone, or UWB measurements may become invalid because of interference, obstruction, or excessive distance.

**Preventive measures:**
- Define communication timeouts and validate incoming measurements.
- Test the communication link at the intended operating distances.
- Distinguish communication loss from valid target movement.
- Implement a failsafe that remains effective when the lure stops transmitting.
- Ensure manual takeover or safe flight termination is possible.

**Contingency plan:**
- Stop following when measurements become stale or invalid.
- Enter a predefined safe mode, such as a controlled landing, using tested flight-controller configuration.
- Restore communication and reinitialize tracking before resuming.
- Restrict testing to a verified operating area if reliability remains insufficient.

### R11 — GPS or Compass Limitations

**Risk:** GPS and compass hardware remain undecided. Position drift or magnetic interference from motors may affect navigation and heading estimates.

**Preventive measures:**
- Determine which navigation functions the selected flight controller and firmware require.
- Verify compass placement and calibration if a compass is used.
- Test heading and position stability with all electronics powered.
- Avoid relying on GPS for precision relative following if UWB provides the required target measurements.

**Contingency plan:**
- Use a verified flight mode that does not depend on unreliable navigation data.
- Reposition or replace the compass if interference is excessive.
- Restrict testing to conditions supported by the verified navigation configuration.

### R12 — Components Damaged During Development and Testing

**Risk:** Crashes, wiring mistakes, or incorrect configuration may damage motors, electronics, batteries, or UWB modules.

**Preventive measures:**
- Keep spare vulnerable components where affordable.
- Verify polarity and continuity before powering new circuits.
- Use current-limited supplies for initial electronic tests where appropriate.
- Test software changes incrementally and retain known-good versions.
- Secure wiring and electronics against vibration.

**Contingency plan:**
- Diagnose the cause before replacing parts or resuming tests.
- Use spare or compatible components when available.
- Reorder critical components promptly and continue software development in parallel.

### R13 — Flight Controller or ESC Incompatibility

**Risk:** The selected flight controller and ESC combination may not fit the frame, support the required firmware, or provide compatible motor outputs and electrical connections.

**Preventive measures:**
- Select the flight controller, ESC, frame, motors, and firmware as a compatible set.
- Verify mounting patterns, voltage ranges, motor output support, current ratings, and connector requirements.
- Compare the complete installed cost of separate components against the AIO alternative.
- Bench-test motor outputs without propellers before attempting flight.

**Contingency plan:**
- Replace incompatible components with verified alternatives.
- Redesign mounting or wiring where the incompatibility can be corrected safely.
- Avoid combining unverified components solely to remain within the original budget.

### R14 — Certification or Legal Restrictions Delay Testing

**Risk:** Applicable drone regulations or operational restrictions may limit where, how, or whether autonomous following tests can take place.

**Preventive measures:**
- Identify the applicable Polish and EU drone rules before flight testing.
- Verify operator requirements, aircraft classification, permitted operating conditions, and applicable authorization requirements.
- Plan tests in a suitable controlled location with appropriate separation from uninvolved people.
- Address regulatory requirements before beginning flight testing.

**Contingency plan:**
- Postpone flight tests until applicable requirements are satisfied.
- Continue with simulation, bench tests, and propeller-off integration.
- Arrange a compliant test location or revise the demonstration to meet the applicable restrictions.

## 4. Risk Monitoring

The risk register should be reviewed regularly and updated whenever hardware tests, software integration, procurement, or design decisions change the likelihood or impact of a risk.

Risk scores should be reassessed after preventive measures have been implemented and their effectiveness has been verified. A planned mitigation should not automatically be treated as a reduction in risk.
