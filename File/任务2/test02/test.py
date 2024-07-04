import cv2 as cv
import numpy as np


# 读取带中文的图片，bgr
def cv_imread(file_path):
    cv_img = cv.imdecode(np.fromfile(file_path, dtype=np.uint8), -1)
    return cv_img

#分别读取图像
img1=cv_imread('C:/Users/12074/Desktop/任务2/1.jpg')

img1=cv.resize(img1,dsize=(800,800),interpolation=cv.INTER_LINEAR)
# cv.imshow('img1',img1)
# cv.waitKey(0)
# cv.destroyAllWindows()
img1_height1,img1_width1=img1.shape[:2]
img1_h1,img1_h2=cv.split(img1,2)
img1_w1,img1_w2=cv.split(img1_h2,2)
cv.imwrite('C:/Users/12074/Desktop/任务2/1.jpg',img1_w2)

img2=cv_imread('C:/Users/12074/Desktop/任务2/2.jpg')
cv.resize(img2,(800,800))



img3=cv_imread('C:/Users/12074/Desktop/任务2/3.jpg')
cv.resize(img3,(800,800))


img4=cv_imread('C:/Users/12074/Desktop/任务2/4.jpg')
cv.resize(img4,(800,800))