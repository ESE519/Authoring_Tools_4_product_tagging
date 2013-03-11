###############################################################################
#    Shell script to install OpenCV 2.3.1 on Ubuntu 11.10.
#    Correct usage:
#    1. Open terminal in Ubuntu.
#    2. Navigate to the folder in which this script is located.
#    3. Type "sudo sh install-opencv2.3.1.sh"
#    Installation will complete and then show you examples to check if
#    it has been installed correctely.
#
#    Author: Rahul Ashok
#    Georgia Institute of Technology
#    rahul.ashok@cc.gatech.edu
#    Copyright (C) 2012  Rahul Ashok
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
###############################################################################

if [ `id | cut -d= -f3 | cut -d\( -f1` = 0 ]	
 then	
        echo	
        echo " Installing OpenCV 2.3.1a"
        echo
 else	
        korisnik=`id | cut -d= -f2 | cut -d\( -f2 |cut -d\) -f1`	
        echo	
        echo  "Permission denied. You need to be root to run this script..."	
        echo	
        exit 0
fi	
cd
sudo mkdir OpenCV2.3.1_install
cd OpenCV2.3.1_install
sudo apt-get remove ffmpeg x264 libx264-dev
sudo apt-get update
sudo apt-get install build-essential checkinstall git cmake libfaac-dev libjack-jackd2-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libsdl1.2-dev libtheora-dev libva-dev libvdpau-dev libvorbis-dev libx11-dev libxfixes-dev libxvidcore-dev texi2html yasm zlib1g-dev
sudo apt-get install libgstreamer0.10-0 libgstreamer0.10-dev gstreamer0.10-tools gstreamer0.10-plugins-base libgstreamer-plugins-base0.10-dev gstreamer0.10-plugins-good gstreamer0.10-plugins-ugly gstreamer0.10-plugins-bad gstreamer0.10-ffmpeg

sudo wget http://download.videolan.org/pub/videolan/x264/snapshots/x264-snapshot-20120217-2245-stable.tar.bz2
sudo tar xvjf x264-snapshot-20120217-2245-stable.tar.bz2
cd x264-snapshot-20120217-2245-stable
sudo ./configure --enable-static
sudo make
sudo make install

cd ..

sudo wget http://ffmpeg.org/releases/ffmpeg-0.9.1.tar.bz2
sudo tar xvjf ffmpeg-0.9.1.tar.bz2
cd ffmpeg-0.9.1
sudo ./configure --enable-gpl --enable-libfaac --enable-libmp3lame --enable-libopencore-amrnb --enable-libopencore-amrwb --enable-libtheora --enable-libvorbis --enable-libx264 --enable-libxvid --enable-nonfree --enable-postproc --enable-version3 --enable-x11grab
sudo make
sudo make install

sudo apt-get install libgtk2.0-0 libgtk2.0-dev
sudo apt-get install libjpeg62 libjpeg62-dev

cd ..

sudo wget http://www.linuxtv.org/downloads/v4l-utils/v4l-utils-0.8.6.tar.bz2
sudo tar xvjf v4l-utils-0.8.6.tar.bz2
cd v4l-utils-0.8.6
sudo make
sudo make install

cd ..

sudo wget http://downloads.sourceforge.net/project/opencvlibrary/opencv-unix/2.3.1/OpenCV-2.3.1a.tar.bz2
sudo tar xvf OpenCV-2.3.1a.tar.bz2
cd OpenCV-2.3.1
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo make install

sudo apt-get install gtk2-engines-pixbuf

sudo echo "export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH" >> ~/.bashrc
sudo echo "export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH" >> ~/.bashrc


echo "Installation complete..."
echo -n "Would you like to run an example and test OpenCV?[Yes/no]"

read answer
if [ "$answer" != "Yes" ]
then
	echo "Done..."
exit
fi

echo "Compiling and running helloworld_OpenCV"

cd ~/OpenCV2.3.1_install

sudo rm -rf helloworld_opencv.cpp
sudo echo "#include <cv.h>
#include <highgui.h>
using namespace cv;
int main()
{
  Mat a=imread(\"./OpenCV-2.3.1/samples/c/lena.jpg\",1);
  namedWindow(\"lena - press any key to break\");
  imshow(\"lena - press any key to break\",a);
  waitKey();
}" >> helloworld_opencv.cpp

sudo g++ -o helloworld_opencv helloworld_opencv.cpp `pkg-config opencv --cflags --libs` 
sudo ./helloworld_opencv
sudo chmod 777 -Rf ~/OpenCV2.3.1_install/


echo -n "Would you like to run another example?[Yes/no]"

read answer
if [ "$answer" != "Yes" ]
then
	echo "Done..."
exit
fi
cd ~/OpenCV2.3.1_install/OpenCV-2.3.1/samples/c/
sh build_all.sh
./delaunay

cd
echo "Done..."
exit
