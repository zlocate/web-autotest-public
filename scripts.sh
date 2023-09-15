#!/bin/bash
export NEWMAN_VERSION=5.3.2
install_newman() {
  npm install -g "newman@$NEWMAN_VERSION" --ignore-engines
}

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