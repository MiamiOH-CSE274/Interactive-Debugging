/* Name: Bo Brinkman
 * Instructor: Dr. Brinkman
 * Course: CSE 274
 * Description: This is the code for the debugger tutorial.
 */

#include <fstream>
#include <string>

//This is the name of the file we will print to
#define OUTPUTFILE "triangle.html"

using namespace std;
/*
 * Input paramter: An integer that tells us the resolution of the triangle to make.
 * Output: None
 * Side-effects: Causes a sideLength x sideLength Sierpinski triangle to be printed as HTML to the
 *   file named in OUTPUTFILE
 * 
 */
void doTriangle(int sideLength)
{
	//First, open up a file to print to. OUTPUTFILE is a constant, defined at the top of the file
	// Note: This will overwrite any previous file that has the same name .. so each time you run
	// this, you will get your old output overwritten with the new one.
	ofstream outfile(OUTPUTFILE);

	outfile << "<HTML><HEAD><TITLE>A Sierpinski Triangle, size " << sideLength << "</TITLE></HEAD>" << endl;
	outfile << "<H1>A Sierpinski Triangle, size " << sideLength << "</H1>" << endl;
	outfile << "<font size=1><pre>" << endl;

	/* To generate a Sierpinski triangle, we will simulate a bug hopping around on a piece of paper.
	 * Imagine a bug is soaked in ink, and then placed on a paper. He hops around, but in a very precise
	 * way: The paper has a triangle drawn on it. Each time he hops, he picks a random corner of the
	 * triangle, and hops HALF WAY there. He keeps doing this forever ... or until he gets really tired.
	 * The picture that results from this process is an approximation to a fractal called the Sierpinski
	 * triangle ... and incidentally, this was the first program that Dr. Brinkman wrote on his TI-82
	 * calculator, when he was in High School.
	 *
	 * In this program the piece of paper is not very big, in relation to the size of the bug. The sideLength
	 * parameter tells us that the piece of paper is sideLength x sideLength, where the unit of measure is
	 * "bug body lengths." Each bug splat will be marked with the character '8'
	 *
	 * P.S. You will notice the Sierpinski Triangle appears on the doors at the entryway to the CSA offices
	 * in Benton. Yes, this is Dr. Brinkman's fault.
	 */

	//Create the grid for my output, and initialize each entry to be a space
	// I am making the grid just a bit bigger than we need, in order to handle rounding
	// errors.
	char* grid = new char[(sideLength+1) * (sideLength+1) + 1];
	/*
	 * In C++, you may use an array of characters to represent a string. Unfortunately, however,
	 *  C++ does not know how long the array is, so we must use the special character '\0',
	 *  known as the "null character" to terminate a string. The null character is numerically
	 *  equal to zero (so ((int)'\0') == 0), and is used as a sentinel to mark the end of a string.
	 *  Such a string is called a "null-terminated string." Without this '\0', your program will
	 *  probably crash if you do "cout << grid;"
	 */
	grid[sideLength*sideLength] = '\0';

	int i;
	for(i=0; i < sideLength*sideLength; i++)
	{
		grid[i] = ' ';
	}

	//The first corner of the triangle is in the lower left
	double p1x = 0;
	double p1y = sideLength - 1;
	grid[((int)p1y)*sideLength + (int)p1x] = '8';

	//The second corner of the triangle is in the lower right
	double p2x = sideLength - 1;
	double p2y = sideLength - 1;
	grid[((int)p2y)*sideLength + (int)p2x] = '8';

	//The third corner is in the middle of the top
	double p3x = sideLength/2;
	double p3y = 0;
	grid[((int)p3y)*sideLength + (int)p3x] = '8';

    //We pick an arbitrary place for the bug to start ... in this case the lower left corner
	double curx = 0;
	double cury = sideLength - 1;

	//There are sideLength*sideLength spots in the grid, so we shouldn't need quite
	// this many hops ... but because of the randomness, we may need to make more hops
	// than one would expect based just on the number of visible splats at the end
	for(int i = 0; i < sideLength*sideLength; i++)
	{
		//This simulates the bug splatting down at the point (curx, cury)
		grid[((int)(cury+0.5))*sideLength + (int)(curx+0.5)] = '8';

		//This next part picks a random corner, and then calculates the point that
		// is halfway from the current position to the picked corner.
		int randomPoint = rand() % 3; //Get a random number between 0 and 2
		switch(randomPoint)
		{
		case 0:
			curx = (curx + p1x)/2.0;
			cury = (cury + p1y)/2.0;
			break;
		case 1:
			curx = (curx + p2x)/2.0;
			cury = (cury + p2y)/2.0;
			break;
		case 2:
			curx = (curx + p3x)/2.0;
			cury = (cury + p3y)/2.0;
			break;
		}
	}
	
	//Now, print out the grid
	for(int i=0;i<sideLength; i++)
	{
		for(int j=0;j<sideLength; j++)
		{
			outfile << grid[i*sideLength + i];
		}
		outfile << endl;
	}
	
	//For every new, there should be an equal and opposite delete!
	delete[] grid;

	//Finish off the HTML file
	outfile << "</pre></font></html>" << endl;

	//Close the file
	outfile.close();

}

int main()
{
	//Not much to do in main. Just pick a triangle size, and go for it.
	doTriangle(200);

	return 0;
}
