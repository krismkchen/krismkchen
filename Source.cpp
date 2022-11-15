// g++ opencv-camera.cpp -o a.out `pkg-config --cflags --libs opencv`
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Cannot open camera\n";
        return 1;
    }

    Mat frame;
    Mat gray;
    //namedWindow("live", WINDOW_AUTOSIZE); // 命名一個視窗，可不寫
    while (true) {
        // 擷取影像
        bool ret = cap.read(frame); // or cap >> frame;
        if (!ret) {
            cout << "L20 Kris 1 Can't receive frame (stream end?). Exiting ...\n";
            cout << "L21 Kris 2 Can't receive frame (stream end?). Exiting ...\n";
            break;
        }
#if 1//kris test 0710
        cout << "L25 Kris 1 Can receive frame (stream end)..\n";
        int width = 240;// cap.get(CAP_PROP_FRAME_WIDTH);
        int height = 1080;// cap.get(CAP_PROP_FRAME_HEIGHT);
        cap.set(CAP_PROP_FRAME_WIDTH, width);
        cap.set(CAP_PROP_FRAME_HEIGHT, height);
        int fps = cap.get(CAP_PROP_FPS);
        printf("L28 Image Size: %d x %d; fps = %d;\n", width, height, fps);

#endif
        // 彩色轉灰階
        //cvtColor(frame, gray, COLOR_BGR2GRAY);

        // 顯示圖片
        imshow("live RGB", frame);
        //imshow("live Gray", gray);

        // 按下 q 鍵離開迴圈
        if ((waitKey(1) == 'q') || (waitKey(1) == 27)){
            break;
        }
    }
    // VideoCapture 會自動在解構子裡釋放資源
    return 0;
}