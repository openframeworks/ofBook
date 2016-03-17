#머리말

*by [Zach Lieberman](http://thesystemis.com)*


openFrameworks began around 2004 / 2005.  I was teaching at Parsons School of Design, and at the same time, making a living as an artist creating interactive projects with code.

오픈프레임웍스는 대략 2004/2005년에 시작되었습니다. 당시 저는 Parsons School of Design에서 가르치고 있었고, 동시에 코드로 인터랙티브한 프로젝트 작업을 하는 아티스트로서의 삶도 함께 하고 있었습니다.

I had graduated a few years earlier from grad school in 2002, and we were using computational tools like Director / Lingo and Flash when I was there -- it was the heyday of flash experimentation.  In 2002, my professor, Golan Levin, invited me to collaborate with him on some projects after I graduated from school and he introduced me to ACU, a C++ library that had been developed at MIT under the Aesthetics and Computation Group, the group that John Maeda ran which had students like Elise Co, Peter Cho, Ben Fry, Casey Reas and Golan himself.

저는 2002년 대학원을 몇년 더 일찍 졸업했는데, 제가 있을 당시 우리는 Director/Lingo와 플래시와 같은 계산적인 툴을 사용하고 있었습니다 -- 당시엔 플래시를 사용한 실험들의 전성기였었죠. 2002년, 제 교수님이셨던, Golan levin은 학교를 졸업한 후에 교수님과 함께 공동작업을 할것을 제안하시며, MIT랩의 Aesthetics and Computation Group에 의해 개발중이던 C++인 ACU를 소개해주셨습니다. 이 그룹은 John Maeda의 지도로 Elise Co, Peter Cho, Ben Fry, Casey Reas, Golan 자신과 같은 학생들로 구성되어 있었습니다.

ACU as a library was great, but quite oriented to late 90s tech such as SGI machines.  It was also not open source and not actively maintained.  Folks like Ben Fry had fortuitously moved on to developing Processing and it seemed like it wasn't going to last us a long time for our work.  It seemed like we would need an alternative codebase moving forward.

라이브러리로써의 ACU는 훌륭했지만, SGI 머신과 같이 90년대 후반의 기술을 지향하고 있었습니다. 또한 오픈소스가 아니었으며, 활발히 유지보수되지도 않았죠. Ben Fry와 같은 친구들은 우연히 프로세싱의 개발로 옮겨갔으며, it seemed like it wasn't going to last us a long time for our work. 이는 마치 우리가 보다 진보된 대안적인 코드베이스를 필요로 하는것처럼 보였습니다.

In addition, I really wanted to share the code I was writing in my professional practice with my students.  I remember vividly having conversations with the administration of the department at Parsons where they said, "Art students don't want to learn C++."  I started teaching classes with oF in 2005, and I had students like Theo Watson, Christine Sugrue, and Evan Roth who created remarkably wild, experimental work with oF and that argument crumbled rapidly.   C++ provided low level access to the machine for things like computer vision, sound processing, access to hardware as well as access to a wide array of libraries that other folks had written.  It opened up doors to expressive uses of computation.

게다가, 저는 정말로 저의 학생들과 함께한 전문적인 연습들을 작성한 코드들을 공유하고 싶었습니다. 파슨스 스쿨의 학과 행정부서원들과 나눴던 대화를 생생히 기억합니다. "예술학과 학생들은 C++를 배우길 원치 않아요" 2005년 oF으로 클래스를 가르치기 시작했는데, 당시 oF로 정말로 거칠게 실험적인 작업을 했던 Theo Watson, Christine Sugrue, Evan Roth과 같은 학생들이 있었고, 저 주장은 순식간에 산산조각 났습니다. C++는 다른 이들이 작성했던 다양한 라이브러리를 사용함으로써 컴퓨터 비전, 사운드 처리, 하드웨어 접근과 같은 기계 하위 레벨의 접근을 제공합니다. 이는 컴퓨팅의 사용을 표현하는 장을 열어주었습니다.

Theo Watson, who was my student in 2005, joined the oF team to help produce an OS X version.  In the early days, we had openFrameworks up online behind a cryptic "join the mailing list" front page and Theo and I would produce a single static HTML page with oF documentation.  It was not super public, but we had a small and dedicated group of people starting to use oF. I'm not totally sure when our first official release was, but I remember vividly presenting openFrameworks to the public in a sort of beta state at the 2006 OFFF festival where we had an advanced processing workshop held at Hangar. One of the participants of that workshop, Arturo Castro, joined the oF team to help produce a Linux version.  Theo, Arturo and I have been joined by a huge group of people who use oF and help contribute to it.

2005년 저의 학생이었던 Theo Watson은 oF의 OS X 버전 제작을 돕기 위해 oF 팀에 합류했습니다. 초기에는, 오픈프레임웍스를 메인페이지의 "메일링 리스트 신청"으로 숨겨두었고, Theo와 저는 정적인 HTML 페이지의 oF도큐먼트를 만들었습니다. 아주 공개적이지는 않았지만, oF를 사용하기 시작하는 쇼규모의 헌신적인 사람들의 그룹이 있었습니다. 공식적인 배포가 언제였는지 확실치 않지만, Hanger에서 열린 2006년 OFFF 페스티벌에서 가졌던 고급 프로세싱 워크숍에서 일종의 베타 단계인 오픈프레임웍스를 발표했던 떄가 생생히 기억나는군요. 당시 워크샵의 참가자 중 한명었던, Arturo Castro가 리눅스 버전의 제작을 위해 oF 팀에 함류했습니다. Theo, Aruro 그리고 저는 oF를 사용하고 그것을 위해 공헌하고 있는 거대한 사용자 그룹에 합류해왔습니다.


I think one of the most important things about code and any tool is joy, and I can't express how much joy I've had working with Theo and Arturo, joking about weird operating systems properties, having late night Skype calls to figure out tough issues.  I think one of the strengths of oF is that it attracts really caring, helpful people who like to make things and share what they've learned.

저는 코드와 다른 어떠한 도구에 있어서 가장 중요한 것이 즐거움이라고 생각합니다. Theo와 Arturo함께 해왔던 작업이 얼마나 즐거웠는지는 말로 표현할 수 없을 정도입니다. 괴상한 운영체제 속성들에 대한 농담들, 골치아픈 이슈를 해결하기 위해 늦은 밤까지 가졌던 Skype 대화들..  oF의 장점중 하나는 바로 그들이 배웠던 것들을 공유하고 만들어가는, 도움이 되는, 정말 배려할 줄 아는 사람들을 끌어당긴다는 점입니다.


In 2008, we won a prize at Ars Electronica and built a laboratory called oF lab which brought many of us who had been working remotely, face-to-face, often for the first time.  It was the first of many such world-wide meetings, labs, workshops, and developer conferences that have helped grow the community.  That year we also held an oF workshop in Japan at YCAM and discovered that there was a whole community of people across the world using this tool.  It was way more global than we had thought.  It was simultaneously heartening and also a little bit frightening, the realization that there were people around the world who were using this tool to make a living.

2008년, 저희는 Ars Electronica에서 우승하여 oF lab이라는 연구소를 열었는데, 그동안 원격으로 작업해왔던 많은 사람들이 대부분 처음으로 만났습니다. 이 때가 커뮤니티를 성장하는데 도움을 주었던 수많은 개발자 컨퍼런스, 워크샵, 연구실들, 전 세계적인 미팅의 처음이었습니다. 같은 해에 일본의 YCAM에서 oF워크숍을 개최하였고, 전 세계에서 온 사람들의 커뮤니티 모두가 이 툴을 사용하고 있는것을 알게되었습니다. 그것은 저희가 생각했던 것보다 더 글로벌했습니다. 정말로 큰 힘이 되었으며 또한 약간 놀랍기도 했습니다. 이 툴을 사용하는 전세계의 사람들이 살아있게 만들어간다는것을 깨달았습니다.

We've been lucky in these events to be able to work with great institutions such as The Studio for Creative Inquiry, V&A museum, YCAM, Imal, Ars Electronica and Eyebeam, which have helped sponsor events to bring the oF community together.



In recent years, we've tried to help grow and expand the community -- folks like Kyle McDonald have helped organize the diverse interests of developers and keep everything focused while Caitlin Morris has produced detailed surveys of the community.  Greg Borenstein and James George helped launch ofxAddons.com, an online repository which helps organize the impressive quantity of addons that the community is creating on a daily basis.  In addition, there are now section leaders for the development of oF, helping grow different parts of the codebase and helping imagine what modern oF looks like.  Finally, there are countless contributors to oF who help with the codebase, documentation, examples, addons and answering questions on the forum.

More than anything, we've tried as hard as we can to create a friendly atmosphere around programming, which can be an unfriendly activity and in some ways isolating.  We preach the idea of art-making as a laboratory, as R&D (Research & Development) for humanity, and oF is one attempt to make a large lab where we can grow and share experiments together.   There's been a big movement for DIY  (Do it Yourself) culture these days, things like Make Magazine and Instructables promoting a culture of sharing through making.  We are big fans of DIWO (Do it With Others) and try to do that as much as we can online and offline.  Somehow, luckily, we've attracted some of the most amazing, helpful, warm-hearted, lovely people to come be a part of this, and if you're not already, we'd like to say **welcome**.


## about this book

This book, much in the spirit of openFrameworks, is a community driven affair and it's **very much a work in progress**.   It was a suggestion on the openFrameworks developers mailing list which kicked this off and for a the past months we've been hacking away on it.

A couple of notes, 

* Feedback is very much appreciated and we'd like to know what's missing, or what you'd like to have in here.  Likewise, if you find something helpful, we'd love to hear it, too!  Our github repo is active and we take issues and pull requests.
* Please note that there are likely gaps here.  We've tried to roughly lay out chapters in order of skill level, but since it's a collectively written book, it can feel a bit disorienting, with some chapters being on the long side, while some are short.  Think of it not as a book you read front to back, but more like a collection of short tutorials from the community.

*Every chapter, unless noted, is licensed: [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US)*

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>


## credits

Countless thanks to Rachel Uwa for organizing this project, Tega Brain for helping edit it, Ishac Bertran and Andy Clymer for directing the design, and Arturo Castro, Christoph Buchner and Michael Hadley for developing the codebase for generating the book.   In addition, the following authors and editors have contributed to this book:  Rui Pereira, Arturo Castro, Brannon Dorsey, Zach Lieberman, Kayla Lewis, Josh Nimoy, Phoenix Perry, Jane Friedhoff, Caitlin Morris, Pierre Proske, Golan Levin, Blair Neal, Michael Hadley, Abraham Avnisan, Christopher Baker, Lukasz Karluk, Omer Shapira, Mimi Son & Elliot Woods (Kimchi and Chips), Eva Schindling, Pierre Thirion, Joel Gethin Lewis, Roy Macdonald, Adam Carlucci, Christoph Buchner, tpltnt as well as countless others who have given feedback, submitted pull requests, offered advice, etc.

I think if there's one motto that openFrameworks (and open source generally) embodies, it is:

*together we know more*

