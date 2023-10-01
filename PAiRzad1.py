#!/usr/bin/env python3
from ev3dev.ev3 import *
sensor = ColorSensor()
left_motor = LargeMotor(OUTPUT_A)
right_motor = LargeMotor(OUTPUT_B)
sensor.mode = 'COL-COLOR'

while sensor.value() != 5:
    actual_color_value = sensor.value()
    if actual_color_value == 1:
        right_motor.run_direct(duty_cycle_sp = 15)
        left_motor.run_direct(duty_cycle_sp = 5)
    else:
        right_motor.run_direct(duty_cycle_sp = 5)
        left_motor.run_direct(duty_cycle_sp = 15)
        
left_motor.stop()
right_motor.stop()