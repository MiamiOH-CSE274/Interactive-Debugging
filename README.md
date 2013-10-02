Author
==========
"Emrick, Garrett", emrickgj
Interactive-Debugging
=====================

Lab on using the interactive debugger

This lab is designed to help you learn the debugger. For that reason, I recommend that you do all the exercises in order. Skipping around, reading ahead, or finishing the exercises as quickly as possible, is not going to be as helpful.

Fill in your answers in this file, and hand it in via a pull request. I will be grading it only on whether or not you made a genuine effort to complete the lab and answer all questions.

Step 1
------
Create a project file, and add sierpinski.cpp to the project. Also, look at correct-triangle.html to see an example of correct output. Skim/read the source code for sierpinski.cpp, and try to answer the following questions:

* 1.a) The purpose of the program is to generate a Serpinski Triangle.  
* 1.b) Yes the program does produce output, the output goes to the "correct-triangle.html" file. 
* 1.c) The program does not accept any input, although one could modify it to take input as the doTriangle method takes an arbitrary integer.

Step 2
-------
Build and run Sierpinski. An output file called “triangle.html” should be placed in your project directory, along with your source code. The file should exist, but you will notice that its contents do not look much like the correct output.

* 2.a) For one, it's not even a triangle, it's a giant rectangle. It has some eights that are present, but these only go in horizontal rows. The other thing that is interesting is that there seems to be another symbol being placed in all places, 
* but I'm not sure what this symbol is. Looks like a cross or a lowercase f.

Step 3
------
The first problem I noticed is that I expected the main part of the print-out to consists only of spaces and 8s, but the output I actually got has some strange characters in it.

The characters to print out in the main part of the file are stored in a big array called “grid.” The program is broken into three main parts: (1) Setting up the problem, (2) Filling out “grid,” and (3) Printing “grid.” 

* 3.a) Explain one or two methods you could use to determine which of the three parts of the program is causing this first bug. (In step 4, I will tell you how I would do it.)
* 

To tell if the setting up of the problem is right, I could simply try and double check the math and calculations of the program, in fact for most of these I could walk step by step through the code to try and see if there are any
obvious problems with the program. After that, I would check to make sure the array is set up right, and it is properly handled throughout the program. To test the printing of the triangle, I could change the starting number to see the
effect, and determine if there are any obvious problems that would cause it to print this output. For filling out the grid, we could also change what is being printed out in the "spaces" to see if that effects it to see what happens. I
think the most helpful step though would to do a step-by-step run of the program, which is what I would do both in Java and Mips if I were having obvious problems like this.

 
Step 4
------
I want to determine when the trash starts to appear in “grid.” In order to do this I will set two breakpoints: One at line 85 (the last line of the “Setting up the problem” section), and one at line 115 (the first line of the “Printing grid” section).

Next, I will hit the green play button in my toolbar, to “Start Debugging.” This can also be found under the Debug menu.

When your program stops at the first breakpoint, scroll up until you find the variable “grid” … you shouldn’t have to go up far. Right-click on “grid”, and select QuickWatch. This will open a window that shows you the variable name, its value (which is what the variable contains right now), and its type.

* 4.a) Empty spaces, but right now it contains a bunch of weird characters, or -51 (ASCII value)

Hint: In order to get a better look at the contents of grid (which is an array of characters), in the QuickWatch window, select the drop-down box at the end of the “value” column and choose “text visualizer.” This should pop up a window that gives you view of everything contained in grid. The view in the QuickWatch window cuts off when it runs out of room.

If everything was as you expected in question 4.a, then hit the play button again to continue debugging. Repeat the QuickWatch process (inspecting the grid variable) when you hit the next breakpoint.

* 4.b) The setup obviously has problems, it is wrong long before it gets to the first debugging point. 

Step 5
------
In the previous step you should have identified that the bug is occurring in the setup phase of the program. The evidence is that, at the end of the startup phase, the array called “grid” contains lots of weird looking characters, instead of spaces, as we would expect.

* 5.a) The for loop is where it should do that, in lines 62-66

Step 6
------
Once you have found the line that says “grid[i] = ‘ ‘;”, it may or may not be obvious to you what the bug is. The bug is of a type that is VERY easy to over-look, and probably most of the class doesn’t see it. Imagine that you can’t find the bug just by looking at the code. Next, we will use interactive debugging to narrow things down a bit more.

First, stop the debugger (by hitting the stop button), and then remove all your old breakpoints. The fast/easy way to do this is to go to the Debug menu, and select Delete All Breakpoints. Next, we will set a breakpoint on line 65, the line that starts “grid[i] =”. Then go ahead and run the debugger again.

At first it looks like this code should work. The for loop seems to be using its counter variable i correctly, and we seem to have the correct test condition in the loop. So, since we don’t see the problem, lets try just stepping through the program to see if what we expect to happen actually happens.

The “step over” command in the debugging menu is designed to make the program execute the current line, and then stop on the next line of code that would be executed. In a loop, for example, each step should move you one line down the body of the loop, then when you step at the end of the loop it should take you back to the top. You should step through the body of the loop one time for each iteration of the loop.

* 6.a) I would expect to hit it 40000 times, since it starts at zero.
* 6.b) Doesn't do exactly what I'm expecting, but I'm not sure if I'm using the button correctly, it only runs once thruogh the for loop. It seems that i is somehow 40000 before the loop starts...
* 6.c) It isn't running through the loop correctly. Upon looking at it for quite a long time, I noticed the semi-colon after the for loop.

Step 7
------
In the previous step you should have identified the bug: The for loop has a semi-colon after it! This means that the “body of the loop” was not getting executed over and over (as we desired), but instead was only executed once, when i was 40000. 

Fix the bug by deleting the stray semi-colon. Then, re-build and re-run the program, to generate a new triangle.html. Look at it, and see how it looks. 

* 7.a) We fixed the loop not running correctly, and now the array is filled with spaces.
 
Step 8
------
Well, the weird characters are gone. Now there are only spaces and 8s, so that is good … but now we can see that what is getting printed out is not very triangle-like. In fact, did you notice that each row just contains repeats of the same character? Some rows have 8s, some have spaces, but it seems like there are not any rows that contain a mix.

Repeat step 4, and try to identify which of the three stages of the program is causing this incorrect output. If grid only contains longs stripes of 8s, then there are probably still problems in the first two stages. If grid contains a mix of 8s and spaces, then the problem is likely in the printing.

* 8.a) At the end of the first stage, it should be a bunch of spaces
* 8.b) It should look like a mix of 8's and spaces
* 8.c) Pretty sure it's in the print section, uses i instead of j.
 
Step 9
------
At the end of section 1, grid was mostly empty, as we expected. At the end of section 2, grid contained a mix of 8s and spaces, which was also as we expected. Hence, we suspect that the bug must be in the printing section (roughly lines 115-122). Remember that we observed that each row printed the same character over and over again.

Can you find the bug? If not, try stepping through the doubly-nested loop. You can put your mouse over ANY variable to see what its current value is, so you don’t have to use QuickWatch unless you want to look at something big (like a whole array, or a class structure). As you step through, you should be looking for anything that could lead to the same character being printed over and over, and only changing from line to line.

* 9.a) It doesn't use J when it prints, which is either the x/y of the array since we are using one that is single dimensional. Without using j, it would make since it's all printing in a row.
 
Step 10
-------
In the previous step you should have discovered that the “grid[i*sideLength +i]” is incorrect … you really wanted “grid[i*sideLength + j]”. Make the fix, and re-run your code to see if we are closer to having correct output.

* 10.a) The triangles all seem smashed to the right side.

Step 11
-------
It looks to me like we have a problem with the top vertex of the triangle. Why is it in the top right, instead of in the top center? Use the comments in my code to find the part that is supposed to set the top corner of the triangle to be in the center.

* 11.a) It never takes half, or actually gets the middle when it is calculating the middle of the top. It should be (sideLength - 1) / 2.0;
* 11.b) I would have probably had to of spent a lot of time looking over the code to figure out what is going on. Eventually, after realizing what the code does, I would see that one of the variables was the middle, and because the y of that one is zero, I would assume it to be that one. Would be a headache to find if they weren't nice names though.

 
Step 12
-------
In the previous step, you should have discovered that the line “double p3x = sideLength -1;” is incorrect. Instead, it should be “double p3x = sideLength/2.0;”. Make the change, and re-run your program to see how it affects the output. 

* 12.a) Only half of the triangle appears to be printing, or more of the right side seems to be printing than the left.

Step 13
-------
Things are looking pretty good now. We have something triangle-like, and the top point is in the right place. Something still seems weird though … it is as if the little hopping bug prefers to jump down and to the right … there ARE some 8s in the left half of the screen, but almost all of the triangles seem heavily skewed to the left, and down.

* 13.a) Based on what I am getting, I am assuming it is where the triangle is generating. Where the for loop is.

 
Step 14
-------
It seems most likely that the problem with the code is in the middle section, where the triangle is actually generated. From debugging, I convinced myself that we were printing out what was in grid, so the problem must be that grid is being calculated incorrectly.

Personally, I could not see the problem right away. When all else fails, I generally step through the program, and see if anything unexpected happens. Try setting a breakpoint on the first line inside the loop that builds the triangle (the line that starts “grid[((int)(cury+0.5)”), and start stepping. 

Any time you have conditional logic (like a switch statement of if statement) within a loop, you might have to step through the loop many times before you see the problem … because the problem might occur in only one of the cases. 

You have a couple of options now. One is to just step through the loop for a while, until you have seen all of the cases in the conditional logic work.

The other option is to create a break point within each condition. So, for example, put a break on “case 0”,  a break on “case 1” and a break on “case 2”. Then run the program in the debugger. The first time you hit a particular breakpoint (say the case 2 breakpoint), step through the code and make sure it does what you expected. If so, you can remove that breakpoint, and continue debugging. This way you can try all three cases without having to do a whole lot of manual stepping.

* 14.a) It was pretty obvious, it was missing the break statement at case 0. This caused this case to be basically useless since it went on to the next one, and re-assigned what it had just done.

 
Step 15
-------
In the previous step you should have discovered the problem was with the “case 0” case within the switch statement. Whenever you hit case 0, the bug hops halfway to point 1 … but then the program drops through into the “case 1” part, and the bug hops halfway to point 2, as well! This is why the bug seems to never hop left: Any time it hops left, it immediately hops to the right again. The fix for this is to insert the missing break statement, just before “case 1:”.

Make the fix, and re-run your program. If all went well, your program should produce output that looks very similar to (but not identical, because of the randomness involved) the provided correct-triangle.html.

Congrats!

Summary
=======
In this lesson you have learned to:

1.	Set breakpoints
2.	Run the debugger
3.	Step through your code
4.	Inspect variables through tooltips and through the QuickWatch window
5.	Follow a pattern of thinking in debugging. Always try to:
  1.	Predict what should happen
  2.	Design a test to see if it did happen as expected
  3.	A plan for what to do, based on the outcome of the test
