#!/bin/bash
# scripts/flash.sh

# 1. Find where OpenOCD is installed on your Fedora host
OPENOCD_BIN=$(which openocd)

if [ -z "$OPENOCD_BIN" ]; then
    echo "Error: OpenOCD not found! Install it with 'sudo dnf install openocd'"
    exit 1
fi

echo "Flashing with system OpenOCD: $OPENOCD_BIN"

# 2. Flash using the system OpenOCD, ignoring the container paths
west flash --skip-rebuild -- --openocd="$OPENOCD_BIN"