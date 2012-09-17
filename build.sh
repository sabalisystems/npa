#!/bin/sh

# --
# Copyright (c) 2012 by itopia.pl team.
# 
# build.sh - builder script (for developers)
# Author: Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
# --

parallel=2

printf "Cleaning ... "
make -j${parallel} clean 
make -j${parallel} distclean 
printf "done.\n"

printf "Configuring... "
autoreconf -i --force
./configure
printf "done.\n"

printf "Compiling ... "
make -j${parallel}
printf "done.\n"
