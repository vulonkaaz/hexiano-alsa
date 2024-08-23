# Hexiano to ALSA

This very simple C program makes a virtual ALSA midi device from the
Hexiano android app

## How it works

It listens for Hexiano logs on the android debug bridge, before using
this program you'll have to set up the android debug bridge, once
done you should be able to run `adb logcat` and see everything that's
happening on your mobile device including the Hexiano events, this
software basically launches the same command to see what's going on,
if your command to access the logs is something else than 
`adb logcat` on your system please change the source code accordingly

## How to compile

`cc -o hexmidi main.c -lasound`

Replace hexmidi with whatever executable name you'd like

Get Hexiano here 
https://f-droid.org/en/packages/org.gitorious.jamesjrh.isokeys/

(you will require an older android device to run the App)
