# Network


*by [Arturo Castro](http://arturocastro.net)*


## TCP vs UDP

TCP and UDP are 2 of the most used protocols to comunicate through a network. Indeed it's so common that the suite of protocols on which internet is based is usually called TCP/IP. We are not goint to enter into details of protocol layers... but instead explain what are the main differences between this 2 protocols so we can know when it makes sense to use one or the other and how.

### TCP

Transmission Control Protocol, is without doubt the most used network protocol on the Internet, it is a protocol based on a connection, stream based and resistant to errors, package reordering and package lose. Let's see what all that means.

To understand all that we might need to know how a TCP/IP network works slightly. First of all we need to know that when we send something it's usually divided in packages, each segment of the network might support a different package size so it might subdivide our packages in smaller packages.

Also, when we send those package from one computer to another even with a connection based protocol like TCP there's no way of knowing in advance which path it's going to take. On the Internet there's several paths to arrive from one point to another and packages go through whatever path is more optimal at some moment which might not be the best some milliseconds after that.

Another problem is that packages might get corrupted in their way to the destination computer for example because of electrical noise in some of the cables.

With all that let's say we send packages ABCD in that order, it might be that at the other end we get something like BCG! packages B and C arrived first, package A got corrupted and turned into G and package D was totally lost.

Now TCP is able to solve all that problems, when TCP sends a package it numbers them so when the other side receives them is able to order them. It also adds to each package something called a CRC that allows the other side to know if the package is corrupt.

When the destination receives a package and that package is correct, it sends a confirmation, also called an ACK. If after some time the sender hasn't received that confirmation, it sends the package again.

This ACK packages also allow to regulate the speed with which packages are sent, without entering in details, if we are downloading something with a network connection that allows 1Mb download from a server with a bandwith of 10Mb, at some point some router in the path to our computer will start dropping packages, the server won't receive the ACK from us and will start to slow down the rate at which it sends packages till we can keep up and there's no package loss.

So as we can see using a TCP connection ensures that everything we send is received correctly in the other side.

So why not just always use TCP?  Well TCP has some limitations, for example TCP is connection oriented, that means that in order to communicate with another machine we need to open a connection explictly to that machine and only to that machine.

TCP is also stream oriented, that means that we cannot send individual messages and expect them to arrive in one piece, they will arrive eventually but not exactly as we sent them. For example if we send something like:

        "Hello world!! this is an openFrameworks network message"
        
in the other side we can receive it like:

        "Hello w"
        "orld!"
        "!this is a"
        "n openFr"
        "ameworks ne"
        "twork mess"
        "age"
        
We can't even be sure of which side those packages are going to have. There's tricks to send full messages, like adding a delimiter to our messages, for example openframeworks when doing:

```cpp
tcpClient.send("Hello world!! this is an openFrameworks network message");
```

internally is sending:

        "Hello world!! this is an openFrameworks network message[/TCP]\0"
        
The last `\0` is actually added for compatibility reasons with old versions of flash! and along with the `[\TCP]` allows the other side to read the stream till it receives the full message. so when you do:

```cpp
string message = tcpServer.receive();
```

internally ofxTCPCLient/Server will read the stream keep the partial messages in memory and wait till it gets the delimiter and only then returning a full message. This is done transparently but if you are interfacing with some other protocol comming from a non OF application you might need to do this your self by using `sendRaw()` `sendRawMsg()` `receiveRaw()` and `receiveRawMsg()` which don't send or expect a terminator.

If the protocol you are working with uses TCP and a delimiter, chances are you might be able to use this same trick by using:

```cpp
tcpClient.setMessageDelimiter(myDelimiter);
```


Something important that you might know already in order to connect applications through a network protocol, you usually need, an IP address and a port, the IP address is specific to each machine, the port to each application. So with an IP/port pair we can define an application running in a specific address along all Internet, almost.

In most internal networks, at your home for example, there's a router that connects the machines in that network to internet, these routers usually do something called NAT: Network Address Translation. NAT was invented because the current IP protocol IPv4 has really limited number of IP addresses and what it does is that internally in the network it uses a reserved range of addresses: 192.168.x.x/24 or 10.x.x.x/32 which are addresses that won't be found directly on internet. When we try to connect to an external address it acts as a kind of proxy between our computer and the server that we want to connect to but using it's own external address, when it receives a response it translates the address to an internal one, the one from our computer and sends the packages back to us.

While this is really practical, it means that if we have 2 computers behind NAT routers it's in principle imposible to open a connection between them. There's ways to configure a router to send any package sent to a specific port to the same internal address and there's also libraries like [ofxNice](https://github.com/arturoc/ofxNice) that allow to do what it's called NAT transversal but that will only work using UDP.

### UDP

UDP or User Datagram Protocol, is a non connection datagram oriented, non resitant to errors protocol, it is more or less the total opposite to TCP, we don't need to stablish a connection, instead we just send messages to a specific address and port, as long as there's a process listening in that machine and that port it'll receive the message.

Datagram oriented means that whatever we send, it it fits in the pacakge size supported by the network, by all segments in the path from one computer to another, it will arrive in one piece to the other side, so when in openFrameworks we do:

```cpp
string message = "Hello world!! this is an openFrameworks network message";
udpManager.SendAll(message, message.size());
```

The other size will receive that message in one piece, if it receives it.

As we've said before UDP, is not resistant to errors so package may not arrive, they might get corupted and there's no way to recover them or they can arrive in a different order in which we sent them. UDP also doens't adjust for bandwitdth so if one side is sending faster than what the other side can receive or even if it fills the local buffers while sending some pcakges will get lost and what's more we won't receive any advice that they got lost.

UDP might seem not useful then but it has some advantages. Some times, we don't mind some packages being lost, for example if we are sending a package every few frames with the state of our application we don't midn if sometime we don't receive one of them, it's also really hard to loose a package on a local network, but if you need total reliability don't trust that and just use TCP.

Som of the advantages of UDP come from the fact that is conectionless, that means among other things that we can broadcast messages to all the computers in the local network using a broadcast address, usually in the form: 192.168.0.255, if the IP of our machine is 192.168.0.3 and our network mask 255.255.255.0. We can also use multicast if we are working across networks although that's more difficult to setup. We can reuse ports, so we can have more than one process in the same machine using the same port or use the same port to send and receive...

Also UDP as we mentioned before allows to do NAT transversal using some clever tricks although is not something that can be done with raw UDP and requires some third party library.


## OSC

OSC is an applcation level protocol is of a higher level than UDP or TCP, and it's main characteristic is that it allows to send types like int, float, string... without worring about the underlying architecture. It's usually based on UDP so it has the same problems as it.

It's usage in openFrameworks is really simple so just check the examples in the addons folder to know how it works

Another advantage of using OSC is that there's lots of commercial and open source projects that support OSC to communicate with them so using OSC you might be able to control easily some other software or receive results from it.


*This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.*

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>
