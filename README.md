# LabVIEW & LINX Multi-Platform Temperature Regulation System

A real-time data acquisition and closed-loop temperature control system developed in **National Instruments LabVIEW**, utilizing the **MakerHub LINX** framework to interface with various microcontrollers over Serial (UART) and TCP/IP connections.

---

## 🚀 Key Features

* **Closed-Loop Fan Modulation:** Continuously acquires ambient temperature telemetry and dynamically regulates fan speed (PWM / digital switching) to maintain target thermal thresholds.
* **Cross-Platform Firmware Layer:** Modular driver abstraction supporting a broad range of embedded targets including Arduino (Uno, Mega, Nano, Leonardo), ESP8266 (Wi-Fi), Digilent chipKIT (WF32, Max32, uC32), and PJRC Teensy.
* **Dual Interface Listeners:** Implements both hardware Serial (UART 9600–115200 baud) and TCP/IP network listener state machines for local and remote telemetry streams.
* **Standalone Deployment:** Packaged with LabVIEW VI Server configuration (`.ini`) and compiled into a standalone Windows runtime executable (`.exe`).

---

## 🛠️ Tech Stack

* **SCADA / Instrumentation:** NI LabVIEW, LabVIEW VI Server
* **Hardware Abstraction:** LabVIEW MakerHub LINX Toolkit
* **Embedded Targets:** ATmega328P, ATmega2560, ESP8266, PIC32 (chipKIT), ARM Cortex-M4 (Teensy)
* **Communication Protocols:** UART/Serial, TCP/IP
* **Firmware Language:** C / C++ (Embedded Listeners)

---

## 📁 Repository Structure

```text
LabVIEW-LINX-TempFan-Controller/
├── LabView/
│   ├── MaybeFinally TF.vi    # Core Virtual Instrument (Block Diagram & Front Panel)
│   └── TempFanEnded/         # Compiled standalone runtime binaries & configurations
├── Firmware_LINX/            # Multi-target LINX listener firmware & library sources
├── .gitignore
└── README.md

```

⚙️ How to Use
1. Hardware Firmware Flash

    Open the Arduino IDE.

    Navigate to Firmware_LINX/LINX/examples/ and open the sketch corresponding to your target board (e.g., Arduino_Uno_Serial.ino or ESP8266).

    Upload the sketch to your board.

2. LabVIEW Execution

    Open LabView/MaybeFinally TF.vi directly in NI LabVIEW (2020 or newer recommended with LINX toolkit installed).

    Select your device's COM port or TCP IP address on the front panel.

    Run the VI to monitor temperature curves and fan states in real-time.

## 👨‍💻 Author

Ali Molaei

M.Sc. in Mechatronics Engineering | Embedded Systems & Automation

    Email: molaeiali24@gmail.com

    Telegram: @AliMoj4z
