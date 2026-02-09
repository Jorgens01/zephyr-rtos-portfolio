#!/bin/bash

# 1. Get the absolute path of the script's directory (scripts/)
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

# 2. Get the project root (zephyr-portfolio/) by going up one level
PROJECT_ROOT=$(dirname "$SCRIPT_DIR")

# Detect Container Engine
if command -v podman &> /dev/null; then
    ENGINE="podman"
    ARGS="--userns=keep-id --security-opt label=disable"
    echo "Using Podman..."
else
    ENGINE="docker"
    ARGS="--user $(id -u):$(id -g)"
    echo "Using Docker..."
fi

IMAGE_NAME="zephyr-portfolio-env"

# Build the image if it doesn't exist
if ! $ENGINE image inspect $IMAGE_NAME > /dev/null 2>&1; then
    echo "Building container image..."
    BUILDAH_FORMAT=docker $ENGINE build -t $IMAGE_NAME -f "$PROJECT_ROOT/docker/Dockerfile" "$PROJECT_ROOT"
fi

# Run the container
echo "Mounting $PROJECT_ROOT to /workdir"
$ENGINE run -it --rm \
    $ARGS \
    --entrypoint /bin/bash \
    -v "$PROJECT_ROOT:/workdir" \
    $IMAGE_NAME