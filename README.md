# HC-SR04 Ultrasonic Sensor API README

## Overview

This repository hosts a comprehensive API for interfacing with the HC-SR04 ultrasonic sensor, suitable for use with any microcontroller (uC) equipped with PWM capabilities. The API facilitates the initialization of the HC-SR04 sensor and provides robust functionality for accurately measuring distances. It's designed for high precision and efficiency in a variety of applications.

## Key Features

- **Sensor Initialization:** Initialize the HC-SR04 sensor with customizable hardware settings.
- **Distance Measurement:** Accurately measure distances using ultrasonic waves.
- **State Management:** Handle various states of the sensor including waiting for echo, measuring, and completing measurement.
- **Error Handling:** Error handling for improved reliability.

## Core Files

- `hc_sr04.h`: Main API declarations.
- `hc_sr04.c`: Implementation of the API.
- `hc_sr04_types.h`: Defines types and enums used in the API.
- `hc_sr04_hardware.h`: Hardware interface abstraction.
- `hc_sr04_tests.c`: Unit tests for the API.

## Testing

- The API includes comprehensive unit tests using the Google Test framework.
- Tests cover various scenarios including error conditions, state transitions, and distance measurements.

## Dependencies

- Standard C libraries for general functionality.
- Google Test framework for unit testing.

## Contribution

Contributions are welcome. Please follow the standard pull request process for contributions.

## License

This project is licensed under the MIT License.

## Author

cF-embedded.pl
