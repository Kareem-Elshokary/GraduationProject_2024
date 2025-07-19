#              GraduationProject_2024
# Design and Development of an Autonomous Self-parking Car

## 📌 Overview
This project presents the design and development of an autonomous self-parking system capable of detecting suitable parking spaces, selecting the appropriate parking type (parallel or perpendicular), and executing the parking and exit maneuvers automatically. It integrates Advanced Driver Assistance Systems (ADAS) concepts to enhance safety, reduce human error, and improve parking efficiency in tight urban environments.

## 🧠 Features
- Automatic detection of parking spaces.
- Smart decision-making for choosing parking strategy.
- Smooth and safe maneuvering using non-holonomic kinematic constraints.
- Real-time obstacle detection and avoidance.
- Full software architecture including MCAL, HAL, and Application Layer.
- Real-time scheduling using RTOS.
- MATLAB-based simulation and validation.

## 🛠️ Technologies & Components
Hardware:
- Custom-designed chassis and steering mechanism (inspired by BMW car dimensions)
- STM32F103C8T6 (Bluepill)
- Ultrasonic Sensors × 4
- DC Motors × 2
- Servo Motor × 1
- L298N Motor Driver
- Lithium Batteries, BMS, Voltage Regulators

Software:
- Path planning algorithms implemented & tested in MATLAB
- Low-level drivers (MCAL): GPIO, RCC, EXTI, Timer, UART, I2C
- Hardware Abstraction Layer (HAL) for motor and sensor control
- Application Layer with custom path planning and control logic
- Real-Time Operating System (RTOS) for task scheduling

