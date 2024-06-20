#!bin/bash

set -e

test -d cident && (echo 'you have to delete cident directory' ; exit 1)
git clone git@github.com:PalmNeko/cident.git cident
cd cident
make
