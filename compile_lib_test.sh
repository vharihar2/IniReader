#$Id: compile_lib_test.sh,v 1.1 2021/12/15 09:34:30 venkatnarayan.h Exp venkatnarayan.h $
#
gcc -Wall test_vhutil_config_unique_keys.cpp vhutil_config_unique_keys.o \
  -o test_vhutil_config_unique_keys.x -std=c++11 -lm -lstdc++
