# Project Name

## Overview
This project is an electronics/embedded systems project that involves firmware development, PCB design, simulation, and documentation for a device utilizing the DS3232 RTC (Real-Time Clock) and SSD1306 OLED display. The repository provides all necessary resources for development, prototyping, simulation, and deployment.

## Directory Structure
- **Code/**: Contains firmware source code developed using MPLAB IDE.
  - Written in C for a microcontroller (e.g., PIC).
  - Example files: `main.c`, `ds3232.c`, `ssd1306.c`.
- **Datasheets/**: Stores technical documentation for components.
  - Includes: `DS3232.pdf` (Real-Time Clock datasheet), `SSD1306.pdf` (OLED display datasheet).
- **Pcb/**: Contains PCB design files created with KiCAD.
  - Includes schematics and board layouts (e.g., `.sch`, `.kicad_pcb`).
- **Simulation/**: Includes simulation models for Proteus.
  - Contains Proteus project files and schematics (e.g., `.pdsprj`).

## Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/MatkoKardum/wristwatch
   ```
2. **Code**:
   - Install MPLAB X IDE and the appropriate compiler (e.g., XC8 for PIC microcontrollers).
   - Open the project in `Code/` using MPLAB X IDE.
   - Configure the microcontroller and build the firmware.
3. **PCB Design**:
   - Install KiCAD (version 6 or later recommended).
   - Open PCB files in the `Pcb/` directory using KiCAD.
   - Verify schematics and generate fabrication files as needed.
4. **Simulation**:
   - Install Proteus (version 8 or later recommended).
   - Open simulation files in the `Simulation/` directory using Proteus.
   - Run simulations to validate circuit behavior with DS3232 and SSD1306.
5. **Datasheets**:
   - Reference `DS3232.pdf` and `SSD1306.pdf` in the `Datasheets/` directory for component specifications and pin configurations.

## Requirements
- **Software**:
  - MPLAB X IDE with XC8 compiler (for C firmware development).
  - KiCAD (for PCB design).
  - Proteus (for circuit simulation).
- **Hardware**:
  - Microcontroller compatible with MPLAB (e.g., PIC series).
  - DS3232 Real-Time Clock module.
  - SSD1306 OLED display (I2C or SPI interface).
- **Dependencies**:
  - Ensure MPLAB libraries for DS3232 and SSD1306 are included in `Code/`.
  - Verify Proteus component models for DS3232 and SSD1306 are available.

## Usage
1. **Firmware Development**:
   - Modify source code in `Code/` to implement desired functionality (e.g., timekeeping with DS3232, display output on SSD1306).
   - Compile and flash the firmware using MPLAB X IDE.
2. **PCB Design**:
   - Use KiCAD to modify or finalize PCB layouts in `Pcb/`.
   - Export Gerber files for fabrication.
3. **Simulation**:
   - Run Proteus simulations in `Simulation/` to test circuit behavior before hardware implementation.
4. **Component Reference**:
   - Consult `Datasheets/DS3232.pdf` for RTC configuration (e.g., I2C communication).
   - Refer to `Datasheets/SSD1306.pdf` for OLED display setup (e.g., I2C/SPI settings).

## Contributing
- Fork the repository and create a new branch for your feature or bug fix.
- Submit pull requests with clear descriptions of changes.
- Ensure code follows MPLAB C coding standards and PCB designs are compatible with KiCAD.

## License
This project is licensed under the MIT License - see the `LICENSE` file for details.

## Contact
For questions or support, open an issue on the repository or contact matej.kardu.contact@gmail.com
