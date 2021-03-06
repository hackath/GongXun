
#pragma once

#include <linux/videodev2.h>
#include <iostream>
#include <string>
#include <unistd.h>     /*Unix标准函数定义*/
#include <fcntl.h>      /*文件控制定义*/
#include <sys/ioctl.h>

int set_camera_exposure(std::string id, int val)
{
    // 通过v4l2配置摄像头参数
    int cam_fd;
    if ((cam_fd = open(id.c_str(), O_RDWR)) == -1) {
        std::cerr << "Camera open error" << std::endl;
        return -1;
    }
    // 手动曝光
    struct v4l2_control control_s;
    control_s.id = V4L2_CID_EXPOSURE_AUTO;
    control_s.value = V4L2_EXPOSURE_MANUAL;
    ioctl(cam_fd, VIDIOC_S_CTRL, &control_s);

    // 设置曝光值
    control_s.id = V4L2_CID_EXPOSURE_ABSOLUTE;
    control_s.value = val;
    ioctl(cam_fd, VIDIOC_S_CTRL, &control_s);
    close(cam_fd);

    return 0;
}
