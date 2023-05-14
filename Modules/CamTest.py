# For Cam Testing only!

import cv2

cap = cv2.VideoCapture(0)

while True:
    success, img = cap.read()

    if not success:
        print("Video input not available")
        continue

    cv2.imshow("Cam", cv2.flip(img, 1))

    if cv2.waitKey(5) & 0xFF == 27:
        break

cap.release()
