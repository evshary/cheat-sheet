import cv2

def rotate_img(img):
    # Rotate the image
    (h, w, d) = img.shape
    center = (w // 2, h // 2)

    # Arg1: rotate center
    # Arg2: rotate angle (-:clockwise, + conterclockwise)
    # Arg3: resize
    M = cv2.getRotationMatrix2D(center, 180, 1.0)

    new_img = cv2.warpAffine(img, M, (w, h))
    return new_img

cap = cv2.VideoCapture(0)

# Set the size of vedio
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

# Use XVID format
fourcc = cv2.VideoWriter_fourcc(*'XVID')
# output avi video with FPS 20, resolution 640x480
# isColor should be true if you want to record color video
out = cv2.VideoWriter('camera.avi', fourcc, 20.0, (640, 480), isColor=False)

while (True):
    # Read image from camera
    ret, frame = cap.read()
    if not ret:
        print("Unable to read camera")
        break;

    # process image
    rotate_frame = rotate_img(frame)
    gray_rotate_frame = cv2.cvtColor(rotate_frame, cv2.COLOR_BGR2GRAY)
    new_frame = gray_rotate_frame
    # Show image
    cv2.imshow("my camera", new_frame)

    # write the video
    out.write(new_frame)

    # Press q to leave
    if (cv2.waitKey(1) == ord('q')):
        break

cap.release()
out.release()
cv2.destroyAllWindows()
