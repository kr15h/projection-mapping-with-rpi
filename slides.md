slidenumbers: true
autoscale: true
footer: © Krisjanis Rijnieks 2017

## Projection Mapping 
## with the 
## Raspberry Pi

---

# Introduction

Hello. How are you? 
Please introduce yourself.

- What is your name?
- What do you do?
- Why are you here?

---

# Author

Krisjanis Rijnieks.
Some facts.

- From Riga, Latvia
- MA in Arts and Design / Media Lab Helsinki
- Member of Pixelache Helsinki

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

# Workshop

---

# Day 1

- Preparing the SD card
- Exploring ofxPiMapper
- Using your own images and videos
- Introduction to command line interface
- openFrameworks basics

---

# Day 2

- Custom source development with openFrameworks
- Compiling on the Raspberry Pi
- Autostart and scripts
- Synchronizing multiple Pi's
- SD card backup

---

# Software

We are going to use open source projection mapping addon for openFrameworks. **ofxPiMapper**.

- Started as MA thesis at Media Lab Helsinki
- Integrates with openFrameworks
- Runs on Linux as well as Mac and Windows

---

# Download

Go to **ofxpimapper.com**, click on **Download latest**.
It is OK to not unzip it.

---

# Burn

Use Etcher for burning your SD card.
Download it from **etcher.io**

---

# Boot

Make sure that the **last** step is plugging in the power supply.

1. Insert SD card
2. Connect and turn on the projector
3. Connect keyboard and mouse
4. Plug in the power

---

# Shortcuts

You can find an ever updating version of keyboard shortcuts on the ofxPiMapper GitHub repository.

**https://github.com/kr15h/ofxPiMapper**

---

# Experiment

---

# Using Own Sources

Find some image and / or video sources that you want to use. 

**Images**: jpg, jpeg, png (2000 x 2000px max)
**Videos**: mp4 (H.264 encoding, 1280 x 720px)

---

# Video Encoding Tools

Use HandBrake to encode your videos. You can download it from the following website.

**handbrake.fr**

Use the **Fast 720p30** preset for encoding.

---

# Encoding with FFmpeg

In case you decide to use **FFmpeg** (cross-platform solution to record, convert and stream audio and video), here is a basic command you can use.

```
ffmpeg -i source.mov -vf scale=w=1280:h=720 destination.mp4
```

Website: **ffmpeg.org**

---

# Uploading Sources

It is easiest to put files on USB thumb drive.

1. Copy files to USB thumb drive
2. Plug the USB drive into Rasbberry Pi
3. Reboot the Raspberry Pi

Sources will be copied from USB drive to SD card.

---

# Advanced Setup

In order to get the most out of it, we have to configure Raspberry Pi network connection.

Type: **ext** to enter the command line interface (CLI) of the Raspberry Pi.

---

# Configure WiFi

Use the following command on the Raspberry Pi.

```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

---

# Editing WiFi Config

```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

Change the `ssid` and `psk`.

```
network={
        ssid="YOUR_SSID"
        psk="YOUR_PASSWORD"
}
```

---

# Finalizing WiFi Setup

Replace with your network credentials. Hit **CTRL+X** and **Y** and **ENTER** to save and exit. Use the following to reboot.

```
sudo reboot
```

---

# Getting IP Address

Use the following command to see the IP address of your Raspberry Pi.

```
hostname -I
```

You should see output similar to **192.168.0.3**. Note it down somewhere.

---

# Uploading via SFTP

Raspberry Pi uses the **S**ecure **SH**ell protocol and that works with file transfers as well. Get one of the following.

**FileZilla** (filezilla-project.org)
**WinSCP** Windows only (winscp.net)

---

# Using SCP

You can also use the command line interface to upload files. 

```
scp movie-a.mp4 movie-b.mp4 \
pi@192.168.0.3:/home/pi/openFrameworks/addons/\
ofxPiMapper/example/bin/data/sources/videos/
```

---

# Connecting to the Pi

Use the **inet addr** from before

Username: **pi**
Password: **raspberry**

Use the RasPi config tool to change the password.

```
sudo raspi-config
```

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
**Windows**: Get PuTTY (putty.org)

---

# Connecting via Terminal

Use the following command.

```
ssh pi@192.168.0.3
```

Replace the IP address with the one your Pi has. Enter password (**raspberry**) when asked to do so.

If you get a question about certificates, type **yes** and hit **ENTER**.

---

# Connecting via PuTTY

Use the following credentials to establish connection.

**Hostname**: 192.168.0.3 (replace this)
**Username**: pi
**Password**: raspberry

---

# Command Line 101

```
pwd 	    Print working directory
ls 		    List directory
ls -l 		List with options
ls -al 		List including hidden files with options
cd /my/dir  Change directory to /my/dir
cd ..       Change directory to one level up
cd          Go to home directory of user pi
```

---

# Create Text File

```
# Create empty file.txt
touch file.txt  

# To add or replace content.
echo "Add new line" >> file.txt
echo "Overwrite everything" > file.txt
```

---

# Read Text File

```
cat file.txt    Read short file
less file.txt   Read big file (hit Q to exit)
nano file.txt   Edit file with nano
```

Use **CTRL + X** to exit. Nano will ask if you sure. Hit **Y** to confirm and **ENTER** to write to the file.

---

# Troubleshooting

In case your terminal is not behaving as expected, try to use the following key combination to exit the frozen state.

**CTRL + C**

If that does not help, do a **hard reboot** by unplugging the power source.

---

# Powering up and down

Use one of the following to **reboot**.

```
sudo reboot
```

Use one of the following to **shutdown**.

```
sudo halt
```

---

# Launch on Boot with Crontab

Cron is job scheduler software available on UNIX-like systems.

Run the following command to edit `crontab`.

```
crontab -e
```

---

# Edit Crontab

Add the following to the crontab file to launch ofxPiMapper example on boot.

```
@reboot /home/pi/openFrameworks/addons/ofxPiMapper/example/bin/example
```

Press **CTRL + X** to exit. Hit **Y** to confirm changes and **ENTER** to write to file.

---

# Crontab Fields

```
Field          Allowed values
-----          --------------
minute         0-59
hour           0-23
day of month   1-31
month          1-12 
day of week    0-7 (0 or 7 is Sunday)
```

---

# Crontab Example

For example, launch a script **every day on 13:15**

```
15 13 * * * /home/pi/script.sh
```

Make sure you have set the **execute permissions** of the file, to d that use the line below.

```
chmod a+x /home/pi/script.sh
```

---

# Keep ofxPiMapper up to Date

Go to ofxPiMapper addon directory.

```
cd /home/pi/openFrameworks/addons/ofxPiMapper
```

Use the following command to pull in latest changes.

```
git pull origin master
```

---

# Recompile Example

At this point you should recompile the example.

```
cd example
make && make run
```

---

# Going Fullscreen

When compiling done, navigate to the `bin` folder and run it with the **-f** flag.

```
cd bin
./example -f
```

---

# Uploading Your App

1. Connect to Pi with **FileZilla** or **WinSCP**
2. /home/pi/openFrameworks/apps/myApps
3. Drop **yourApp** folder there

---

# Compiling Your App

1. Use **Terminal** or **PuTTY** to connect to your Pi
2. cd /home/pi/openFrameworks/apps/myApps/**yourApp**
3. type **make** and when it completes **make run**

---

# Keeping System up to Date

Use the following commands to update your Raspberry Pi.

```
sudo apt-get clean
sudo apt-get update
sudo apt-get upgrade
```

The *update* and *upgrade* commands will take a while. That's normal.

---

# Backing up on Mac

Make sure that you do not expand the filesystem of the disk image provided during the workshop.

```
diskutil list
diskutil unmountDisk /dev/diskN
sudo dd if=/dev/rdiskN of=./backup.img bs=1m count=3700
```

---

# Backing up on Windows

Use **Win32DiskImager** to back up your SD card.

1. Select SD card drive from the list
2. Click on the folder icon
3. Select where to save the **_.img** on disk
4. Click **Open**
5. Click **Read**

---

# Thank you!

If you notice that something is missing, please add an issue.

[^1]: Image source: Google Cultural Institute
