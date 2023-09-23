# gps-playground

## Requirements

### Software

- [Zephyr RTOS](https://docs.zephyrproject.org/latest/getting_started/index.html)
- [Zephyr SDK](https://docs.zephyrproject.org/latest/getting_started/index.html)
- [West](https://docs.zephyrproject.org/latest/guides/west/index.html)
- [ROS2](https://docs.ros.org/en/foxy/Installation.html)

### Additional Dependencies

- List any other additional dependencies

## Installation

### Zephyr RTOS and SDK

Follow the [official installation guide](https://docs.zephyrproject.org/latest/getting_started/index.html).

### West

```bash
pip install west
```
### Usage

```
west build -b nucleo_l496zg
west flash
```
