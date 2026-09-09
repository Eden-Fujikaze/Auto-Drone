<p align="center">
  <img src="./assets/temp_banner.png" alt="Auto-Drone Banner" width="100%">
</p>

# Autonomous flight drone
Project for a drone following a "lure" via DW1000 modules.
## Current grasp on the project:
### What it does
Communicate with the "lure", a microcontroller carried by a person that sends a UWD signal, and identify the person holding the lure.
The drone's camera would communicate with the Ping of the lure and find who to follow.
### Goal
Achieve fully autonomous flight with a certain deadzone for safety.
#### Sub-Goals
- Multiple flight modes.
- A battery life of atleast 30 minutes.
### Problems
1. UWD does not provide angle - just distance.
- Camera would provide a way to recognize what to follow solving the angle problem but it is way more work.
+ Additional prototyping would be done with the esp pinging a laptop camera to test if it works.
- LiDAR or an additional camera would allow for proper depth perception.
