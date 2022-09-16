#!/bin/bash

source web-autotest-public/scripts.sh

npm install -g newman
timeout 60 bash web-autotest-public/proj15/bin/newman.sh
endpoints_exit_code=$?
node web-autotest-public/proj15/test-server.js
server_exit_code=$?
check $endpoints_exit_code
check $server_exit_code