#!/bin/sh
PROGRAM=${PWD##*/}
PYTHONPATH=. ./$PROGRAM
rm *.pyc
