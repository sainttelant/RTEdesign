#include "UcitRteBase.hpp"

namespace UcitRTE
{
	AppBase* UcitSplitF::DispatchTask(void * data)
	{
		printf("it begins to dispatch Split obj detection task!\n");
		return new SplitIF(data);
	}


	void SplitIF::LinkData(void* data)
	{
		mdatas =(RTEsenderSplitInfo*) data;
	}
	void SplitIF::RunWork()
	{	
		printf("Receive Dispatch Task, it begins to work Split obj detection!\n");
		printf(">>>>>>SplitIF prepare Datas������<<<<<<<<\n");
		
		if (mdatas ==nullptr)
		{
			printf("UcitSplit modules has not received inferDatas! Maybe not work well!\n ");
		}
		std::vector<SplitObjIF::SplitObjSender> v_runret= SplitObjIF::SplitIF::Instance().RunSplitDetect(true);

	};


};
