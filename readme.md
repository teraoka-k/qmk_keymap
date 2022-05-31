# Keymap for Planck ez

## NOTE
You need to add usergroup to flash bin as follows.

1. `sudo apt install libusb-1.0-0-dev`
2. `sudo touch /etc/udev/rules.d/50-wally.rules`
3. `sudo nvim /etc/udev/rules.d/50-wally.rules`
```
    # Teensy rules for the Ergodox EZ
ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789B]?", ENV{ID_MM_DEVICE_IGNORE}="1"
ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789A]?", ENV{MTP_NO_PROBE}="1"
SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789ABCD]?", MODE:="0666"
KERNEL=="ttyACM*", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789B]?", MODE:="0666"

# STM32 rules for the Moonlander and Planck EZ
SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="df11", \
    MODE:="0666", \
    SYMLINK+="stm32_dfu"
```
4. `sudo groupadd plugdev`
5. `sudo usermod -aG plugdev $USER`