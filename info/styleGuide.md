# Style guide #

Now that we are generating the book, we should make sure we are all are using a consistent formatting.

## file hierarchy ##

Your chapter should be stored within the repository like this:

- ofBook
    - Chapters
        - Chapter_Name
            - chapter.md
            - images/ (if you have images)
            - code/ (if you have code)

Note: your chapter should actually be called `chapter.md`.  Images should not be fetched from the web - they should be uploaded to the images/ directory.

## header tags ##

Use the header tag hierarchy for your chapter.  The top level header (`#`) should be your chapter title (i.e. once per chapter), the next header level (`##`) should be sections of your chapter, etc.  This is important for the table of contents and for the web and pdf formatting of the book.  Header tags will make linking to a specific section of a chapter awesome and fun, and it will make the text easier to read.  As a general practice, your outline can become the header tag structure. 

Please consider liberal and judicious use of the header tag.  Take a look at the pro git book as a reference.  Here is a good example: [rendered markdown version](https://github.com/progit/progit/blob/master/en/02-git-basics/01-chapter2.markdown) and [raw markdown version](https://raw2.github.com/progit/progit/master/en/02-git-basics/01-chapter2.markdown).  You'll want to consider how often and what level of tag to give, the pro-git book does a good job of giving some guidance there.  We should use it as a reference.

## code ##

Use fenced code markdown styling for code.  Use 4 spaces in place of tabs for indenting your code.

Code lines should not exceed 70 characters.

```cpp
    float minArea = 1000000;
        float minIndex = -1;
        for (int i = 1; i < indices.size()-1; i++){
            float area = triArea( indices[i-1].pos, indices[i].pos, indices[i+1].pos);
            if (area < minArea){
                minArea = area;
                minIndex = i;
            }
        }
```
        
and use backticks ( \` ) for inline code like `printf()`

## images ##

Use the following format:

`![Caption](images/pathToImage.png "Optional Title")`

The caption is what is used by the book rendering pipeline to generate a caption for each figure.

## links ##

Please use inline links and add titles to the links for more details explanation (helps for accessibility).  Don't repeat the link text in the title. 

for example this: 

`[ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons")`

produces this: 

> be sure to check out [ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons") 

Please also consider how you might want to link to other parts of the text.  Since those link might not make sense now, feel free to add a comment or note about where you might want to link to **[note: link to eva's chapter]** 

## newlines ##

Between paragraphs include one empty line of whitespace, as per the markdown spec. 

Feel free to experiment with newlines in a paragraph. If it makes sense for you, you can write your paragraphs with a newline after every sentence.  Be careful to not have whitespace after the period, since two whitespaces get turned into a `<\br> tag. for example: 

	Feel free to experiment with newlines.
	If it makes sense, you can write your paragraphs with a newline after every sentence.
	Be careful to not have whitespaces after the period, since two write spaces get turned into a `<\br> tag. 
	for example: 

The benefits of this is that it makes github changes significantly easier to read, and will help you identify long sentences.  The drawbacks is that it might be less intuitive to write and read.  Do what feels right. 

## non markdown / extensions ##

If you have a specific need, such as latex equations, use a simply available tool (and common format) and write a note at the top of your chapter.  Omer's math chapter is a good example, to view the equations you need to use stackedit.io.  In general try to use as minimal a deviation from vanilla markdown as possible. 

## comments /annotation for graphics ##

If you have annotations for people involved in this book (*but not the reader/end user*), please use HTML comments. They start with a `<--` and end with `-->`.
```html
<!-- This is an comment example which can not be read by the reader of the book -->
```

## chapter length ##

This book currently aims at 20-25 pages per chapter. This includes images and code snippets.
(See [issue 38](https://github.com/openframeworks/ofBook/issues/38) for discussion reference)

## mentioning openFrameworks ##
In general you should spell out "openFrameworks". If you feel the need to abbreviate it, please use "oF".
