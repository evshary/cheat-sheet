import cv2

filename = "kitten.jpg"

## read image
# default: cv2.IMREAD_COLOR (RGB color level)
my_img = cv2.imread(filename)
# gray level
my_img_gray = cv2.imread(filename, cv2. IMREAD_GRAYSCALE)
print("Image type: ", type(my_img))
print("Image size: ", my_img.shape)

## show image
# Able to adjust the window
cv2.namedWindow('My image', cv2.WINDOW_NORMAL)
cv2.imshow('My image', my_img)
cv2.imshow('My image gray', my_img_gray)

## Wait key to close window
cv2.waitKey(0)
cv2.destroyAllWindows()
# We can only close specific window
# cv2.destoryWindow('My image')

## Output different type image (based on filename extension)
cv2.imwrite('kitten_png.png', my_img_gray)
cv2.imwrite('kitten_tiff.tiff', my_img_gray)
