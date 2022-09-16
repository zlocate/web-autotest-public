#!/bin/bash

source web-autotest-public/scripts.sh

npm install -g newman
timeout 60 bash web-autotest-public/proj13/bin/newman.sh
check $?