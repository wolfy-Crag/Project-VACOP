import os
import can

os.system('sudo ip link set can0 type can bitrate 50000')
os.system('sudo ifconfig can0 up')

can0 = can.interface.Bus(channel = 'can0', bustype = 'socketcan')# socketcan_native

msg = can.Message(arbitration_id=0x123, data=['a','a','a','a','a','a','a','a'], is_extended_id=False)
can0.send(msg)

os.system('sudo ifconfig can0 down')
