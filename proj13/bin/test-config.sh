#!/bin/bash

source web-autotest-public/scripts.sh

npm i -f
npm install -g pnpm@7.30.3
pnpm i --fix-lockfile --prefix web-autotest-public/
node web-autotest-public/proj13/test-config.js
check $?