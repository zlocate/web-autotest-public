#!/bin/bash

source web-autotest-public/scripts.sh

npm i -f
npm install -g pnpm
pnpm i --frozen-lockfile --prefix web-autotest-public/
node web-autotest-public/proj13/test-config.js
check $?