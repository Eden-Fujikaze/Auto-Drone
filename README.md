<p align="center">
  <img src="./assets/temp_banner.png" alt="Auto-Drone Banner" width="100%">
</p>
<hr>

# Project breakdown
## What is it \[S\]
Drone following an object (the "lure").
Communicates with the "lure", a microcontroller carried by a person that sends a UWB signal, and identify the person holding the lure.
Using BU03 and BU04 modules alongside and ESP32c6 we can make the following system.
## Budget \[M\]
TBA
## Is it achievable \[A\]
Considering predispositions and the planning already started the project seems completable in the given timeframe.
## The purpose \[R\]
Example usages include:
- automatic recording hands-free, usable for motorcycle rides.
- looking cool following like a minion
## Time bounds \[T\]
Deadline in march, ~9 months.
## Goal
Achieve fully autonomous flight with a certain deadzone for safety.
## Sub-Goals
- Multiple flight modes.
- A battery life of at least 30 minutes.
## What is not included
- Handling multiple lures or drones
- Obstacle detection and avoidance
- Flight in harsh conditions
## Hardware list, prices and weight estimates
Updated often at [hardware list](docs/hardware.md)

## Risks
The differentiation here is:
| Category | Meaning |
| - | - |
| Risk | Might happen |
| Issue | Already true |
| Open decision | Not yet made |
| Expected cost/Problem | Will happen |

### Risks
 
| ID | Risk | Probability | Impact | Score | Priority |
| - | - | - | - | - | - |
| R1 | Shell may add weight because of 3d printing artifacts and drag and may disturb prop airflow | | | | |
| R2 | Drone/component self injury while testing | | | | |
| R3 | Project deadline slips | | | | |
| R4 | Battery fire hazard | | | | |
| R5 | No legal certification in time for tests | | | | |

<details>
<summary><b>Open decisions</b></summary>

| ID | Decision |
| - | - |
| O1 | What FC |
| O2 | FC firmware. |
| O3 | ESP32c6 and FC interface and protocol. |
| O4 | Frame, bought or printed. |
| O5 | Final flight time target |
| O6 | How do we height hold. |
| O7 | Budget figure. |
</details>
<details>
<summary><b>Issues</b></summary>

| ID | Issue |
| - | - |
| I1 | Knowledge gap on flight-controller, ESC and firmware topics. |

</details>
<details>
<summary><b>Decisions</b></summary>

| ID | Decision |
| - | - |
| D1 | Self-funded, no school budget |
| D2 | UWB for lure comms, BU04 on the drone for angle |
| D3 | Fixed height, 2D following only |
 
</details>
<details>
<summary><b>Problems</b></summary>
See more at [problems](docs/problems.md)
 
| ID | Problem |
| - | - |
| P1 | Long UWB delivery. Solution: Order ASAP |
 
</details>
<details>
<summary><b>Not Enough Info</b></summary>

| ID | Unknown |
| - | - |
| N1 | UWB AoA is not precise enough |
| N2 | Refresh rate does not allow stable and smooth following |
| N3 | Hover efficiency is unverified, so the 30 min goal could be missed |
 
</details>

## TODO

<details>
<summary><b>TODO</b></summary>

- [ ] Research NEI section to organize it into risks, problems etc.
- [ ] Find out the legal requirements to fly
- [ ] Find thrust and power tables for the shortlisted 2306 motor and 5" prop to replace $\eta$ guess 
- [ ] Confirm the ESC and flight controller support 6S
- [ ] Check the BU04 and BU03 datasheets for AoA details
- [ ] Order the UWB modules
- [ ] Check barometer vs alternatives for height hold (downward rangefinder, optical flow)
- [ ] What the fuck are escs and a flight controller
- [ ] Learn how to pick the correct brushless motors
- [ ] What is UART

</details>

## Battery model

<details>
<summary>Assumptions and formula</summary>

| Symbol | Meaning | Value | Confidence |
| - | - | - | - |
| $m_0$ | Drone mass - battery | 450 | 0.8 |
| $\eta$ | Hover efficiency | $7 \frac{g}{W}$ | 0.2 |
| $P_e$ | Electronic drain | 5 W | 0.5 |
| $u$ | Usable charge to keep reserver | 80% | 1 |
| $\rho$ | Charge per kg | LiPo $145 \frac{Wh}{kg}$, Li-on $230 \frac{Wh}{kg}$ | 0.5 |
| $t$ | flight time | 0.5 h | 0.9 |

$m_b=\frac{t(m_0+\eta P_e)}{\frac{u \rho \eta}{1000}-t}$
$E_{req} = \frac{\rho m_b}{1000}$
 
</details>

## Schedule
 
<details>
<summary>Gantt chart</summary>



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
    Fully assemble droned                 :milestone, t17, after t11, 0d

    section Certification
    Drone certification                   :crit, t12, 2027-01-01, 31d
    
    section Testing
    Autonomous following and deadzone     :t13, 2027-01-20, 35d
    Multiple flight modes                 :t14, 2027-02-01, 25d
    Battery life testing                  :t15, 2027-02-10, 20d
    Final testing and improvements        :t16, 2027-02-20, 25d
```
PS: Lure development will already be in progress using WiFi to have a working demo. But the UWB version will be reinterpreted using our demo as noted on the Gantt diagram.

</details>
