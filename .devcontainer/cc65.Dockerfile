# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.154.0/containers/alpine/.devcontainer/base.Dockerfile

# [Choice] Alpine version: 3.12, 3.11, 3.10, ..., 3.18
ARG VARIANT="3.18"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-alpine-${VARIANT}

RUN apk update && \
    apk add --no-cache --virtual .build-deps git build-base
    
RUN mkdir -p /sdk
WORKDIR /sdk
RUN git clone https://github.com/cc65/cc65.git
RUN git clone https://github.com/42Bastian/sprpck.git

WORKDIR /sdk/cc65
RUN nice make -j2
RUN make install PREFIX=/usr

ENV CC65_HOME=/usr/share/cc65/
ENV CC65_INC=/usr/share/cc65/include
ENV CA65_INC=/usr/share/cc65/asminc
ENV LD65_CFG=/usr/share/cc65/cfg
ENV LD65_LIB=/usr/share/cc65/lib
ENV LD65_OBJ=/usr/share/cc65/obj

WORKDIR /sdk/sprpck/src
RUN make \
    && install sprpck /usr/bin
WORKDIR /sdk