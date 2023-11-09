#!/bin/bash

source web-autotest-public/scripts.sh

npm install -g pnpm@7.30.3
echo "Понижаем версию mongoose"
npm explain mongoose|| true
npm i mongoose@6 || true
npm explain mongoose|| true
echo "Закончили понижение версии mongoose"
pnpm i --fix-lockfile --prefix web-autotest-public/
node web-autotest-public/proj13/prepare-test-endpoints.js
check $?
