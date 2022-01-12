#ifndef _SPLITIF_HPP_
#define _SPLITIF_HPP

#include <iostream>
#include <vector>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/video/background_segm.hpp>
#include <memory>
#include <time.h>
#include <string>

namespace SplitObjIF
{

    struct GpsPostion
    {
        double longtitude;
        double latititude;
    };
    struct RadarPostion
    {
        float x;
        float y;
    };

    struct SplitObjSender
    {
        int SplitID;
        GpsPostion m_gps;
        RadarPostion m_radarpos;
        long appearing_timestamp;
        long dispearing_timestamp;
        cv::Rect m_postion; //after resizing pics, in patch positions
        cv::Rect origlayout;
		cv::Mat imgdata;
		unsigned int firstshowframenum;
		int ID;
		bool moved;
		bool haschecked;
		int checktimes;
    };

    struct SplitObjReceiver
    {
       unsigned int framenum;
       long timestamp;
       cv::Mat imageData;
       // 安全起见拷贝一次从inferout，等号操作深拷贝一次
       std::vector<cv::Rect> v_inferout;
        /* data */
    };


    void work(std::vector<SplitObjIF::SplitObjSender> &senderpin, int method =0);

    //封装一下background abstract~~~

    void InitGaussian(uchar* r_ptr, cv::Mat& ROIarea, int& nL, int& nC);
    void backgroundsubstract(double& sum, double& sum1, bool& close, int& background, \
        double& rVal, double& gVal, double& bVal, \
        double& temp_cov, \
        double& weight, \
        double& var, \
        uchar* r_ptr,
        uchar* b_ptr, \
        int nL, \
        int nC, \
        double mult, \
        double muR, \
        double muG, \
        double muB, \
        double dR, \
        double dG, \
        double dB, \
        double mal_dist, \
        cv::Mat& origin,
        cv::Mat& binimg);

    class SplitIF
    {
    public:
        static SplitIF  &Instance()
		{
			static SplitIF m_SplitIF;
			return m_SplitIF;
		};
        void RunSplitDetect(SplitObjReceiver &datain,std::vector<SplitObjIF::SplitObjSender>& dataout,bool run);
        void Setdata(SplitObjReceiver inferout);
        void Setinnerframecount(unsigned int framecount);
        unsigned int Getinnerframecount();
        SplitObjReceiver GetReceiverData();
    private:

        SplitIF();
        virtual ~SplitIF();
        SplitObjReceiver m_Data;
        unsigned int innerframecount;
    };
    
    
} // namespace SplitObj

#endif // !_SPLITIF_HPP_








