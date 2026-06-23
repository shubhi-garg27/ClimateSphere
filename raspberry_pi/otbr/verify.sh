#!/bin/bash

echo "Checking OTBR Service"

sudo systemctl status otbr-agent

echo ""
echo "Thread Network Interfaces"

ip addr | grep wpan
