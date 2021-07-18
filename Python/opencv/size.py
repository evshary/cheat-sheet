import cv2
from matplotlib import pyplot as plt

def cut_img(img):
    # Cut the size
    x_l, x_r = 200, 600
    y_u, y_d = 0, 400
    new_img = img[y_u:y_d, x_l:x_r] # y first, x second
    return new_img

def resize_img(img):
    # Resize the image
    new_w = int(img.shape[1] * 0.5)
    new_h = int(img.shape[0] * 0.5)
    new_img = cv2.resize(img, (new_w, new_h), interpolation = cv2.INTER_AREA)
    return new_img

def rotate_img(img):
    # Rotate the image
    (h, w, d) = img.shape
    center = (w // 2, h // 2)

    # Arg1: rotate center
    # Arg2: rotate angle (-:clockwise, + conterclockwise)
    # Arg3: resize
    M = cv2.getRotationMatrix2D(center, 45, 1.0)

    new_img = cv2.warpAffine(img, M, (w, h))
    return new_img

bgr_img = cv2.imread('kitten.jpg')

# OpenCV format is BGR, matplotlib format is RGB
# We need to transform BGR to RGB
rgb_img = bgr_img[:,:,::-1]
# or we can transform thisway
#rgb_img = cv2.cvtColor(bgr_img, cv2.COLOR_BGR2RGB)

img1 = cut_img(rgb_img)
img2 = resize_img(img1)
img3 = rotate_img(img2)

# Use matplotlib to show image
plt.imshow(img3)
plt.show()
