#!/bin/bash

make all

./run_all_tests.sh

for test_script in bin/*.test
do
  ./$test_script
done
