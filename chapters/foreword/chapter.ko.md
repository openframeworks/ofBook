# 머리말

*[Zach Lieberman](http://thesystemis.com) 작성*

오픈프레임웍스는 대략 2004/2005년에 시작되었습니다. 당시 저는 Parsons School of Design에서 가르치고 있었고, 동시에 코드로 인터랙티브한 프로젝트 작업을 하는 아티스트로서의 삶도 함께 하고 있었습니다.


저는 2002년 대학원을 몇년 더 일찍 졸업했는데, 제가 있을 당시 우리는 Director/Lingo와 플래시와 같은 계산적인 툴을 사용하고 있었습니다 -- 당시엔 플래시를 사용한 실험들의 전성기였었죠. 2002년, 제 교수님이셨던, Golan levin은 학교를 졸업한 후에 교수님과 함께 공동작업을 할것을 제안하시며, MIT랩의 Aesthetics and Computation Group에 의해 개발중이던 C++인 ACU를 소개해주셨습니다. 이 그룹은 John Maeda의 지도로 Elise Co, Peter Cho, Ben Fry, Casey Reas, Golan 자신과 같은 학생들로 구성되어 있었습니다.

라이브러리로써의 ACU는 훌륭했지만, SGI 머신과 같이 90년대 후반의 기술을 지향하고 있었습니다. 또한 오픈소스가 아니었으며, 활발히 유지보수되지도 않았죠. Ben Fry와 같은 친구들은 우연히 프로세싱의 개발로 옮겨갔으며, it seemed like it wasn't going to last us a long time for our work. 이는 마치 우리가 보다 진보된 대안적인 코드베이스를 필요로 하는것처럼 보였습니다.

게다가, 저는 정말로 저의 학생들과 함께한 전문적인 연습들을 작성한 코드들을 공유하고 싶었습니다. 파슨스 스쿨의 학과 행정부서원들과 나눴던 대화를 생생히 기억합니다. "예술학과 학생들은 C++를 배우길 원치 않아요" 2005년 oF으로 클래스를 가르치기 시작했는데, 당시 oF로 정말로 거칠게 실험적인 작업을 했던 Theo Watson, Christine Sugrue, Evan Roth과 같은 학생들이 있었고, 저 주장은 순식간에 산산조각 났습니다. C++는 다른 이들이 작성했던 다양한 라이브러리를 사용함으로써 컴퓨터 비전, 사운드 처리, 하드웨어 접근과 같은 기계 하위 레벨의 접근을 제공합니다. 이는 컴퓨팅의 사용을 표현하는 장을 열어주었습니다.

2005년 저의 학생이었던 Theo Watson은 oF의 OS X 버전 제작을 돕기 위해 oF 팀에 합류했습니다. 초기에는, 오픈프레임웍스를 메인페이지의 "메일링 리스트 신청"으로 숨겨두었고, Theo와 저는 정적인 HTML 페이지의 oF도큐먼트를 만들었습니다. 아주 공개적이지는 않았지만, oF를 사용하기 시작하는 쇼규모의 헌신적인 사람들의 그룹이 있었습니다. 공식적인 배포가 언제였는지 확실치 않지만, Hanger에서 열린 2006년 OFFF 페스티벌에서 가졌던 고급 프로세싱 워크숍에서 일종의 베타 단계인 오픈프레임웍스를 발표했던 떄가 생생히 기억나는군요. 당시 워크샵의 참가자 중 한명었던, Arturo Castro가 리눅스 버전의 제작을 위해 oF 팀에 함류했습니다. Theo, Aruro 그리고 저는 oF를 사용하고 그것을 위해 공헌하고 있는 거대한 사용자 그룹에 합류해왔습니다.

저는 코드와 다른 어떠한 도구에 있어서 가장 중요한 것이 즐거움이라고 생각합니다. Theo와 Arturo함께 해왔던 작업이 얼마나 즐거웠는지는 말로 표현할 수 없을 정도입니다. 괴상한 운영체제 속성들에 대한 농담들, 골치아픈 이슈를 해결하기 위해 늦은 밤까지 가졌던 Skype 대화들..  oF의 장점중 하나는 바로 그들이 배웠던 것들을 공유하고 만들어가는, 도움이 되는, 정말 배려할 줄 아는 사람들을 끌어당긴다는 점입니다.

2008년, 저희는 Ars Electronica에서 우승하여 oF lab이라는 연구소를 열었는데, 그동안 원격으로 작업해왔던 많은 사람들이 대부분 처음으로 만났습니다. 이 때가 커뮤니티를 성장하는데 도움을 주었던 수많은 개발자 컨퍼런스, 워크샵, 연구실들, 전 세계적인 미팅의 처음이었습니다. 같은 해에 일본의 YCAM에서 oF워크숍을 개최하였고, 전 세계에서 온 사람들의 커뮤니티 모두가 이 툴을 사용하고 있는것을 알게되었습니다. 그것은 저희가 생각했던 것보다 더 글로벌했습니다. 정말로 큰 힘이 되었으며 또한 약간 놀랍기도 했습니다. 이 툴을 사용하는 전세계의 사람들이 살아있게 만들어간다는것을 깨달았습니다.

We've been lucky in these events to be able to work with great institutions such as The Studio for Creative Inquiry, V&A museum, YCAM, Imal, Ars Electronica and Eyebeam, which have helped sponsor events to bring the oF community together.

저희는 운좋게도 지금까지 The Studio for Creative Inquiry, V&A museum, YCAM, Imal, Ars Electronica, Eyebeam 등 스폰서들로부터 도움을 받아 oF 커뮤니티를 모으게 되었던 훌륭한 행사들을 진행할 수 있었습니다.

근래에 들어, 저흰 커뮤니티의 성장과 확장을 시도하고 있습니다 -- Kyle McDonald는 다양한 관심사를 갖고 있는 개발자들을 조직하고 집중하는것을 돕고 있으며, Caitlin Morris는 커뮤니티의 설문에관한 디테일들을 담당하고 있습니다. Greg Borenstein과 James George는 매일매일 커뮤니티가 만들어내고 있는 양질의 애드온을 한곳에 모을수 있게 하는 온라인 저장소인 ofxAddons.com를 런칭하는데 도움을 주었습니다. 게다가 oF의 개발을 위한 섹션 리더들은 코드베이스의 서로다른 파트들의 성장과, 앞으로의 oF가 가야할 방향을 의논하고 있습니다. 마지막으로, 셀 수 없는 많은 분들의 공헌자들이 코드베이스, 문서, 예제, 애드온, 포럼의 질문에 대한 답변 작성 등으로 오픈프레임웍스를 돕고 있습니다.

무엇보다도, 저희는 활동함에 있어 자칫 서먹해지거나 독립적이기 쉬운 프로그래밍 분위기를 좀더 친숙하게 만들기 위해 최선을 다하고 있습니다. 연구소로서의 예술마케팅에 관한 아이디어, 인문학(humanity)을 위한 R&D아이디어를 전파하는것입니다. 오픈프레임웍스는 함께 경험을 공유하고 저희가 성장할 수 있는 커다란 연구실을 만들기 위한 하나의 시도입니다. 한동안 메이킹을 시도하는 문화로 DIY(Do It Yourself:스스로하자)라는 큰 움직임이 있어봤습니다. 저희는 DIWO(Do it With Others:남들과 함께 하라)의 커다란 팬이며, 가능한한 온라인과 오프라인에서 이것을 시도하고 있습니다. 운좋게도 아마 저희가 환상적이고, 도움을 주는, 따뜻한 마음을 지닌, 사랑스런 사람들에게 함께하도록 이끌어왔었습니다. 만약 여러분이 아직 아니라면, **환영**한다고 말씀드리고 싶네요.

## 책에 관하여

이 책에는 오픈프레임웍스의 정신이 가득 담겨있습니다. 커뮤니티에 의해 진행되고 있으며, 현재 **한참 진행중인 작업**입니다. 이 프로젝트는 오픈프레임웍스 개발자 메일링리스트에서 제안되어 시작되었으며, 지난 몇달간 이 작업을 진행중입니다.

몇가지 염두할 사항들,

* 무엇이 빠졌는지, 혹은 내용중 뭐가 맘에 들었는지 같은 피드백을 주시면 정말로 감사하겠습니다. 마찬가지로 만약 뭔가 도움이 될만한 것을 찾았다면, 마찬가지로 저희에게 알려주세요! github 저장소는 활발히 진행중이며 이슈와 pull request를 받고 있습니다.
* 이 책에 몇몇 빈틈이 있다는 점을 염두해주세요. 난이도의 순서대로 러프하게 레이아웃을 잡아놨습니다만, 참여형태로 작성되는 책이므로, 어떤 챕터는 짧고 어떤 챕터는 길게 구성되어있는 등 약간 혼란스러울 수 있습니다. 처음부터 끝까지 읽는 책이 아니라 커뮤니티의 짧은 튜토리얼의 모음집에 가깝다고 생각하시면 됩니다.

*모든 챕터는, 별도로 언급되지 않는 한, 이하의 라이센스를 따릅니다.: [크리에이티브 커먼즈 저작자표시-비영리-동일조건변경허락 4.0 국제 라이센스](http://creativecommons.org/licenses/by-nc-sa/4.0/deed.ko)*

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>


## Credits

이 프로젝트를 조직한 Rachel Uwa, 편집을 돕는 Tega Brain, 디자인을 디렉팅해준 Ishac Bertran과 Andy Clymer, 책을 자동생성하는 코드베이스 및 개발을 담당해준 Christoph Buchner와 Micheal Hadley에게 무한한 감사의 말씀을 드립니다. 더불어 뒤에 언급되는 분들은 이 책에 공헌해주신 저자와 편집자들입니다: Rui Pereira, Arturo Castro, Brannon Dorsey, Zach Lieberman, Kayla Lewis, Josh Nimoy, Phoenix Perry, Jane Friedhoff, Caitlin Morris, Pierre Proske, Golan Levin, Blair Neal, Michael Hadley, Abraham Avnisan, Christopher Baker, Lukasz Karluk, Omer Shapira, Mimi Son & Elliot Woods (Kimchi and Chips), Eva Schindling, Pierre Thirion, Joel Gethin Lewis, Roy Macdonald, Adam Carlucci, Christoph Buchner, tpltnt, 이 밖에도 피드백을 주시거나, pull request를 확인해주시고, 조언을 구한 셀 수 없이 많은 분들이 있습니다.

만약 오픈프레임웍스(그리고 일반적인 오픈소스)에 하나의 모토를 가져야 한다면, 그것은 이것일 것입니다.:
*together we know more*(함께라면, 우리는 더 많이 안다)

