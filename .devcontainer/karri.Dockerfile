# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.154.2/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version: bionic, focal
# [Choice] Debian version: buster, stretch
ARG VARIANT="stretch"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install additional OS packages for build tooling and SSL libraries
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends build-essential libssl-dev

RUN mkdir -p /sdk
WORKDIR /sdk
RUN git clone https://bitbucket.org/atarilynx/lynx.git

WORKDIR /sdk/lynx/tools
RUN make -f Makefile.deb
WORKDIR /sdk/lynx/tools/cc65
RUN make -f make/gcc.mak install