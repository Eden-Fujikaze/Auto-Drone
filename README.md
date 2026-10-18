<p align="center">
  <img src="./assets/temp_banner.png" alt="Auto-Drone Banner" width="100%">
</p>

## Project breakdown

### What is it \[S\]
Drone following an object (the "lure").
Communicates with the "lure", a microcontroller carried by a person that sends a UWB signal, and identify the person holding the lure.
Using BU03 and BU04 modules alongside and ESP32c6 we can make the following system.
### Budget \[M\]
TBA
### Is it achievable \[A\]
Considering predispositions and the planning already started the project seems completable in the given timeframe.
### The purpose \[R\]
Example usages include:
- automatic recording hands-free, usable for motorcycle rides.
- looking cool following like a minion
### Time bounds \[T\]
Deadline in march, ~9 months.
### Goal
Achieve fully autonomous flight with a certain deadzone for safety.
#### Sub-Goals
- Multiple flight modes.
- A battery life of at least 30 minutes.
### What is not included
- Handling multiple lures or drones
- Obstacle detection and avoidance
- Legal certification
- Flight in harsh conditions
### Unorganized milestones
- Finish hardware research and choices
- Obtaining drone certification
- Start demoing a lure - drone ping app via WiFi because of the lack of an UWB module on hand
- Iterate concept art
- Research how remote control communication works
- Design a bare bones remote control system
- Design a 3d printable body for the drone
- Start assembly on a bare bones frame
### Problems
See more at [problem](docs/problems.md)
### Unorganized risks
- Delivery of the UWB module taking a long time
- Drone harming used components via crashing
```mermaid
gantt
    title Projekt Dron UWB
    dateFormat YYYY-MM-DD
    axisFormat %b

    section Research
    Hardware research and choices         :t01, 2026-10-01, 40d
    Research remote control communication :t02, 2026-10-01, 50d

    section Design
    Iterate concept art                   :t03, 2026-10-23, 25d
    Design 3D-printable drone body        :t04, 2026-11-01, 30d
    Design lure                           :t05, 2026-11-01, 25d

    section Software
    Develop drone and control software    :t06, 2026-10-25, 120d
    Software updates and adjustments      :t07, 2027-01-15, 60d

    section Assembly
    Purchase parts                        :t08, after t05, 35d
    Assemble lure                         :t09, after t05, 20d
    Assemble bare-bones drone frame       :t10, after t04, 30d
    Integrate UWB modules                 :t11, after t10, 30d
    Fully assemble droned                 :milestone, t16, after t11, 0d

    section Certification
    Drone certification                   :crit, t11, 2027-01-01, 31d
    
    section Testing
    Autonomous following and deadzone     :t12, 2027-01-20, 35d
    Multiple flight modes                 :t13, 2027-02-01, 25d
    Battery life testing                  :t14, 2027-02-10, 20d
    Final testing and improvements        :t15, 2027-02-20, 25d
```
