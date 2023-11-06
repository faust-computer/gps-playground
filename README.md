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

**setting up zephyr env**
```
# in root directory
west update

# now you can 'west build' inside of gps_playground
cd gps_playground
west build
```

**building and running**

```
# build for nucleo_l496zg
west build -b nucleo_l496zg

# build it locally
west build -b qemu_x86 

# build and run locally
west build -b qemu_x86 --force -t run

# flash
west flash
```
