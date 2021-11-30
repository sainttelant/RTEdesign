#ifndef __UcitRteBase__
#define __UcitRteBase__
#include "SplitIF.hpp"

#include <iostream>
#include <string.h>

namespace UcitRTE
{
	typedef SplitObjIF::SplitObjReceiver RTEsenderSplitInfo;
	// add  Abstract application
	class AppBase
	{
	public:
		AppBase(){};
		virtual ~AppBase() {};
		virtual void RunWork() {};
		virtual void LinkData(void* data) {};
	};

	// specific app 
	class SplitIF :public AppBase
	{
	public:
		SplitIF(void *data)
		{
		LinkData(data);
		 RunWork();
		};
		void RunWork();
		void LinkData(void* data);
	private:
		RTEsenderSplitInfo* mdatas;
	};

	// match module 
	class MatchIF :public AppBase
	{
	public:
		MatchIF()
		{
			void RunWork();
		}
	};

	// factory Base
	class UcitRteBase
	{
	public:
		virtual ~UcitRteBase() {};
		virtual AppBase* DispatchTask(void *data) = 0;
		//virtual UcitRteBase* Takeover() = 0;
	};

	// specific modules'factory
	class UcitSplitF:public UcitRteBase 
	{
	public:
		UcitSplitF()
		{
			printf("Construct Split_F\n");
		};
		AppBase* DispatchTask(void *data);
		//UcitSplitF* Takeover();
	};

};
#endif