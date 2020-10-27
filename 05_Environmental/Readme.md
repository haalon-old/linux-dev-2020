# Enviromental

Do an out-of-source build with following commands:
```shell
mkdir build
cd build
cmake ..
make all
```

To disable PCRE2_UCP, use `cmake -DUSE_UTF=ON ..` instead

To clean up - just remove the *build* directory


