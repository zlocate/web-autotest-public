#!/bin/bash

source web-autotest-public/scripts.sh

npm install -g pnpm
pnpm i --frozen-lockfile --prefix web-autotest-public/
node web-autotest-public/proj13/prepare-test-endpoints.js
check $?