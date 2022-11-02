# docker buildx

A docker CLI plugin for able to build with [BuildKit](https://github.com/moby/buildkit)

Support multiple builder instance and build for cross-platform images

## Install

Refer to [here](https://github.com/docker/buildx)

1. Download binary from [GitHub releases page](https://github.com/docker/buildx/releases/latest)
2. Rename to `docker-buildx`
3. Put the file under `$HOME/.docker/cli-plugins`
```bash
mkdir -p $HOME/.docker/cli-plugins
mv docker-buildx $HOME/.docker/cli-plugins
```
4. Give permission
```bash
chmod +x ~/.docker/cli-plugins/docker-buildx
```

## Usage

* Create new builder

```bash
docker buildx create --name mybuilder
# Set as default builder
docker buildx use mybuilder
# List the buildx builder
docker buildx ls
```

* Create Dockerfile

```bash
FROM debian:buster

ARG TARGETPLATFORM
ARG BUILDPLATFORM
RUN echo "I am running on $BUILDPLATFORM, building for $TARGETPLATFORM" > /log

CMD uname -m
```

* Build

```bash
docker buildx build -t buildxtest --platform linux/amd64,linux/arm64 .
# If you want to push to dockerhub
docker buildx build -t evshary/buildxtest --platform linux/amd64,linux/arm64 . --push
```

* Show the supported image on dockerhub

```bash
docker buildx imagetools inspect evshary/buildxtest
```

* Will use specific image based on different architecture

```bash
docker run --rm -it evshary/buildxtest bash
```

* Remove builder

```bash
docker buildx rm mybuilder
# Clear all cache
docker buildx prune
```

## bake

Able to build images concurrently. The `bake` will read HCL files to build images.

For more detail, refer to [here](https://docs.docker.com/engine/reference/commandline/buildx_bake/)

# Run cross-platform docker

* Install qemu for different platform

```bash
docker run --privileged --rm tonistiigi/binfmt --install *
# There should be qemu binary here
ls /proc/sys/fs/binfmt_misc/*
```

* You can run different platform docker image by assigning the SHA
  - The SHA can be gotten from `docker buildx imagetools inspect evshary/buildxtest`

```bash
docker run --rm -it docker.io/evshary/buildxtest:latest@sha256:803761f0046cbee916faba69dd16a054d277c7d428f2c3decca4f8ab23072832 bash
```

* If you want to remove qemu

```bash
docker run --privileged --rm tonistiigi/binfmt --uninstall "*" 
docker rmi tonistiigi/binfmt
```
