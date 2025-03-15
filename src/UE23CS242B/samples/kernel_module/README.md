# Kernel Module in Docker

> [!Caution]
> Ensure your **Docker container kernel** matches your **host kernel**. I've set Ubuntu for now.

## Build the Docker Image

```bash
docker build -t ubuntu-kernel-env .
```

## Run the Docker Container

```bash
docker run --rm -it --privileged ubuntu-kernel-env
```

