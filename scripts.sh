#!/bin/bash

function print_red(){
	echo -e "\e[31m$@\e[0m"
}

function check(){
	if [[ $1 != 0 ]]
		then
		print_red "FAILED"
		exit 1
	fi
}