# What's Textop?
 
A simple Text Editor for editing rich text files. 
Built with Qt Creator.
Compiled and tested on Ubuntu 20.04 LTS (64bit) with Qt5.


# Options/Features:

1. File: New, Open, Save, Save As
2. Edit: Copy, Cut, Paste, Undo, Redo
3. Bold/Unbold selected text
5. Subscript functionality
6. Superscript functionality


# Additional Features:

1. About Me Section
2. About Me Push Button
3. Keyboard shortcuts for cut, copy, paste etc.


# How to run the code?

To run the code, at first we need to install the prerequisites:-

a->  g++ :

- $ sudo apt-get install g++ -y 

b->  make :

- $ sudo apt-get install make -y 

c-> qt5 :

- $ sudo apt-get install qt5-default

Next, we go to the project directory "Textop", compile Textop.pro and build:

- $ cd Textop
- $ qmake Textop.pro
- $ make

Now, we can run the Textop file as:-
 - $ ./Textop  
 (from the project directory)
 
 * Alternatively, the GUI way:-
 
 Open the project: Textop.pro
 in Qt CReator and hit the "Run" button.


# What has been done?

1. General - basic text-editor functionalities like cut, copy, paste, new file, open, save, exit etc.
have been developed along with a logo/icon for the application.
2. Specific - 
	- a. Bold/unbold feature has been added
	- b. Subscript and superscript of selected text has been implemented
	- c. About me option and push button - that shows my resume.


# Issues/challenges

1. It was challenging to implement the subscript and superscript functionalities
because when I followed the same procedure as I did for the bold trigger,
it didn't work. I also tried with html tags <sup> </sup> and <sub> </sub> (but 
it had some issues with replacing the existing text).
2. There were some issues while installing Qt on Windows. So, I shifted to Ubuntu
and thereafter it has been quite simple.  
3. The about me page is rigid to scrolling, which is why if volume of 
content is extended, the later portions would not be shown.


# References

1.  https://www.youtube.com/watch?v=x858_WCtl_Y
2. https://www.youtube.com/watch?v=I96uPDifZ1w
3. https://github.com/rohitsaluja22/OpenOCRCorrect

![image](https://user-images.githubusercontent.com/64594310/154801512-601cbcdf-0e99-4111-941c-e906a46e4e01.png)
![image](https://user-images.githubusercontent.com/64594310/154801561-71685bc3-ba3d-475b-a6a4-1e31cdc8d20f.png)
![image](https://user-images.githubusercontent.com/64594310/154801878-93383490-f149-48a8-b7ae-8c768693f85f.png)
![image](https://user-images.githubusercontent.com/64594310/154801653-237eebdb-1271-40a8-959e-2f69d5f9157b.png)
![image](https://user-images.githubusercontent.com/64594310/154801723-5bdfc41b-c0a9-4f01-906d-9645870831e2.png)
![image](https://user-images.githubusercontent.com/64594310/154801835-5278c293-f5c2-458f-baba-da93c2fae8df.png)
