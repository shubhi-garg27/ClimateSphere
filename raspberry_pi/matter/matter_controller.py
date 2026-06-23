from devices import *

fan = Fan()

light = Light()

vent = Vent()


def update_devices(
        fan_speed,
        brightness,
        vent_angle):

    fan.set_speed(
        fan_speed
    )

    light.set_level(
        brightness
    )

    vent.set_angle(
        vent_angle
    )

    print(
        "Matter Update:",
        fan_speed,
        brightness,
        vent_angle
    )
