# kde-xopp-thumbnailer
KF5 Thumbnailer for Xournal++ journal files

## Requirements

General QT5 stuff. I will skip those as probably KDE users have them alreaady installed.

## Building
```
mkdir build
cd build
cmake -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DCMAKE_INSTALL_PREFIX=`kf5-config --prefix` ..
make
sudo make install
```
