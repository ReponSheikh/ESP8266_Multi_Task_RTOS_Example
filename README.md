ESP8266 RTOS Multi-Task Demo
This is a simple PlatformIO project demonstrating the use of the FreeRTOS SDK on an ESP8266 microcontroller. The application showcases a basic multi-tasking environment by running two separate tasks concurrently.

✨ Features
LED Blinking Task: A dedicated task that toggles the built-in LED on the ESP8266 every 500 milliseconds.

Serial Printing Task: A separate task that prints a "Hello" message to the serial monitor every 1000 milliseconds.

PlatformIO Integration: The project is configured for easy building and uploading using the PlatformIO ecosystem, simplifying the toolchain setup.

🚀 Getting Started
Prerequisites
PlatformIO Core or PlatformIO IDE for VS Code installed.

An ESP8266 development board (e.g., ESP-12E, NodeMCU).

Installation
Clone the repository:

git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name

Open the project in your IDE:
Open the project folder in VS Code with the PlatformIO extension installed. PlatformIO will automatically detect the project and install the necessary platforms and libraries.

Build and Upload:

Connect your ESP8266 board to your computer.

In the PlatformIO toolbar, click the Build (checkmark icon) and then the Upload (right-arrow icon) buttons.

Alternatively, you can use the PlatformIO CLI:

pio run --target upload

Monitor Serial Output:

To see the messages from the serial printing task, open the PlatformIO Serial Monitor by clicking the Monitor (plug icon) button.

You can also use the CLI:

pio device monitor

🛠️ Project Structure
src/main.c: Contains the main application code with the two FreeRTOS tasks and the user_init entry point.

platformio.ini: The configuration file for PlatformIO, specifying the board, framework, and build options.
