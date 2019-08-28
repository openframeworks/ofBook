<!--
# Philosophy
-->

# 哲学

_by [Zach Lieberman](http://thesystemis.com)_

<!--
The endeavour of openFrameworks is guided by a number of goals: it should be collaborative, usable and simple, consistent and intuitive, cross-platform, powerful, and extensible. It is also driven by a "do it with others" (DIWO) philosophy.
-->

openFrameworks は幾つかのゴールに向かった取り組みを行なっています。それは協働的であること、実用的かつシンプルであること、一貫性があり直感的であること、クロスプラットフォームであること、パワフルさ、そして拡張可能であることです。加えて、「皆でやろう（do it with others / (DIWO)」の哲学によって推進されています。

<!--
### Collaborative
-->

### 協働的であること

<!--
The development of openFrameworks is collaborative. It thrives on the contributions of many people who engage in frequent discussion, and collaborate on addons and projects. We encourage people to make openFrameworks their own and contribute to the ecosystem.
-->

openFrameworks の開発は協働的なもので、議論に盛んに参加し、アドオンやプロジェクト上で協働する多くの人々の貢献の上に成り立っています。私たちは皆が openFrameworks を我が物とし、このエコシステムに貢献することを推奨しています。

<!--
We use git, a distributed versioning system, which means that people can branch, experiment, and make suggestions. If you look at the network diagram on [GitHub](https://github.com/openframeworks/openFrameworks "link to the GitHub repository of openFrameworks"), it looks like some alien diagram, full of weaving branches, code pulling apart and coming together. There's a huge community all over the world working on the core code: fixing bugs, submitting pull requests, and shaping the tool the way they want to see it. It's a world wide project and it's common to wake up in the USA to an inbox full of pull requests and issues emails from coders in Asia and Europe. Over 70 people have contributed to the openFrameworks core directly, and hundreds of people have forked the code or contributed in other ways.
-->

私たちは git という分散型バージョン管理システムを用いています。これは人々がブランチを作り、実験し、提案が可能なことを意味します。[GitHub](https://github.com/openframeworks/openFrameworks "link to the GitHub repository of openFrameworks") のネットワーク図を見てみると、沢山の曲がりくねったブランチ、枝分かれしてまた合流するコードによるエイリアンのダイヤグラムのように見えます。コアのコードに対して作業する、世界中に広がる巨大なコミュニティが存在します。彼らはバグを修正し、プルリクエストを送り、必要な形のツールを具現化します。これは全世界的なプロジェクトであり、合衆国で目を覚ました時に、アジアやヨーロッパのプログラマからのプルリクエストやイシューで一杯の電子メールの受信箱を目にすることは日常茶飯事です。

<!--
 ### Simplicity -->

### シンプルさ

<!--
 openFrameworks tries to balance usability and simplicity. The earliest versions of openFrameworks used the core as a tool for teaching C++ and [OpenGL](https://en.wikipedia.org/wiki/OpenGL "wikipedia article on OpenGL"), but over time the examples have become the best way to learn while the core takes advantage of more advanced features. In exchange, we've created many more examples that come with openFrameworks, with the goal of trying to make simple, hackable starting points for experimentation.
 -->

openFrameworks は有用性とシンプルさのバランスを取ることを目指しています。openFrameworks の最初期のバージョンは C++ と [OpenGL](https://en.wikipedia.org/wiki/OpenGL "wikipedia article on OpenGL")を教えるためのツールとしてその中核の部分を利用していましたが、時を経るにつれて中核部分はより先進的な機能を取り入れるようになり、サンプル（examples）が学習のための最適な方法となりました。代わりに openFrameworks に同梱される沢山のサンプルを作成して、実験のために改変していけるシンプルなスタート地点としました。

<!--
We want openFrameworks to be as simple as possible, especially for folks coming from other languages and environments. C++ is a "large" language, large in the sense that you can write very different types of C++ code. If you go to the bookstore, you'll see hundreds of C++ books. We want to create a library where you don't need to be an expert, where at most you might need a book or two, but that the patterns, approaches and style of the code is simple and intuitive. We were especially interested in achieving a sort of parity with [Processing](http://www.processing.org/ "processing language and IDE website"), where many of the functions are similar, allowing easier movement from one framework to another.
-->

可能な限り、私たちは openFrameworks を特に他の言語や環境から来た人々にとってシンプルなものにしたいです。C++ は「大きな」言語で、それはつまり全く違うタイプの様々な C++ コードを書くことが出来るという意味です。書店に行けば何百もの C++ の書籍を目にするでしょう。私たちはあなた方が専門家になる必要なく、多くとも一冊か二冊があれば事足りて、コードのパターン、アプローチやスタイルはシンプルかつ直感的であるようなライブラリを作りたいのです。私たちは [Processing](http://www.processing.org/ "processing language and IDE website") とある意味で同質となること、つまり多くの機能が似通っていて一方のフレームワークから他方への移行が容易になることに特に関心を持っていました。

<!--
### Consistent and Intuitive
-->

### 一貫性と直感的であること

<!--
openFrameworks is consistent and intuitive: it should operate on the principle of least surprise, so that what you learn about one part of openFrameworks can be applied to other parts of it. Beginners can use openFrameworks to learn about common programming patterns, and advanced users will be able to apply their experience from other languages and toolkits.
-->

openFrameworks は一貫性があり直感的です。これは最小の驚きの原則によって運営されており、openFrameworks のあるパートで学んだことは別のパートでも適用可能です。初学者は openFrameworks をよくあるプログラミングのパターンについて学ぶことに使い、上級者は他の言語やツールキットでの経験を適用することができるでしょう。

<!--
Students first is the motto. A lot of the thinking guiding openFrameworks is: what would I have liked in a tool 5 or 10 years ago? We want the patterns of coding to be simple and to make it as easy as possible to type. This means having self-explanatory function names like "play" and "stop" for video players, and variable names that are intuitive. We have lots of discussions about intuition, driven by a desire to make the code as straightforward as possible. You should learn by typing, autocomplete should be helpful, etc.
-->

学生ファーストであることがモットーです。openFrameworks を導く上で多く考えることは、私が 5 年あるいは 10 年前だったらどんなツールを好んだろうか？コーディングのパターンはできる限りシンプルでタイピングしやすいものにしたいです。これは動画のプレーヤにおいては "play" や "stop" といった自己言及的な関数名や直感的な変数名を持つことを意味します。直感的であることについては私たちは数多くの議論をしていますが、これはコードを出来るだけ素直な物にしたいという要求によるものです。タイプすることによって学んだり、オートコンプリート機能は使えるべきである、などです。

<!--
### Cross-platform
-->

### クロスプラットフォームであること

<!--
openFrameworks is a cross-platform toolkit. openFrameworks supports as many development environments and operating systems as possible. When you download openFrameworks, you can pick your platform and development environment of choice, and have projects and examples ready to learn from and play with. Difficult-to-port code is kept out of the core, and kept in addons instead.
-->

openFrameworks はクロスプラットフォームなツールキットです。openFrameworks は可能な限り多くの開発環境や OS をサポートします。openFrameworks をダウンロードをする際には任意のプラットフォームや開発環境を選ぶことができ、学んだりそれで遊んだりできるプロジェクトやサンプルを入手できます。移植が困難なコードはコアの部分からは取り除かれ、代わりにアドオンの中に置かれます。

<!--
openFrameworks is designed to work on a multitude of platforms: OS X, Windows, Linux, iOS, Android, embedded ARM Linux systems, as well as experimental platforms such as BlackBerry PlayBook. openFrameworks developers have devised some clever ways of interfacing with other languages, such as Java in the case of Android, or Objective-C in the case of iOS.
-->

openFrameworks は多くのプラットフォーム：OS X、 Windows、 Linux、 Android、 組み込みの ARM Linux システム、Blackberry PlayBook のような実験的なプラットフォームの上でも動作します。openFrameworks の開発者は Android の場合には Java、iOS の場合には Objective-C といった他の言語と接続する上手な方法も考案しています。

<!--
The joy of a cross-platform library is that it's easy to port your ideas from platform to platform. You can sketch on your laptop then immediately run it on your phone. It allows your ideas to come first, without worrying about the grunt work in making something work across platforms.
-->

クロスプラットフォームなライブラリの良い点は、あなたのアイデアをプラットフォームをまたいで移植することが簡単なことです。ラップトップ上でスケッチし、即座に電話機上で実行できます。プラットフォームをまたいで動作させるための退屈な仕事の心配をせず、アイデアを最優先にできるのです。

<!--
### Powerful
-->

### パワフルさ

<!--
openFrameworks is powerful: it allows you to leverage advanced libraries like [OpenCV](http://opencv.org/ "OpenCV, a library for (real-time) computer vision"), use hardware like your graphics card efficiently, and connect peripherals like cameras and other devices.
-->

openFrameworks はパワフルです。[OpenCV](http://opencv.org/ "OpenCV, a library for (real-time) computer vision")のような高度なライブラリを利用したり、グラフィックカードのようなハードウエアを効果的に使ったり、カメラやその他のデバイスといった周辺機器を接続することができます。

<!--
We chose C++ because it's a fairly low level language but can still be programmed in a high level way. Because C++ is an extension of the older C programming language, it's possible to write very low level, oldschool C code or higher level C++ code. In openFrameworks, we try to harness both approaches and present simple, clear, yet powerful ways of working with code. Using C++ also makes it easier to interface to the many libraries that have been written in C and C++ without needing to rely on a wrapper for another language.
-->

私たちが C++ を選択したのは、それがかなり低レベルな言語でありながら高レベルなやり方でプログラムすることが可能だからです。C++ はより古い C 言語の拡張なので、とても低レベルでオールドスクールな C コードや、より高レベルな C++ コードを記述できます。openFrameworks では私たちは両方のアプローチを使い、シンプル、明瞭でありながらパワフルなコードとの関わりを提示します。C++ を利用することはまた、他の言語のラッパに依存することなく C や C++ で書かれた沢山のライブラリと接続することを容易にしています。

<!--
openFrameworks essentially wraps other libraries such as OpenGL, [Cairo](http://cairographics.org/ "Cairo, a vector graphics library"), [FreeType](http://freetype.org/ "FreeType, a software library to render fonts"), [FreeImage](http://freeimage.sourceforge.net/ "FreeImage, a library to work with common computer graphic image formats"), and OpenCV. You can think of openFrameworks as a layer of code between user code (the code you will write) and these libraries. The libraries have different styles, idioms, approaches, etc. and our job is to wrap them in a way which makes them more consistent and intuitive.
-->

openFramewoks は基本として OpenGL や [Cairo](http://cairographics.org/ "Cairo, a vector graphics library")、[FreeType](http://freetype.org/ "FreeType, a software library to render fonts")、[FreeImage](http://freeimage.sourceforge.net/ "FreeImage, a library to work with common computer graphic image formats")、OpenCV といったライブラリをラップしています。openFrameworks はユーザーコード（あなたが記述するコード）とこれらのライブラリの間にある層として考えることができます。これらのライブラリには異なるスタイルやイディオムやアプローチがあります。そして私たちの仕事はそれらをラップして、一貫性があり直感的なものとすることです。

<!-- ### Extensible -->

### 拡張可能性

<!--
openFrameworks is extensible. When you find something missing from openFrameworks it's easy to create addons that extend it. The core addons for openFrameworks generally wrap libraries rather than solving problems in novel ways. When openFrameworks wraps libraries, the libraries are left exposed for further hacking.
-->

openFrameworks は拡張可能です。もし openFrameworks に足りない物を見つけた場合、簡単に拡張するアドオンを作成できます。openFrameworks の中核のアドオンは斬新な方法で問題を解決するというよりは、概してライブラリをラップしています。openFrameworks はライブラリをラップしていますが、それらのライブラリはさらなるハックのために外部に露出されたままです。

<!--
One mental image of openFrameworks is a scaffolding, or shoulders to stand on, while building what you want. One thing that helps keep the core light is that rather than try to include everything we can, openFrameworks has an "addon" system that allows for additional code, libraries, and approaches to be shared between users and woven into projects as necessary.
-->

あなたが望むものを構築する際の openFrameworks の概念の一つは足場、もしくは足がかりとなる肩です。中核部分を軽量に保つことができるよう、 openFrameworks では全てのものをできるだけ同梱しようとする代わりに「アドオン」のシステムを持っていて、追加のコード、ライブラリ、アプローチがユーザー間で共有され、必要に応じてプロジェクトに組み込むことができるのです。

<!--
An openFrameworks addon can be a snippet of code, or it might wrap much more complex libraries such as OpenNI, Tesseract, or Box2d. Addon names usually begin with the prefix "ofx", allowing you to easily see the difference between "core" code and non core code. In addition, we include "core addons", addons that we think people will probably want to use, such as ofxOpenCv, but aren't essential for every project.
-->

openFrameworks のアドオンはコードのスニペットでも良いし、またはもっと複雑な OpenNI、Tesseract、Box2D のようなライブラリをラップしているかもしれません。アドオンの名前は通常 "ofx" という接頭辞から始まり、「中核」のコードと非中核のコードを容易に区別できます。加えて私たちは、例えば ofxOpenCv のように、皆がおそらく利用したいが全てのプロジェクトでは必須でないようなアドオンを「コアアドオン」として同梱しています。

<!--
We try to organize and support the community developing addons through the [http://ofxaddons.com](http://ofxaddons.com "ofxaddons, a collection of oF addons") site, which automatically collects addons from GitHub by looking for repos that contain the term "ofx" in the title. Right now there are more than 1,500 addons.
-->

私たちは、[http://ofxaddons.com](http://ofxaddons.com "ofxaddons, a collection of oF addons") というサイトを通じてアドオンを開発するコミュニテイを整え支援しています。これは Github 上からタイトルに "ofx" という語彙を含むレポジトリを探すことで自動的にアドオンを収集しています。

<!--
### Do it with others (DIWO)
-->

### 皆でやろう (Do it with others / DIWO)

<!--
The driving philosophy behind openFrameworks is "do it with others" (DIWO). We love do it yourself (DIY) culture, which has been heavily promoted and facilitated by the rise of tutorial website like Instructables or Make. But we're also excited about the idea of "making socially" ("with others"). We practice DIWO through workshops, developer conferences, hackathons/labs, knitting circles and meetups in person, and online in the form of mailing lists, forum posts, and so on. We even have a gang sign. Because if you have a gang, you have to have a gang sign. The most important thing we want to stress is that you are not alone, that there's a great group of people out there learning, teaching, hacking, making and exploring the creative side of code.
-->

openFrameworks の背後にある強い哲学は「皆でやろう (Do it with others / DIWO)」というものです。私たちは Instructables や Make といったチュートリアルサイトの興りによって盛んに宣伝され手がけられている「自分でやろう Do it yourself (DIY) カルチャーを愛しています。しかし私たちは「ソーシャルに作る」（皆で）というアイデアにも興奮します。私たちはワークショップ、デベロッパカンファレンス、ハッカソン/ラボ、手芸サークルや個人的なミートアップ、メーリングリストやフォーラムでの投稿などのオンラインの形態を通じて DIWO を実践しています。私たちはギャングサインすら持っています。なぜなら仲間となるときにはギャングサインを持つべきだからです。私たちが強調したい最も大事な点は、あなたは独りではなく、学び、教え、ハックし、コードの創造的な側面を探求する人々による素晴らしいグループがあるということです。
