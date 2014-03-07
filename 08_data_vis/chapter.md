<h1>Information Vis Chapter</h1>

<p>This chapter introduces some basic information visualisation techniques using OF.  
<<<<<<< HEAD
It is a very brief overview of dealing with data in OF. It overviews how to load and store datasets, useful functions for converting data and some examples of how to build basic plots.</p>

<h1>1. Intro </h1><h2>1.1 What is data/information? Some contextual background on what these terms mean. </h2><p>Computation has driven a huge increase in our capacity to collect, sort and store data. Yet our ability to perceive and understand this data remains limited by the human body’s sensory and cognitive abilities. Data visualisation aims to aid in the interpretation and presentation of data so it can be understood as information and potentially applied as knowledge. Spanning science, art, design, computation and (as some theorists argue) also philosophy , data visualisation is a way of present large and complex datasets graphically in ways that can reveal trends and patterns that might otherwise remain invisible. </p><p>Data projects can be realised in C++ and Openframeworks however at the time of writing, the community using OF for data visualisation remained relatively small compared to those using other languages and IDEs. Do you think there are any specific advantages or reasons for this. What does C++ offer over using other languages here?</p><p>This chapter introduces some basic ways to work with data and visualise datasets using OpenFrameworks. It describes common data formats and file types, and works through examples of how these can be processed to produce basic graphical outputs.</p><h2>1.2 Definition of terms and chapter structure </h2><p>Data is produced from processes of observation. It is symbols or numerical interpretations that “represent the properties of objects, events or environments” (Ackoff, 1989). Information comes from understanding and analysing the context and descriptive qualities of the data, it relates to why the data was collected. Although these terms are often used loosely and interchangeably, in the field of information science data is generally thought of as a raw material from which information is produced through analytical processes.These definitions may need to be further refined. </p><h2>1.3 Steps of visualising data </h2><p>Ben Fry is a data artist and the author of Visualizing Data (2008), a well-known text outlining data visualisation approaches for the Processing programming environment. This an excellent reference text for anyone who wishes to dive deeper into thinking and working with data visualisation techniques. In it, Fry describes seven stages for visualising data that are useful for structuring a general process of working with data. These steps are:</p><ol>
<li>Acquire:  Obtain the data, whether from a file on a disk or a source over a network.</li> <li>Parse: Provide some structure for the data’s meaning, and order it into categories. </li><li>Filter: Remove all but the data of interest. </li><li>Mine: Apply methods from statistics or data mining as a way to discern patterns or place the data in mathematical context. </li><li>Represent: Choose a basic visual model, such as a bar graph, list, or tree. </li><li>Refine: Improve the basic representation to make it clearer and more visually engaging. </li><li>Interact: Add methods for manipulating the data or controlling what features are visible. </li>
</ol><h1>2. Working with data </h1><h2>Aquire</h2><p>There is now an enormous amount of data that is available from online sources such as weather services, newspapers census records and from social media platforms. Datasets are often available in the form of files with thousands or even millions of entries and real-time data is often available via an Application Programming Interfaces (API), which is an interface, or a set of rules that define the process of how other applications can communicate with it. Every API is designed differently and therefore can be communicated with in different ways. This chapter presents both an example of visualizing a static dataset imported into OF from external files, and an example that reads data from the New York Times API in section 10.X.</p><p>When working with datasets in OF there are several different ways in which to bring data into your program. Of course you can manually enter data into an array or string however this is inconvenient for large datasets. As such data is typically brought into a program by loading the contents of an external file into OpenFrameworks and storing it in a class. However before proceeding to do this, we must parse the data.</p><h2>Parse</h2><p>Say you have downloaded some weather data from a weather service and intend to visualise it. Before you load it into OF, it is important to parse the data. This means you open the file to check its format and see that the data is tagged correctly. You should also check that each line of your data is broken up consistently across columns. This can be done in a number of ways like, printing your file out in the terminal or opening your file in a text editor or spreadsheet program and checking for inconsistencies or gaps.</p><h2>Filter</h2><p>Your dataset is likely to contain extra information not relevant to your visualisation. For example in the tab separated (.tsv) file shown in figure 1, the file has columns like station ID and latitude and longitude that are not relevant to our visualisation. As these are unchanged throughout the whole file which gives data of one location, they can be removed so that they do not inferere with the visualisation process.</p> <p>*Might need more here</p><h2>Mine</h2><p>As Fry (2008) outlines, the mining stage of visualising data involves applying statistical methods and math to your dataset to analyse patterns and trends within it. This might be as simple as identifying the minimum and maximum values so that you know the range of variation in your data. Depending on your data, you may wish to calculate an average or a median value.  </p><p>Once you have completed this step, it is now time to load and visualise your data in OF. We will return to the last three stages of Fry’s data visualisation steps following this example.</p><h1>2.1 Quick overview of some common file structures. tsv, csv, xml, json </h1><p>Data is available and stored in specific file types that have particular structures and syntax. The following file types are some of the most common forms of structuring data.</p><ul><li>CSV: comma separated values (csv) files. These can be directly imported into OF.</li><li>TSV: text files are tab separated (tsv) files. These can be directly imported into OF. </li><li>XML:  An xml document is composed of tags with values and other tags inside of them. A tag has a name, attributes, values. If a tag contains other tags they are called its children. If a tag is inside of another, the enclosing tag is called its parent. The tags next to one another are siblings.</li>
1234	<parentTagName>    <tagName attributeName="attributeValue">TagValue</tagName>    <siblingTag /></parentName> <p>Reading an XML file in OF requires the use of an OF addon called ofxXmlSettings.</p><li>JSON: JSON stands for ‘javascript object notation’. This is a human readable file that is built on two structures, a collection of name/value pairs which can be realised in OF as a struct and an ordered list of values, realised as a vector. Json files also are parsed using an OF addon called ofxJSON, see example 2.XX for how to implement this. </li></ul><h1>2.2 Loading and saving data </h1><p>Once you have parsed and mined your data, you will want to load it into your program. To do this firstly you must save the data file to your OF folder so that your program can find your data file. It must be saved in a folder called data that is located in the bin folder. FIGURE OF FILE STRUCTURE HERE</p><h2>2.2.2 ofBuffer</h2><p>Once you have done this you will load this file into your OF program using the ofBuffer class. ofBuffer will read the data into a buffer (a temporary storage for our data as we write code to restructure and process it).ofBuffer is what is known as a convenience class, and provides easy methods for reading from and writing to files. A convenience class simply means that this is a class that doesn’t do anything by itself but wraps or allows access to the functionality of a group of other classes. </p><h2>2.2.2 Buffer Functions</h2><p>ofBufferFromFile();  is a function that allows you to load your data file.</p>	ofBuffer file = ofBufferFromFile("weather.tsv");	cout << buffer.getText();<p>So here our weather tsv file has been loaded into a variable called ‘file’.</p>getFirstLine();<p>Returns all text up to the first new line (first carriage return).</p>getNextLine();<p>You need to be able to run through each line of data in the buffer. This function allows us to do this so long as the data contains the \n or \r (new line characters). We can call it with a conditional function that checks we are not at the last line so that our program knows when to leave the buffer:</p>	while (!file.isLastLine()){        	string line = file.getNextLine();	}isLastLine();<p>In the above example we also use this function to determine whether the current text is the last line in the text file. </p><h2>2.2.3 Structs? Explain here – or has this happened elsewhere?</h2><p>Structs are useful way for declaring lists of related variables with one name in a block of memory, so in this case, all the entries on each line of our data file. Each variable of a struct can then be accessed by a single pointer. For example the following defined a struct called weatherData that contains four variables. Like all declarations, structs would be declared in the h file of your program.</p>  typedef struct {        int date;    float tmax;    float tmin;    float prcp;    } weatherData;<p>Once a struct is declared, variables can be declared using it. weatherData wdata; declares a variable wdata which is a weatherdata struct.Explain typedef here?</p><h2>2.2.4 vectors</h2><p>Vectors are also an important data structure for storing lists of data in OF. In example 2.XX we define a vector of structs, where each struct is a list of variables, and each list of variables holds the values from each line of our data file.</p><h2>2.3 Conversion functions (ofSplitString, ofToString, ofToInt)</h2><p>Conversion functions enable the manipulation of each line of data in the buffer. They allow each line to be split and for parts of it to be placed into string or integer variables.</p>ofSplitString(line, “\t” );<p>This function splits a string at a specified character. It has two arguments, the first is the name of the string to be split and the second is the character at which it is to be split. (\t indicates split at a tab)</p>string ofToString(integer, value);<p>ofToString object takes a number and turns it into a string representation of that number. The first argument is the integer to be transformed and the second indicates to how many decimals places you want to use. If you do not specify the second value, then the default value used is 7. ofToInt(const string &intString);ofToInt(string);Similar to the previous, this object converts string or a string representation into an actual integer variable. ofToFloat(const string &intString);ofToFloat(string);This object converts another variable type into an a float variable. <h1>3 Time series example</h1><p>Using all these functions will allow you to load your data file and place each line into a vector as follows. In this example we are going to graph a large weather data file sourced from a NOAA weather station (REF) in New York. After we parsed and mined this data file, it will probably look something like this:</p> IN THE H FILE:<p>We define a struct called timeData which will hold the values from each line of our file.</p>typedef struct {    	int year;	float month	float day;	float hour;	float max;	float min;	float temp;} timeData;<p>We will declare a vector that will contain a list of structs, one for each line of our data file. </p>class testApp : public ofBaseApp{	public:vector < weatherData > dataPoints;};IN THE TESTAPP FILE:<p>We load the data into the buffer and then run through each line of the buffer, placing the values into the struct called data.</p>ofBuffer buffer = ofBufferFromFile(“weather.csv");   	string temp = buffer.getNextLine();       while (!buffer.isLastLine()){        string temp = buffer.getNextLine();        vector < string > values = ofSplitString(temp, ",t");        weatherData data;        data.year = ofToInt(split[0]);        data.month = ofToFloat(split[1]);        data.day = ofToFloat(split[2]);        data.hour = ofToFloat(split[3]);		   data.max = ofToFloat(split[3]);	    data.min = ofToFloat(split[3]);		   data.temp = ofToFloat(split[3]);        dataPoints.push_back(data);    }<p>To finish this example here </p><h1>4. Working with Real time data </h1><h2>4.1 APIs</h2><h1>3. Geolocated data example using a json file.</h1><h1>Further resources</h1><p>JSON validation tools like: http://jsonlint.com/ </p>References<p>Fry, B. (2008). Visualizing Data. O’Reilly Media.Ackoff, R. L. (1989). From Data to Wisdom. Journal of Applied Systems Analysis, 16, 3–9.</p>
=======
It is a very brief overview of dealing with data in OF. It overviews how to load and store datasets, useful functions for converting data and some examples of how to build basic plots.</p>

<h1>1. Intro </h1>

<h2>1.1 What is data/information? Some contextual background on what these terms mean. </h2>
<p>Computation has driven a huge increase in our capacity to collect, sort and store data. Yet our ability to perceive and understand this data remains limited by the human body’s sensory and cognitive abilities. Data visualisation aims to aid in the interpretation and presentation of data so it can be understood as information and potentially applied as knowledge. Spanning science, art, design, computation and (as some theorists argue) also philosophy , data visualisation is a way of present large and complex datasets graphically in ways that can reveal trends and patterns that might otherwise remain invisible. </p>


<p>Data projects can be realised in C++ and Openframeworks however at the time of writing, the community using OF for data visualisation remained relatively small compared to those using other languages and IDEs. Do you think there are any specific advantages or reasons for this. What does C++ offer over using other languages here?</p>


<p>This chapter introduces some basic ways to work with data and visualise datasets using OpenFrameworks. It describes common data formats and file types, and works through examples of how these can be processed to produce basic graphical outputs.</p>


<h2>1.2 Definition of terms and chapter structure </h2>
<p>Data is produced from processes of observation. It is symbols or numerical interpretations that “represent the properties of objects, events or environments” (Ackoff, 1989). Information comes from understanding and analysing the context and descriptive qualities of the data, it relates to why the data was collected. Although these terms are often used loosely and interchangeably, in the field of information science data is generally thought of as a raw material from which information is produced through analytical processes.
These definitions may need to be further refined. </p>


<h2>1.3 Steps of visualising data </h2>
<p>Ben Fry is a data artist and the author of Visualizing Data (2008), a well-known text outlining data visualisation approaches for the Processing programming environment. This an excellent reference text for anyone who wishes to dive deeper into thinking and working with data visualisation techniques. In it, Fry describes seven stages for visualising data that are useful for structuring a general process of working with data. These steps are:
</p>
<ol>
<li>Acquire:  Obtain the data, whether from a file on a disk or a source over a network.</li> 
<li>Parse: Provide some structure for the data’s meaning, and order it into categories. </li>
<li>Filter: Remove all but the data of interest. </li>
<li>Mine: Apply methods from statistics or data mining as a way to discern patterns or place the data in mathematical context. </li>
<li>Represent: Choose a basic visual model, such as a bar graph, list, or tree. </li>
<li>Refine: Improve the basic representation to make it clearer and more visually engaging. </li>
<li>Interact: Add methods for manipulating the data or controlling what features are visible. </li>
</ol>


<h1>2. Working with data </h1>
<h2>Aquire</h2>
<p>There is now an enormous amount of data that is available from online sources such as weather services, newspapers census records and from social media platforms. Datasets are often available in the form of files with thousands or even millions of entries and real-time data is often available via an Application Programming Interfaces (API), which is an interface, or a set of rules that define the process of how other applications can communicate with it. Every API is designed differently and therefore can be communicated with in different ways. This chapter presents both an example of visualizing a static dataset imported into OF from external files, and an example that reads data from the New York Times API in section 10.X.</p>


<p>When working with datasets in OF there are several different ways in which to bring data into your program. Of course you can manually enter data into an array or string however this is inconvenient for large datasets. As such data is typically brought into a program by loading the contents of an external file into OpenFrameworks and storing it in a class. However before proceeding to do this, we must parse the data.</p>


<h2>Parse</h2>
<p>Say you have downloaded some weather data from a weather service and intend to visualise it. Before you load it into OF, it is important to parse the data. This means you open the file to check its format and see that the data is tagged correctly. You should also check that each line of your data is broken up consistently across columns. This can be done in a number of ways like, printing your file out in the terminal or opening your file in a text editor or spreadsheet program and checking for inconsistencies or gaps.</p>


<h2>Filter</h2>
<p>Your dataset is likely to contain extra information not relevant to your visualisation. For example in the tab separated (.tsv) file shown in figure 1, the file has columns like station ID and latitude and longitude that are not relevant to our visualisation. As these are unchanged throughout the whole file which gives data of one location, they can be removed so that they do not inferere with the visualisation process.</p>

 

<p>*Might need more here</p>

<h2>Mine</h2>
<p>As Fry (2008) outlines, the mining stage of visualising data involves applying statistical methods and math to your dataset to analyse patterns and trends within it. This might be as simple as identifying the minimum and maximum values so that you know the range of variation in your data. Depending on your data, you may wish to calculate an average or a median value.  </p>

<p>Once you have completed this step, it is now time to load and visualise your data in OF. We will return to the last three stages of Fry’s data visualisation steps following this example.</p>

<h1>2.1 Quick overview of some common file structures. tsv, csv, xml, json </h1>
<p>Data is available and stored in specific file types that have particular structures and syntax. The following file types are some of the most common forms of structuring data.</p>

<ul>
<li>CSV: comma separated values (csv) files. These can be directly imported into OF.</li>
<li>TSV: text files are tab separated (tsv) files. These can be directly imported into OF. </li>
<li>XML:  An xml document is composed of tags with values and other tags inside of them. A tag has a name, attributes, values. If a tag contains other tags they are called its children. If a tag is inside of another, the enclosing tag is called its parent. The tags next to one another are siblings.</li>
1
2
3
4	<parentTagName>
    <tagName attributeName="attributeValue">TagValue</tagName>
    <siblingTag />
</parentName> 

<p>Reading an XML file in OF requires the use of an OF addon called ofxXmlSettings.</p>

<li>JSON: JSON stands for ‘javascript object notation’. This is a human readable file that is built on two structures, a collection of name/value pairs which can be realised in OF as a struct and an ordered list of values, realised as a vector. Json files also are parsed using an OF addon called ofxJSON, see example 2.XX for how to implement this. </li>
</ul>

<h1>2.2 Loading and saving data </h1>

<p>Once you have parsed and mined your data, you will want to load it into your program. To do this firstly you must save the data file to your OF folder so that your program can find your data file. It must be saved in a folder called data that is located in the bin folder. 
FIGURE OF FILE STRUCTURE HERE</p>

<h2>2.2.2 ofBuffer</h2>
<p>Once you have done this you will load this file into your OF program using the ofBuffer class. ofBuffer will read the data into a buffer (a temporary storage for our data as we write code to restructure and process it).
ofBuffer is what is known as a convenience class, and provides easy methods for reading from and writing to files. A convenience class simply means that this is a class that doesn’t do anything by itself but wraps or allows access to the functionality of a group of other classes. </p>
<h2>2.2.2 Buffer Functions</h2>
<p>ofBufferFromFile();  is a function that allows you to load your data file.</p>
	ofBuffer file = ofBufferFromFile("weather.tsv");
	cout << buffer.getText();

<p>So here our weather tsv file has been loaded into a variable called ‘file’.</p>

getFirstLine();
<p>Returns all text up to the first new line (first carriage return).</p>


getNextLine();
<p>You need to be able to run through each line of data in the buffer. This function allows us to do this so long as the data contains the \n or \r (new line characters). 
We can call it with a conditional function that checks we are not at the last line so that our program knows when to leave the buffer:</p>
	while (!file.isLastLine()){
        	string line = file.getNextLine();
	}

isLastLine();
<p>In the above example we also use this function to determine whether the current text is the last line in the text file. </p>

<h2>2.2.3 Structs? Explain here – or has this happened elsewhere?</h2>
<p>Structs are useful way for declaring lists of related variables with one name in a block of memory, so in this case, all the entries on each line of our data file. Each variable of a struct can then be accessed by a single pointer. 
For example the following defined a struct called weatherData that contains four variables. Like all declarations, structs would be declared in the h file of your program.</p>  

typedef struct {
    
    int date;
    float tmax;
    float tmin;
    float prcp;
    
} weatherData;

<p>Once a struct is declared, variables can be declared using it. 
weatherData wdata; declares a variable wdata which is a weatherdata struct.
Explain typedef here?</p>

<h2>2.2.4 vectors</h2>
<p>Vectors are also an important data structure for storing lists of data in OF. In example 2.XX we define a vector of structs, where each struct is a list of variables, and each list of variables holds the values from each line of our data file.</p>

<h2>2.3 Conversion functions (ofSplitString, ofToString, ofToInt)</h2>
<p>Conversion functions enable the manipulation of each line of data in the buffer. They allow each line to be split and for parts of it to be placed into string or integer variables.</p>

ofSplitString(line, “\t” );
<p>This function splits a string at a specified character. It has two arguments, the first is the name of the string to be split and the second is the character at which it is to be split. (\t indicates split at a tab)</p>

string ofToString(integer, value);
<p>ofToString object takes a number and turns it into a string representation of that number. The first argument is the integer to be transformed and the second indicates to how many decimals places you want to use. If you do not specify the second value, then the default value used is 7. 
ofToInt(const string &intString);
ofToInt(string);
Similar to the previous, this object converts string or a string representation into an actual integer variable. 
ofToFloat(const string &intString);
ofToFloat(string);
This object converts another variable type into an a float variable. 

<h1>3 Time series example</h1>
<p>Using all these functions will allow you to load your data file and place each line into a vector as follows. 
In this example we are going to graph a large weather data file sourced from a NOAA weather station (REF) in New York. After we parsed and mined this data file, it will probably look something like this:</p>
 
IN THE H FILE:
<p>We define a struct called timeData which will hold the values from each line of our file.</p>
typedef struct {
    
	int year;
	float month
	float day;
	float hour;
	float max;
	float min;
	float temp;

} timeData;

<p>We will declare a vector that will contain a list of structs, one for each line of our data file. </p>

class testApp : public ofBaseApp{
	public:
vector < weatherData > dataPoints;
};

IN THE TESTAPP FILE:
<p>We load the data into the buffer and then run through each line of the buffer, placing the values into the struct called data.</p>

ofBuffer buffer = ofBufferFromFile(“weather.csv");
   
	string temp = buffer.getNextLine();
   
    while (!buffer.isLastLine()){
        string temp = buffer.getNextLine();
        vector < string > values = ofSplitString(temp, ",t");
        weatherData data;
        data.year = ofToInt(split[0]);
        data.month = ofToFloat(split[1]);
        data.day = ofToFloat(split[2]);
        data.hour = ofToFloat(split[3]);
		   data.max = ofToFloat(split[3]);
	    data.min = ofToFloat(split[3]);
		   data.temp = ofToFloat(split[3]);
        dataPoints.push_back(data);
    }

<p>To finish this example here </p>

<h1>4. Working with Real time data </h1>
<h2>4.1 APIs</h2>
<h1>3. Geolocated data example using a json file.</h1>

<h1>Further resources</h1>
<p>JSON validation tools like: http://jsonlint.com/ </p>

References
<p>Fry, B. (2008). Visualizing Data. O’Reilly Media.
Ackoff, R. L. (1989). From Data to Wisdom. Journal of Applied Systems Analysis, 16, 3–9.</p>

>>>>>>> d6b3ceab4364899e3a7de19144cf3139fd794adf
