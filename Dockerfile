# Dockerfile for containerized development
FROM ubuntu:20.04

# Install the necessary packages
ENV TZ=Europe/Amsterdam
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install necessary packages
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    libfmt-dev \
    curl \
    pandoc \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Change working directory
WORKDIR /advent2021/

# Copy all
COPY . .

# Compile all
RUN make build

# Entrypoint
CMD [ "make", "run"]
