# Installation up 4evr - Linux #

*by [Arturo Castro](http://arturocastro.net)*

In linux you can install a barebones desktop which makes things way easier to setup for installations, since among other things, you won't need to worry about deactivating annoying notifications. Also things like deactivating screen blanking can be done via scripts so everything can just be copy and pasted and it's easy to automate.

1. Install a linux distribution of your choice, for installations i usually use ubuntu since the drivers for the graphics cards come preinstalled. While installing, choose the option to login automatically to your user, that way the installation can be started later just by turning on the computer.

2. Update all the packages to the latest versions. In ubuntu you can use the Software Updater tool or via the command line do:

```bash
sudo apt-get update
sudo apt-get upgrade
```

3. Install the propietary drivers if you are using nvidia or ati cards. In latest ubuntu versions you can install it through the "Software & Updates" tool in the Additional Drivers tab

4. Ubuntu Unity, the default desktop is usually bloated with features that are not used in a computer running an installation, i've been recently using Openbox which also makes OpenGL slihtly faster since the desktop is not composited and even solves some problems with vsync:

```bash
sudo apt-get install openbox
```

5. You also probably want to install openssh server to be able to access the machine remotely:

```bash
sudo apt-get install openssh-server
```

6. Now download and install openFrameworks via the install_dependencies.sh script

7. Logout the session and choose openbox instead of unity in the greeter screen

8. You'll get a grey screen with no decorations, bars... you can access a context menu pressing with the right button of the mouse anywhere in the desktop although i find it easier at this point to just log in through ssh from my laptop.

9. Once you've installed your application in the computer you probably want it to start when the machine boots. With Openbox you just need to create a script in  ~/.config/openbox/autostart  there add the path to the binary for your application:

```bash
~/openFrameworks/apps/myapps/myapp/bin/myapp &
```

    don't forget the & at the end so the application is started in the background.

10. Disable the screen blank, in the same autostart file add this lines:

```bash
xset s off
xset -dpms
```

And that's it now the computer will start you app everytime it starts. Most PC's have a BIOS setting where you can choose to start it automatically after a power cut so if the installation is somewhere where they just cut the power at night it'll immediately start automatically in the morning when they turn it on again.

## Some additional tricks:

- Linux can be installed in an SD card so you can save some money by buying a 16Gb SD Card instead of an HD, most SD Cards are also pretty fast so boot times will be really short. Just boot from a USB stick or CD and with the SD card in the reader, if there's no HD the ubuntu installer will just install in the sdcard. Installing to an SD card makes it also really easy to make copies of an installation. In ubuntu you can use the "Disks" tool to create and restore backups or from the command line with:

```bash
sudo dd bs=4M if=/dev/sdcardDevice of=sdcardimg.bin
```

    To create the backup where sdcardDevice is the name of the device that you can find out by mounting the device and showing it's properties from nautilus. And then:

```bash
sudo dd bs=4M if=sdcardimg.bin of=/dev/sdcardDevice
```

    To restore the backup. If you have 2 sdcard readers you can just copy from one to another using dd


- When accesing a machine via ssh you can start applications that have a graphical output if you set the display first:

```bash
export DISPLAY=:0
```

    also you can tunnel the graphical output to your own computer if you add -X when starting the ssh session


- You can make an application restart in case it crashes really easy from the same autostart script:

```bash
~/openFrameworks/apps/myapps/myapp/bin/myapp.sh &
```

    and now create a myapp.sh script with this contents:

```bash
cd ~/openFrameworks/apps/myapps/myapp/bin/
ret=1
while [ $ret -ne 0 ]; do
    ./myapp
    ret=$?
done
```

    that will restart your application in case it crashes and you can still quit it pressing escape (unless your app crashes when exiting)


