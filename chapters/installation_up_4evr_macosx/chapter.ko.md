#Installation up 4evr#

*[Blair Neal](http://blairneal.com/) 에 의해 작성*

At work I recently had to set up a four installations of different configurations that would need to run all day, every day, 24 hours a day for a couple months with as few crashes or glitches as possible and without anyone going to check on them. This is something that a lot of media artists need to do all the time, and there are a bunch of different tricks and tips to keeping things up for an extended period, I figured I'd share my findings. There are alternate ways to do many of these tasks and this is only one road so please share some tips you've picked up out in the field down in the comments box below.

I had to do several searches in a couple different places to find all the information I needed to keep everything consistently up and bug free. Luckily most of the installations I was dealing with this time were fairly light in terms of resources and complications, but it's always best practices to have a safety net.

I usually run these off brand new, unboxed computers so this is sort of starting from scratch. Most of the things I point out are set to the opposite by default.

Tip: if you're doing multiple computers, do these prep steps on one of them and just boot the others into target disk mode and use something like [Carbon Copy Cloner](http://www.bombich.com/) to mirror the first one on the next so everything is as consistent as possible.

##Step 1: Prep your software and the computer
##단계 1: 여러분의 소프트웨어와 컴퓨터를 준비합니다.

여러분의 소프트웨어를 빌드, 혹은 앞으로 소행될 어떤 것이든, 오랫동안 동작할 설치임을 명심하시기 바랍니다. 설치의 시작부터 누가 되었든 간에 어떤 사람에 의해 조정될 필요가 있는 것이 어떤 것들인지를 기획하시기 바랍니다. 제 경험에 비추어 보면, 그것들은 가능한한 간단해야 합니다, 따라서 관리자가 고치기 쉬워야 하지, Xcode를 열어서 컴파일하거나 앱을 벗어나지 않도록 해야 합니다.  지금 여러분이 이런것들을 간단하게 만드는데 드는  시간이 나중에 뭔가 문제가 생겼을때 원격 디버깅을 하는 시간을 절약할 수 있을것입니다.

여러분의 어플리케이션이 항상 최상위에 있도록 하기 위해 아래의 사항들을 훑어가며 몇몇 자동화된 세팅을 끄거나 해제해야 합니다. 내용들은 10.7, 10.8, 10.9, 10.10 등등 여러분이 구동하는 환경에 따라 다소 차이가 있을 수 있습니다.

Nick Hardeman has made a utility application for setting all of these attributes and more from one location - [check it out here](http://nickhardeman.com/610/openframeworks-configuring-osx-for-a-long-term-installation/)

Nick Hardman은 이러한 각종 요소들을 한곳에서 세팅할 수 있는 유틸리티 프로그램을 만들었습니다 - [이곳을 확인하세요](http://nickhardeman.com/610/openframeworks-configuring-osx-for-a-long-term-installation/)

시스템 환경설정에서:
- **데스크톱 및 화변보호기:** 화면보호기를 해제하세요. 시간설정을 "절대안함"으로 세팅하시기 바랍니다. 저는 또한 배경화면을 블랙/ 혹은 여러분의 어플리케이션 스크린/클라언트의 로고 로 바꾸는것을 추천드립니다 - 심지어 이런것들을 자동으로 변경하게 할 수 있습니다. - 명심하세요 - **이 설정들은 누군가 알아차리기 전에는 망가진것이 아니랍니다 :)**

- **Desktop and Screensaver:** Disable your screensaver. Set it's time to "Never." I also suggest changing your desktop background to either black/a screenshot of your app/you client's logo - you can even set these to change automatically - remember - **it's not broken until someone notices** :)
 - **에너지 절약:** 디스플레이 잠자기와 컴퓨터 잠자기를 절대안함으로 설정하세요. "전원 실패 이후 자동으로 시작하기"를 활성화하고, "컴퓨터가 멈췄을 경우 자동으로 시작하기"를 활성화하세요. (이 설정들은 10.7 또는 이후 버전부터 가능합니다)
 - **사용자 및 그룹:** 로그인 옵션으로 가서 "자동 로그인"을 활성화하세요
 - **소프트웨어 업데이트:** 자동 업데이틀 끄세요
 - **공유:** 만약 구동되는 컴퓨터가 모니터가 없거나 혹은 접근할 수 없는 곳에 있다면, 파일공유와 화면공유를 켜는것을 잊지 마십시오. 이렇게 하면 같은 네트워크에 있을 때(이는 옵션으로, 여러분이 보안을 염려한다면 드리는 말씀입니다) 컴퓨터의 접근과 제어가 가능합니다.
 - **네트워크:** 만일 원격제어가 필요없거나 혹은 설치에 있어서 인터넷 연결이 필요가 없다면, wifi를 끄는것은 나쁘지 않은 생각입니다. 적어도 "무선 네트워크를 선택하세요"라는 팝업이 뜰 일은 없을것입니다. 또한 새로운 네트워크에 연결시에 물어보기 옵션을 끌 수도 있습니다.
 - **블루투스:** 만약 마우스 혹은 키보드를 연결하지 않고 구동할 경우, 가끔 여러분의 어플리케이션에서 "블루투스 키보드/마우스 셋업" 팝업이 떠서 귀찮을 수 있습니다. 블루투스 환경설정에서 고급설정에 들어가 이를 임시로 끌 수 있습니다. 10.6은 아래를 살펴보세요. 
 - **보안:** "자동 로그인 끄기"가 체크해제 되었는지 꼭 확인하시기 바랍니다. 여러분이 정말 편집자적인 성격이라면, 구형 맥이나 맥북에 존재하는 IR 리모콘 리시버를 해제할 수 있습니다. 가끔 짖궃은 사람들이 Apple TV 리모콘을 이용해 장난하는 것을 방지할 수 있습니다. 이것을 해제하려면, 보안->일반->고급(10.8 이상)으로 간 다음 "IR리시버 제어 해제"를 체크하시기 바랍니다.
 - **알림 센터:** 
 - **Notification Center:** You can either [disable Notification Center completely](http://www.tekrevue.com/tip/how-to-completely-disable-notification-center-in-mac-os-x/), or set your "Do Not Disturb" to basically on be on forever by setting it with overlapping times like the screenshot below

![BluetoothSettings](images/Bluetooth_settings.png)

![SecuritySettings](images/Security_settings.png)

![SharingSettings](images/Sharing_settings.png)

![Login_items](images/Auto_login.png)

![Power_settings](images/PowerSettings.png)

![Update_disable](images/Auto_update_disable.png)

![Notification_Center](images/Notification_Center_disable.png)

You can also disable the "This Application Unexpectedly Quit" and the subsequent bug report that comes with it by running this command in terminal OR renaming the Problem Reporter app:

```bash
sudo chmod 000 /System/Library/CoreServices/Problem\ Reporter.app
```

Another useful tool for modifying certain OSX .plists for disable or enabling certain things is [Tinkertool](http://www.bresink.com/osx/TinkerTool.html) You can use this to disable or enable certain things that System Preferences doesn't cover.

I would also look at this filepath and you can rename files in here to temporarily disable them on the computer you're using: /System/Library/CoreServices

You can rename "Notification Center" to "Notification Center_DEACTIVATE" or something (or you can move it) - and then you won't get any obnoxiously "helpful" Notification Center popups.

If necessary, You can also hide all of the desktop icons with this terminal command:

```bash
defaults write com.apple.finder CreateDesktop -bool false
```


##Step 2: Boot into your software

Things get unplugged, power goes out, not everyone has budget or space for a battery backup etc etc. Above, I covered how to have everything reboot automatically after power failures or freezes, but you'll also need your app to be ready to go from boot and not leave the desktop open to prying eyes. There are many ways to have your application load automatically - the simplest is using OSX's built in tools: In the System Preferences "Accounts" panel, select "Login Items" and drag your application into there to have it open automatically on launch.

![Login Items](images/Login_items.png)

##Step 3: Keep it up (champ!)

There are several ways to make sure your application goes up and stays up -

###Launchd

Using Launch Daemons is an alternate way to get apps to load on boot and to continuously re-open them if they go down. Launchd plists are very useful alternatives to cron jobs and can be used to run things on a periodic basis or on calendar days. You could achieve similar results with a combination of automator and iCal, but it depends on what you're comfortable with.

Here is an [Apple Doc](http://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPSystemStartup/Chapters/CreatingLaunchdJobs.html) on using Launch Agents and Launch Daemons in various ways.

The [difference between a Launch Daemon and a Launch Agent](http://techjournal.318.com/general-technology/launchdaemons-vs-launchagents/) (Basically whether you need it to run when a user is logged in or not…for most simple options like launching a regular app, you'll just want a Launch Agent)

Also note (!) that you may need to point your launch daemon to a file within your .app package, not just the app itself - you have to point it to the file in the MacOS folder inside the .app package (right-click your app and select "Show package Contents") Otherwise you might be wondering why the launchdaemon isn't launching your app.

A launchd example from [admsyn](https://gist.github.com/4140204)

Of course you could make the launchd plist yourself for free from a template like above. You can read all about them with the command "man launchd.plist" typed into terminal to get an idea of what each toggle controls. One quick method to setting up Launchd is to use Lingon ($4.99 in the App Store) or [Lingon X](http://www.peterborgapps.com/lingon/)


In Lingon, hit the + to create a new launchd plist. Just make it a standard launch agent. Now Set up your plist like so:

![LingonSetup](images/LingonSetup.png)

One additional/optional thing you can add to this is to put an additional key in the plist for a "Successful Exit". By adding this, your app won't re-open when it has detected that it closed normally (ie You just hit escape intentionally, it didn't crash). Can be useful if you're trying to check something and OS X won't stop re-opening the app on you. To easily add this to the key, click the advanced tab and click the checkbox for "Successful exit" - or just add it manually as it in the above screenshot.

###Shell script+Cron Job method

(I got the following super helpful tip from [Kyle McDonald](http://kylemcdonald.net/))
)

This method is sort of deprecated in relation to the launchd method - you can run shell scripts with Lingon and launchd in the same manner as what we've got here. Shell scripting is your best friend. With the help of the script below and an application called CronniX (or use Lingon) , you will be able to use a cronjob to check the system's list of currently running processes. If your app does not appear on the list, then the script will open it again, otherwise it won't do anything. Either download the script or type the following into a text editor, replacing Twitter.app with your app's name and filepath. Don't forget the ".app" extension in the if statement!:

	\#!/bin/sh
		if [ $(ps ax | grep -v grep | grep "Twitter.app" | wc -l) -eq 0 ] then
		echo "Twitter not running. opening..."
		open /Applications/Twitter.app
		else
		echo "Twitter running" fi

Save that file as something like "KeepOpen.sh" and keep it next to your application or somewhere convenient.

After creating that file, you'll need to make it executable. To do this, open the Terminal and in a new window type "chmod +x " and then enter the path to the shell script you just created (you can either drag the shell script into the terminal window or manually type it). It would look something like this:


    4Evr-MacBook-Pro:~ Forever4Evr$ chmod +x /Users/Forever4Evr/Desktop/KeepOpen.sh

After you have made it executable, you're now ready to set it up as a cronjob. Tip: to test the script, you can change the extension at the end to KeepOpen.command as an alternative to opening it with Terminal, but the same thing gets done.

Cronjobs are just low level system tasks that are set to run on a timer. The syntax for cronjobs is outside of the scope of this walkthrough, but there are many sites available for that. Instead, the application CronniX can do a lot of the heavy lifting for you.

After downloading CronniX, open it up and create a new cronjob. In the window that opens,  in the command window, point it to your KeepOpen.sh file and  check all of the boxes in the simple tab for minute, hour, month, etc. This tells the job to run every minute, every hour, every day, every month. If you want it to run less frequently or at a different frequency, play around with the sliders.

![Cronnix_link](images/Cronnix-settings.png)

Now just hit "New" and then make sure to hit "Save" to save it into the system's crontab. Now if you just wait a minute then it should open your app every minute on the minute. Maybe save this one for the very end if you have more to do :)

This is a great tool if there is an unintended crash because the app will never be down longer than a minute.

###Non-Cronjob - Shell Script Method

    \#!/bin/bash

    while true
    do
    #using open to get focus
    echo "Trying to open empty example"
    open -a emptyExample
    sleep 10
    done

Just type this into a plaintext document and save it as something like "KeepMyAppAlivePlz.command" and then use chmod as above to make the file executable  and then drop this in your login items as  above. This one will just continuously try and open your app every 10ms, but if it is already open, the OS knows to not try opening it a second, third, fourth time.

Make sure to check the Console.app for any errors that may have come through when no one caught them, whenever you check the installation in person or remotely. This is not a fix-all for buggy programming, just a helper to keep things running smooth. The more things you can do to leave yourself notes about why the crash happened, the faster you can address the core issue.

Applescript is also a very solid choice for doing some more OS specific work in terms of having odd menus clicked or keypresses sent in some order.

##Step 4: Reboot periodically

This one is a little more preventative, or maybe superstitious so hopefully someone can point out a concrete reason why this is a good idea. Depending on your app and the amount of stuff it reaches into, there could be some memory leaks or other OS bugs that you haven't accounted for. Rebooting every day or week is a good idea to keep everything tidy, system wise.

The simplest option by far would be to go to System Preferences->Energy Saver and then click "Schedule…" and enter in some values if you need to turn the computer off to rest for a longer period of time to save it some stress when it might not be used at night time or something. Heat can do funny things sometimes, so if you have a chance to get your computer to rest and the time to test it, definitely give this a shot…saves some energy too which is nice.

![Auto-reboot](images/Auto_reboot.png)

You could also set up another shell script with a crontab as above with CronniX that reboots the system with as often as you specify.

Another option (if you don't want to deal with the terminal and shell scripting) is to use iCal to call an Automator iCal event. This method is perhaps a little easier to schedule and visualize when you will reboot. Within Automator, create a new file with the iCal event template to do something like this:

![Automator Shell Script](images/Automator_example2.png)

Run it to see if it does what you expect and then save it out. When you save,it will open in iCal as an action that gets opened. Just set it to repeat as often as you'd like. You can also set things like having it email you when it reboots or runs the script.

If you'd like to just close your programs and re-open them and there is a background and foreground do something like this (pauses are so the quitting and re-opening stuff has time to actually execute):

![AutomatorPause](images/Automator_example.png)

##Step 5: Check in on it from afar.

There are a bunch of options here from various paid web services (like [Logmein](http://www.logmein.com/) or [Teamviewer](http://teamviewer.com/)), to VNC (many options for this: [RealVNC](http://realvnc.com/) and Chicken of the VNC tend to come up a bunch) to [SSHing](http://www.mactricksandtips.com/2009/06/ssh-into-your-mac.html). The choice here depends on your comfort level and how much you need to do to perform maintenance from far away. Also - see below for tips on logging the status of your app as an alternative way

Leaving a Dropbox connected to the computer and your own is super useful for file swaps between the two computers. Although most remote screensharing services have file sharing built in, Dropbox is just a nice, fairly transparent option.

Determining the IP of the machine on a dynamically allocated network can be a pain, especially in screenless/headless installations. To make this a little easier, Robb Godshaw wrote a little Automator Script that says the IP aloud using Text-to-Speech 30 seconds after the computer boots. [Download link on Instructables.](http://www.instructables.com/id/Configuring-a-Mac-for-an-always-on-operation/steps/9)

##Step 6: Test, test, test.


You've already tested and perfected your software for the installation, so make sure to test all of the above methods and automatic scripts in as realistic manner as you can before you leave it alone for the first day at school.

You can't account for everything, so don't beat yourself up if something does eventually happen, but this list will hopefully alleviate a little bit of frustration. Good luck!


##Additional Tips: Logging

If you have an installation that runs for weeks or months, you might want a way to keep tabs on it that doesn't involve remotely logging in and checking on it. A good thing to have would be to have something on the system that writes certain info to a text file (kept on a linked Dropbox), or better write that file to a web server that you can then check.

There are a couple things you can do depending on what you want to know about the state of your installation.

There is a terminal command you can use to get a list of all of the currently running processes on your computer:

    ps aux (or ps ax)

(more info above ps commands [here](https://developer.apple.com/library/mac/documentation/Darwin/Reference/ManPages/man1/ps.1.html))) – Further more you can filter this list to only return applications you're interested in learning about:

    ps aux | grep "TweetDeck"

This will return a line like this:

    USER             PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
    laser          71564   0.4  1.7  4010724 140544   ??  S    Sun03PM  14:23.76 /Applications/TweetDeck.app/Contents/MacOS/TweetDeck -psn_0_100544477
    laser          95882   0.0  0.0  2432768    600 s000  S+   12:11PM   0:00.00 grep TweetDeck

Now you have the following useful info: CPU usage, Memory usage (as percentage of total memory), Status, Time Started, Time Up

All that is left is to write this output to a text file, which you can do with a line like this:

    ps aux | grep 'TweetDeck' >> /Users/laser/Dropbox/InstallationLogs/BigImportantInstall/Number6ProcessLog.txt

This line basically says - tell me the open processes (px aux) - only give me the lines that have "Tweetdeck" in them (grep Tweetdeck) - and then append them to a text file located at this location ( >> path_to_text_file)

Now we just need to make this an executable shell script and set it up as a launch daemon or cron job – see above at Step 3 to learn how to run the shell script at a regular interval using Lingon and launchd. If the app isn't running, it will only return the "grep YourAppName" process which is a good thing to log because if your app isn't open you won't know how long it's been out (nothing will be logged), but having the grep process logged will at least tell you it was checking for it. Grep will also more accurately tell you what time it checked – the other app will only give you a start time and up time.

Let's also take this one step further and say, hypothetically, that the Triplehead2Go display adapter you have is fairly wonky and you don't always get the displays or projectors to connect after reboot – or maybe a projector is shutting itself off and disrupting things. Well we can log the currently available resolutions too! Try entering the line below in your own terminal:

    system_profiler SPDisplaysDataType

This will return a list of connected displays and some metadata about them including resolution and names.

Let's say you want to make sure you're running a resolution of 3840×720 at all times…or you want a log of resolution changes. You would do something like:

    system_profiler SPDisplaysDataType | grep Resolution

This will return "Resolution: 3840×720" which you can combine with the above lines to write it all to a text file. So here would be your shell script file if you wanted to record the currently running processes and the current resolutions:

        \#!/bin/bash
    ps aux | grep 'YourAppName' >> /Users/you/filepath/Install6ProcessLog.txt
    system_profiler SPDisplaysDataType | grep Resolution >> /Users/you/Dropbox/Install6ProcessLog.txt

And now you're feeling excited, maybe you want to grab a fullscreen screenshot at a regular interval too, just to make sure there is no funkiness happening that you can't see…well you could add this line to the above as well:

    screencapture ~/Desktop/$(date +%Y%m%d-%H%M%S).png

This will save a screenshot to the desktop (specify your own file path) with a formatted date and time. You may want to do this every hour instead of every 5 minutes since it's a big chunk of data and it may cause some issue with your screens. As usual – test before deploying!

Bonus points would be to create an auto-generated table and webpage that takes all of this info and puts it into a nice view that you can use to check all of your installations at a glance.

If the process logger isn't enough, we can use what we learned in that process to actually set up a system to email you if something is amiss so you don't have to manually check it. We can do this all with the command line and internal tools, it's just a more involved setup. This is going to be fairly general and will need some tuning in your specific case.

First you will need to configure postfix so you can easily send emails from the terminal – [follow the instructions here as closely as possible](http://benjaminrojas.net/configuring-postfix-to-send-mail-from-mac-os-x-mountain-lion/)

If you were using a gmail account you would do:

*InstallationSupport@gmail.com*

*pass: yourpassword*

The line in the passwd file mentioned in the article would be: smtp.gmail.com:587 installationSupport@gmail.com:yourpassword

Now send a test email to yourself by running: echo "Hello" | mail -s "test" "InstallationSupport@gmail.com"

Second step is to combine this new found ability to send emails from the Terminal with a process to check if your application is still running…something like the below would work with some tweaking for what you're looking to do:

    \#!/bin/sh
    if [ $(ps ax | grep -v grep | grep "YourApp.app" | wc -l) -eq 0 ] ; #Replace YourApp.app with your own app's name
    then
            SUBJECT="Shit broke"
            EMAIL="InstallationSupport" #this is the receiver
         EMAILMESSAGE="This could be for adding an attachment/logfile"
         echo "The program isn't open - trying to re-open">$SUBJECT
         date | mail -s "$SUBJECT" "$EMAIL"  "$EMAILMESSAGE"

            echo "YourApp not running. Opening..."

        open /Applications/YourApp.app #reopen the app - set this to an exact filepath
    else
        echo "YourApp is running"
    fi

Now you just need to follow the instructions from Step 3 above to set this shell script up to run with launchd – you can check it every 5 minutes and have it email you if it crashed. You could also adapt the If statement to email you if the resolution isn't right or some other process condition.

##Memory leak murderer

See [this article](http://blairneal.com/blog/memory-leak-murderer/) about combining the above process with something that kills and restarts an app if it crosses a memory usage threshold

Bonus – if using MadMapper – see [this link](http://blairneal.com/blog/applescript-to-automatically-fullscreen-madmapper-for-installations/) for an AppleScript that will open MadMapper and have it enter fullscreen – and enter "OK" on a pesky dialog box.

##Alternate resources:

###MAC OS X
This is an amazing addon for openFrameworks apps that keeps your application open even after a large range of failures: [ofxWatchdog](https://github.com/toolbits/ofxWatchdog
)
[http://vormplus.be/blog/article/configuring-mac-os-x-for-interactive-installations](http://vormplus.be/blog/article/configuring-mac-os-x-for-interactive-installations
)

[Nick Hardeman's utility for setting all of these from one location](http://nickhardeman.com/610/openframeworks-configuring-osx-for-a-long-term-installation/)

Nick Hardeman's [ofxMacUtils](https://github.com/NickHardeman/ofxMacUtils)

###LINUX

[https://github.com/openframeworks/ofBook/blob/master/chapters/installation_up_4evr_linux/chapter.md](https://github.com/openframeworks/ofBook/blob/master/chapters/installation_up_4evr_linux/chapter.md)

###RASPBERRY PI

[https://sfpc.hackpad.com/rPi-run-4-ever-qFgafqYPM54](https://sfpc.hackpad.com/rPi-run-4-ever-qFgafqYPM54)

###WINDOWS:
If you're looking for help with this task with Windows, check out this awesome script [StayUp](http://www.bantherewind.com/stayup) from Stephen Schieberl. Also for Windows: http://www.softpedia.com/get/System/File-Management/Restart-on-Crash.shtml and this tool for scripting OS operations on windows http://www.nirsoft.net/utils/nircmd.html

Check out this great step by step from EVSC: http://www.evsc.net/home/prep-windows-machine-for-fulltime-exhibition-setup
