#include "UcitRteBase.hpp"


int main() {

	UcitRTE::UcitRteBase* UcitFactory = nullptr;
	UcitRTE::AppBase* Task = nullptr;

	// ׼������ģ�������
	
	SplitObjIF::SplitObjReceiver dataforsplit;
	//  ...��������

	dataforsplit.framenum = 0;
	dataforsplit.timestamp = 111200;
	UcitFactory = new UcitRTE::UcitSplitF();
	
	float factor =(float )2560 / (float)960.0;
	printf("results:%f \n", factor);
	Task = UcitFactory->DispatchTask(&dataforsplit);

	
	delete UcitFactory;
	delete Task;
	system("PAUSE");
	return 0;
}




