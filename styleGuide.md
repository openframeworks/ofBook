# Style guide #


Here's some simple tips to try to keep the formatting similar across everyones chapter drafts, etc. 

## header tags ##

please consider liberal and judicious use of the header tag.  Take a look at the pro git book as a reference and example here.  See for example this: 

https://github.com/progit/progit/blob/master/en/02-git-basics/01-chapter2.markdown

and this: 

https://github.com/progit/progit/edit/master/en/02-git-basics/01-chapter2.markdown

for good refences.  You'll want to consider how often and what level of tag to give, the pro-git book does a good job of giving some guidance there.  We should use it as a reference.

Header tags will make cross linking awesome and fun, and will make the text easier to read.  As a general practice, you outline can become the header tag structure. 

## code ##

please use the github markdown for code.  indent code if it's multiline

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

Please also consider how you might want to link to other parts of the text.  Since those link might not make sense now, feel free to add a comment or note about where you might want to link to **note: link to eva's chapter** 



