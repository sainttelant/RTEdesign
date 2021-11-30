#include "UcitRteBase.hpp"


int main() {

	UcitRTE::UcitRteBase* UcitFactory = nullptr;
	UcitRTE::AppBase* Task = nullptr;

	// 准备几个模块的数据
	
	SplitObjIF::SplitObjReceiver dataforsplit;
	//  ...其他数据

	dataforsplit.framenum = 0;
	dataforsplit.timestamp = 111200;
	UcitFactory = new UcitRTE::UcitSplitF();
	
	Task = UcitFactory->DispatchTask(&dataforsplit);

	
	delete UcitFactory;
	delete Task;
	system("PAUSE");
	return 0;
}




