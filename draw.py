import cv2 as cv 
import numpy as np

blank = np.zeros((500, 500, 3), dtype='uint8')
cv.imshow('Blank', blank)
#paint the blank image a certain color
blank[:] = 0, 255, 0 # BGR 
cv.imshow('Green', blank)
cv.waitKey(0)# wait for a key press
#draw a rectangle
cv.rectangle(blank, (0, 0), (250, 250), (255, 0, 0), thickness=cv.FILLED) # BGR
cv.imshow('Rectangle', blank)
cv.waitKey(0)
#draw a circle
cv.circle(blank, (blank.shape[1]//2, blank.shape[0]//2), 40, (0, 0, 255), thickness=cv.FILLED) # BGR
cv.imshow('Circle', blank)
#what is blank.shape[1]//2?
#blank.shape[1] is the width of the image, blank.shape[0] is the height of the image
#//2 is the integer division operator, so it gives the center of the image
#draw a line
cv.line(blank, (0, 0), (250, 250), (0, 255, 0), thickness=3) # BGR
cv.imshow('Line', blank)
#draw text  
gray = cv.cvtColor(blank,cv.COLOR_BGR2GRAY)



