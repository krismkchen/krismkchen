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
    //namedWindow("live", WINDOW_AUTOSIZE); // �R�W�@�ӵ����A�i���g
    while (true) {
        // �^���v��
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
        // �m����Ƕ�
        //cvtColor(frame, gray, COLOR_BGR2GRAY);

        // ��ܹϤ�
        imshow("live RGB", frame);
        //imshow("live Gray", gray);

        // ���U q �����}�j��
        if ((waitKey(1) == 'q') || (waitKey(1) == 27)){
            break;
        }
    }
    // VideoCapture �|�۰ʦb�Ѻc�l������귽
    return 0;
}