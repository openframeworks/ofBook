<!--
# C++ Language Basics
-->

# C++ 言語の基礎

_by [Jetty Nimoy](http://jtn.im)_

<!--
> The magician of the future will use mathematical formulas.
>
> **--Aleister Crowley, 1911**
-->

> 未来の魔術師は数式を用いるであろう
>
> **--アレイスター・クロウリー, 1911**

<!--
## Look Alive!
-->

## ぐずぐるするな！

<!--
This chapter introduces you to writing small computer programs using the C++ language. Although I assume very little about your previous knowledge, the literacy you gain from this chapter will directly influence your comprehension in subsequent chapters of the book, as most other topics stand on the shoulders of this one. Furthermore, the lessons herein are cumulative, meaning you can't skip one of the topics or you will get lost. If you get stuck on one of the concepts, please seek help in understanding specifically the part that did not make sense before moving on to the next topic. Following the lessons with this sort of rigor ensures that not only will you get the most out of openFrameworks, but computers in general.
-->

このチャプターでは C++ 言語を用いて小さなコンピュータプログラムを書きます。事前の知識はとても少ないことを想定していますが、その他のトピックの大部分はこれの上に立脚しますので、このチャプターから得られるリテラシーはこの本の後続のチャプターの理解に直接的に影響します。さらに、ここでのレッスンは累積的なものなので、つまりトピックを飛ばせば迷子になってしまうでしょう。一つの概念で詰まってしまった場合、次のトピックに移動する前に理解できなかったパートをはっきりと理解するための助けを求めてください。このように、ある意味厳格にレッスンを続けることで、openFrameworks だけでなくコンピュータ一般を最大限に活用できるようになるでしょう。

<!--
## Iteration
-->

## イテレーション

<!--
I did most of my drawing and painting in the mid-nineties, a high school AP art student sporting a long black ponytail of hair shaved with a step, round eyeglasses, and never an article of clothing without spill, fling, smattering, or splotch of Liquitex Basics acrylic paint. Bored out of my mind in economics class, playing with my TI-82 graphing calculator, I discovered something that flipped a light bulb on in my heart. Unlike smaller calculators around my house growing up, the TI-82 had a thick instruction manual. Amidst sections in this manual about trigonometry functions and other dry out-of-reach science, something caught my thirsty, young eye: a sexy black-on-white pyramid with smaller upside-down pyramids infinitely nested inside, shown in Figure 1.
-->

長いポニーテールに段のついた刈り上げと丸メガネを着けていて、リキテックス・ベーシックスのアクリル絵の具が飛び散り、浴び、こぼれ落ち、染みの無い衣服など着たことがなかった 90 年代の中盤の高校でのアートの AP 学生時代に私はドローイングやペインティングの多くを行いました。経済の授業に飽き飽きして TI-82 型グラフ計算機で遊んでいた時に、私は心の内に電気の灯るような物事を発見しました。生まれ育った家に転がっていた小さな計算機と違い、TI-82 には分厚い取扱説明書がありました。このマニュアルの中、三角法の関数やその他無味乾燥な手の届かない科学の章の間に、何か：図 1 に示すような、一回り小さな逆さまのピラミッドがその内側に無限にネストされているセクシーな白黒のピラミッドが、私の飢えた若き眼を奪いました。

<!--
![Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments](images/sierpinski-fractal-ti82.png "Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments")
-->

![Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments](images/sierpinski-fractal-ti82.png "Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments")

<!--
This fractal, the famous [Sierpinski triangle](https://www.wolframalpha.com/input/?i=sierpinski+triangle), accompanied about twenty-five computer instructions making up the full SIERPINS program. I looked closer at the code, seeing a few numeric operations – nothing too advanced, and most of it was commanding words, like "do this", or "if something then do another thing". I was able to key in the code from the book into the graphing calculator and run the program. At first, just a blank LCD panel. Slowly a few random pixels switched to black here and there, not really showing any pattern. After a few more seconds, the scene filled in and I could already see faint outlines of triangles. After a good long time, my calculator finally matched the picture in the book. My mind was officially blown. Certain things did not make sense. What sort of miracle of nature caused such a complex form to come from so little instruction? The screen had over six thousand pixels in it, so why is it that a mere twenty-five instructions was all it took to create this amazing, organism-like artwork? Whose artwork was it? Might I derive a new work from it? Rarely had I ever seen such a magical reward coming from so little work. I had found my new basics. I felt the need to understand the program because (I decided) it was important. I went back into the code and changed some of the numbers, then ran the program again. The screen went blank, then drew a different picture, only this time, skewed to the left, falling out of the viewport. Feeling more courageous, I attempted to change one of the English instructions, and the machine showed an error, failing to run.
-->

このフラクタル、有名な [Sierpinski triangle](https://www.wolframalpha.com/input/?i=sierpinski+triangle) には完全なシェルピンスプログラムを構成する 25 行あまりのコンピュータの命令が添えられていました。私は幾つかの数値演算も見ながらコードを仔細に調べました - 何も高度すぎることはなく、ほとんどのものは命令する言葉で、「これをせよ」や「もし何々ならば他のことをせよ」のようなものでした。私は書籍からグラフ計算機にコードを打ち込み、プログラムを実行することができました。最初はただの空白の液晶パネルです。徐々にいくつかのランダムなピクセルがあちこちで黒く切り替わりますが特に法則性は見出せません。さらに何秒かすると画面が満たされ、すでにトライアングルの輪郭がかすかに見えてきます。十分な時間が経過すると、計算機はついに書籍のものとぴったり一致しました。私の気持ちははっきりいってぶっ飛びました。明確には意味がわかりませんでした。どのような自然の神秘がこんなにわずかな命令からこのような複雑な形態を生み出すのか？画面には 6,000 ピクセルがあり、わずか 25 行の命令がこの驚くべき生物のようなアートワークを生み出すに足るのだろうか？これは誰のアートワークなのか？私は新しい作品をそこから派生しうるのか？それまで私はそれほどにごくわずかの仕事からこれほどの魔法のような報いを得られたことはほとんどありませんでした。私は新たな礎を発見しました。私はそれが重要（だと私が決めたので）プログラムを理解する必要性を感じました。私はコードに戻って数値のいくつかを変更し、プログラムをもう一度実行しました。スクリーンは空白になり、異なった画像を描きました。今回だけは左に歪み、ビューポートからはみ出してしまいました。私は勇気を出して英語の命令の一つを変更し、そしてマシンはエラーを出し、実行に失敗しました。

<!--
![Figure 2: The human loop of a programmer.](images/programmer-cycle.png "Figure 2: The human loop of a programmer.")
-->

![Figure 2: The human loop of a programmer.](images/programmer-cycle.png "Figure 2: The human loop of a programmer.")

<!--
The cycle illustrated in Figure 2 is an infinitely repeating loop that I have had a great pleasure of executing for a couple decades and I still love what I do. Each new cycle never fails to surprise me. As I pursue what it means to create a program, and what it means to create software art. The process of iteratively evolving a list of computer instructions always presents as much logical challenge as it does artistic reward. Very few of those challenges have been impossible to solve, especially with other people available to collaborate and assist, or by splitting my puzzle into smaller puzzles. If you have already written code in another environment like Processing, Javascript, or even HTML with CSS, then this first important lesson might seem too obvious.
-->

図 2 に示しているサイクルは私が何十年も実行する楽しみを感じており今なお愛している、無限に繰り返されるループです。プログラムを作成することが何を意味するのか、そしてソフトウェア芸術を創ることが何を意味するのかを追求する中で、どんな新しいサイクルも私を驚かせなかったことはありません。コンピュータ命令のリストが繰り返し進化していくプロセスは芸術的な報いであると同時にロジカルな挑戦でもあります。これらの挑戦は、特に他の皆との協働や支援を得られる時、または問題をより小さな課題に分割できるときにはほとんど解決できないということはありません。もし Processing や JavaScript、または HTML と CSS などの他の環境でコードを書いたことがあれば、この最初の大事なレッスンは明白なものかもしれません。

<!--
![Figure 3: Don't get the wrong idea.](images/profit-not.png "Figure 3: Don't get the wrong idea.")
-->

![Figure 3: Don't get the wrong idea.](images/profit-not.png "Figure 3: Don't get the wrong idea.")

<!--
For those just now familiarizing themselves with what it means to write small programs, it is important to understand the iterative nature of the code writing process. The anecdote in Figure 3 shows what this process is *not*. Rarely would you ever enter some code into the editor just once, and expect to hit compile and see your finished outcome. It is natural, and commonly accepted for programs to start small, have plenty of mistakes (bugs), and evolve slowly toward a goal of desired outcome or behavior. In fact it is so commonplace that to make the former assumption is a downright programmer's mistake. Even in older days when programs were hand-written on paper, the author still needed to eyeball the code obsessively in order to work out the mistakes; therefore the process was iterative. In learning the C++ language, I will provide tiny code examples that you will be compiling on your machine. The abnormal part is typing the code from the book into the editor, and (provided your fingers do not slip) the program magically runs. I am deliberately removing the troubleshooting experience in order to isolate the subject matter of the C++ language itself. Later on, we will tackle the commonplace task of *debugging* (fixing errors) as a topic all its own.
-->

小さなプログラムを記述することにこれから慣れ親しんでいく皆さんにとって、コードを書くプロセスにある繰り返しの性質を理解することは大切です。図 3 の挿話はこのプロセスでは「ありません」。エディタにたった一度だけコードを記述し、コンパイルを叩いて完成品を期待できることはほとんどないでしょう。小さなプログラムから始まり、多くの失敗（バグ）を持っていて、望む結果や挙動に向かってゆっくりと進化していくことは自然で、通常受け入れられています。事実、事前の推測は全くのプログラマの誤りであることはよくあることです。プログラムが紙に書かれていた昔の時代でさえも、作者は執拗にコードを睨みつけて間違いを直す必要がありました：つまりこのプロセスは反復的なものなのです。C++ 言語を学ぶにあたって、私はあなたのマシンでコンパイルできる小さなコード例を提示します。変則的な部分はこの本からエディタにコードをタイプすることですが、（あなたの指が滑らない限り）プログラムは魔法のように動作します。私はわざと問題解決の経験を除いていますが、C++ 言語そのものの問題によるものを分離するためです。後ほど、よくある「デバッグ」（エラーの修正）作業それ自体のトピックにも取り組みます。

<!--
## Compiling My First App
-->

## 最初のアプリをコンパイルする

<!--
Let us start by making the smallest, most immediate C++ program possible, then use the convenient environment to test small snippets of C++ code throughout this chapter. In order to do that, we must have a *compiler*, which is a program that translates some code into an actual runnable app, sometimes referred to as the executable file. C++ compilers are mostly free of charge to download, and in a lot of cases, open source. The apps we generate will not automatically show up in places like Apple's App store, Google Play, Steam, Ubuntu Apps Directory, or Pi Store. Instead, they are your personal, private program files and you will be responsible for manually sharing them later on. In the following chapter *oF Setup and Project Structure*, the compiler will sit on your local computer, able to run offline. For now, we will be impatient and compile some casual C++ on the web using a convenient tool by Sphere Research Labs. Please open your web browser and go to [ideone](http://ideone.com) (http://ideone.com).
-->

できる限り最も小さく、直接的な C++ プログラムから始め、その便利な環境をこのチャプターを通して C++ コードをテストするために利用しましょう。このために私たちは「コンパイラ」が必要ですが、これは何らかのコードを実行可能なアプリ、しばしば実行可能ファイルとも言われるものに翻訳します。C++ コンパイラの大部分は無料でダウンロード可能で、多くの場合がオープンソースです。私たちが生成するアプリは自動的に Apple の App Store、Google Play、Steam、Ubuntu Apps Directory や Pi Store のような場所には現れません。その代わり、それらは個人的でプライベートなプログラムであり、後から手動で共有することにあなたは責任を持っています。続くチャプターの "oF Setup and Project Structure" では、コンパイラはあなたのローカルコンピュータに存在し、オフラインで動作するでしょう。今は我慢して、Sphere Research Labs による便利なツールで 簡単な C++ を Web 上でコンパイルしましょう。ブラウザを開いて [ideone](http://ideone.com) (http://ideone.com) に行きましょう。

<!--
You will notice right away that there is an editor already containing some code, but it may be set to another language. Let's switch the language to C++14 if it is not already in that mode. Down at the bottom left of the editor, press the button just to the left of "stdin", as shown in Figure 4. The label for this button could be any number of things.
-->

<!--
![Figure 4](images/where-is-says-java.png "Figure 4")
-->

![Figure 4](images/where-is-says-java.png "Figure 4")

<!--
A menu drops down with a list of programming languages. Please choose C++14, shown in Figure 5.
-->

プログラミング言語のリストのドロップダウンメニューが開きます。図 5 に示すように C++14 を選択します。

![Figure 5](images/choose-c14.png "Figure 5")

<!--
![Figure 5](images/choose-c14.png "Figure 5")
-->

<!--
Notice that the code in the editor changed, and looks something like figure 6.
-->

エディタのコードが変化し、図 6 のようになることに注目してください。

<!--
![Figure 6](images/empty-template.png "Figure 6")
-->

![Figure 6](images/empty-template.png "Figure 6")

<!--
This is just an empty code template that does nothing, and creates no errors. The numbers in the left hand gutter indicate the line number of the code. Press the green button labeled *Run*. You will see a copy of the code,  "Success" in the comments, and the section labeled *stdin* (standard input) will be empty. *stdout* (standard output) will also be empty.
-->

これはただの空のコードの雛形で、何もせず、エラーも起きません。左手の溝の数字はコードの行数を示しています。"Run" というラベルのついた緑のボタンを押します。コメント欄にコードのコピーと "Success" が現れ、"stdin"（標準入力）とラベルのあるエリアは空っぽです。"stdout"（標準出力）も同様に空です。

<!--
### Interlude on Typography
-->

### タイポグラフィについての余談

<!--
Most fonts on the web are variable width, meaning the letters are different widths; the eye finds that comfortable to read. Fonts can also be fixed-width, meaning all the letters (even the W and the lowercase i) are the same width. Although this may look funny and quaint like a typewriter, it serves an important purpose. A fixed width font makes a block of text into a kind of game board, like chess squares or graphing paper. Computer programming code is generally presented in fixed-width typesetting, because it is a form of ASCII-art. The indentation, white space characters, and repetitive patterns are all important to preserve and easily eyeball for comparison. Every coder I know except artist Jeremy Rotsztain uses some manner of monospaced font for their code. Some typeface suggestions are Courier, Andale Mono, Monaco, Profont, Monofur, Proggy, Droid Sans Mono, Deja Vu Sans Mono, Consolas, and Inconsolata. From now on, you will see the font style switch to `this inline style` . . .
-->

Web 上の大部分のフォントは可変幅であり、つまり各文字は異なった横幅です；目には読み易いです。フォントには固定幅のものもあり、これは全ての文字（W と小文字の i でさえも）が同じ横幅です。これはタイプライターのように変わって奇妙に見えるかもしれませんが、重要な目的を担います。固定幅のフォントはテキストのブロックをゲーム版のようなもの、たとえばチェス盤や方眼紙のようなものにします。コンピュータプログラムのコードは通常固定幅の書式設定で表示されますが、これはそれがアスキーアートの様式だからです。インデント、ホワイトスペース文字、および繰り返しパターンは重要であり、保存して肉眼で比較することを容易にします。芸術家の Jeremy Rotsztain を除く私の知る全てのプログラマは彼らのコードに単一幅のフォントの何らかの様式を用いています。タイプフェイスの提案の例は Courier、Andale Mono、Monaco、Profont、Monofur、Proggy、Droid Sans Mono、Deja Vu Sans Mono、Consolas、そして Inconsolata などです。今後`このインラインスタイル` . . .

<!--
```cpp
and this style encased in a block . . .
```
-->

```cpp
nそしてこのブロック中のスタイル . . .
```

<!--
. . . and that just means you are looking at some code.
-->

. . . に、フォントスタイルが変化することに気づくでしょうが、これはあなたが何らかのコードを見ていることを意味します。

<!--
### Comments
-->

### コメント

<!--
Now please press *Edit* (Figure 7) at the top left of the code editor.
-->

さて、コードエディタの左上の _Edit_ (図 7) を押下してください。

<!--
![Figure 7](images/ideone-edit.png "Figure 7")
-->

![図7](images/ideone-edit.png "図7")

<!--
You will see a slightly different editing configuration but the same template code will still be editable at the top. We will now edit the code. Find line 5, where it says:
-->

わずかに異なる編集設定がありますが、同じテンプレートのコードが上部で編集可能になっているでしょう。今度はコードを編集してみましょう。5 行目を探すと、このようになっています：

<!--
```cpp
// your code goes here .
```
-->

```cpp
// コードをここに書きます。
```

<!--
A line beginning with a double forward slash is called a comment. You may type anything you need to in order to annotate your code in a way you understand. Sometimes it's useful to “comment out code” by placing two forward-slashes before it, because that deactivates the C++ code without deleting it. Comments in C++ can also take up multiple lines, or insert like a tag. The syntax for beginning and ending comment-mode is different. Everything between the `/* and the */` becomes a comment:
-->

2 つのスラッシュから始まる行はコメントと呼ばれます。あなたが理解できる方法で注釈をつけるために、何で記述することができます。スラッシュを 2 つ前方に置くことで"コードのコメントアウト"をすると便利なことがあります、なぜならばこれで C++ のコードを削除せずに無効化することができるからです。C++ でのコメントは複数行に渡ったり、タグのように挿入されることもできます。コメントモードの開始と終了の構文は異なります。`/* と */`の間の全てがコメントになります：

<!--
```cpp
/*
this is a multi-line comment.
still in comment mode.
*/
```
-->

```cpp
/*
これは複数行コメントです。
まだコメントモードです。
*/
```

<!--
Please delete the code on line 5 and replace it with the following statement:
-->

5 行目のコードを削除して以下の宣言に置き換えてください：

<!--
```cpp
cout << "Hello World" << endl;
```
-->

```cpp
cout << "Hello World" << endl;
```

<!--
This line of code tells the computer to say "Hello World" into an implied text-space known as *standard output* (aka. *stdout*). When writing a program, it is safe to expect *stdout* to exist. The program will be able to "print" text into it. Other times, stdout's just a window pane in your coding environment that's used for troubleshooting.
-->

このコード行は暗黙の _標準出力_ (別名 _stdout_)として知られるテキスト空間に "Hello World" と言うように命令しています。プログラムを記述するときに、_stdout_ が存在することは期待しても安全です。このプログラムはそこにテキストを"プリント"するでしょう。別の時には、ただのトラブルシューティングに使われるコーディング環境のウインドウペインとなります。

<!--
You may put almost anything between those quotes. The quoted phrase is a called a *string* of text. More specifically, it is a *c-string literal*. We will cover more on strings later in this chapter. In the code, the chunk `cout <<` part means "send the following stuff to stdout in a formatted way." The last chunk `<< endl` means "add a carriage return (end-of-line) character to the end of the hello world message." Finally, at the very end of this line of code, you see a semicolon (;).
-->

引用符の間にはほとんどどんなものでも入れることが可能です。引用されたフレーズは文章の _文字列(string)_ と呼ばれます。より厳密には、これは*C 文字列リテラル* です。ストリングについてはこの章の後ろでさらにカバーします。このコードで `cout <<` の塊のパートは「以降のものを標準出力に整形して出力せよ」という意味です。最後の `<< endl` のパートは「キャリッジリターン（行の終わり）文字を hello world メッセージの末尾に追加せよ」の意味です。最後に、このコード行の一番最後にセミコロン(;)があります。

<!--
In C++, semicolons are like a full stop or period at the end of the sentence. We must type a semicolon after each statement, and usually this is at the end of the line of code. If you forget to type that semicolon, the compile fails. Semicolons are useful because they allow multiple statements to share one line, or a single statement to occupy several lines, freeing the programmer to be flexible and expressive with one's whitespace. By adding a semicolon you ensure that the compiler does not get confused: you help it out and show it where the statement ends. When first learning C or C++, forgetting the semicolon can be an extremely common mistake, and yet it is necessary for the code to compile. Please take extra care in making sure your code statements end in semicolons.
-->

C++ では、セミコロンは文の終わりの終止符あるいはピリオドのようなものです。それぞれの宣言の最後にはセミコロンをタイプしなければならず、これは通常はコードの行の末尾にあります。もしセミコロンをタイプするのを忘れた場合、コンパイルは失敗します。セミコロンは 1 行に複数の宣言があることや、一つの宣言で複数の行を使うことを許容し、プログラマがホワイトスペースによって柔軟で表現豊かであると感じることができるために有用なものです。セミコロンを追加することで、コンパイラが混乱しないことを確実にします：あなたが手助けをして、どこで宣言が終了するかを示してあげるのです。始めて C や C++ を学ぶ際、セミコロンを忘れることはとてもよくあるミスたり得ますが、それでもこれはコードをコンパイルするために必要なものです。十二分に注意してコードの宣言はセミコロンで終了するようにしてください。

<!--
While you typed, perhaps you noticed the text became multi-colored all by itself. This convenient feature is called *syntax-coloring* (or syntax-highlighting) and can subconsciously enhance one's ability to read the code, troubleshoot malformed syntax, and assist in searching. Each tool will have its own syntax coloring system so if you wish to change the colors, please expect that it's not the same thing as a word processor, whose coloring is something you add to the document yourself. A code editor will not let me assign the font "TRON.TTF" with a glowing aqua color to *just* `endl` (which means end-of-line). Instead, I can choose a special style for a whole category of syntax, and see all parts of my code styled that way as long as it's that type of code. In this case, both `cout` and `endl` are considered keywords and so the tool colors them black. If these things show up as different colors elsewhere, please trust that it's the same code as before, since different code editors provide different syntax coloring. The entire code should now look like this:
-->

タイプすると、テキストが自動でマルチカラーに色付けされることに気づくかもしれません。この便利な機能は _シンタックスカラーリング_（またはシンタックスハイライト）と呼ばれ、コードを読んだり、変なシンタックスのトラブルシューティングや検索を支援する能力を潜在的に向上させます。ツールはそれぞれ独自のシンタックスカラーリングシステムを持っているので、もし色を変えたいと思った場合、色がドキュメントそのものに追加されるようなワープロと同じではないと考えてください。コードエディタは "TRON.TTF" フォントを光るアクアカラーを `endl` （これは行末を意味します）_だけ_ に割り当てることを許しません。代わりに、シンタックスの種類全部のために特別なスタイルを選び、それがそのタイプのコードである限りコードの全てのパーツがその方法でスタイル付けされて見ることができます。このケースでは、`cout` と `endl` の両方がキーワードと見なされるので、ツールはそれらを黒く色付けします。もしこれらが他の場所で別の色で現れた場合も、コードは以前と同じであることを信じてください。なぜなら異なるコードエディタは別のシンタックスカラーリングを提供しているからです。今はコード全体はこのように見えています：

<!--
```cpp
#include <iostream.h>
using namespace std;

int main(){
	cout << "Hello World" << endl;
	return 0;
}
```
-->

```cpp
#include <iostream.h>
using namespace std;

int main(){
	cout << "Hello World" << endl;
	return 0;
}
```

<!--
Now press the green *ideone it!* button at the bottom right corner and watch the output console, which is the bottom half of the code editor, just above that green button. You will see orange status messages saying things like “Waiting for compilation,” “Compilation,” and “Running”. Shortly after, the program will execute in the cloud and the standard output should show up on that web page. You should see the new message in Figure 8.
-->

今度は右下の角にある緑の _ideone it!_ ボタンを押下し、コードエディタの下半分、ちょうど緑のボタンの上の出力コンソールを見ましょう。 「コンパイル待ちです(Waiting for compilation）」「コンパイル（Compilation）」「実行中（Running）」というようなオレンジのステータスメッセージが表示されるでしょう。すぐ後に、プログラムはクラウド上で実行されて標準出力が Web ページに表示されます。図 8 にあるメッセージが出るでしょう。

<!--
![Figure 8](images/hello-world.png "Figure 8: Hello World appears in output window")
-->

![図8](images/hello-world.png "図8: Hello World が出力ウインドウに表示されている")

<!--
You made it this far. Now give yourself a pat on the back. You just wrote your first line of C++ code; you analyzed it, compiled it, ran it, and saw the output.
-->

ここまでやりきりました。あなた自身を褒めてください。あなたはたった今最初の C++ コードを書きました；分析し、コンパイルし、実行し、出力をご覧ください。

<!--
## Beyond Hello World
-->

## Hello World を越えて

<!--
Now that we've gotten our feet wet, let's go back and analyze the other parts of the code. The first line is an include statement:
-->

これで私たちは第一歩を踏み出しましたので、後戻りしてコードの他の部分を分析してみましょう。最初の行は include 宣言です：

<!--
```cpp
#include <iostream>
```
-->

```cpp
#include <iostream>
```

<!--
Similar to *import* in Java and CSS, `#include` is like telling the compiler to cut and paste some other useful code from a file called *iostream.h* at that position in the file, so you can depend on its code in your new code. In this case, iostream.h *provides* `cout` and `endl` as tools I can use in my code, just by typing their names. In C++, a filename ending in **.h** is called a header file, and it contains code you would include in an actual C++ implementation file, whose filename would end in **.cpp**. There are many standard headers built into C++ that provide various basic services – in fact too many to mention here. If that wasn't enough, it's also commonplace to add an external library to your project, including its headers. You may also define your own header files as part of the code you write, but the syntax is slightly different:
-->

Java や CSS での _import_ と同様、`#include` はコンパイラに _iostream.h_ というファイルから他の有用なコードをファイルのその場所にカット＆ペーストするように告げるようなものなので、あなたの新しいコードはそのコードに依存することができます。このケースでは、iostream.h は `cout` と `endl` を私のコードの中で、それらの名前をタイプするだけで利用できるツールとして _提供_ します。C++ では、**.h** で終わるファイル名はヘッダファイルと呼ばれ、これはファイル名が **.cpp** で終わる C++ の実際の実装ファイルでインクルードするであろうコードを含んでいます。標準ヘッダが C++ には沢山組み込まれて様々な基本的なサービスを提供しています - 事実、ここで挙げるには多すぎます。もしそれで十分でなければ、プロジェクトに外部のライブラリを、そのヘッダをインクルードすることで追加することはよくあることです。あなたが記述する」k〜どの一部としてヘッダファイルを定義することもできますが、構文はやや異なります：

<!--
```cpp
#include "MyCustomInclude.h"
```
-->

```cpp
#include "MyCustomInclude.h"
```

<!--
In openFrameworks, double quotes are used to include header files that are not part of the system installation.
-->

openFrameworks では、ダブルクオートはシステムのインストールの一部でないヘッダファイルをインクルードするときに使われます。

<!--
### What's with the # ?
-->

### # 付きは何?

<!--
It's a whole story, but worth understanding conceptually. The include statement is not really C++ code (notice the absence of semicolon). It is part of a completely separate compiler pass called *preprocessor*. It happens before your actual programmatic instructions are dealt with. They are like instructions for the code compiler, as opposed to instructions for the computer to run after the compile. Using a pound/hash symbol before these *preprocessor directives*, one can clearly spot them in the file, and for good reason too. They should be seen as a different language, mixed in with the real C++ code. There aren't many C++ preprocessor directives — they are mostly concerned with herding other code. Here are some you might see.
-->

これが全体像ですが、概念は理解する価値があります。include 宣言は実際には C++ コードではありません（セミコロンがないことに注目してください）。これは完全に分離されたコンパイラのパスの一部分で _プリプロセッサ_ と呼ばれます。これは実際のプログラムの命令が処理される前に行われます。これらはコンパイル後に実行されるコンピュータへの命令に対して、コードのコンパイラに対する命令のようなものです。ポンド/ハッシュ記号をこれら _プリプロセッサ命令（preprocessor directives）_ の前に使うことで、人はファイル中で明確かつ十分な理由をもって、これらを見つけることができます。これらは異なる言語が、実際の C++ コードに混ざっているように見えるでしょう。C++ プリプロセッサ命令は多くはありません - それらはほとんどその他のコードを集めることに関連します。これらのいくつかを見るでしょう。

<!--
`#define`
`#elif`
`#else`
`#endif`
`#error`
`#if`
`#ifdef`
`#include`
`#line`
`#pragma`
`#undef`
-->

`#define`
`#elif`
`#else`
`#endif`
`#error`
`#if`
`#ifdef`
`#include`
`#line`
`#pragma`
`#undef`

<!--
Let's do an experiment. In the code editor, please comment out the include directive on line 1, then run the code. To comment out the line of code, insert two adjacent forward-slashes at the beginning of the line.
-->

実験してみましょう。コードエディタで、1 行目の include 命令をコメントアウトし、コードを実行してください。コードの行をコメントアウトするには、連続した 2 つのスラッシュを行の始めに挿入します。

<!--
```cpp
//#include <iostream>
```
-->

```cpp
//#include <iostream>
```

<!--
The syntax coloring will change to all green, meaning it's now just a comment. Run the code by pressing the big green button at the bottom right, and you'll see something new in the output pane.
-->

シンタックスカラーリングが全て緑に変わって、今はこれがコメントに過ぎないことを意味します。右下にある大きな緑のボタンを押してコードを実行すると、出力ペインの何か新しい物に気づくでしょう。

<!--
```
prog.cpp: In function 'int main()':
prog.cpp:5:2: error: 'cout' was not declared in this scope
  cout << "Hello World" << endl;
  ^
prog.cpp:5:27: error: 'endl' was not declared in this scope
  cout << "Hello World" << endl;
                           ^
```
-->

```
prog.cpp: In function 'int main()':
prog.cpp:5:2: error: 'cout' was not declared in this scope
  cout << "Hello World" << endl;
  ^
prog.cpp:5:27: error: 'endl' was not declared in this scope
  cout << "Hello World" << endl;
                           ^
```

<!--
The compiler found an error and did not run the program. Instead, in an attempt to help you fix it, the compiler is showing you where it got confused. The first part, *prog.cpp*: tells you the file that contains the error. In this case, ideone.com saved your code into that default file name. Next, it says `In function 'int main()'`: file showing you the specific section of the code that contains the error, in this case, between the {curly brace} of a function called *main*. (We will talk about functions and curly braces later). On the next line, we see `prog.cpp:5:2:`. The 5 is how many lines from the top of the file, and 2 is how many characters rightward from the beginning of the line. Next, we see `error: 'cout' was not declared in this scope`. That is a message describing what it believes is wrong in the code. In this case, it's fairly correct. iostream.h is gone, and therefore no `cout` is provided to us, and so when we try to send "Hello World", the compile fails. On the next couple of lines, you see the line of code containing the fallacious `cout`, plus an extra little up-caret character on the line beneath it, and that is supposed to be an arrow pointing at a character in the code. In this case, the arrow should be sitting beneath the 'c' in `cout`. The system is showing you visually which token is at fault. A second error is shown, and this time, the compiler complains that there is no endl. Of course, we know that in order to fix the error, we need to include `<iostream.h>` so let us do that now. Please un-comment line 1 and re-run the code.
-->

コンパイラがエラーを発見し、プログラムは実行されません。代わりに、あなたがこれを修正するのを助ける為の試みとして、コンパイラはどこでわからなくなったかを示します。最初のパート、_prog.cpp_: はエラーのあるファイルを教えています。このケースでは、ideone.com がデフォルトのファイル名であなたのコードを保存しています。次に、`In function 'int main()'`:
　とありますが、エラーを含んでいる特定の部分を示していて、この例では、_main_ という関数の {中括弧} の中です。（関数と中括弧については後ほど触れます）次の行には、`prog.cpp:5:2:`とあります。5 はファイルの最初から何業あるか、そして 2 は行の始めから右方向に何文字あるかです。次に、`error: 'cout' was not declared in this scope` というものがあります。これは何がコード中でエラーと思われているかを記述しています。この例では、これはかなり正しいです。iostream.h が無くなっていて、それにより `cout` が我々に提供されておらず、したがって "Hello World" を送信しようとした時に、コンパイラが失敗しているわけです。続く 2 行には、疑わしい `cout` を含むコード行があり、そしてその下の行には小さな上向きのキャレットがあって、これはコード中の文字を指している矢印と推察できます。このケースではこの矢印は `cout` の `c` を指しています。システムはどのトークンが誤りか視覚的に示しているわけです。二つ目のエラーが表示されていて、今度はコンパイラは endl が無いと訴えています。もちろん、このエラーを修正するには `<iostream.h>` をインクルードすることを私たちは知っていますので、これをやりましょう。1 行目のコメントを解除してコードを再実行してください。

<!--
```cpp
#include <iostream>
```
-->

```cpp
#include <iostream>
```

<!--
When using openFrameworks, you have choice of tools and platforms. Each one shows you an error in a different way. Sometimes the editor will open up and highlight the code for you, placing an error talk bubble for more info. Other times, the editor will show nothing, but the compile output will show a raw error formatted similarly to the one above. While sometimes useful that we receive several errors from a compile, it can save a lot of grief if you focus on understanding and fixing the very first error that got reported. After fixing the top error, it is likely that all subsequent errors will elegantly disappear, having all been covered by your first fix.  By commenting out that single line of code at the top, we caused two errors.
-->

openFrameworks を使う際には、あなたが選択したツールとプラットフォームがあります。それぞれはエラーを異なった方法で表示します。あるものはコードを開いてハイライトし、追加情報のためのエラーのフキダシを出すでしょう。または、エディタは何も表示せず、コンパイル出力が上記に似たような生のエラーを表示するでしょう。時にコンパイラから複数のエラーを受け取ることは有用ですが、報告された最初のエラーだけを理解して修正することにフォーカスすると落胆の多くを受けずに済むでしょう。最上部のエラーを修正すると、後続のエラーは最初の修正によりカバーされて綺麗に消えてしまうことが多いです。最上部のコード 1 行をコメントアウトすることで、2 つのエラーが発生したのです。

<!--
### Namespaces at First Glance
-->

### はじめての名前空間（namespace）

<!--
Moving on to line 2, we see:
-->

2 行目には以下があります：

<!--
```cpp
using namespace std;
```
-->

```cpp
using namespace std;
```

<!--
Let's say you join a social website and it asks you to choose a username. My name is Mx. Jetty Nimoy — username might be JNIMOY. I submit the page and it returns an error, telling me that username is already taken, and I have to choose another, since my former father, Joseph Nimoy, registered before I did and he's got JNIMOY. And so I must use my middle initial T, and create a unique username, JTNIMOY. I just created and resolved a *namespace conflict*. A namespace is a group of unique names — none are identical. It's possible to have identical names, as long as they are a part of two separate namespaces. Namespaces help programmers avoid stepping on each other's toes by overwriting one another's symbols or hogging the good names. Namespaces also provide a neat and tidy organization system to help us find what we're looking for. In openFrameworks, everything starts with `of` . . . like `ofSetBackground` and `ofGraphics`. This is one technique to do namespace separation because it's less likely that any other names created by other programmers would begin with `of`. The same technique is used by OpenGL. Every name in the OpenGL API (Application Programming Interface) begins with `gl` like `glBlendFunc` and `glPopMatrix`. In C++ however, it is not necessary to have a strictly disciplined character prefix for your names, as the language provides its own namespacing syntax. In line 2, `using namespace std;` is telling the compiler that this .cpp file is going to use all the names in the `std` namespace. Spoiler-alert! those two names are `cout` and `endl`. Let us now do an experiment and comment out line 2, then run the code. What sort of error do you think the compiler will return?
-->

とある SNS に入会して、ユーザー名を選択するように言われたとしましょう。私の名前は Mx. Jetty Nimoy なので - ユーザー名は JNIMOY でしょうか。私はページを送信するとエラーが返され、私の父である Joseph Nimoy が以前に登録して彼がすでに JNIMOY を取得してしまっていたので、そのユーザー名はすでに取得されていて別のものを選択しなければならないと言われました。ですので私はミドルネームのイニシャルである T を用い、固有な JTNIMOY というユーザー名を作成します。私は _名前空間（namespace）の衝突_ を生み出し、解決しました。名前空間は固有な名前のグループで - 一つとして重複していません。同一の名前が存在することは、それらが別の 2 つの名前空間にある限りにおいて可能です。名前空間はプログラマが他人のシンボルを上書きしてしまったり、良い名前を占有するなどしてお互いに不愉快になることの無いように助けてくれます。名前空間はまた、探しているものを見つけることを助けるためのすっきりと整理された管理システムを提供しています。openFrameworks では、全て `of` から始まっています . . . `ofSetBackground` とか `ofGraphics` のような感じです。これは名前空間を分割する一つのテクニックで、なぜならば他人が作成した別の名前が `of` から始まることはあまりなさそうだからです。同じテクニックが OpenGL でも使われています。OpenGL API（Application Programming Interface）の全ての名前は `glBlendFunc` や `glPopMatrix` のように `gl` から始まっています。C++ ではしかしながら言語が名前空間の構文を提供しているため、名前に必ずしも厳密にお行儀の良い接頭辞を付ける必要はありません。2 行目では、`using namepace std;` がコンパイラにこの .cpp ファイルは全ての名前を `std` 名前空間の中で使おうとしていることを伝えています。ネタバレ注意！これらの 2 つの名前は `cout` であり `endl` です。実験として 2 行目をコメントアウトし、実行してください。コンパイラはどんなエラーを返すと思いますか？

<!--
```cpp
/* using namespace std; */
```
-->

```cpp
/* using namespace std; */
```

<!--
It's a very similar error as before, where it cannot find `cout` or `endl`, but this time, there are suggested alternatives added to the message list.
-->

前ととても似たエラーで、`cout` や `endl` が見つけられていませんが、今度は、メッセージリストに提案された選択肢が表示されています。

<!--
```
prog.cpp:5:2: note: suggested alternative:
In file included from prog.cpp:1:0:
/usr/include/c++/4.8/iostream:61:18: note:   'std::cout'
   extern ostream cout;  /// Linked to standard output
                  ^
```
-->

```
prog.cpp:5:2: note: suggested alternative:
In file included from prog.cpp:1:0:
/usr/include/c++/4.8/iostream:61:18: note:   'std::cout'
   extern ostream cout;  /// Linked to standard output
                  ^
```

<!--
The compiler says, "Hey, I searched for `cout` and I did find it in one of the namespaces included in the file. Here it is. `std::cout`" and in this case, the compiler is correct. It wants us to be *more explicit* with the way we type `cout`, so we express its namespace `std` (standard) on the left side, connected by a double colon (::). it's sort of like calling myself `Nimoy::Jetty`. Continuing our experiment, edit line 5 so that `cout` and `endl` have explicit namespaces added.
-->

コンパイラは「ねえ、`cout` を探したんだけどファイルでインクルードされている名前空間の一つから見つけたよ。これがそれさ。`std::cout`」といっていて、この例ではコンパイラは正解です。`cout` とタイプする際に _より明示的に_ することを求めていますので、それの名前空間である `std`（standard）を左側に示し、2 つのコロン（::）を続けます。これは私自身を `Nimoy::Jetty` と呼ぶようなものです。実験を続け、5 行目を編集して `cout` と `endl` に明示的な名前空間が付加されるようにしましょう。

<!--
```cpp
std::cout << "Hello World" << std::endl;
```
-->

```cpp
std::cout << "Hello World" << std::endl;
```

<!--
When you run the code, you will see it compiles just fine, and succeeds in printing "Hello World". Even though the line that says `using namespace std;` is still commented out. Now imagine you are writing a program to randomly generate lyrics of a song. Obviously, you would be using `cout` quite a bit. Having to type `std::` before all your `cout`s would get really tedious, and one of the reasons a programming language adds these features is to reduce typing. So although line 2 `using namespace std;` was not necessary, having it in place (along with other `using namespace` statements) can keep one's C++ code easy to type and read, through implied context.
-->

コードを実行すると、正常にコンパイルされて、"Hello World" とプリントすることに成功すると思います。`using namespace std;` と書いている行はコメントアウトされているのにです。歌の歌詞をランダムに生成するプログラムを書いていると想像してください。明らかに、`cout` をかなり使うと思います。全ての `cout` の前に `std::` とタイプすることはとても退屈ですし、プログラミング言語がこの機能を追加している理由の一つはタイプ量を減らすことです。ですので 2 行目の `using namespace std;` は必須では無いのですが、それが（他の `using namespace` 宣言と共に）存在することで、C++ コードを暗黙的なコンテキストによって読み書きしやすくできるのです。

<!--
Say I'm at a Scrabble party in Manhattan, and I am the only JT. People can just call me JT when it's my turn to play. However, if James Taylor (aka JT) joins us after dinner, it gets a bit confusing and we start to call the Jetties by first and last name for clarity. In C++, the same is also true. I would be `Nimoy::JT` and he would be `Taylor::JT`. It's alright to have two different `cout` names, one from the `std` namespace, and another from the `improved` namespace, as long as both are expressed with explicit namespaces; `std::cout` and `improved::cout`. In fact, the compiler will complain if you don't.
-->

私がマンハッタンでのスクラブルのパーティに居るとして、私はただの JT だけ、としましょう。人々は私のターンの時に JT とだけ呼ぶことができます。しかし、もし James Taylor（別名 JT）がディナーの後に参加した場合、少しややこしくなるので、明確にするために Jetties を姓名で呼び始めるでしょう。C++ でも同様のことが言えます。私は `Nimoy::JT` で、彼は `Taylor::JT` なのです。二つの `cout` の名前があり、一つは `std` 名前空間、もう一つは `improved` 名前空間から来ていて、双方が明示的な名前空間で `std::cout` や `improved::cout` のように示されていればそれは全く正しいです。事実、そうでなければコンパイラは不満をいうでしょう。

<!--
You will see more double-colon syntax (::) when I introduce classes.
-->

2 重コロンの構文（::）についてはクラス（class）の紹介の時にさらに見るでしょう。

<!--
## Functions
-->

## 関数

<!--
Moving on, let us take a look at line 4:
-->

続いて、4 行目を見ていきましょう：

<!--
```cpp
int main() {
```
-->

```cpp
int main() {
```

<!--
This is the first piece of code that has a beginning and an end, such that it "wraps around" another piece of code. But more importantly, a function *represents* the statements enclosed within it. The closing end of this *function* is the closing curly brace on line 7:
-->

これが初めての開始と終了を持つコード片で、ですので他のコード片を "包んで" います。しかしより大事なことは、関数はその中に入っている宣言を _代表している_ ということです。この _関数（function）_ の終了は 7 行目の閉じかっこです。

<!--
```cpp
}
```
-->

```cpp
}
```

<!--
In C++, we enclose groups of code statements inside functions, and each function can be seen as a little program inside the greater program, as in the simplified diagram in figure 9.
-->

C++ では、図 9 の単純化された図のように、関数の中にコード宣言のグループを閉じ込め、それぞれの関数はより大きなプログラムの中にある小さなプログラムのように見えます。

<!--
![Figure 9: Many Functions](images/program-anatomy.png "Figure 9. A program contains many functions, and each function contains zero or more statements.")
-->

![図9: たくさんの関数](images/program-anatomy.png "図9. プログラムにはたくさんの関数があり、それぞれの関数にはゼロ以上の宣言が含まれています。")

<!--
Each of these functions has a name by which we can call it. To call a function is to execute the code statements contained inside that function. The basic convenience in doing this is less typing, and we will talk about the other advantages later. Like a board game, a program has a starting position. More precisely, the program has an *entry-point* expected by the compiler to be there. That entry-point is a function called *main*. The code you write inside the *main* function is the first code that executes in your program, and therefore it is responsible for calling any other functions in your program. Who calls your *main* function? The operating system does! Let's break down the syntax of the main function in this demo. Again, for all you Processing coders, this is old news.
-->

これらの関数にはそれぞれ、呼び出し可能な名前がついています。関数を呼び出すとは、その関数の中に含まれているコード宣言を実行することです。基本的な利便性はタイピングが少ないことですが、その他の利点については後ほど述べましょう。ボードゲームのように、プログラムには開始地点があります。より厳密には、プログラムにはコンパイラがそこにあると期待している _エントリーポイント_ が存在します。そのエントリーポイントは _main_ と呼ばれる関数です。_main_ 関数の中に書かれたコードがプログラムの中で最初に実行されるコードであり、したがってこれはプログラム中の他のいかなる関数を呼ぶことにも責任を持ちます。誰が _main_ 関数を呼ぶのでしょうか？オペレーティングシステムです！このデモの main 関数の構文をブレークダウンしてみましょう。繰り返しますが、Processing のプログラマにとってはこれは古いニュースです。

<!--
![Figure 10: The Function](images/function-anatomy.png)
-->

![Figure 10: The Function](images/function-anatomy.png)

<!--
When defining a function, the first token is the advertised return type. Functions can optionally return a value, like an answer to a question, a solution to a problem, the result of a task, or the product of a process. In this case, *main* promises to return an `int`, or *integer* type, which is a whole number with no fraction or decimal component. Next token is the name of our function. The system expects the word "main" in all lower-case, but you will later define your own functions and we will get into naming. Next is an opening and closing parenthesis. Yes, it seems kind of strange to have it there, since there is nothing inside it. Later, we will see what goes in there — but never leave out the pair of parentheses with functions because in a certain way, that is the major hint to the human that it's a function. In fact, from now on, when I refer to a function by name. I'll suffix it with a ( ), for example `main()` when the function requires no parameter and I'll suffix it with a (...), for example `main(...)`, when the function requires one or more parameters
-->

関数を定義する際、最初のトークンは宣言された戻り値の型です。関数は値を戻すことができますが、質問に対する答え、問題に対する解法、タスクの結果、または加工処理の生産物のようなものです。このケースでは、 _main_ は分数や少数の無い数字の全体を指す `int`、または _整数値_ の一つを返すと約束しています。次のトークンは関数の名前です。システムは "main" という語は全て小文字であることを期待しますが、後ほどあなた独自の関数を定義し、名前付けに取り組みましょう。次は始めおよび終わり丸括弧です。そうですね、これには何も中に無いので、そこに存在することが奇妙に見えるかもしれません。後でここになにが入るのかを見ていきましょう - しかし関数から括弧を省くことの無いようにしてください、なぜならばある意味でこれは人間に対してこれが関数であるという主要なヒントだからです。事実、今後私は関数を名前で読んでいきます。そして例えば関数が引数を必要としない場合には `main()` のようにそれに()を付加し、関数が一つかそれ以上の引数を要求する場合には `main(...)` のようにそれに(...)を付加します。

<!--
Next, we see an opening curly bracket. Sometimes this opening curly bracket is on the same line as the preceding closing parenthesis, and other times, you will see it on its own new line. It depends on the personal style of the coder, project, or group — and both are fine. For a complete reference on different indent styles, see the Wikipedia article on Indent Style (http://en.wikipedia.org/wiki/Indent_style).
-->

続いて、始め波括弧があります。この始め波括弧はその前の終わり丸括弧と同じ行にあることもありますが、そうでない場合にはそれ自身の新規の行に書きます。これは個人的なプログラマ、プロジェクトやグループに依存しますが - どちらでも結構です。異なるインデントスタイルの完全なリファレンスについては Indent Style についての Wikipedia の記事(http://en.wikipedia.org/wiki/Indent_style)を参照してください。

<!--
In between this opening curly bracket and the closing one, we place our code statements that actually tell the computer to go do something. In this example, I only have one statement, and that is the required `return`. If you leave this out for a function whose return type is `int`, then the compiler will complain that you broke your promise to return an int. In this case, the operating system interprets a 0 as "nothing went wrong". Just for fun, see what happens when you change the 0 to a 1, and run the code.
-->

この始め波括弧と終わりの間に、私たちはコンピュータに何かをさせる具体的な命令となるコード宣言を書きます。この例では、一つの宣言だけがあり、それは必要とされている `return` です。もしこれを戻り値の型が `int` の関数において省略すると、コンパイラは整数を返すという約束をあなたが破ったとして文句を言うでしょう。このケースでは、オペレーティングシステムは 0 を「つつがなく実行された」と解釈します。面白半分、0 を 1 に変更してコードを実行し、何が起こるかご覧ください。

<!--
## Custom Functions
-->

## カスタム関数

<!--
We will now define our own function and make use of it as a word template. Type the sample code into your editor and run it.
-->

私たち自身の関数を定義して言葉のテンプレートとして使ってみましょう。サンプルコードをエディタに入力して実行してください。

<!--
```cpp
#include <iostream>
using namespace std;

void greet(string person){
	cout << "Hi there " << person << "." << endl;
}

int main() {
	greet("moon");
	greet("red balloon");
	greet("comb");
	greet("brush");
	greet("bowl full of mush");
	return 0;
}
```
-->

```cpp
#include <iostream>
using namespace std;

void greet(string person){
	cout << "Hi there " << person << "." << endl;
}

int main() {
	greet("moon");
	greet("red balloon");
	greet("comb");
	greet("brush");
	greet("bowl full of mush");
	return 0;
}
```

<!--
The output shows a familiar bedtime story.
-->

出力は馴染みの深いおとぎ話です。

<!--
```
Hi there moon.
Hi there red balloon.
Hi there comb.
Hi there brush.
Hi there bowl full of mush.
```
-->

```
Hi there moon.
Hi there red balloon.
Hi there comb.
Hi there brush.
Hi there bowl full of mush.
```

<!--
In this new code, notice the second function `greet(...)` which looks the same but different from `main()`. It has the same curly brackets to hold the code block, but the return type is different. It has the same pair of parentheses, but this time there is something inside. And what about that required return statement? The _void_ keyword is used in place of a return type when a function does not return anything. So, since `greet(...)` has a _void_ return type, the compiler will not complain should you leave out the `return`. In the parentheses, you see `string person`. This is a parameter, an input-value for the function to use. In this case, it's a bit like find-and-replace. Down in `main()`, you see I call `greet(...)` five times, and each time, I put a different string in quotes between the parentheses. Those are _arguments_.
-->

この新しいコードでは、`main()` と同じように見えて異なる `greet(...)` という 2 つ目の関数に注目してください。同じようにコードブロックを保持する波括弧がありますが、戻り値の型が異なります。同様に丸括弧のペアもありますが、何かが中にあります。必要な return 宣言についてはどうでしょうか？関数が何も返さない場合には _void_ キーワードが戻り値の型の場所に置かれます。そういうわけで、`greet(...)` は _void_ の戻り値の型を持っていますので `return` を省略してもコンパイラは文句を言わないでしょう。丸括弧の中には `string person` というのがあります。これは引数で、関数が利用する入力値です。このケースでは、検索と置換に少し似ています。`main()` を見ると、私が `greet(...)` を 5 回呼び、それぞれ引用符の中の異なった文字列を、丸括弧の中に入れています。これらが _引数_ です。

<!--
As an aside, to help in the technicality of discerning between when to call them _arguments_ and when to call them _parameters_, see this code example:
-->

余談として、いつそれらを _引数_ と呼んでいつ _パラメタ_ と呼ぶのかを専門的に区別するのを助けるために、このコード例をご覧ください：

<!--
```cpp

void myFunction(int parameter1, int parameter2){
	//todo: code
}

int main(){
	int argument1 = 4;
	int argument2 = 5;
	myFunction(argument1,argument2);
	return 0;
}

```
-->

```cpp

void myFunction(int parameter1, int parameter2){
	//todo: code
}

int main(){
	int argument1 = 4;
	int argument2 = 5;
	myFunction(argument1,argument2);
	return 0;
}

```

<!--
Getting back to the previous example, those five lines of code are all **_function calls_**. They are telling `greet(...)` to execute, and passing it the one string argument so it can do its job. That one string argument is made available to `greet(...)`'s inner code via the parameter called `person`. To see the order of how things happen, take a look at Figure 11.
-->

前の例に戻ると、これらの 5 行のコードは全て **_関数呼び出し_** でした。それらは `greet(...)` を実行するように告げ、彼らが仕事を実行できるように文字列の引数を一つ渡しました。この一つの文字列の引数が `person` というパラメタを通じて `greet(...)` 内部のコードで利用可能となっています。事が起こっている順序を知るには、図 11 をご覧ください。

<!--
![Figure 11. Function Call Flow](images/function-call.png "Figure 11. Function Call Flow")
-->

![Figure 11. Function Call Flow](images/function-call.png "Figure 11. Function Call Flow")

<!--
The colorful line in Figure 11 is the path drawn by an imaginary playback head that steps over the code as it executes. We start at the blue part and go in through the main entry-point, then encounter `greet(...)`, which is where a _jump_ happens. As the line turns green, it escapes out of `main()` temporarily so it can go follow along `greet(...)` for a while. About where the line turns yellow, you see it finished executing the containing code inside `greet(...)` and does a second jump (the return) this time going back to the previous saved place, where it continues to the next statement. The most obvious advantage we can see in this example is the reduction of complexity from that long `cout` statement to a simple call to `greet(...)`. If we must call `greet(...)` five times, having the routine _encapsulated_ into a function gives it convenience power. Let's say you wanted to change the greeting from "Good night" to "Show's over ". Rather than updating all the lines of code you cut-and-pasted, you could just edit the one function, and all the uses of the function would change their behavior along with it, in a synchronized way. Furthermore, code can grow to be pretty complex. It helps to break it down into small routines, and use those routines as your own custom building blocks when thinking about how to build the greater software. By using functions, you are liberated from the need to meticulously represent every detail of your system; therefore a function is one kind of _abstraction_ just like abstraction in art. This sort of abstraction is called _encapsulation of complexity_ because it's like taking the big complex thing and putting it inside a nice little capsule, making that big complex thing seem smaller and simpler. It's a very powerful idea — not just in code.
-->

図 11 のカラフルな線はコード上を実行に合わせて移動する想像上の再生ヘッドによって描かれる経路です。青い部分からスタートして main のエントリーポイントに入っていき、そして `greet(...)` に遭遇し、ここで _ジャンプ_ が発生します。線が緑になると、一時的に `main()` を抜けてしばらく `greet(...)` を辿っていきます。線が黄色になる頃には `greet(...)` の中に含まれるコードの実行は終わって 2 回目のジャンプ（return）が発生し、今度は先ほど保存された場所に戻って、次の宣言に続いていきます。この例で見ることができる明らかな利点は長い `cout` 宣言からシンプルな `greet(...)` の呼び出しに複雑さが削減されていることです。私たちが `greet(...)` を 5 回呼ばなければいけない場合、ルーチンを関数中に _カプセル化_ することは利便性の力を与えてくれます。あなたが挨拶を "Good night" から "Show's over " に変更するとしましょう。カット＆ペーストしたコード行の全てを更新するのではなく、たった一つの関数を変更することができてこれに関わるこの関数の利用がいっぺんに変更されるのです。さらに、コードは本当に複雑に成長します。それを小さなルーチンに分割し、それらのルーチンをカスタムの構成ブロックとして利用し、より大きなソフトウェアをどのように構築するかを考えることを助けるのです。関数を利用することで、システムの全てのディテールまで注意深く表現することから開放されます；それゆえ関数は _抽象化_ の一つの形態で、アートにおける抽象化に似ています。この種の抽象化は _複雑さのカプセル化_ と呼ばれますが、なぜならば大きく複雑なものを綺麗で小さなカプセルに入れてその大きく複雑な代物をより小さく、シンプルに見せるようなものだからです。これは - プログラミングだけでなく - 非常にパワフルなアイデアです。

<!--
## Encapsulation of Complexity
-->
## 複雑さのカプセル化

<!--
Imagine actor Laurence Fishburne wearing tinted pince-nez glasses, offering you two options that are pretty complicated to explain. On the one hand, he is willing to help you escape from the evil Matrix so that you may fulfill your destiny as the hacker hero, but it involves living life on life's terms and that is potentially painful but whatever. The story must go on and by the way, there is a pretty girl. On the other hand, he is also willing to let you forget this all happened, and mysteriously plant you back in your tiny apartment where you can go on living a lie, none the wiser. These two options are explained in the movie _The Matrix_ and then the main character is offered the choice in the form of colored pills, as a way to simplify an otherwise wordy film scenario. The two complex choices are encapsulated into a simple analogy that is much easier for movie audiences to swallow. See Figure 12.
-->
俳優のローレンス・フィッシュバーンが色付きの鼻眼鏡を着けて、とても複雑な説明の2つの選択肢をあなたに提示していると想像してください。一つには、ハッカーの英雄としての宿命を全うするためにあなたが悪しきマトリックスからの脱出を助けることを彼が望んでいるが、それは潜在的に苦痛以外の何者でもない運命と共に生きることを意味します。ともかくストーリーは続き、可愛い少女が現れます。一方では、彼はあなたが起きたこと全てを忘れてしまい、何も気づかずに不可解にも偽りの生活を送る小さなアパートにあなたを戻すことを望んでいます。この2つの選択肢は映画の _The Matrix_ で説明されていて、そうでなければ冗長になってしまうシナリオをシンプルにする手法として、主人公は選択を色付きの錠剤の形で提示されます。2つの込み入った選択肢は単純な比較にカプセル化されていて、それは映画の観客にとってずっと肚落ちしやすいものです。

<!--
![Figure 12. Red Pill and Blue Pill from The Matrix](images/red-blue-pills.png "Figure 12. Red Pill and Blue Pill from The Matrix")
-->
![Figure 12. Red Pill and Blue Pill from The Matrix](images/red-blue-pills.png "Figure 12. Red Pill and Blue Pill from The Matrix")

<!--
Rather than repeating back the entire complicated situation, Neo (the main character) needed only to swallow one of the pills. Even if it were real medicine, the idea of encapsulating complexity still applies. Most of us do not have the expertise to practice medicine in the most effective way, and so we trust physicians and pharmacologists to create just the right blend of just the right herbs and chemicals. When you swallow a pill, it is like calling that function because you have the advantage of not needing to understand the depths of the pill. You simply trust that the pill will cause an outcome. The same is true with code. Most of the time, a function was written by someone else, and if that person is a good developer, you are free to remain blissfully ignorant of their function's inner workings as long as you grasp how to properly call their function. In this way, you are the _higher-level_ coder, meaning that you simply call the function but you did not write it. Someone who creates a project in openFrameworks is sitting on the shoulders of the openFrameworks layer. openFrameworks sits on the shoulders of the OpenGL Utility Toolkit, which sits on OpenGL itself, and so on. In other words, an openFrameworks project is a _higher-level_ application of C++, a language with a reputation for _lower-level_ programming. As illustrated in Figure 13, I sometimes run into a problem when I tell people I wrote an interactive piece in C++.
-->
込み入った状況全体を繰り返すのでなく、ネオ（主人公）は単にどちらかの錠剤を飲めば良いのです。現実の薬においてさえも、複雑さをカプセルに閉じ込めるというアイデアはなお当てはまります。我々の殆どは最も効果的に医療行為を行うための専門知識を持っていないので、医者や薬学者がただ適切な薬草や化学物質の正しい配合を作ることを信じるのです。あなたが錠剤を飲み込む時、それは関数を呼ぶことに似ていて、なぜならばあなたは錠剤の奥深さを理解する必要がないという利点があるからです。あなたは単純にその錠剤が成果を出すことについて信頼します。同じことがプログラムコードにも言えます。殆どの場合、関数は他の誰かによって書かれていて、もしその人が良い開発者であるならば、あなたはそれらの関数の適切な呼び方を理解している限り、幸運にもその関数の内部的な動作からは開放されます。このように、あなたは _高レベル（higher-level）_ のプログラマで、つまりあなたが記述していない関数を単純に呼び出すことを意味します。openFrameworks でプロジェクトを作成する人は、openFrameworksの肩の上に乗っています。openFrameworksはOpenGL Utility Toolkitの肩に乗り、それはOpenGLそのものに立脚している、といった具合です。言い換えれば、openFrameworksのプロジェクトは _低レベル_ プログラミングとしての評判のあるC++の _高レベル_ アプリケーションなのです。図13に図示するように、私がインタラクティブな作品をC++で書いているというとしばしば問題が発生します。

<!--
![Figure 13. Standing on Shoulders of Giants](images/shoulders-of-giants.png "Figure 13. Standing on Shoulders of Giants")
-->
![図13. 巨人の肩に乗る](images/shoulders-of-giants.png "図13. 巨人の肩に乗る")

<!--
There are a few advantages to using C++ over the other options (mostly scripting) for your new media project. The discussion can get quite religious (read: heated) among those who know the details. If you seek to learn C++, then usually it is because you seek faster runtime performance, because C++ has more libraries that you can snap into your project, or because your mentor is working in that language. An oF project is considered higher-level because it is working with a greater encapsulation of complexity, and that is something to be proud of.
-->
新規のメディアプロジェクトにC++を利用することは、他の選択肢（ほとんどスクリプト言語）に対して幾つかの利点があります。この議論は詳しい人々の中では非常に宗教的に（もとい：白熱したものに）なり得ます。あなたがC++を学ぼうとするとき、理由はたいていより速いランタイムの性能を求めるか、あなたのプロジェクトに組み込めるライブラリがより多いか、あなたのメンターがその言語に取り組んでいるからでしょう。oFのプロジェクトは高レベルと考えられますが、これは複雑なものの入ったより大きなカプセルを扱っているからであり、これは誇れるべきものです。

<!--
## Variables (part 1)
-->
## 変数（パート1）

<!--
> A “thing” is a “think”, a unit of thought
>
> -- Alan Watts
-->
> A “thing” is a “think”, a unit of thought
> 「物体」は「考え」、思考の単位である
>
> -- アラン・ワッツ

<!--
Please enter the following program into ideone and run it.
-->
以下のプログラムをideoneに入力して実行してください。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	cout << "My friend is " << 42 << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << 42 << "." << endl;
	cout << "That number plus 1 is " << (42+1) << "." << endl;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	cout << "My friend is " << 42 << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << 42 << "." << endl;
	cout << "That number plus 1 is " << (42+1) << "." << endl;
	return 0;
}
```

<!--
The output looks like this:
-->
出力は以下のようになります。

<!--
```
My friend is 42 years old.
The answer to the life the universe and everything is 42.
That number plus 1 is 43.
```
-->
```
My friend is 42 years old.
The answer to the life the universe and everything is 42.
That number plus 1 is 43.
```

<!--
We understand from a previous lesson that stuff you put between the `<<` operators will get formatted into the `cout` object, and magically end up in the output console. Notice in the last line, I put a bit of light arithmetic (42+1) between parentheses, and it evaluated to 43. That is called an _expression_, in the mathematics sense. These three lines of code all say something about the number 42, and so they all contain a _literal_ integer. A literal value is the contents typed directly into the code; some would say "hard wired" because the value is fixed once it is compiled in with the rest.
-->
これまでのレッスンで、`<<` オペレータの間に入れたものは `cout` オブジェクトに整形されて入り、魔法のようにコンソールに出力されることを理解しました。最後の行で、括弧の中に簡単な計算（42+1）を入れ、それは43と評価されたことに注目してください。これは数学的な意味で _式（expression）_ と呼ばれます。これらの3行のコードは全て数字の42について何かを語っていますので、それらは全て _リテラル_ の整数を含んでいます。リテラルの値というのはプログラムに直接記述された内容です;コンパイルされると他の部分と値が固定されるため「ハード・ワイヤード」と呼ぶ人もいます。

<!--
If I want to change that number, I can do what I know from word processing, and "find-and-replace" the 42 to a new value. Now what if I had 100,000 particles in a 3D world. Some have 42s that need changing, but other 42s that should not be changed? Things can get both heavy and complex when you write code. The most obvious application of _variables_ is that they are a very powerful find-and-replace mechanism, but you'll see that variables are useful for more than that. So let's declare an integer at the top of the code and use it in place of the literal 42s.
-->
この数字を変更したいとすると、ワープロで知っていることは可能なので、42を新しい値に「検索と置換」します。3D空間に100,000のパーティクルがあったとしたらどうでしょう。いくつかは変化し続ける42であり、その他は変化してはいけない42だったら？プログラムを書いているとき、物事は重く複雑になり得ます。最もわかりやすい _変数_ の利用法は非常にパワフルな検索と置換のメカニズムですが、変数はそれ以上に有用です。さて、コードの最初に整数を宣言してリテラルの42の箇所で利用してみましょう。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){

	int answer = 42;

	cout << "My friend is " << answer << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << answer << "." << endl;
	cout << "That number plus 1 is " << (answer+1) << "." << endl;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){

	int answer = 42;

	cout << "My friend is " << answer << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << answer << "." << endl;
	cout << "That number plus 1 is " << (answer+1) << "." << endl;
	return 0;
}
```

<!--
Now that I am using the variable `answer`, I only need to change that one number in my code, and it will show up in all three sentences as 42. That can be more elegant than find-and-replace. Figure 18 shows the syntax explanation for declaring and initializing a variable on the same line.
-->
今度は `answer` という変数を利用していて、私はこの1つの数値をコード中で変更すれば良いだけで、それは3つ全ての文章で42として現れます。これは検索と置換よりもずっとエレガントです。図18は変数の宣言と初期化を同じ行で行う構文の説明です。

<!--
![Figure 18. Variable declaration and initialization](images/variable-declaration.png "Figure 18. Variable declaration and initialization")
-->
![図18. 変数の宣言と初期化](images/variable-declaration.png "図18. 変数の宣言と初期化")

<!--
It is also possible to declare a variable and initialize it on two separate lines. That would look like:
-->
変数の宣言と初期化を2行に分けることも可能です。それはこのようになります：

<!--
```cpp
int answer;
answer = 42;
```
-->
```cpp
int answer;
answer = 42;
```

<!--
In this case, there is a moment after you declare that variable when its answer may be unpredictable and glitchy because in C (unlike Java), fresh variables are not set to zero for free — you need to do it. If you don't, the variable can come up with unpredictable values — computer memory-garbage from the past. So, unless you intend to make glitch art, please always initialize your variable to some number upon declaring it, even if that number is zero.
-->
このケースでは、変数の宣言の後、そのanswerが予測できず不安定になる時間がありますが、これはCが（Javaと異なり）新規の変数の自動でゼロに設定されないためです - これはあなたがやる必要があります。そうしなければ、変数は予測できない値 - コンピュータのメモリのゴミ - になります。ですので、誤動作によるアートを作りたいのでない限り、変数は宣言に際してゼロであっても常に何らかの値で初期化するようにしてください

<!--
### Naming your variable
-->
### 変数の名付け

<!--
Notice the arrow below saying "must be a valid name". We invent new names to give our namespaces, functions, variables, and other constructs we define in code (classes, structs, enums, and other things I haven't taught you). The rules for defining a new identifier in code are strict in a similar way that choosing a password on a website might be.
-->
「有効な名前の必要がある」と言っている矢印に注目してください。私たちは名前空間、関数、変数やプログラムに定義する要素（まだお伝えしていないクラス、構造体、列挙型やその他の物）に与える名前を考案します。コード中に新しい識別子を定義するルールは、ウェブサイトでありがちなパスワードの選択方法に似ていて厳格です。

<!--
- Your identifier must contain only letters, numbers, and underscores.
- it cannot begin with a number, but it can certainly begin with an underscore.
- The name cannot be the same as one of the language keywords (for example, the word `void`)
-->
- 識別子は文字、数字、アンダースコアだけを含みます
- 数字からは始まれません。アンダースコアからの開始は可能です。
- 言語のキーワード（例えば `void` という語）と同じにはできません。

<!--
The following identifiers are okay.
-->
以下の識別子はOKです。

<!--
```
a
A
counter1
_x_axis
perlin_noise_frequency
_         // a single underscore is fine
___       // several underscores are fine
```
-->
```
a
A
counter1
_x_axis
perlin_noise_frequency
_         // a single underscore is fine
___       // several underscores are fine
```

<!--
Notice lowercase a is a different identifier than uppercase A. Identifiers in C++ are case-sensitive.
The following identifiers are not okay.
-->
小文字のaは大文字のAと異なる識別子なことに注意してください。C++での識別子は大文字小文字を区別します。
以下の識別子はNGです。

<!--
```cpp
1infiniteloop         // should not start with a number
transient-mark-mode   // dashes should be underscores
@jtnimoy              // should not contain an @
the locH of sprite 1  // should not contain spaces
void                  // should not be a reserved word
int                   // should not be a reserved word
```
-->
```cpp
1infiniteloop         // 数字からは開始できません
transient-mark-mode   // ダッシュはアンダースコアにします
@jtnimoy              // @マークは含められません
the locH of sprite 1  // スペースは入れられません
void                  // 予約語は使えません
int                   // 予約語は使えません
```

<!--
naming your variable `void_int`, although confusing, would not cause any compiler errors because the underscore joins the two keywords into a new identifier. Occasionally, you will find yourself running into `unqualified id` errors. Here is a list of C++ reserved keywords to avoid when naming variables. C++ needs them so that it can provide a complete programming language.
-->
変数に `void_int` と名付けるのは、ややこしいですが、アンダースコアで二つのキーワードを1つの識別子に連結しているにおで、コンパイラのエラーは起きないでしょう。まれに、`unqualified id` エラーに遭遇するかもしれません。これがC++の予約語のリストで、変数の命名時に避けるべきものです。C++には完全なプログラミング言語を提供するためにこれらが必要なのです。

<!--
```
alignas alignof and and_eq asm auto bitand bitor bool break case catch
char char16_t char32_t class compl const constexpr const_cast continue
decltype default delete do double dynamic_cast else enum explicit
export extern false final float for friend goto if inline int long
mutable namespace new noexcept not not_eq nullptr operator or or_eq
override private protected public register reinterpret_cast return
short signed sizeof static static_assert static_cast struct switch
template this thread_local throw true try typedef typeid typename
union unsigned using virtual void volatile wchar_t while xor xor_eq
```
-->
```
alignas alignof and and_eq asm auto bitand bitor bool break case catch
char char16_t char32_t class compl const constexpr const_cast continue
decltype default delete do double dynamic_cast else enum explicit
export extern false final float for friend goto if inline int long
mutable namespace new noexcept not not_eq nullptr operator or or_eq
override private protected public register reinterpret_cast return
short signed sizeof static static_assert static_cast struct switch
template this thread_local throw true try typedef typeid typename
union unsigned using virtual void volatile wchar_t while xor xor_eq
```

<!--
### Naming conventions
-->
### 命名規則

<!--
> Differences of habit and language are nothing at all if our aims are identical and our hearts are open.
>
> **--Albus Dumbledore**
-->
> 目的を同じくし、心を開くならば、習慣や言葉の違いはまったく問題にはならぬ
> 
> **--アルバス・ダンブルドア

<!--
Identifiers (variables included) are written with different styles to indicate their various properties, such as type of construct (variable, function, or class?), data type (integer or string?), scope (global or local?), level of privacy, etc. You may see some identifiers capitalized at the beginning and using `CamelCase`, while others remain all `lower_case_using_underscores_to_separate_the_words`. Global constants are found to be named with `ALL_CAPS_AND_UNDERSCORES`. Another way of doing lower-case naming is to start with a lowercase `letterThenCamelCaseFromThere`. You may also see a hybrid, like `ClassName__functionName__variable_name`. These different styles can indicate different categories of identifiers.
-->
（変数を含む）識別子は異なるスタイルで書かれていて、構成要素の種類（変数、関数やクラス？）、データ型（整数や文字列？）、スコープ（グローバルかローカル？）、プライバシーのレベルなどの様々な属性を表します。あなたはその他が全て `lower_case_using_underscores_to_separate_the_words（単語の区切りにアンダースコアを利用した小文字）` であるのに、幾つかの識別子が大文字から始まって「キャメルケース」を利用していることに気づくでしょう。グローバルな定数は `ALL_CAPS_AND_UNDERSCORES（全て大文字とアンダースコア）` の名前で見つかります。もう一つは小文字の `letterThenCamelCaseFromThere（文字から始まってそれからキャメルケース）` です。ハイブリッドもあって、 `ClassName__functionName__variable_name` のようなものです。これらの異なるスタイルで違った識別子のカテゴリを示すことができます。

<!--
More obsessively, programmers may sometimes use what is affectionately nicknamed _Hungarian Notation_, adding character badges to an identifier to say things about it but also reduce the legibility, for example `dwLightYears` and `szLastName`. Naming conventions are not set in stone, and certainly not enforced by the compiler. Collaborators generally need to agree on these subtle naming conventions so that they don't confuse one another, and it takes discipline on everyone's part to remain consistent with whatever convention was decided. The subject of naming convention in code is still a comically heated debate among developers, just like deciding which line to put the curly brace, and whether to use tabs to indent. Like a lot of things in programming, someone will always tell you you're doing it wrong. That doesn't necessarily mean you are doing it wrong.
-->
より過剰には、プログラマが親しみを込めて _ハンガリアン表記_ と呼ばれるものを使うかもしれません。これは文字のバッジを識別子に付けて、それについての何かを表現しますが、これは、例えば `dwLightYears` や `szLastName` のように可読性を下げてもしまいます。命名規則は変更できないものではなく、コンパイラによって強制されているものでもありません。共同作業者は通常これらの繊細な命名規則について合意しお互いに混乱しないようにし、全員のパートが決定されたいかなる規則に対しても首尾一貫するように、規律を用いなければいけません。コードの命名規則の話題は、どの行に波括弧を置くか、インデントにタブを使うかのように、開発者間で滑稽に白熱する議論でもあります。プログラミングの多くの事と同様に、誰かが常にあなたは間違ったやり方をしていると言うでしょう。それは必ずしもあなたが間違っていることは意味しないのです。

<!--
### Variables change
-->
### 変数の変更

<!--
We call them variables because their values _vary_ during runtime. They are most useful as a bucket where we put something (let's say water) for safe keeping. As that usually goes, we end up going back to the bucket and using some of the water, or mixing a chemical into the water, or topping up the bucket with more water, etc. A variable is like an empty bucket where you can put your stuff. Figure 19 shows a bucket from the game _Minecraft_.
-->
変数は実行中に値が _変化_ するためにそう呼ばれます。これは大抵何か（たとえば水）を保管するために入れるバケツとして有用です。通常、最終的にはバケツに戻って水を幾らか利用するか、薬品を水に混ぜるか、バケツに水を足したりします。1つの変数は空のバケツのようなものでそこに何かを入れることができます。図19は _Minecraft_ というゲームのバケツです。

<!--
![Figure 19. Bucket, courtesy of Mojang AB](images/minecraft-bucket.png "Figure 19. Bucket, courtesy of Mojang AB")
-->!
[図19. バケツ, Mojang AB 提供](images/minecraft-bucket.png "図19. バケツ, Mojang AB 提供")

<!--
If a computer program is like a little brain, then a variable is like a basic unit of remembrance. Jotting down a small note in my sketchbook is like storing a value into a variable for later use. Let's see an example of a variable changing its value.
-->
コンピュータプログラムが小さな脳とした場合、変数は記憶の記憶の基本的な単位のようなものです。スケッチブックにノートをちょっと書き留めることは後から使うために値を変数に保存するようなものです。変数がその値を変化させる例を見てみましょう。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = 1;
	cout << counter;
	counter = 2;
	cout << counter;
	counter = 3;
	cout << counter;
	counter = 4;
	cout << counter;
	counter = 5;
	cout << counter;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = 1;
	cout << counter;
	counter = 2;
	cout << counter;
	counter = 3;
	cout << counter;
	counter = 4;
	cout << counter;
	counter = 5;
	cout << counter;
	return 0;
}
```

<!--
The output should be `012345`. Notice the use of the equal sign. It is different than what we are accustomed to from arithmetic. In the traditional context, a single equal sign means the expressions on both sides would evaluate to the same value. In C, that is actually a double equal (==) and we will talk about it later. A single equal sign means "Solve the expression on the right side and store the answer into the variable named on the left side". It takes some getting used to if you haven't programmed before. If I were a beginning coder (as my inner child is perpetually), I would perhaps enjoy some alternative syntax to command the computer to store a value into a variable. Something along the lines of: `3 => counter` as found in the language _ChucK_ by Princeton sound lab, or perhaps something a bit more visual, as my repurposing of the Minecraft crafting table in figure 20.
-->
出力は `012345` となるはずです。イコールの使い方に注意してください。これは計算で慣れ親しんでいるものとは異なります。伝統的な文脈では、1つのイコールは両側の式は等価として評価されます。Cでは、それは実際には二重のイコール（==）であり、それについては後で述べます。単独のイコールは「右辺の式を評価して左辺の名前の変数に答を保存せよ」という意味です。もしこれまでプログラムをしたことがない場合には慣れるまでには少し時間が掛かるでしょう。もし私が（私の内なる子供は常にそうであるように）コーディング初心者であった場合、値を変数に保存する命令をコンピュータにするための他の文法についても恐らく楽しむことでしょう。Princeton sound lab による _Chuck_ という言語にある `3 => counter` というようなもの、あるいはもう少し視覚的に、図20に示すMinecraftの作業台の流用のようなものかもしれません。

<!--
![Figure 20. Minecraft crafting table repurposed for variable assignment](images/minechuck.png "Figure 20. Minecraft crafting table repurposed for variable assignment")
-->
![図20. 変数割り当てのために改変したMinecraft作業台](images/minechuck.png "図20. 変数割り当てのために改変したMinecraft作業台")

<!--
The usefulness of having the variable name on the left side rather than the right becomes apparent in practice since the expressions can get quite lengthy! Beginning a line with `varname =` ends up being easier for the eyeball to scan because it's guaranteed to be two symbols long before starting in on whatever madness you plan on typing after the equals sign.
-->
変数名が右でなく左側にあることの有用性は実際にはとても明白で、式はとても長くなり得るからです！行を `varname =` で開始すると目で追いやすく、イコールの後に入力しようとしているものがどんな狂気の沙汰であっても、その前はシンボル2つ分の長さであることが保証されているからです。

<!--
Analyzing the previous code example, we see the number increments by 1 each time before it is output. I am repeatedly storing literal integers into the variable. Since a programming language knows basic arithmetic, let us now try the following modification:
-->
先ほどのコード例を詳しく見ると、数字を毎回1ずつ出力前に増やしていることが分かります。私は繰り返しリテラルな整数を変数に保存しました。プログラミング言語は基本的な算術を知っているので、以下のような変更をしてみましょう：

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	return 0;
}
```

<!--
The output should still be `012345`. By saying `counter = counter + 1`, I am incrementing `counter` by 1. More specifically, I am using `counter` in the right-hand "addition" expression, and the result of that (one moment later) gets stored into `counter`. This seems a bit funny because it talks about `counter` during two different times. It reminds me of the movie series, _Back to the Future_, in which Marty McFly runs into past and future versions of himself. See Figure 21.
-->
出力は依然として `012345` です。`counter = counter + 1` とすることで、`counter` を1ずつ増加させています。より厳密には、`counter` を右側の「加算」式で利用し、その結果を（直後に）`counter` に保存しています。これは `counter` を2つの別の時に述べているので少し奇妙に見えます。これは、マーティ・マクフライが過去と未来のバージョンの彼自身に遭遇するという、映画シリーズの _バック・トゥ・ザ・フューチャー_ を思い起こしますね。

<!--
![Figure 21. The future Marty uses the past Marty](images/futuremarty.png "Figure 21. The future Marty uses the past Marty")
-->
![図21. 未来のマーティが過去のマーティを利用する](images/futuremarty.png "図21. 未来のマーティが過去のマーティを利用する")

<!--
Great Scott, that could make someone dizzy! But after doing it a few times, you'll see it doesn't get much more complicated than what you see there. This is a highly _practical_ use of science fiction, and you probably aren't attempting to challenge the fabric of spacetime (unless you are Kyle McDonald, or maybe a Haskell coder-->
<!-- i mean these things as a high compliment, not as mockery -->
<!--). The point here is to modify the contents of computer memory, so we have `counter` from one instruction ago, in the same way that there might already be water in our bucket when we go to add water to it. Figure 22 shows `bucket = bucket + water`.
-->
なんたることだ、めまいがする！しかしそれを何度か繰り返すと、見えるほどには複雑でないことが分かります。これは非常に _実践的な_ SFの利用であり、（あなたがカイル・マクドナルドかHaskellのプログラマでない限り<!--褒めているのであって、馬鹿にはしていないですよ-->）時空の構造に挑もうとしているわけではないでしょう。大事な事は、水を加えようとした時にすでにそのバケツには水が入っているであろうことと同様に、コンピュータのメモリの内容を変更するために、1命令前の `counter` を取得しているのです。`バケツ = バケツ + 水` を図22で示します。


<!--
![Figure 22. bucket = bucket + water](images/minecraft-inc.png "Figure 22. bucket = bucket + water")
-->
![図22. バケツ = バケツ + 水](images/minecraft-inc.png "図22. バケツ = バケツ + 水")

<!--
Incrementing by one, or adding some value to a variable is in fact so commonplace in all programming that there is even syntactic sugar for it. _Syntactic Sugar_ is a redundant grammar added to a programming language for reasons of convenience. It helps reduce typing, can increase comprehension or expressiveness, and (like sugar) makes the programmer happier. The following statements all add 1 to `counter`.
-->
1ずつ加算することは、または変数に何らかの値を足すことは実際あらゆるプログラミングで非常に日常茶飯事な事なので、そのための糖衣構文も存在します。_糖衣構文（シンタックスシュガー）_ とは簡単のためにプログラミング言語に追加された冗長な文法です。タイプ量を減らし、理解力や表現力を向上させ、そして（砂糖のように）プログラマを幸せにします。以下の宣言は全て `counter` に1を追加します。

<!--
```cpp
counter = counter + 1; // original form
counter += 1;          // "increment self by" useful because it's less typing.
counter++;             // "add 1 to self" useful because you don't need to type a 1.
++counter;             // same as above, but with a subtle difference.
```
-->
```cpp
counter = counter + 1; // 元の形式
counter += 1;          // 「自分に加算する」はタイプ量が少ないので便利です
counter++;             // 「自分に1を足す」は1をタイプする必要がないので便利です。
++counter;             // 上と同様ですが、わずかに違います。
```

<!--
Let's test this in the program.
-->
プログラムでテストしてみましょう。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	return 0;
}
```

<!--
Yes, it's a lot less typing, and there are many ways to make it more concise. Here is one way.
-->
やった、ずっとタイプ量が減りました。もっと完結にする方法はたくさんあります。これが1つの方法です。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	return 0;
}
```

<!--
The answer is still `012345`. The postfix incrementing operator will increment the variable even while it sits inside an expression. Now let's try the prefix version.
-->
答えは依然 `012345` です。後置の加算演算子は式の中に存在したとしても変数を加算します。今度は前置のバージョンを試してみましょう。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	return 0;
}
```

<!--
If you got the answer `123456`, that is no mistake! The prefix incrementing operator is different from its postfix sister in this very way. With `counter` initialized as 0, `++counter` would evaluate to 1, while `counter++` would still evaluate to 0 (but an incremented version of `counter` would be left over for later use). The output for the following example is `1112`.
-->
`123456` の答えが出ても、これは間違いではありません！前置の加算演算子は後置の姉妹とはまさにこの部分で異なるのです。0で初期化された `counter` に対して、`++counter` は1と評価し、`counter++` はまだ0と評価します（しかし加算されたバージョンの `counter` が後からの利用のために残ります）。以下の例の出力は `1112` です。

<!--
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter; // 1: increments before evaluating
	cout << counter;   // 1: has NOT changed.
	cout << counter++; // 1: increments after evaluating
	cout << counter;   // 2: evidence of change.
	return 0;
}
```
-->
```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter; // 1: 評価の前に加算される
	cout << counter;   // 1: 変化しません。
	cout << counter++; // 1: 評価の後に加算される
	cout << counter;   // 2: 変化した証拠です。
	return 0;
}
```

<!--
For arithmetic completeness, I should mention that the subtractive _decrementing_ operator (counter--) also exists. Also, as you might have guessed by now, if one can say `counter + 1`, then a C compiler would also recognize the other classic arithmetic like `counter - 3` (subtraction), `counter * 2` (asterisk is multiplication), `counter / 2` (division), and overriding the order of operations by using parentheses, such as `(counter + 1) / 2` evaluating to a different result than `counter + 1 / 2`. Putting a negative sign before a variable will also do the right thing and negate it, as if it were being subtracted from zero. C extends this basic palette of maths operators with boolean logic and bitwise manipulation; I will introduce them in Variables part 2.
-->
算術的な完全性のために、負の _減算_ 演算子（counter--）も存在することに触れなければいけません。そして、恐らくここまでに推測しているように、`counter + 1` と言えるならば、Cコンパイラは `counter -3`（減算）、`counter * 2` （アスタリスクは乗算です）、`counter / 2` （除法）、丸括弧を利用した演算子の順番の強制は `(counter + 1) / 2` は `counter + 1 / 2` とは違う結果と評価されるようにその他の古典的な算術を認識します。

<!--
There are a few more essentials to learn about variables, but we're going to take what we've learned so far and run with it in the name of fun. In the meantime, give yourself another pat on the back for making it this far! You learned what variables are, and how to perform basic arithmetic on them. You also learned what the ++ operator does when placed before and after a variable name.
-->
変数についてはもう少し学ぶべき基礎がありますが、とりあえずは今まで学んだ事を使って、楽しんで実行してみましょう。さしあたりは、ここまでたどり着いたことにもう一度、あなた自身を褒めてあげてください！あなたは変数の何たるか、そしてそれに基本的な算術を行うやりかたを学びました。また、++演算子が変数名の前と後に置かれたときに何をするかを学びました。

<!--
The C++ language gets its name from being the C language plus one.
-->
C++言語はC言語プラス1であることから名前が取られています。

<!--
## Conclusion
-->
## 結論

<!--
Congratulations on getting through the first few pages of this introduction to C++. With these basic concepts, you should be able to explore plenty far on your own, but I will admit that it is not enough to prepare you to comprehend the code examples in the rest of ofBook. Because of limited paper resources, what you've seen here is a "teaser" chapter for a necessarily lengthier introduction to the C++ language. That version of this chapter got so big that it is now its own book — available unabridged on the web, and possibly in the future as its own companion book alongside ofBook. Teaching the C++ language to non-programmers is indeed a large subject all itself, which could not be effectively condensed to 35 pages, let alone the 100+ page book it grew to be. If you're serious about getting into openFrameworks, I highly recommend you stop and read the unabridged version of this chapter before continuing in ofBook, so that you may understand what you are reading. You will find those materials [here](https://github.com/openframeworks/ofBook/blob/master/chapters/cplusplus_basics/unabridged.md)
-->
C++の紹介の最初の数ページを完了し、おめでとうございます。これらの基本的な概念をもってあなたは自分自身で十分遠くまで探検できるはずです、しかしofBookの残りのコード例を理解するための準備には十分でないことは認めます。紙幅の制限により、ここでみているものは十分な長さのC++言語への導入の「予告編」なのです。この章のそのバージョンはとても大きいので今ではそれ自身の書籍になっています - 完全版がWebで、将来的にはofBookの副読本として。非プログラマにC++言語を教えるためにはそれ自身で実際たくさんの科目が存在し、100ページ超の書籍に増大することは言うまでもなく、効果的に35ページに圧縮することはできません。真剣にopenFrameworksに取り組む場合、あなたが何を読んでいるのかを理解するためには、ofBookを読み進める前に立ち止まってこのチャプターの完全版を読むことを高く推奨します。資料は [こちら](https://github.com/openframeworks/ofBook/blob/master/chapters/cplusplus_basics/unabridged.md)

<!--
## PS.
-->
## 追伸

<!--
Stopping the chapter here is by no means intended to separate what is important to learn about C++ from what is not important. We have simply run out of paper. In lieu of how important the rest of this intro to C++ is, and based on ofZach's teaching experience, here is more of what you'll find in the unabridged version:
-->
章がここで終わることは、C++言語において何が重要で何が重要でないかを分けることを決して意図していません。単純に紙幅が尽きたのです。C++の導入の残りの部分の重要さの代わりに、そしてofZach氏の教育の経験に基づき、以下は完全版で見ることのできる詳細です：

<!--
- Variables exist for different periods of time - some for a long time, and some for a small blip in your program's lifecycle. This subject of _scope_ is covered in the unabridged version of this book, entitled _Variables (part 2)_.
-->
- 変数はそれぞれ異なる期間存在します - 幾つかは長い時間、幾つかはプログラムのライフサイクルでの少しの間。_スコープ_ の科目はこのブックの完全版でカバーされており、_変数（パート2）_ というタイトルです。

<!--
- Variables have a _data type_. For example, one holds a number while another holds some text. More about that in _Fundamental Types_.
-->
- 変数には _データ型_ があります。例えば、あるものは数値を保有し別のものは何らかのテキストを保有します。_基本的な型(
（Fundamental Types）_ にさらにあります。

<!--
- It's important to reiterate that unlike Processing, variables do not necessarily start with a zero value. You must initialize them with your desired value, and otherwise there's no telling what will be waiting there for you. You'll find additional discussion of this phenomenon in the introduction to arrays.
-->
- Processingとは違い、変数は必ずしもゼロ値から始まりません。望みの値で初期化する必要があり、そうでなければその先に何が待っているか分かりません。この現象についての追加の議論は配列の導入部分にあります。

<!--
> The best way to predict your future is to create it.
>
> **--Abraham Lincoln**
-->
> 未来を予測する最良の方法は、それを創り出すことだ。
> 
> **--エイブラハム・リンカーン**
