# Lab3-Maps
Maps and Sets

## Purpose
The purpose of this lab is to have some fun and maybe to also learn a little bit about how to use
implementations of lists, sets, and maps in C++’s standard libraries.

## Required Knowledge
In order to understand the solutions to this lab, you should become familiar with lists, sets, and
maps, and be able to use the the implementations of these data structures provide in C++’s standard
library. You should also be able to read and write to a file.

## Overview
Machine learning has become increasingly popular in Computer Science. To state things perhaps
too simply, in machine learning, a training set is used to determine the probability that an event
occurs given a set of inputs. In this lab, you will train a map on the words from a document and
then produce text that has the same distribution of words as the original document.

## Scoring
The lab will be scored as follows:
1. (14 points) Read the document into a set of strings and print them to a file.
2. (14 points) Read the document into a vector of strings and print them to a file.
3. (14 points) Create a map from a string (the key) to a string (the value).
4. (14 points) Generate text from this map.
5. (14 points) Generate text from a map that pairs strings (keys) to a vector of strings (values).
6. (14 points) Generate text from a map composed of a list of strings as keys and vectors of strings
as values.
7. (16 points) Explore different texts and methods, and observe when the algorithm produces
interesting things. Have a little fun. Discuss what you did in your Canvas Submission.

## Details
This lab has a different flavor than other labs for this class. Much of this lab is more of a tutorial
than a you-figure-out-the-code lab. We’ll walk you through each step. To ensure that you benefit
from this style of lab, make sure you understand the code you write. Once you have finished, zip
up your code, and submit it. Note, you must go in and pass this lab off with the TAs in person.
The rest of the document walks you through each of the steps.

### Part 1
Write a program that takes as input a command-line argument that specifies the name of a text file.
If you are reading in 1Nephi.txt, the input should be “1Nephi”. Read the file and store each word
of the file into a set (remove all punctuation – you may find the “isalpha” function to be helpful
for this). 

#### Output: 
Print the contents of the set to a new file with each string in the set appearing on a new
line. The file 1Nephi.txt provides a good input file for you to test your code on. Unless I’ve done
this incorrectly (which is possible), your output file should have close to 1690 words in it (your
word count may vary somewhat depending on how you deal with hyphens). The name of the file
should be “[filename]_set.txt”, where [filename] is the command-line input supplied by the “user.”

### Part 2
Add to your program a function that reads the file (specified from the command-line) and stores
each word of the file into a vector. (remove all punctuation – you may find the “isalpha” function
to be helpful for this).

#### Output: 
Print the contents of the vector to a new file with each string in the vector appearing on a
new line. The file 1Nephi.txt provides a good input file for you to test your code on. Unless I’ve
done this incorrectly (which is possible), your output file will have close to 25,106 words in it
(your word count may vary somewhat depending on how you deal with hyphens). The name of
the file should be “[filename]_vector.txt”, where [filename] is the command-line input supplied
by the “user.”

#### Insight: 
You should know why there are more words in the vector than in the set. If you don’t know, find out why.

### Part 3
Next, let’s do something with your vector of strings. You’ll create a map of strings to string. To
do this, for each string in your vector of strings (except the last string), create an entry in your map
that has the string as the key, and the next word in the vector as the value. For example, for the
phrase “having been born of goodly parents”, you would add the entries (key=”having”,
value=”been”), (key=”been”, value=”born”), (key=”born”, value=”of”), etc. Here is a snippet of
code that does this (make sure you understand it):
``` c++
map<string, string> wordmap;
string last="";
for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
  wordmap[last]=*it;
  last = *it;
}
```
*Note that lst is the list of strings created in part 2 (I used a list instead of a vector just to confuse
you!*

Notice that our first entry that we put into wordmap has an empty string as the key, and the first
word as the value.

#### Output: 
Print out the map to a file named the file [filename]_1_1.txt. So, if the second commandline
argument specifying the input file is “1Nephi”, your output file should be called 
“1Nephi_1_1.txt”. On each line of the file, output the key a comma and space “, “, and then the
value.

### Part 4
Next, let’s do something with your map. Your map has “learned” the contents for each word in
the document. We want to generate new text using this context. You can generate 100 words of
text as follows (make sure you understand how this works):

``` c++
string state = "";
for(int i = 0; i < 100; i++){
  cout << wordmap[state] << " ";
  state = wordmap[state];
}
cout << endl;
```
If	you	run	this	code	using	1Nephi.txt as	input,	you	should	get	something	like:

> I and endure to the last day And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it is Amen And thus it

#### Output: 
Print the sermon/poem/story/speech you generated to the terminal.
### Part 5
That	isn’t	very	cool,	because	we	get	stuck	in	a	loop since we	are	only	keeping	track	of	the	last	
“next	word”	we’ve	seen	for	every	word.		We	can	do	better.		Let’s	keep	track	of	*all* of	the	words	
that	are	seen	after	a	word.		To	do	this,	let’s	change the map to be a map with strings as keys and
vectors of strings as values. Thus, we’ll put each consecutive pair of words in the document into
our map as we did before. But this time, we’ll keep track of each word that comes after a particular
word. We can to this like this (make sure you understand how this works):

``` c++
map<string, vector<string>> wordmap;
string state = "";
for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
  wordmap[state].push_back(*it);
  state = *it;
}
```
*Note that lst is the list of strings created in part 2 (I used a list instead of a vector just to confuse
you!*

When I run this code, I get the following vector of strings associated with the Key “Nephi”:

> having, do, will, being, because, returned, said, and, crept, had, being, do, and, did, and,
> being, had, and, and, do, wherefore, after, Nevertheless, proceed, having, was, because,
> what, saw, also, beheld, beheld, beheld, beheld, saying, beheld, heard, am, had, was, spake,
> did, had, did, took, had, went, having, did, did, beheld, did, who, had, did, did, was, spake,
> said, said, did, did, began, began, did, received, did, have, did, had, said, declare, say, make

You can check to see whether you get the same list (to do that, you’ll need to iterate over the
keys in your map until you find “Nephi”, and then you can print out all the words in the vector
(Value) associated with the Key “Nephi.”

#### Output: 
To verify that you have created this correctly, print out the vector of words that
correspond to the 6th entry in the map (accessed using an iterator).

Now that you have created this map, you can generate a better sermon (than before) by
generating words using this map. We do this by randomly picking a string from the vector of
strings associated with the “key” (which is the last word spoken). I generated a 100-word
sermon with this code:

``` c++
srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
state = "";
for (int i = 0; i < 100; i++) {
  int ind = rand() % wordmap[state].size();
  cout << wordmap[state][ind] << " ";
  state = wordmap[state][ind];
}
cout << endl;
```

The generated text now sounds a lot more readable and doesn't get stuck in an infinite loop.
Here’s sample output.
> I had complained against the children of my father yea he hath done and he should never had spoken and made unto thy life was truly spake unto the Lord and he loveth his life Therefore remember the wilderness and he spake unto ripeness and power of the world And I looked and people And it came to and their journeying they were delivered him that they did speak many years in the remnant of a large and a church and judgments of the waters for they shall turn their fathers in other book hath also be glorified Then I

#### Output: 
Print the sermon/poem/story/speech you generated to the terminal.

### Part 6
But we are still only using one word to get “context” and the generated text still doesn't sound very
good. We would really like to use a phrase as a key so that we can learn multiple word context. In
other words, for the phrase: “I Nephi having”, we would like to have “I Nephi” be the key (two
words) for “having”. To do this, we just change the key for the map to be a list of strings. As we 
move through the text, we can push words onto the back of the list and pop words off the front of
the list to continually get a context of M words. Here’s the code:
``` c++
  int M=2;
  map<list<string>, vector<string>> wordmap;
  list<string> state;
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
                        
  for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state.push_back(*it);
    state.pop_front();
  }
```
*Note that lst is the list of strings created in part 2 (I used a list instead of a vector just to confuse
you!*

We can then generate a new sermon from the resulting map with this code:

``` c++
  state.clear();
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind]<<" ";
    state.push_back(wordmap[state][ind]);
    state.pop_front();
  }
```
The texts that is generated now sound much more like English (though admittedly, it ain’t perfect).
Here’s a sample 100-word sermon that I generated for M=2:

> I Nephi have written are true and living God And it came to pass that Zoram did take me and were partaking of the Lord my brethren they were disputing one with another concerning the things which he hath spoken And it came to pass that the Lord hath protected my sons are no more for the Lord such as Great and marvelous are thy works O Lord according to the words of the Lamb of God wherefore thou shalt also behold a man among the children of men And we beheld the pointers which were many he said unto

Note that, for some inputs, the above code might produce a “floating point exception” if somehow
wordmap[state].size() is equal to zero. You could fix this by identifying when this is the case, and
then resetting the state to its initial value (obtained in lines 2-3 of the previous snippet of code).

#### Output: 
Print the sermon/poem/story/speech you generated to the terminal.

### Part 7
Do something creative to try to improve your algorithm, or experiment with different texts.
Trump.txt and Nephi_Trump.txt are provided, but you could find cooler ones. For example, you
could collect a bunch of poems by Robert Frost into a .txt file, and then run your algorithm to see
what kinds of poems you could generate. When you submit the code to Canvas, include a discussion of what you did.

# Summary for Handing in the Code
You should submit your c9.io user id on Canvas so that the TA can run through parts 1-6 in order for any input file, and
produce the expected output.


