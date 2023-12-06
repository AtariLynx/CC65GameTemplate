# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.154.2/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version: bionic, focal
# [Choice] Debian version: buster, stretch
ARG VARIANT="focal"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install additional OS packages for build tooling and SSL libraries
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends build-essential libssl-dev

RUN mkdir -p /sdk
WORKDIR /sdk

RUN wget http://bjoern.spruck.net/lynx/newcc65_mod.tgz
RUN git clone https://github.com/42Bastian/lyxass.git
RUN git clone https://github.com/42Bastian/sprpck.git
RUN git clone https://github.com/42Bastian/new_bll.git
RUN git clone https://github.com/42Bastian/lynx-encryption-tools.git

# newcc65 
RUN tar -zxvf newcc65_mod.tgz
WORKDIR /sdk/newcc65
RUN make install
RUN install bin/* /usr/bin
ENV CC65INCLUDE=/sdk/newcc65/include
ENV CC65LIB=/sdk/newcc65/lib

# BLL
ENV BLL_ROOT=/sdk/new_bll/

# lyxass
WORKDIR /sdk/lyxass
RUN make
RUN install lyxass /usr/bin

# sprpck
WORKDIR /sdk/sprpck/src
RUN make
RUN install sprpck /usr/bin

# Lynx encryption tools
WORKDIR /sdk/lynx-encryption-tools
RUN make
RUN install lynxdec lynxenc lynxverify /usr/bin