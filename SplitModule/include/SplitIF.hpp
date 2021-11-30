#ifndef _SPLITIF_HPP_
#define _SPLITIF_HPP

#include <iostream>
#include <vector>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui_c.h>
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
        cv::Rect m_postion;
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
       // 安全起见拷贝一次从inferout，等号操作深拷贝一次
       std::vector<cv::Rect> v_inferout;
        /* data */
    };


    void work(std::vector<SplitObjIF::SplitObjSender> &senderpin);


    class SplitIF
    {
    public:
        static SplitIF  &Instance()
		{
			static SplitIF m_SplitIF;
			return m_SplitIF;
		};
        std::vector<SplitObjIF::SplitObjSender> RunSplitDetect(bool run);
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








