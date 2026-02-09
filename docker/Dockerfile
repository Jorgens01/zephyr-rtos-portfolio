# docker/Dockerfile
FROM ghcr.io/zephyrproject-rtos/zephyr-build:v0.26.13

# Set the working directory inside the container
WORKDIR /workdir

# Ensure git is configured safe for the workspace
RUN git config --global --add safe.directory /workdir