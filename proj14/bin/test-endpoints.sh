#!/bin/bash

source web-autotest-public/scripts.sh

install_newman
timeout 60 bash web-autotest-public/proj14/bin/newman.sh
check $?