# 序文

*by [Zach Lieberman](http://thesystemis.com)*


openFrameworksは2004か2005年ごろに開始されました。私はParsons School of Designで教鞭を執っており、そして同時に、プログラムによってインタラクティブなプロジェクトを制作するアーティストとしても生計を立てていました。

私は2002年に大学院を数年早く卒業しており、そこではDirector / LingoやFlashといったコンピューターツールを利用していました。その頃はflashによる実験の全盛期でした。2002年に、私の教授であるGolan Levinが、卒業後いくつかのプロジェクトでの共同作業に誘ってくれました。彼は私にACUというC++ライブラリを紹介してくれました。これはJohn Maedaが運営しElise Co、Peter Cho、Ben Fry、Casey Reasといった学生やGolan自身も参加するMITのAesthetics and Computation Groupの元で開発されたものです。

ライブラリとしてのACUは素晴らしいものでしがが、SGIマシンのような90年代後期の技術に非常に適応されていました。これはまたオープンソースでもなく、活発にメンテナンスもされていませんでした。思いがけずBen Fryといった人々がProcessingの開発に移行しました。それはつまり私達に長い時間は残されていないということのように思えました。私達は別のコードベースに移行する必要があると考えたのです。

加えて、私は私が学生と専門的な練習として書いたコードを共有したいと真剣に考えていました。Parsonsの学部の運営組織との会話で「アートの学生はC++を学びたいとは思わないよ」と言われたことを鮮明に覚えています。私は2005年にoFを使ったクラスを開始しました。そこにはTheo Watson、Christine SugrueやEvan Rothといった、際立って面白く実験的な作品をoFで制作した学生がいて、その議論は急速に崩れ去りました。C++はコンピュータビジョン、サウンド処理、ハードウェアへのアクセスといったもののためのマシンへの低レベルアクセスだけでなく、他の人々の書いた広範なライブラリへのアクセスも提供してくれました。それは計算機の豊かな利用を可能にしてくれたのです。

Theo Watsonは2005年に私の生徒でしたが、oFチームに参加してOS Xバージョンの開発を助けてくれました。初期には、openFrameworksは"join the mailing list"という暗号めいたフロントページのもとで公開していて、oFのドキュメントのある単一の静的なHTMLページをTheoと私で書いていました。それは広く公開されているというものでもありませんでしたが、oFを使い始めてくれた小さく献身的な集団を持つことができました。最初の公式なリリースがいつだったのか全く定かではありませんが、私はopenFrameworksをbeta状態のような形で2006年のOFFFフェスティバルでプレゼンテーションしたことをよく覚えています。その場で私達は上級のprocessingワークショップを倉庫の中で行っていました。そのワークショップの参加者の一人であるArturo CastroはoFチームに参加してLinuxバージョンの開発を助けてくれました。Theo、Arturoそして私にoFを利用する多くの人間が加わって、これに対する貢献をしてくれるようになりました。

私はプログラムやいかなるツールにおいても最も大事なものの一つは喜びであると考えており、私はTheoとArturoとの仕事での喜びは表現しきれません。奇妙なOSの性質についてジョークを言ったり、深夜のSkype通話で困難な問題を解明したりしました。私はoFの強みの一つは、物を作り、彼らが学んだことを共有することが好きな、本当に思いやりがあって頼れる人々を惹きつけていることだと考えています。

2008年には、Ars Electronicaでの賞を獲得してoF labという研究所を設立し、これまでリモートで作業してきた我々の多くが、初めて頻繁に顔を合わせて仕事をできるようになりました。これが、コミュニティの成長を支えた数多くのワールドワイドな会議、ラボ、ワークショップ、カンファレンスといったものの最初でした。その年私達はoFワークショップを日本のYCAMで行い、世界中にこのツールを利用する人々のコミュニティがあることを知ることができました。これは私達が考えていたよりもずっとグローバルなものでした。同時に、勇気付けられるとともに少し恐ろしいことでもありますが、世界中にこのツールを使うことによって生活している人々がいることも認識しました。

私達がこれらのイベントでThe Studio for Creative Inquiry、V&A museum、YCAM、Imal、Ars ElectronicaやEyebeamといった素晴らしい団体と働くことができ、oFコミュニティを結びつけるイベントを支援していただけたことは幸運なことでした。

近年では、コミュニティを成長、拡大させることに取り組んでいます。Caitlin Morrisがコミュニティの詳細な調査を行い、Kyle McDonaldといった人々が開発者の多様な興味関心をまとめ上げてフォーカスを保っています。Greg BorensteinとJames GeorgeはofxAddons.com立ち上げを支援しました。これはコミュニティが日々作っている驚くほど数多くのアドオンをオーガナイズするオンライン上のレポジトリです。加えて、今ではoFの開発にセクションリーダーも存在します。彼らはコードベースのそれぞれの部分の成長を助け、モダンなoFがどのようなものか想像することを助けています。最後に、oFにはコードベース、ドキュメント、サンプル、アドオンやフォーラムでの質問に回答してくれる数え切れない数のコントリビュータたちがいます。

何よりも、プログラミングは無愛想で、ある意味で孤独な活動になりえるのですが、私達はできる限りフレンドリーな雰囲気を作り出そうとしています。私達は芸術制作活動を人間性のための研究所またはR&D（研究開発）であるという考えを広めていて、oFは実験を共に拡大し共有することのできる巨大な研究所を作るための試みの一つなのです。今日では制作を通して共有するというカルチャーを広めるMake MagazineやInstructablesなどをはじめとした、DIY (Do it Yourself、自分でやろう) カルチャーの大きなムーブメントがあります。私達はDIWO (Do it With Others、皆んなでやろう) の熱心なファンで、これをできるだけオンラインそしてオフラインで行っています。幸運にも、なんとか私達は、これに参加してくれる最も素晴らしく、頼りになり、親切で、愛すべき人々を惹きつけることができています。もしあなたがまだそうでないのであるならば**ようこそ**と言いたいです。


## このブックについて

このブックは、openFrameworksの精神のもとコミュニティによって推進されており、その**多くが作業中**です。これはopenFrameworks開発者のメーリングリストでの提案によって開始され、過去数カ月にわたって突貫で作業してきました。

いくつかの注記

* フィードバックはおおいに歓迎です。何か欠けているものや、入れた方が良さそうなものを知りたいと考えています。同様に、なにか役に立つことを見つけたら、それも教えていただきたいです！githubレポジトリはアクティブで、issueやpull requestを受け付けています。
* おそらくギャップがあるだろうことも付け加えます。私達はスキルレベルに応じてラフに章立てを作りましたが、これは協働作業で書かれているブックなので、やや一貫性がなかったり、章も長い、または短かったりするでしょう。これは最初から最後まで読むような本ではなく、むしろコミュニティによる短いチュートリアル州のようなものと考えてください。

*注記がある場合を除き、全ての章のライセンスは：[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US)*

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>


## クレジット

このプロジェクトをオーガナイズしてくれているRachel Uwa、編集のTega Brain、デザインディレクションのIshac BertranそしてAndy Clymer、あとはブックを生成するコードベースを開発してくれたArturo Castro、Christoph BuchnerそしてMichael Hadleyには感謝しきれません。
加えて、以下の著者と編集者がこのブックに貢献してくれました：Rui Pereira, Arturo Castro, Brannon Dorsey, Zach Lieberman, Kayla Lewis, Josh Nimoy, Phoenix Perry, Jane Friedhoff, Caitlin Morris, Pierre Proske, Golan Levin, Blair Neal, Michael Hadley, Abraham Avnisan, Christopher Baker, Lukasz Karluk, Omer Shapira, Mimi Son & Elliot Woods (Kimchi and Chips), Eva Schindling, Pierre Thirion, Joel Gethin Lewis, Roy Macdonald, Adam Carlucci, Christoph Buchner, tpltnt そしてフィードバックをくれて、pull requestを送り、アドバイスをしてくれるなどした数え切れない方々。

もしopenFrameworks（そしてオープンソース一般）を形作っているモットーが一つだけあるとするならば、それは：

*共にあるからより良く知ることができる*

