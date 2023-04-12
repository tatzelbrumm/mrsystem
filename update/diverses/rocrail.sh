#!/bin/sh

PACKAGE=rocrail-14095-raspbian-jessie-armhf.deb
URL="https://launchpad.net/rocrail/sunrise/2.0/+download"

wget -P /tmp "$URL/$PACKAGE"
dpkg -i /tmp/$PACKAGE
rm /tmp/$PACKAGE
