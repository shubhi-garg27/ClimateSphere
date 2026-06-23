
#!/bin/bash

sudo apt update

sudo apt install -y \
docker.io \
git \
curl \
avahi-daemon

git clone \
https://github.com/openthread/ot-br-posix.git

cd ot-br-posix

sudo ./script/bootstrap

INFRA_IF_NAME=wlan0 \
sudo ./script/setup
