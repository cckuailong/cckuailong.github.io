#! /bin/bash
cd
apt -y install zlib1g-dev libbz2-dev libcurl4-openssl-dev

mkdir ~/bgpstream
cd ~/bgpstream
#curl -LO https://research.wand.net.nz/software/wandio/wandio-4.2.0.tar.gz
tar zxf wandio-4.2.0.tar.gz
cd wandio-4.2.0/
./configure
make
make install
ldconfig

apt -y install librdkafka-dev

cd ~/bgpstream
#curl -LO https://github.com/CAIDA/libbgpstream/releases/download/v2.0-rc2/libbgpstream-2.0.0-rc2.tar.gz
tar zxf libbgpstream-2.0.0-rc2.tar.gz
cd libbgpstream-2.0.0/
./configure --without-kafka
make
make check
make install
ldconfig

pip3 install python-dateutil

cd ~/bgpstream
#curl -LO https://github.com/CAIDA/pybgpstream/releases/download/v2.0/pybgpstream-2.0.0.tar.gz
tar zxf pybgpstream-2.0.0.tar.gz
cd pybgpstream-2.0.0
python3 setup.py build_ext
python3 setup.py install --user
