import cv2
from config import config
import copy

class Image:
    def __init__(self, nameimage):
        self.image = None
        self.nameimage = nameimage

    def average_filter(self, kernel_size):
        radius = int(kernel_size / 2)
        filtered_image = copy.deepcopy(self.image)
        for colunm in range(self.image.shape[0]):
            for line in range(self.image.shape[1]):
                kernel = []
                self.fillkernel(colunm, line, kernel, radius)
                filtered_image[colunm][line] = int(sum(kernel) / kernel_size ** 2)
        self.write_text(filtered_image, "Average Applied")
        cv2.imwrite(config.PATH_OUTPUT_IMAGES +"AVERAGED_"+str(i) + self.nameimage+".jpg",
                     filtered_image)


    def median_filter(self, kernel_size,i):
        radius = int(kernel_size / 2)
        filtered_image = copy.deepcopy(self.image)
        for colunm in range(self.image.shape[0]):
            for line in range(self.image.shape[1]):
                kernel = []
                self.fillkernel(colunm, line, kernel, radius)
                filtered_image[colunm][line] = sorted(kernel)[int((len(kernel))/2)]
        self.write_text(filtered_image,"Median Filter Applied")
        cv2.imwrite(config.PATH_OUTPUT_IMAGES+"MEDIAN_IN_"+str(i)+self.nameimage+".jpg",
                    filtered_image)

    def contrast_redefinition(self):
        filtered_image = copy.deepcopy(self.image)
        histogram = [0]*256
        size = self.image.size
        for colunm in self.image:
            for line in colunm:
                histogram[line] += 1
        for _p in range(0, len(histogram)):
            histogram[_p] = histogram[_p] / self.image.size
        for _p in range(1, len(histogram)):
            histogram[_p] = histogram[_p] + histogram[_p - 1]
        for _p in range(0, len(histogram)):
            histogram[_p] = int(round((((len(histogram) - 1) * histogram[_p])), 0))
        for colunm in range(self.image.shape[0]):
            for line in range(self.image.shape[1]):
                filtered_image[colunm][line] = histogram[filtered_image[colunm][line]]

        self.write_text (filtered_image, "Equalization Applied")
        cv2.imwrite (config.PATH_OUTPUT_IMAGES + "EQUALIZATION_" + self.nameimage,
                     filtered_image)

    def limiarization(self, threshold):
        filtered_image = copy.deepcopy(self.image)
        for colunm in range(self.image.shape[0]):
            for line in range(self.image.shape[1]):
                if(self.image[colunm][line] > threshold):
                    filtered_image[colunm][line] = 255
                else:
                    filtered_image[colunm][line] = 0
        self.write_text(filtered_image, "Limiarization Applied")
        cv2.imwrite(config.PATH_OUTPUT_IMAGES + "LIMIARIZATION_" + self.nameimage,
                    filtered_image)


    def load_image(self, modo = 0):
        try:
            path_image = config.PATH_INPUT_IMAGES + self.nameimage
            self.image = cv2.imread (path_image, modo)
            if self.image is None:
                raise IOError("FILE {namefile} NOT FOUND".format(namefile=self.nameimage))
        except IOError as exc:
            print("ERROR : {args} ".format(args=exc.args))

    def show_image(self):
        try:
            if self.image is None:
                raise IOError ("FILE {namefile} NOT FOUND".format (namefile=self.nameimage))
            cv2.imshow(self.nameimage, self.image)
            cv2.waitKey(0)
            cv2.destroyAllwindows()
        except IOError as exc:
            print("ERROR : {args} ".format(args=exc.args))

    def fillkernel(self, colunm, line, kernel, radius):
        for l in range(colunm - radius, colunm + radius + 1):
            for j in range(line - radius, line + radius + 1):
                if (l + colunm < 0 or j + line < 0):
                    kernel.append(0)
                elif (l + radius > self.image.shape[0] or j + radius > self.image.shape[1]):
                    kernel.append(0)
                else:
                    kernel.append(self.image[l][j])

    def write_text(self,image,text):
        font = cv2.FONT_HERSHEY_SIMPLEX
        bottomLeftCornerOfText = (10, 25)
        fontScale = 1
        fontColor = (255, 255, 255)
        lineType = 2
        cv2.putText(image, text,
                     bottomLeftCornerOfText,
                     font,
                     fontScale,
                     fontColor,
                     lineType)

    def setImage(self,np_array,pos_x,pos_y):
        for l in range(0,self.image.shape[0]):
            for c in range(0, self.image.shape[1]):
                np_array[l + int(pos_x / 2)][c + int(pos_y / 2)] = float(self.image[l][c])




