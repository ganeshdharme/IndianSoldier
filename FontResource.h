#include"IResource.h"
class FontResource:public IResource
{
	hgeFont *fnt;
	void loadResource(string filename) override;
	void freeResource(string filename) override;
	bool isResourceLoading()override;
	void incrementRefcount()override;
	void decrementRefcount()override;
	hgeFont* getFont();
	FontResource();
	void setPath(string)override;
	string getPath()override;
};