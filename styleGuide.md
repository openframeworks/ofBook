# Style guide #


Here's some simple tips to try to keep the formatting similar across everyones chapter drafts, etc. 

## header tags ##

please consider liberal and judicious use of the header tag.  Take a look at the pro git book as a reference and example here.  See for example this: 

https://github.com/progit/progit/blob/master/en/02-git-basics/01-chapter2.markdown

and this: 

https://raw2.github.com/progit/progit/master/en/02-git-basics/01-chapter2.markdown

for good refences.  You'll want to consider how often and what level of tag to give, the pro-git book does a good job of giving some guidance there.  We should use it as a reference.

Header tags will make cross linking awesome and fun, and will make the text easier to read.  As a general practice, you outline can become the header tag structure. 

## code ##

please use standard markdown for code.  indent code if it's multiline

        float minArea = 1000000;
        float minIndex = -1;
        for (int i = 1; i < indices.size()-1; i++){
            float area = triArea( indices[i-1].pos, indices[i].pos, indices[i+1].pos);
            if (area < minArea){
                minArea = area;
                minIndex = i;
            }
        }
        
and use backticks ( \` ) for inline code like `printf()`

## links ##

Please use inline links and add titles to the links for more details explanation (helps for accesability).  Don't repeate the link text in the title. 

for example this: 

`[ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons")`

produces this: 

> be sure to check out [ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons") 

You don't have to include titles if you don't want.  It's just useful in some instances. 

Please also consider how you might want to link to other parts of the text.  Since those link might not make sense now, feel free to add a comment or note about where you might want to link to **[note: link to eva's chapter]** 

## notes ##

for now, let's use bold and square brackets for notes, so they are easy to spot on both the raw and rendered copy.  **[will add more here!]**.  If you are leaving a note on someone elses text, please use your initials **[zl:maybe link to this addon]**

## content ##

for your chapter, feel free to make two folders, "code" and "images" to store your assets for now.  For images, don't worry about naming, we'll standardize a figure naming scheme once chapter order is locked down.   I imagine code will also be shuffled, so that it can be in one compileable package, but it's useful for now just to have each chapter self contained.  Feel free to put other text as well in your chapter folder, and any other assets you think you might need. 

## newlines ##

Between paragraphs include one empty line of whitespace, as per the markdown spec. 

Feel free to experiment with newlines in a paragraph. If it makese sense for you, you can write your paragphs with a newline after every sentence.  Be careful to not have whitespace after the period, since two writespaces gets turned into a `<\br> tag. for example: 

	Feel free to experiment with newlines.
	If it makese sense, you can write your paragphs with a newline after every sentence.
	Be careful to not have whitespace after the period, since two writespaces gets turned into a `<\br> tag. 
	for example: 

The benifits of this is that it makes github changes significantly easier to read, and will help you identify long sentences.  The drawbacks is that it might be less intuitive to write and read.  Do what feels right. 

## non markdown / extensions ##

If you have a specific need, such as latex equations, use a simply available tool (and common format) and write a note at the top of your chapter.  Omer's math chapter is a good example, to view the equations you need to use stackedit.io.  In general try to use as minimal a deviation from vanilla markdown as possible. 


