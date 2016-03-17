# Network


*by [Arturo Castro](http://arturocastro.net)*

*corrections by Brannon Dorsey*


## TCP vs UDP

TCP and UDP are 2 of the most used protocols to communicate through a network. Indeed TCP is so common that the suite of protocols on which internet is based is usually called TCP/IP. The network protocols are classified in layers by something called the [OSI model](http://en.wikipedia.org/wiki/OSI_model). TCP and UDP belong to layer 4, the transport layer, and are usually the most used in oF along with protocols from layer 7, the application protocol, like HTTP, FTP or OSC that actually work on top of the other layers, for example HTTP and FTP on top of TCP and OSC usually on top of UDP.

### TCP

**Transmission Control Protocol** is without doubt the most used network protocol on the Internet.  It is a stream-based protocol that is resistant to transmission errors such as packet corruption, reordering and loss. Let's see what all that means.

To understand all that we might need to know a bit about how a TCP/IP network works. First of all we need to know that when we send information (such as a large file) over the network, it is divided in smaller pieces of information called _packets_.  Further, each segment of the network might support a different packet sizes, so those packets might be broken down into even smaller packets. So, ultimately a packet is just a small piece of the information we are trying to send plus some extra information called headers. Headers help keep track of things like packet size, transmission order and the source and destination of the packet.  This division in packets is used among other things so it's easier to recover from errors. For example if we sent a large file in one giant packet, if some parts of it were corrupted during transmission we'd need to resend the full file again. Dividing it in packets containing a small piece of our data and some headers allows us to detect errors per packet so we only need to resend the corrupted packets instead of the whole thing.

When we send a packet from one computer to another, even with a connection based protocol like TCP, there's no way of knowing in advance which route it's going to take on its journey to the destination. On the Internet there are often many possible paths one point to another and with the help of internet hardware like routers, packets are usually transmitted via whatever route is the quickest at the moment they are sent. But that path might no longer be the ideal path some milliseconds later, so the next packet could go through a different route and arrive out of order.

Another problem is that packets might get corrupted on their way to the destination computer, for example, because of electrical noise in some of the cables.

With all that let's say we send packets ABCD in that order, it might be that at the other end we get something like GCB: packet A got corrupted and turned into G, packets B and C arrived ok but in the wrong order, and packet D was totally lost.

TCP is able to solve all of those problems.  When TCP sends packets it adds a sequence number to the headers so that they can be correctly ordered when the other computer receives them. It also adds something called a CRC to each packet that allows the other computer to know if that packet is corrupt.

When the destination receives a packet and that packet is correct, it sends a confirmation, also called an ACK. If after some time the sender hasn't received that confirmation, it sends the packet again, which solves the problem of corrupted and lost packets.

This ACKs also allows the sender to regulate the speed with which packets are sent so if the client has less bandwidth than the server, the server can slow down sending packets until it matches the speed at which the client can reliably receive them.

As we see, using a TCP connection ensures that everything we send is received correctly on the other side.

So why not just always use TCP?  Well TCP has some limitations, for example TCP is connection oriented, that means that in order to communicate with another machine we need to open a connection explicitly to that machine and that machine only.

TCP is also stream oriented. That means that we cannot send individual messages and expect them to arrive in one piece, they will arrive eventually but not exactly as we sent them. For example if we send something like:

        "Hello world!! this is an openFrameworks network message"

On the other side, the application using TCP, we may receive it like:

        "Hello w"
        "orld!"
        "!this is a"
        "n openFr"
        "ameworks ne"
        "twork mess"
        "age"

We can't even be sure of which size those packets are going to have. There's tricks to send full messages, like adding a delimiter to them, for example openFrameworks when doing:

```cpp
tcpClient.send("Hello world!! this is an openFrameworks network message");
```

Internally is sending:

        "Hello world!! this is an openFrameworks network message[/TCP]\0"

The last `\0` is actually added for compatibility reasons with old versions of flash! The `[\TCP]` allows the other side to read the stream until it receives the full message. So when you use:

```cpp
string message = tcpServer.receive();
```

Internally ofxTCPCLient/Server will read the stream, keep the partial messages in memory, and wait until it gets the delimiter before returning a full message. This is done transparently, but if you are interfacing with some other protocol coming from a non-openFrameworks application you might need to do this yourself by using `sendRaw()` `sendRawMsg()` `receiveRaw()` and `receiveRawMsg()` which don't send or expect a terminator.

If the protocol you are working with uses TCP and a delimiter, chances are you might be able to use this same trick by using:

```cpp
tcpClient.setMessageDelimiter(myDelimiter);
```

Something important that you might know already: in order to connect applications through a TCP/IP transport network protocol, you usually need, an IP address and a port, the IP address is specific to each machine, the port to each application. So with an IP/port pair we can define an application running in a specific address along all Internet, almost. For example an application that is running a web server usually runs on port 80, if the machine is being executed in has the IP 15.6.8.2, 15.6.8.2:80 defines that web server among any other application running in any other machine in all the Internet. So if we want to connect two machines, usually all we need to know is the IP and port of the application running in the server and use it in the client to connect to it.

There's an exception though. In most internal networks, like your home network for example, there's a router that connects the machines in that network to the Internet. These routers usually do something called Network Address Translation (NAT). NAT was invented because the IPv4 protocol has a limited number of IP addresses. Internally, the network uses a reserved range of addresses: 192.168.x.x/24 or 10.x.x.x/32, which are addresses that won't be found directly on the internet. When we try to connect to an external address it acts as a kind of proxy between your computer and the server that we want to connect. The router has its own external address, and when it receives a response it translates the address and port in which it has received it to an internal one, the one from our computer and sends the packets back to us.

While this is really practical, it means that if we have two computers behind NAT routers, it's impossible to open a connection between them (in principle) . There are ways to configure a router to send any packet sent to a specific port to the same internal address. There are also libraries like [ofxNice](https://github.com/arturoc/ofxNice) that allow you to do NAT transversal, but that will only work using UDP.

### UDP

UDP or **User Datagram Protocol**, is a non-connection datagram oriented, non-error-resistant protocol. It is more or less the total opposite to TCP. We don't need to establish a connection, instead we just send messages to a specific address and port. As long as there's a process listening on that machine and that port it will receive the message.

Datagram oriented means that whatever we send, that fits in the packet size supported by the network, by all the subnetworks in the path from one computer to another, will arrive in one piece on the other side. In openFrameworks, if we do:

```cpp
string message = "Hello world!! this is an openFrameworks network message";
udpManager.SendAll(message, message.size());
```

the other side will receive that message in one piece -- that is -- if it receives the datagram at all.

As we've said before, UDP is not resistant to errors so the packet may not arrive. It may get corrupted and there's no way to recover it. If we send several packets they may arrive in a different order then they were sent. UDP also doesn't adjust for bandwidth, so if one side is sending faster than what the other side can receive, or even if it fills the local buffers while sending, some packets will get lost. What's worse, neither sender or receiver will receive any feedback that packets were lost.

UDP might seem not useful but it has some advantages. First, it is fast! Since UDP doesn't require feedback (e.g. ACKs) and only minimal header information, there are less bytes to send. In many cases, this speed is more important than reliability.  For example, if we are sending a packet every few frames with the state of our application we don't mind if one or two frames is lost because the destination will be updated with the next packet it receives. It's also really rare to loose UDP packets on a local network. Thus, if you need to send your packets very quickly (also known as low-latency) and you don't mind if a few packets are lost, UDP may be right for you.  If your application requires confirmation that each and every byte arrived at its destination, you'll need to use TCP.

Some of the advantages of UDP come from the fact that is connectionless. That means, among other things, that we can broadcast messages to all of the computers in the local network using a broadcast address. To calculate the broadcast address we need to know the IP address of the machine from where we are sending and the subnetwork mask by doing a bit xor on them you get the broadcast address. For example, if the IP address of our machine is 192.168.0.3, and our network mask is 255.255.255.0, the broadcast address will be 192.168.0.255.  We can also use multicast if we are working across networks although that's more difficult to setup. We can reuse ports, so we can have more than one process in the same machine using the same port, or use the same port to send and receive.

UDP, as we mentioned before, allows us to do NAT transversal using some clever tricks although is not something that can be done with raw UDP and requires a third party library.

A case where UDP might be preferable over TCP is in very time critical applications, you might have heard that UDP is faster than TCP. That is not exactly true, at least is not that fast to make much difference. The real difference is that when using TCP, if a packet gets corrupted or lost the next messages won't get delivered to the application until the lost one is resent so that might introduce a slight delay. In most applications that delay is not noticeable but in some very time critical applications we might prefer to loose some packets than having to wait for them to be resent. We are usually talking of milliseconds here so as we've said it is usually not a problem.

Another possibility is implementing part of the error recovery in TCP while using UDP, for example we might not mind loosing some packets or getting some of them corrupt but we care about the order in which they arrive, in those cases we can implement packet reordering in UDP simply by using a sequence number in each message and reorder the packets in the destination by having a buffer so we can wait a little before actually processing a message to see if any other message that might arrive later needs to be processed before.

In general use TCP if you need your messages to arrive no matter what, when loosing even one packet might be critical and UDP if you need some of the most advanced uses like broadcasting, multicasting, NAT transversal, or when waiting for lost packets to be resent, even a few milliseconds, might make be critical for the application while loosing some packets is ok.

## OSC

OSC or **Open Sound Control**, is an application level protocol. It is of a higher level than UDP or TCP, and its main characteristic is that it allows to send plain data types like int, float and string (among others) without worrying about the underlying architecture of the sending and receiving machine. It's usually based on UDP so it has some of the same problems.

It's usage in openFrameworks is really simple, so just check the examples in the examples/addons folder to know how it works.

One major advantage of using OSC is that there are lots of commercial and open source projects that support OSC. OSC allows your software to easily control (or be controlled) by another piece of software. For example, in a performance you might want a Pure Data patch to generate audio and openFrameworks to generate video.  During the performance, the two programs could control each other's parameters by exchanging OSC messages.

In addition to OSC, there are other application level protocols for specific applications and it's usually easier to use those than trying to use transport protocols like TCP or UDP. For example streaming video is a really complex problem to solve but there are protocols like RTP that already solve or at least mitigate all the complications that it involves so using a library that implements RTP will be easier than trying to send video directly using TCP or UDP.
