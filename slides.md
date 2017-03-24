slidenumbers: true
autoscale: true
footer: © Krisjanis Rijnieks 2017

![](images/click-festival-pi-mapper.jpg)

# [fit] Mapping with the Pi
## [fit] Projection Mapping with the Raspberry Pi

---

# Introduction

Hello. How are you? Please introduce yourself.

- What is your name?
- What do you do?
- Why are you here?

---

# Krisjanis Rijnieks

- From Riga, Latvia
- MA in Arts and Design / Media Lab Helsinki
- Member of Pixelache Helsinki
- Developer of ofxPiMapper

---

# Projects

Projects range in complexity and usually include a combination of the following.

- Creative coding
- Projection mapping
- Digital fabrication

---

The Thirsty Trees, February 2017

![fit loop autoplay](videos/trees.mp4)

---

The Portal Project, December 2016

![fit loop autoplay](videos/portal.mp4)

---

Maker in Residence, December 2016

![fit loop autoplay](videos/mir.mp4)

---

Staro Riga Festival, November 2016

![fit loop autoplay](videos/staro.mp4)

---

SUDO, Summer 2016

![fit loop autoplay](videos/sudo.mp4)

---

Latvian National Museum of Art, May 2016

![fit loop autoplay](videos/lnmm.mp4)

---

# Day 1

- Burning SD card
- Projection mapping
- Using own images and videos
- A bit of command line
- Pinch of openFrameworks

---

# Day 2

- openFrameworks recap
- Custom source development
- Setting up your project
- Synchronizing and projector blending
- Backing up SD card

---

# ofxPiMapper

We are going to use open source projection mapping addon for openFrameworks.

- Started as my MA thesis at Media Lab Helsinki
- Integrates with openFrameworks
- Runs also on Mac, Linux and Windows
- Available on GitHub

---

# Download

Go to the following web address.

**ofxpimapper.com**

Click on **Download latest**.

---

# Burning SD Card

Please follow the link to access the instructions page.

**http://ej.uz/sd-card-burning-guides**

---

# Shortcuts

You can find an ever updating version of keyboard shortcuts on the ofxPiMapper GitHub repository.

**https://github.com/kr15h/ofxPiMapper**

Make sure you have selected the **stable** branch.

---

# Experiment

---

# Own Sources

Find some image and / or video sources that you want to use. 

**Images**: jpg, jpeg, png (2000 x 2000px max)
**Videos**: mp4 (H.264 encoding, 1280 x 720px)

---

# Video Encoding Tools

Use HandBrake to encode your videos. You can download it from the following website.

**handbrake.fr**

Use the **Fast 720p30** preset for encoding.
Use the **Fast 1080p30** if using single video.

---

# Encoding with FFmpeg

In case you decide to use **FFmpeg** (cross-platform solution to record, convert and stream audio and video), here is a basic command you can use.

```
ffmpeg -i source.mov -vf scale=w=1280:h=720 destination.mp4
```

Website: **ffmpeg.org**

---

# Configure WiFi

Use the following command on the Raspberry Pi.

```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

Replace with your network credentials. Hit CTRL+X and Y and ENTER to save and exit. Use the following to reboot.

```
sudo reboot
```

---

# Getting IP Address

Use the following command to see the IP address of the Raspberry Pi wireless network adapter.

```
ifconfig
```

Look for **wlan0** and **inet addr**. It should look like **192.168.0.3** Note it down somewhere.

---

# Getting a SFTP Client

Raspberry Pi uses the **S**ecure **SH**ell protocol and that works with file transfers as well. Get one of the following.

- FileZilla
- WinSCP (Windows only)

---

# Connecting to the Pi

Use the **inet addr** from before

Username: **pi**
Password: **raspberry**

---

# Uploading

```
/home/pi
/openFrameworks/addons
/ofxPiMapper/example/bin/data/sources
```

Put images and videos in the respective folders. Reboot.

```
sudo reboot
```

---

# Secure SHell

SSH is a secure network protocol for controlling another computer through a network.

**Mac and Linux**: use Terminal
**Windows**: Get PuTTY

**chiark.greenend.org.uk/~sgtatham/putty**

---

# Connecting via Terminal

Use the following command.

```
ssh pi@192.168.0.3
```

Replace the IP address with the one your Pi has. Enter password (**raspberry**) when asked to do so.

---

# Connecting via PuTTY

Use the following credentials to establish connection.

**Hostname**: 192.168.0.3 (replace this)
**Username**: pi
**Password**: raspberry

---

# Killing the Example App

In order to stop the running ofxPiMapper example application, run this command.

```
sudo killall example
```

---

# [fit] Command Line 101

```
pwd             Print working directory
cd /my/dir      Change directory to /my/dir
cd ..           Change directory one level up
ls              List directory
ls -al          List directory with hidden files as a list
mkdir /my/dir   Make directory /my/dir
touch file.txt  Create empty file.txt
cat file.txt    Show file contents (best for small files)
less file.txt   Show file contents (good for longer text)   
```

```
echo "New line" >> file.txt
echo "Overwrite" > file.txt
```

---

# [fit] External Command Line Resources

There are a lot of useful guides out there on the Internet. Check out the following links.

- http://kr15h.github.io/rpi-console-intro/index.html
- http://linuxcommand.org/lc3\_learning\_the\_shell.php
- https://www.git-tower.com/learn/git/ebook/en/command-line/appendix/command-line-101

---

# [fit] Editing Text Files With Nano

The simplest command line text editor is `nano`. To open a file in nano, use the following command.

```
nano /path/to/your/file.txt
```

You can not use mouse in *nano*, navigation is possible with the arrow keys *(← ↑ → ↓)* on your keyboard. To close the file, press *ctrl + x*. Nano will prompt you whether you want to save changes. Press *y* if you do, you will have to press *enter* additionally to confirm the file name.

---

# [fit] Keeping System up to Date

Once in a while it is a good idea to update the system. To do that use the following commands.

```
sudo apt-get clean
sudo apt-get update
sudo apt-get upgrade
```

The *update* and *upgrade* commands will take a while. That's normal.

---

# [fit] Powering up and down

After an update or changes in configuration, one might want to reboot the system. Use the following command to do so.

```
sudo reboot
sudo shutdown -r now
```

When changes have to be made to the SD card or the Raspberry Pi has to be shut down for another reason, use the command below.

```
sudo halt
sudo shutdown -h now
```

---

# [fit] Launching on Boot
## Introducing Crontab

Use *Cron*. Cron is job scheduler software available on Unix-like systems like Linux. We are using Raspbian which is a Linux distribution for Raspberry Pi computers.

Run the following command to edit `crontab`.

```
crontab -e
```

---

# [fit] Launching on Boot
## Editing Crontab

You have to add the following line in order to launch ofxPiMapper on next boot.

```
@reboot /home/pi/openFrameworks/addons/ofxPiMapper/example/bin/example
```

If you want to reboot once a day at midnight, add the following (the first five symbols denote: *minute*, *hour*, *day of month*, *month*, *day of week*; *\** means all)

```
0 0 * * * reboot
```

---

# [fit] Keeping ofxPiMapper up to date

```
cd /home/pi/openFrameworks/addons/ofxPiMapper/example
git pull origin master
make
```

---

# Uploading Basic Examples

1. Connect to Pi with **FileZilla** or **WinSCP**
2. /home/pi/openFrameworks/apps/myApps
3. Drop **yourApp** folder there

---

# Compiling Basic Examples

1. Use **Terminal** or **PuTTY** to connect to your Pi
2. cd /home/pi/openFrameworks/apps/myApps/**yourApp**
3. type **make** and when it completes **make run**

---

# Backing up on Mac

Make sure that you do not expand the filesystem of the disk image provided during the workshop.

```
diskutil list
diskutil unmountDisk /dev/diskN
sudo dd if=/dev/rdiskN of=./backup.img bs=1m count=3700
```

---

# Backink up on Windows

Use **Win32DiskImager** to back up your SD card.

1. Select SD card drive from the list
2. Click on the folder icon
3. Select where to save the **_.img** on disk
4. Click **Open**
5. Click **Read**

---

# Changing WiFi Network

```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

Change the `ssid` and `psk`.

```
network={
        ssid="Your SSID"
        psk="Your password"
}
```

---

# [fit] Installing openFrameworks

Once you have the OS (like Raspbian) installed on your SD card, the next step is to install *openFrameworks*. To do that, follow the guide available on the official openFrameworks website.

```
http://openframeworks.cc/setup/raspberrypi/raspberry-pi-getting-started/
```

---

# [fit] Installing ofxPiMapper

Use the following.

```
cd /home/pi/openFrameworks/addons
git clone https://github.com/kr15h/ofxPiMapper.git
git clone https://github.com/jvcleave/ofxOMXPlayer.git
git clone https://github.com/bakercp/ofxIO.git
cd /home/pi/openFrameworks/addons/ofxPiMapper/example
make
```

---

# Thank you!

If you notice that something is missing, please add an issue.

[^1]: Image source: Google Cultural Institute
