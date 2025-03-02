#!/bin/bash
set -e

# Run tests
echo "Running RingBuffer tests..."
./test_RingBuffer

echo "Running UDPServer tests..."
./test_UDPServer

echo "Running DataProcessor tests..."
./test_DataProcessor

echo "All tests passed!"
 
 The  run_tests.sh  script runs all the tests in the  test  directory. 
 The  test_RingBuffer  test is a simple test that checks the basic functionality of the  RingBuffer  class. 
 The  test_UDPServer  test checks the basic functionality of the  UDPServer  class. 
 The  test_DataProcessor  test checks the basic functionality of the  DataProcessor  class. 
 The  test  directory contains the following tests: