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

npm install -g pnpm
pnpm i --frozen-lockfile --prefix web-autotest-public/
node web-autotest-public/proj15/test-config.js
check