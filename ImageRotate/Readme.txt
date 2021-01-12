IDE Used:I have visual studio 2019 to make this project.

Header Files:
	opencv2/opencv.hpp: This is used to import all the necessary functions 
                            in open cv.
	iostream          : This is used to import all the basic and necessary 
                            functions of c++.

Functions:
	translateImg(Mat& , int ,int):
	   Use: This function is used to shift rotated image to prevent it from 
		cutting down from any side.
	   Description:
		1)This function will returns a value of 'Mat' type.
		2)This function takes values of one-'Mat'and two-'int' type.
		  Mat type for image and int type to decide how far the image
		  should move from original position.
   		3)In the function the variable trans_mat will store a image type 
		  which has matrix dimension 2X3 and represented as 
		  [1 0 offsetx] 
		  [0 1 offsety]  here,
	          offsetx is the movement of image along x-direction(horizontal)
	          offsety is the movement of image along y-direction(vertical)
		4)After this I have use predefined function warpAffine() to move
		  the original image in x and y direction. In parameters as first
		  the original/input image, second the output image, third is
		  action to do with image,fourth is size of image.
		5)Finally I returned the translated image.

	main():
	  Use: This is the main function in which main program is done.
	  Description:
		1)We taken input from the user in variable angle for the angle of
		  rotation and str for the path or name of the image.For str user
		  must input with extension of the image.FOR EXAMPLE:if we have a
		  image name PKS of png format in same path we have to write : 
			PKS.png or c:\projects\imageRotate\PKS.png
		2)Now I have stored my image in image variable with MAt keyword 
		  and predefined function used is imread().This function reads and
		  stores the image. In parameters we first give the path or name 
		  of the image and second parameter is flag we have used flag as 
		  unchanged since we want the image without making any change to it.
		3)Now we have checked that is image empty if by any reason it is 
		  empty the program will terminate.
		4)Now I have taken width and height of image and assign both of 
		  them with the maximum value among them.
		5)Now a variable name as pc in which I have stored point of center 
		  with the format as Point2f denotes that it is 
		  of floating type which stores 2 value (x-coordinate,y-coordinate).
		6)Now I have a Rotated variable of Mat type which I have initialized
		  with a predefined function getRotationMatrix2D() this will take 
		  parameter as point of center then second is angle of rotation and 
		  third is scale of image.
		7)After this a predefined function warpAffine() is used which will 
		  take first the original/input image, second the output image, 
		  third is action to do with image, fourth is size of image.
		  (In program the size i have given is of maximum value among
                  height and width refer point 4 for clearity).
		8)Then I have called a function translateImg which was explained 
		  above this function.
		9)Now I have shown original and rotated image by the predefined 
		  function imshow() this function will create a window with name as
		  entered in first value of parameter and second value it take is
		  the image to display.
		10)waitkey(0) is used to wait till a key is pressed.
 		11)After this a predefined function destroyWindow() is called close
		   the window.This take one parameter as the name of window which 
		   I want to close.
