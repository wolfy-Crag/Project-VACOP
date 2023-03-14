#!/bin/bash

# Vérifier si un argument est fourni
if [[ $# -ne 1 ]]; then
  echo "Usage: $0 bitrate"
  exit 1
fi

# Récupérer la valeur de bitrate fournie en tant qu'argument
bitrate=$1

sudo modprobe can
sudo modprobe can_raw

# CAN0
sudo ip link set can0 down
sudo ip link set can0 up type can bitrate $bitrate
sudo ip link set up can0

# CAN1
sudo ip link set can1 down
sudo ip link set can1 up type can bitrate $bitrate
sudo ip link set up can1
