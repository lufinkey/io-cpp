#!/bin/bash

# enter base directory
base_dir=$(dirname "${BASH_SOURCE[0]}")
cd "$base_dir/../"
base_dir="$PWD"

# create external folder
mkdir -p "external"

# determine which libraries should be downloaded
filesystem=false
if [ $# -eq 0 ]; then
	filesystem=true
else
	for arg; do
		if [ "$arg" == "filesystem" ]; then
			filesystem=true
		else
			>&2 echo "unknown dependency $arg"
		fi
	done
fi

# clone filesystem
if $filesystem; then
	if [ ! -e "external/filesystem/.git" ]; then
		echo "fetching filesystem stub"
		git clone --recursive "git@github.com:gulrak/filesystem.git" "external/filesystem" || exit $?
	fi
fi
