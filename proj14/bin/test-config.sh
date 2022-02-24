#!/bin/bash

function print_red(){
	echo -e "\e[31m$@\e[0m"
}

function check(){
	if [[ $? != 0 ]]
		then
		print_red "FAILED"
		exit 1
	fi
}

echo 'до 14.03 сдается по старому флоу'
exit 0

npm install -g pnpm
pnpm i --frozen-lockfile --prefix web-autotest-public/
node web-autotest-public/proj14/test-config.js
check