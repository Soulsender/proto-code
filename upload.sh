#/bin/bash

pkill screen
arduino-cli compile -b arduino:avr:uno proto-code.ino
arduino-cli upload -b arduino:avr:uno -p /dev/ttyACM0 proto-code.ino