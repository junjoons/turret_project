import time
import cv2
import numpy as np

lower = np.array([100, 150, 0])
upper = np.array([140, 255, 255])

# BLUE 100-140 RED 0-10

cap = cv2.VideoCapture(0)
time.sleep(2)

# Manual Setting of width and height
width, height = 640, 480

# Manual Setting of width and height - Not Used
# width, height = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

print(width, height)

while True:
    success, img = cap.read()

    if not success:
        print("Video input not available")
        continue

    image = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(image, lower, upper)

    contours, heirarchy = cv2.findContours(
        mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )

    if len(contours) != 0:
        max_contour_size = 0
        max_contour = np.array([])
        for contour in contours:
            if cv2.contourArea(contour) > 500:
                if cv2.contourArea(contour) > max_contour_size:
                    max_contour_size = cv2.contourArea(contour)
                    max_contour = contour

        if max_contour_size != 0:
            x, y, w, h = cv2.boundingRect(max_contour)
            cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 2)
            cx = x + (w // 2)
            cy = y + (h // 2)
            cv2.circle(img, (cx, cy), 2, (0, 0, 255), 2)

    # img, mask = cv2.resize(img, (width, height)), cv2.resize(mask, (width, height))

    cv2.line(img, ((width // 2), height), ((width // 2), 0), (0, 255, 0), 1)
    cv2.line(img, (width, (height // 2)), (0, (height // 2)), (0, 255, 0), 1)

    cv2.imshow("Original", cv2.flip(img, 1))
    cv2.imshow("Masked", cv2.flip(mask, 1))

    if cv2.waitKey(5) & 0xFF == 27:
        break

cap.release()
