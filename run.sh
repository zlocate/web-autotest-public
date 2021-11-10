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

echo http_get_test
node web-autotest-public/http_get_test.js
check

echo http_post_test
node web-autotest-public/http_post_test.js
check
