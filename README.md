# RTL8814AU drivers
# with monitor mode, frame injection and AP+Jammer


The master branch is based on https://github.com/astsam/rtl8812au  version 5.6.4.2.

Full compatible with Fluxion ( https://github.com/nicshaca/Fluxion-awus1900 ).



# Installation

```
git clone https://github.com/nicshaca/rtl8814au.git

cd rtl8814au

make RTL8814=1
make install RTL8814=1

./dkms-install.sh

```

# Remove

```
./dkms-remove.sh

```


# Credits

```
astsam - for the main work + monitor/injection support - https://github.com/astsam
nicshaca - for compatibility with AWUS1900 (Realtek rtl8814au) and AP+Jammer mode

```


