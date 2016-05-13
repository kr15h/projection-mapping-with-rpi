slidenumbers: true
autoscale: true
footer: © Krisjanis Rijnieks 2016

![](images/click-festival-pi-mapper.jpg)

# [fit] Projection Mapping
# [fit] with the Raspberry Pi

---

# [fit] Network Config

Network is important. We are going to use a wireless network that has been specifically created for the workshop. Use the data below.

SSID: *Projection Mapping*
PASS: *raspberrypi*

---

# [fit] Facts About
# [fit] Krisjanis Rijnieks

 - From Riga, Latvia
 - Studied New Media at the Helsinki Media Lab
 - Currently is a part of Fab Lab Berlin
 - Developer of ofxPiMapper, runs projection mapping workshops
 - Interested in projects connected to creative coding, digital fabrication and projection mapping

![left filtered](images/krisjanis-rijnieks-photo-by-irina-spicaka.png)

---

# [fit] More About 
# [fit] Krisjanis Rijnieks

**Website**
http://rijnieks.lv

**GitHub**
https://github.com/kr15h

**LinkedIn**
https://www.linkedin.com/in/krisjanisrijnieks

![left filtered](images/krisjanis-rijnieks-photo-by-irina-spicaka.png)

---

## What is Projection Mapping

One can turn almost any surface into a screen by using projection mapping.[^1]

![left](images/school-of-ma-01.jpg)

---

## What is Projection Mapping

Here is what you need.

 - A computer
 - A projector
 - A surface
 - Some electricity

![left](images/process-e.jpg)

---

## History

In fact, projection mapping is nothing new. Hans Holbein the Younger did it in 1533 already.[^2]

![right](images/ambassadors-a.jpg)

---

## History

He used anamorphism, perspective distortion, to paint the symbols of mortality and death into his project so it can only be seen from an angle.[^3]

![right](images/ambassadors-b.jpg)

---

## Current Status

Currently projection mapping is mostly associated with transforming the facades of historical buildings.[^4]

![left](images/facade.jpg)

---

## Current Status

Or stage design for electronic music shows like the ISAM project by Amon Tobin.[^5]

![left](images/isam.jpg)

---

## Today

We are going to have a quick walktrhough on how to set up a simple projection mapping installation by using ofxPiMapper and the Raspberry Pi mini-computer.

![right](images/make-light-camp.jpg)

---

# [fit] Schedule Overview

**Day 1**
1. Configuring the Pi
2. Projection mapping

**Day 2**
1. Questions and answers
2. Advanced topics

![right](images/make-light-camp.jpg)

---

# [fit] Installing Raspbian

1. Get a Class 10 micro SD card. 8GB is fine.
2. Download Raspbian from **raspberrypi.org/downloads**
3. Burn the Raspbian disk image onto the SD card

```
diskutil list
diskutil unmountDisk /dev/diskN
sudo dd if=/path/to/rpi/image.img of=/dev/rdiskN bs=2m
```

---

## Step 2

### Starting up the first time

1. Login using username **pi** and password **raspberry**
2. Launch config by typing ```
sudo raspi-config```
3. Expand filesystem
4. Set memory split to at least 128MB
5. Reboot

---

## Step 3

### Download and install openFrameworks

Follow the instructions on **openframeworks.cc**.

http://openframeworks.cc/setup/raspberrypi/raspberry-pi-getting-started/

---

## Step 4

### Download and install ofxPiMapper

- **Make sure that git is installed** ```
sudo apt-get install git```
- **Navigate to openFrameworks addons directory** ```
cd /home/pi/openFrameworks/addons```
- **Clone the ofxPiMapper git repository** ```
git clone https://github.com/kr15h/ofxPiMapper.git```

---

## Step 4

### Download and install ofxPiMapper

- **Clone dependencies** ```
git clone https://github.com/jvcleave/ofxOMXPlayer.git && git clone https://github.com/bakercp/ofxIO.git```
- **Go inside ofxPiMapper example directory** ```
cd /home/pi/openFrameworks/addons/ofxPiMapper/example```
- **Compile and run** ```
make && make run```

---

## Step 5

### Usage

- **Launch ofxPiMapper fullscreen by using the -f flag**```
/home/pi/openFrameworks/addons/ofxPiMapper/example/bin/example -f```

- **Use mouse, keyboard and cheatsheet to do projection mapping**

---

## What now?

Unfortunately this workshop is too short to show everything. Now you might be interested into the following topics.

- Adding your own sources
- Custom generative sources
- Launch on boot
- etc.

---

# Adding Own Sources

There are two ways to do it. 

1. Directly copying files onto the SD card.

2. Uploading via network by using a SFTP program.

---

## Copy Sources Directly

If your computer runs Linux, you can add files to the SD card directly.

1. Insert your SD card in the card reader

2. Navigate to **/home/pi/openFrameworks/addons/ofxPiMapper/example/bin/data/sources**

3. Paste your own content there. Choose the **images/** or **videos/** directory depending on the type of content you have

---

## Upload via SFTP

1. Use a SFTP client like **FileZilla**. Connect by using the IP address of the Raspberry Pi, the username **pi** and password **raspberry**. Use the port **22**.

2. Navigate to **/home/pi/openFrameworks/addons/ofxPiMapper/example/bin/data/sources**

3. Drag and drop files onto the **videos/** or **images/** directory.

---

# Networking, IP Address and SSH

One of the easiest ways for configuring the Raspberry Pi is via the SSH connection. 

SSH translates to Secure Shell and it allows one to control a computer remotely via the command line interface (Terminal).

```
ssh pi@192.168.2.3
```

---

## Wired Network Connection

Ethernet cable is required for this, one end of it has to be connected to the Raspberry Pi, the other one to the ethernet port of a computer.

Internet sharing has to be activated on the computer in order the Raspberry Pi to get an IP address automatically.

It is also possible to connect the other end of the cable to an ethernet switch.

---

## Discovering the IP Address of the Pi

In order to connect to the Raspberry Pi via SSH, we need to know its IP address.

We are going to use **nmap** on Mac and a network scanner application on Windows.

Run the following command to see what IP address has been assigned to the Raspberry Pi.

```
nmap -v -sn 192.168.2.1/24
```

---

## SSH

To SSH into the Raspberry Pi, use the **Terminal** application on Mac and Linux or **MobaxTerm** on Windows.

Use the previously found IP address and enter password **raspberry** when prompted.

```
ssh pi@192.168.2.50
```

---

# Launching on Boot

There are two ways to do it.

1. via **.bashrc** (or **.zshrc** if you use zsh)

2. via **/etc/rc.local**

For both create a **startup.sh** file.

---

## Contents of **startup.sh** File

```
#!/bin/bash
if [ -z "$SSH_CONNECTION" ]; then
    /home/pi/openFrameworks/addons/ofxPiMapper/example/bin/example -f
fi
```

The script makes sure that your scripts are not executed again when you log in via SSH. Make sure the system is allwed to execute it by running the following command.

```
chmod a+x startup.sh
```

---

## Starting up via **.bashrc**

1. Open **.bashrc** in a text editor

2. Add path to **startup.sh** at the end of the file```
/home/pi/startup.sh```

3. Make sure that the **Console Autologin** option is set in the **raspi-config** **Boot Options**.

4. Reboot the pi to test if it works

---

## Starting up via **rc.local**

For this approach you do not need to set the **Console Autologin** option.

1. Open **/etc/rc.local** in a text editor

2. Add the following before the **exit 0** line```
su - pi -c /home/pi/startup.sh &```

This will launch the **startup.sh** script in behalf of the user **pi** before it has logged in.



[^1]: Image from projection mapping workshop by Krisjanis Rijnieks and Irina Spicaka during the School of Machines in Berlin, 2014

[^2]: Image source: Google Cultural Institute

[^3]: Image source: Google Cultural Institute

[^4]: 3D Projection Mapping performance during Fête des Lumières, Lyon, France (2010) Artists: 1024 architecture (Photos: Daniela Krautsack)

[^5]: Image source denverlibrary.org