# $Id: runtest.sh,v 1.3 2021/12/15 09:44:48 venkatnarayan.h Exp $
# #
./compile_lib.sh && \
./compile_lib_test.sh && \
./test_vhutil_config_unique_keys.x

