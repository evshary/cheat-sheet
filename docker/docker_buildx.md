# docker buildx

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

