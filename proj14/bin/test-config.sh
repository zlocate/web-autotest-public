#!/bin/bash

source web-autotest-public/scripts.sh

npm install -g pnpm
pnpm i --frozen-lockfile --prefix web-autotest-public/
node web-autotest-public/proj14/test-config.js
check $?