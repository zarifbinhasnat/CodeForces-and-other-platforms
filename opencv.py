import cv2 as cv

# Fix 1: Escape backslashes or use raw string for file path
img = cv.imread(r'C:\Users\Zarif\Pictures\Camera Roll\WIN_20250119_10_22_26_Pro.jpg')

# Check if the image was read properly
if img is None:
    print("Error: Image not found or path is incorrect.")
else:
    cv.imshow('Zarif', img)

    # Define the resize function
    def rescaleframe(frame, scale=0.75):
        width = int(frame.shape[1] * scale)
        height = int(frame.shape[0] * scale)
        dimensions = (width, height)
        return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

    # Use the resize function and show scaled image
    resized = rescaleframe(img)
    cv.imshow('Resized Image', resized)

    # Add wait and destroy commands
    cv.waitKey(0)
    cv.destroyAllWindows()
