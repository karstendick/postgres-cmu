FROM ubuntu:22.04
RUN apt-get update && \
    apt-get -y install sudo && \
    apt-get -y install xxd
RUN useradd -ms /bin/bash joshua
