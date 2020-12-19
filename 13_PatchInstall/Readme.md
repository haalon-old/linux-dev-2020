# I18nL10n

Do an out-of-source build with following commands:
```shell
mkdir build
cd build
cmake [-DCMAKE_INSTALL_PREFIX=<Installation Prefix>] ..
make all
```

Install with 
```shell
make install [DESTDIR=<DestinationDir>]
```

To clean up - just remove the *build* directory
